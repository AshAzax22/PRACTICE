import { useState, useCallback, useEffect } from "react";
import "./App.css";
import "quill/dist/quill.snow.css";
import io from "socket.io-client";
import Quill from "quill";

const toolbarOptions = [
  ["bold", "italic", "underline", "strike"], // toggled buttons
  [{ list: "ordered" }, { list: "bullet" }, { list: "check" }],
  [{ script: "sub" }, { script: "super" }], // superscript/subscript

  [{ size: ["small", false, "large", "huge"] }], // custom dropdown
  [{ header: [1, 2, 3, 4, 5, 6, false] }],

  [{ color: [] }, { background: [] }], // dropdown with defaults from theme
  [{ font: [] }],
  [{ align: [] }],
];

function App() {
  const [quill, setQuill] = useState();
  const [socket, setSocket] = useState();

  useEffect(() => {
    const s = io("http://localhost:5001");
    setSocket(s);
    return () => {
      s.disconnect();
    };
  }, []);

  useEffect(() => {
    if (quill == null || socket == null) return;
    const handler = (delta, oldDelta, source) => {
      if (source !== "user") return;
      socket.emit("send-changes", delta);
    };
    quill.on("text-change", handler);

    return () => {
      quill.off("text-change", handler);
    };
  }, [socket, quill]);

  useEffect(() => {
    if (quill == null || socket == null) return;
    const handler = (delta) => {
      quill.updateContents(delta);
    };
    socket.on("update-changes", handler);

    return () => {
      socket.on("update-changes", handler);
    };
  }, [socket, quill]);

  const wrapperRef = useCallback((wrapper) => {
    if (!wrapper) return;
    wrapper.innerHTML = "";
    const editor = document.createElement("div");
    wrapper.append(editor);
    const q = new Quill(editor, {
      modules: { toolbar: toolbarOptions },
      theme: "snow",
    });
    setQuill(q);
  }, []);

  return (
    <>
      <div id="container" ref={wrapperRef}></div>
    </>
  );
}

export default App;

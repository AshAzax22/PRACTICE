import { useEffect, useRef } from "react";

import "./App.css";

function App() {
  // the useRef doesnt reRender the DOM
  // its basically used to target dom elements specifically and then use the reference made to play interactions with them

  const nameRef = useRef(null);
  const ageRef = useRef(null);
  console.log(nameRef);
  console.log(ageRef);
  console.log(nameRef.current);
  console.log(ageRef.current);

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(nameRef.current);
    console.log(nameRef.current.value);
    console.log(ageRef.current.value);
  };

  useEffect(() => {
    nameRef.current.focus();
  });

  return (
    <>
      <form onSubmit={handleSubmit}>
        <input type="text" ref={nameRef} placeholder="name" />
        <input type="number" ref={ageRef} placeholder="age" />
        <button type="submit">Submit</button>
      </form>
    </>
  );
}

export default App;

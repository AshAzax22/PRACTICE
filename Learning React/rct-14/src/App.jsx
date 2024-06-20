import "./App.css";
import { useState, useEffect } from "react";
import CompOne from "./assets/CompOne";
function App() {
  const [vari, setVari] = useState(0);
  return (
    <>
      <CompOne vari={vari} />
      <br />
      <br />
      <button onClick={() => setVari(0)}>0</button>
      <p> </p>
      <button onClick={() => setVari(1)}>1</button>
      <p> </p>
      <button onClick={() => setVari(2)}>2</button>
      <p> </p>
    </>
  );
}

export default App;

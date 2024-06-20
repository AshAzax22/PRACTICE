import { useState } from "react";

const CompOne = () => {
  const [curState, setcurState] = useState("TRUE");

  const handleClick = () => {
    if (curState === "TRUE") setcurState("FALSE");
    else setcurState("TRUE");
  };
  return (
    <>
      <h1>{curState}</h1>
      <button onClick={handleClick}>click</button>
    </>
  );
};

export default CompOne;

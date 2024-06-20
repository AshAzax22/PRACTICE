import React from "react";
import { useState, useEffect } from "react";
const CompThree = () => {
  const [width, setWidth] = useState(window.innerWidth);
  const changeWidth = () => {
    setWidth(window.innerWidth);
  };
  useEffect(() => {
    window.addEventListener("resize", changeWidth);
    return () => {
      window.removeEventListener("resize", changeWidth);
    };
    // we need to cleanup the useEffect whenever we re rerender the component else it keeps stacking the event listener
  }, [width]);
  return (
    <>
      <h1>width of window:</h1>
      <p>{width}</p>
    </>
  );
};
export default CompThree;

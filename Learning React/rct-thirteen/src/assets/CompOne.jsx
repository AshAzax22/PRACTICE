import React from "react";
import { useState, useEffect } from "react";

const CompOne = () => {
  const [value, setValue] = useState(0);
  useEffect(() => {
    if (value > 0) document.title = value;
  }, [value]);
  // runs every time the value is changed as its the dependency provided to the useEffect
  return (
    <>
      <p>{value}</p>
      <button
        onClick={() => {
          setValue(value + 1);
        }}
      >
        click me
      </button>
    </>
  );
};

export default CompOne;

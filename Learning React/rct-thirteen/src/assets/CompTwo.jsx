import React, { useEffect, useState } from "react";

const CompTwo = () => {
  const [message, setMessage] = useState("this is unmutated message");
  useEffect(() => {
    setMessage("this is mutated message");
  }, []);
  //runs only once because void dependencies are provided
  return (
    <>
      <h1>runs only once when the component renders</h1>
      <p>{message}</p>
    </>
  );
};

export default CompTwo;

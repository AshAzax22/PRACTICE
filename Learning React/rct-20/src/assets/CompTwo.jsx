import { useContext } from "react";
import { BodyContext } from "../App";

export default function CompTwo() {
  const { printIt } = useContext(BodyContext);
  return (
    <>
      <h1>CompTwo</h1>
      <button onClick={() => printIt()}></button>
    </>
  );
}

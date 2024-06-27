import { useContext } from "react";
import CompTwo from "./CompTwo";
import { BodyContext } from "../App";

export default function CompOne() {
  const { name } = useContext(BodyContext);
  return (
    <>
      <h1>CompOne</h1>
      <h2>{name}</h2>
      <CompTwo />
    </>
  );
}

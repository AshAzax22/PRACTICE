import React from "react";
import { useState } from "react";

let data = [
  {
    name: "james",
    age: 23,
  },
  {
    name: "john",
    age: 24,
  },
  {
    name: "peter",
    age: 25,
  },
];

const CompOne = () => {
  const [people, setPeople] = useState(data);
  const deleteItem = (index) => {
    people.splice(index, 1);
    console.log(people);
    setPeople(
      people.map((person) => {
        return person;
      })
    );
  };
  return (
    <>
      {people.map((person, index) => {
        return (
          <div key={person.name}>
            <h4>{person.name}</h4>
            <p>{person.age}</p>
            <button onClick={() => deleteItem(index)}>delete</button>
          </div>
        );
      })}
    </>
  );
};

export default CompOne;

import { useState } from "react";
import "./App.css";

function App() {
  const [person, setPerson] = useState({ name: "", age: 0, email: "" });
  const handleChange = (e) => {
    const inputField = e.target.name;
    const inputValue = e.target.value;
    setPerson({ ...person, [inputField]: inputValue });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(person);
    setPerson({ name: "", age: 0, email: "" });
  };
  return (
    <>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          name="name"
          placeholder="name"
          value={person.name}
          onChange={handleChange}
        />
        <input
          type="number"
          name="age"
          placeholder="age"
          value={person.age}
          onChange={handleChange}
        />
        <input
          type="text"
          name="email"
          placeholder="email"
          value={person.email}
          onChange={handleChange}
        ></input>
        <button type="submit">Submit</button>
      </form>
    </>
  );
}

export default App;

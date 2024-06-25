import { useState } from "react";

function App() {
  const [name, setName] = useState("");
  const [age, setAge] = useState(0);
  const handleSubmit = (e) => {
    e.preventDefault();
    console.log("Name: ", name);
    console.log("Age: ", age);
    setName("");
    setAge(0);
  };
  return (
    <>
      <form onSubmit={handleSubmit}>
        <label htmlFor="name">Name: </label>
        <input
          type="text"
          id="name"
          name="name"
          value={name}
          onChange={(e) => setName(e.target.value)}
        />
        <br />
        <label htmlFor="age">Age: </label>
        <input
          type="number"
          id="age"
          name="age"
          value={age}
          onChange={(e) => setAge(e.target.value)}
        />
        <br />
        <button type="submit">Submit</button>
      </form>
      {name && <h1>Name: {name}</h1>}
      {age > 0 && <h1>Age: {age}</h1>}
    </>
  );
}

export default App;

import "./App.css";
import { useState, useEffect } from "react";
import UserList from "./assets/UserList";
function App() {
  const [users, setUsers] = useState([]);
  const [name, setName] = useState("");
  const [age, setAge] = useState(0);
  const [email, setEmail] = useState("");
  const [id, setId] = useState(0);

  const handleSubmit = (e) => {
    e.preventDefault();
    setUsers([...users, { id, name, age, email }]);
    setId(0);
    setName("");
    setAge(0);
    setEmail("");
  };

  const updateUsers = (updatedUsers) => {
    setUsers(updatedUsers);
  };

  return (
    <>
      <form onSubmit={handleSubmit}>
        <input
          type="number"
          placeholder="ID"
          value={id}
          onChange={(e) => setId(e.target.value)}
        />
        <input
          type="text"
          placeholder="Name"
          value={name}
          onChange={(e) => setName(e.target.value)}
        />
        <input
          type="number"
          placeholder="Age"
          value={age}
          onChange={(e) => setAge(e.target.value)}
        />
        <input
          type="email"
          placeholder="Email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
        />
        <button type="submit">Add User</button>
      </form>
      {users.length != 0 && (
        <UserList users={users} updateUsers={updateUsers} />
      )}
    </>
  );
}

export default App;

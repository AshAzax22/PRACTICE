import { useReducer } from "react";
import "./App.css";

const reducer = (state, action) => {
  switch (action.type) {
    case "nameChange":
      return {
        ...state,
        name: action.newName,
      };
    case "ageChange":
      return {
        ...state,
        age: action.newAge,
      };
    case "mailChange":
      return {
        ...state,
        mail: action.newMail,
      };
    default:
      return state;
  }
};
const initialState = { name: "", age: 0, mail: "" };

function App() {
  const [state, dispatch] = useReducer(reducer, initialState);

  const handleNameChange = (e) => {
    dispatch({ type: "nameChange", newName: e.target.value });
  };
  const handleAgeChange = (e) => {
    dispatch({ type: "ageChange", newAge: e.target.value });
  };
  const handleMailChange = (e) => {
    dispatch({ type: "mailChange", newMail: e.target.value });
  };
  const handleSubmit = (e) => {
    e.preventDefault();
    console.log(state);
  };
  return (
    <>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          value={state.name}
          name="name"
          placeholder="name"
          onChange={handleNameChange}
        />
        <input
          type="number"
          value={state.age}
          name="age"
          placeholder="age"
          onChange={handleAgeChange}
        />
        <input
          type="text"
          value={state.mail}
          name="mail"
          placeholder="email"
          onChange={handleMailChange}
        />
        <button type="submit">Submit</button>
      </form>
    </>
  );
}

export default App;

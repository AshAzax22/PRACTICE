import React from "react";
import "./App.css";
import CompOne from "./assets/CompOne";

export const BodyContext = React.createContext();
const printIt = () => {
  console.log("Hello");
};
function App() {
  return (
    <BodyContext.Provider value={{ name: "ashutosh", printIt }}>
      <CompOne />
    </BodyContext.Provider>
  );
}

export default App;

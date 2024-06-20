ReactDOM.render(
  <h1>hello this is rendered by react</h1>,
  document.querySelector("#root")
);
let u = (
  <ul>
    <li>one</li>
    <li>two</li>
    <li>three</li>
  </ul>
);

function NewComp() {
  return (
    <div>
      <h1>hello this is new component</h1>
    </div>
  );
}
ReactDOM.render(u, document.querySelector("#list"));
ReactDOM.render(
  <div>
    <NewComp />
  </div>,
  document.querySelector("#newComp")
);

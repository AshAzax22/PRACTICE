import User from "./User";

const userData = [
  {
    name: "John",
    age: 25,
  },
  {
    name: "Jane",
    age: 24,
  },
  {
    name: "Doe",
    age: 26,
  },
];

export default function Users() {
  return (
    <>
      {userData.map((user) => {
        return <User {...user} />;
        {
          /* we can pass the entire object user to the component User but will have to destructre it separately so instead we can destructure it here directlty using a spread opearator using {...user} */
        }
      })}
    </>
  );
}

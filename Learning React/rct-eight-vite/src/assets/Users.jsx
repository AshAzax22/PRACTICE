import User from "./User";

const userData = [
  {
    name: "Ashutosh",
    post: "Developer",
    message: "Hello, I am a developer",
  },
  {
    name: "Rahul",
    post: "Designer",
    message: "Hello, I am a designer",
  },
  {
    name: "Rohit",
    post: "Tester",
    message: "Hello, I am a tester",
  },
];

export default function Users() {
  return (
    <>
      <User
        name={userData[0].name}
        post={userData[0].post}
        message={userData[0].message}
      >
        {/* anything written between the opening and closing of the componenet as in this case : <User></User> */}
        <p>
          Lorem ipsum dolor sit amet consectetur adipisicing elit. Beatae, quod
        </p>
      </User>
      <User
        name={userData[1].name}
        post={userData[1].post}
        message={userData[1].message}
      />
      <User
        name={userData[2].name}
        post={userData[2].post}
        message={userData[2].message}
      />
    </>
  );
}

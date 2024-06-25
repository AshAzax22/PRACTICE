import React from "react";
import User from "./User";
import styles from "./UserList.module.css";

const UserList = (props) => {
  const { users, updateUsers } = props;

  const deleteUser = (id) => {
    const updatedUsers = users.filter((user) => user.id !== id);
    updateUsers(updatedUsers);
  };
  return (
    <ul>
      {users.map((user) => {
        const { id, name, age, email } = user;
        return (
          <User
            id={id}
            key={id}
            name={name}
            age={age}
            email={email}
            deleteUser={deleteUser}
          />
        );
      })}
    </ul>
  );
};

export default UserList;

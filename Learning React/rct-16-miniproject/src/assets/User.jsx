import React from "react";
import styles from "./User.module.css";
const User = (props) => {
  const { id, name, age, email, deleteUser } = props;

  return (
    <li className={styles.user}>
      <h1 className={styles.name}>{name}</h1>
      <div className={styles.subContainer}>
        <div className={styles.details}>
          <p className={styles.age}>{age}</p>
          <p className={styles.email}>{email}</p>
        </div>
        <div className={styles.buttonContainer}>
          <button onClick={() => deleteUser(id)}>Delete User</button>
        </div>
      </div>
    </li>
  );
};

export default User;

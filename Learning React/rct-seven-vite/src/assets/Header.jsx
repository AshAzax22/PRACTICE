import styles from "./Header.module.css";
import Title from "./Title";
import logo from "./logo.png";
export default function Header() {
  return (
    <>
      <div className={styles.Header}>
        <img src={logo} alt="logo" width={100} />
        <Title />
        <div></div>
      </div>
    </>
  );
}

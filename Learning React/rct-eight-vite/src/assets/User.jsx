export default function User(props) {
  const { name, post, message } = props;
  return (
    <>
      <h1>{name}</h1>
      <h2>{post}</h2>
      <h3>{message}</h3>
      {props.children}
      {/*  //can access the children from the prop object  */}
    </>
  );
}

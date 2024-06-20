export default function User(props) {
  const { name, age } = props;
  return (
    <>
      <h1>{name}</h1>
      <h2>{age}</h2>
    </>
  );
}

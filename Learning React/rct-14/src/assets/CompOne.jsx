import React from "react";

const CompOne = (props) => {
  const { vari } = props;
  if (vari == 0) {
    return <>case when var is 0</>;
  } else if (vari == 1) {
    return <>case when var is 1</>;
  }
  return <>case when var is 2</>;
};

export default CompOne;

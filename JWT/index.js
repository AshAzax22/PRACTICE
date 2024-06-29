//imports
const express = require("express");
const app = express();
const bcrypt = require("bcrypt");
const jwt = require("jsonwebtoken");
const mongoose = require("mongoose");
const User = require("./models/User");
const cors = require("cors");

//constant values and env values
const MONGO_URI = "mongodb://localhost:27017/auth_demo";
const PORT = process.env.port || 3000;
const JWT_ENCRYPT_KEY = "chronicles_jwt_encryptor";
const REFRESH_TOKEN_KEY = "refresh_token_encrypto";

//mongo connect
mongoose.connect(MONGO_URI);

//middlewares
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cors());
//routes

//signup route
app.post("/signup", async (req, res) => {
  const { email, password } = req.body;

  if (await User.findOne({ email })) {
    return res.status(400).send("user already exists");
  }
  try {
    const hashed_password = await bcrypt.hash(password, 10); //hashing the password to store it with a cost factor of 10
    const user = new User({
      email,
      password: hashed_password,
      refresh_token: "",
    });
    await user.save();
    res.status(200).send("signup successfull");
  } catch (err) {
    res.status(400).send("signup failed");
  }
});

//login route
app.post("/login", async (req, res) => {
  const { email, password } = req.body;
  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).send("user not found");
    }
    const isLoggedOut = user.refresh_token == "" ? true : false; //checking if the user is logged out or not
    if (!isLoggedOut) {
      return res.status(400).send("user already logged in");
    }
    const is_valid = await bcrypt.compare(password, user.password);
    if (is_valid) {
      try {
        const payload = { email: user.email };
        const token = jwt.sign(payload, JWT_ENCRYPT_KEY, { expiresIn: "1h" });
        const refresh_token = jwt.sign(payload, REFRESH_TOKEN_KEY);
        user.refresh_token = refresh_token;
        await user.save();
        res.status(200).send({ token, refresh_token });
      } catch (err) {
        res.status(400).send("token generation failed");
      }
    }
  } catch (err) {
    res.status(400).send("login failed");
  }
});

//refresh token route
app.post("/refresh", (req, res) => {
  const { email, refresh_token } = req.body;
  const user = User.findOne({ email });
  if (!user) res.status(400).send("refresh failed");
  try {
    if ((user.refresh_token = refresh_token)) {
      res.status(401).send("refresh token invalid");
    }
    const token = jwt.sign(user, JWT_ENCRYPT_KEY, { expiresIn: "1h" });
    res.status(200).send({ token });
  } catch (err) {
    res.status(400).send("refresh failed");
  }
});

//middleware to verify the JWT
const verifyToken = (req, res, next) => {
  const token = req.headers.authorization?.split()[1]; //get token from header
  if (!token) {
    req.status(401).send("unauthorised");
  }
  try {
    const decoded_token = jwt.verify(token, JWT_ENCRYPT_KEY);
    req.user = decoded_token;
    next();
  } catch (err) {
    res.status(401).send("authorization failed");
  }
};

//protected route
app.get("/protected", verifyToken, (req, res) => {
  res.status(200).send("protected route accessed");
});

//logut route
app.post("/logout", async (req, res) => {
  const { email } = req.body;
  const user = await User.findOne({ email });
  if (!user) return res.status(400).send("logout failed");
  if (user.refresh_token == "") {
    return res.status(400).send("user already logged out");
  }
  user.refresh_token = "";
  await user.save();
  res.status(200).send("logout successfull");
});

//server
app.listen(PORT, () => {
  console.log(`server started on port ${PORT}`);
});

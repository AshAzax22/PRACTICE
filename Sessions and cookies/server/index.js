const express = require("express");
const mongoose = require("mongoose");
const session = require("express-session");
const MongoDBSession = require("connect-mongodb-session")(session);
const bcrypt = require("bcrypt");

const app = express();

const port = 3000;
const mongoURI = "mongodb://localhost:27017/test";

// connect to mongodb
mongoose.connect(mongoURI);

// session store
const store = new MongoDBSession({
  uri: mongoURI,
  collection: "sessions",
});

store.on("error", (err) => {
  console.log(err);
});

// middleware
app.use(express.json()); // To parse JSON bodies
app.use(express.urlencoded({ extended: true })); // To parse URL-encoded bodies

// session middleware
app.use(
  session({
    secret: "learning sessions and cookies",
    resave: false,
    saveUninitialized: false,
    store: store,
  })
);

//middleware function to check if the user is authenticated
const isAuthenticated = (req, res, next) => {
  if (!req.session.isAuth) {
    res.status(401).send("unauthorized");
  }
  next();
};

//user schema
const userSchema = new mongoose.Schema({
  email: String,
  password: String,
});

//user model
const User = mongoose.model("User", userSchema);

// routes

//signup
app.post("/signup", async (req, res) => {
  const { email, password } = req.body;
  const hashPassword = await bcrypt.hash(password, 10);
  const user = new User({
    email,
    password: hashPassword,
  });
  await user.save();
  res.status(200).send("user created");
});

//login
app.post("/login", async (req, res) => {
  const { email, password } = req.body;
  const user = await User.findOne({ email });
  if (!user) {
    res.status(401).send("user not found");
  }
  const valid = await bcrypt.compare(password, user.password);
  if (!valid) {
    res.status(401).send("invalid password");
  } else {
    req.session.isAuth = true;
    res.status(200).send("logged in");
  }
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});

//dashboard needs authentication to enter
app.get("/dashboard", isAuthenticated, (req, res) => {
  if (!req.session.auth) {
    res.status(401).send("unauthorized");
  }
  res.status(200).send("welcome to dashboard");
});

//logout and destroy the cookie
app.post("/logout", (req, res) => {
  req.session.destroy();
  res.status(200).send("logged out");
});

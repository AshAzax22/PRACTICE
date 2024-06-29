const io = require("socket.io")(5001, {
  cors: {
    origin: "*",
    methods: ["GET", "POST"],
  },
});

io.on("connection", (socket) => {
  console.log("connected");
  console.log(socket.id);
  socket.on("send-changes", (delta) => {
    console.log(delta);
    socket.broadcast.emit("update-changes", delta);
  });
});

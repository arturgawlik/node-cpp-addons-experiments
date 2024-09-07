const addon = require("./build/Release/callback.node");

addon((msg) => {
  console.log(msg);
});

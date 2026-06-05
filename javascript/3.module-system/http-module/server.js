// require http module from node module
const http = require('http');

const server = http.createServer((req, res) => {
//   console.log(req);
  res.writeHead(200, { 'Content-type': 'text/plain' });
  res.end('Hello node js from http module');
});

const port = 3000;
server.listen(port, () => {
  console.log(`server is listening on port ${port}`);
});

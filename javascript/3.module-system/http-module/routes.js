const http = require('http');

// creating a different routes
const server = http.createServer((req, res) => {
  if (req.url === '/') {
    res.writeHead(200, { 'Content-type': 'text/plain' });
    res.end('Home page');
  }
  else if(req.url === '/about') {
    res.writeHead(200, { 'Content-type': 'text/plain' });
    res.end('About page');
  }
  else if(req.url === '/projects') {
    res.writeHead(200, { 'Content-type': 'text/plain' });
    res.end('Project page');
  }
  else if(req.url === '/contact') {
    res.writeHead(200, { 'Content-type': 'text/plain' });
    res.end('Contact page');
  }
  else {
    res.writeHead(404, { 'Content-type': 'text/plain' });
    res.end('Page not found');
  }
});

const port = 5000;
server.listen(port, () => {
  console.log(`server is listening on port ${port}`);
});

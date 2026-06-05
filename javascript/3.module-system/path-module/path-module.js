// require path module from node modules
const path = require('path');

/* print directory name */
console.log('directory name: ', path.dirname(__filename));
// console.log('directory name: ', __dirname);

/* print file name */
console.log('file name: ', path.basename(__filename));
// console.log('File name: ', __filename);

/* print file extension */
console.log("file extention: ", path.extname(__filename));

/* joining path */
const joinPath = path.join('/nodejs-project', 'document', 'node-practice');
console.log('join path: ', joinPath);

/* resolve path using for add in main path*/
const resolvePath = path.resolve('projects', 'document', 'node', 'node-project');
console.log('resolve path: ', resolvePath);

/* normalize path for simplifying path */
const normalizePath = path.normalize('/user/.document/../node/node-practice');
console.log('normalize path: ', normalizePath);

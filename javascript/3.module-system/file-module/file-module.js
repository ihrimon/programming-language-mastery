// require fs and path module from node modules
const fs = require('fs');
const path = require('path');

/* creating a folder and file with synchronous way */
console.log('creating a folder and file with synchronous way')
function createFolderAndFileWithSync() {
  // folder created
  const syncFolder = path.join(__dirname, 'sync-folder');
  if (!fs.existsSync(syncFolder)) {
    fs.mkdirSync(syncFolder);
  }

  // file created
  const syncFilePath = path.join(syncFolder, 'sync-file.txt');

  // data added in file and read file
  fs.writeFileSync(syncFilePath, 'Hello node js with synchronous way');
  console.log(fs.readFileSync(syncFilePath, 'utf-8'));

  // new data added in existing file
  fs.appendFileSync(syncFilePath, '\nsomething added for file update');

  // read updated file
  console.log('After updated: ');
  console.log(fs.readFileSync(syncFilePath, 'utf-8'));
}

// function calling
createFolderAndFileWithSync();

/* creating a folder and file with asynchronous way */
console.log('\ncreating a folder and file with asynchronous way')
function createFolderAndFileWithAsync() {
  // folder created
  const asyncFolder = path.join(__dirname, 'async-folder');
  if (!fs.existsSync(asyncFolder)) {
    fs.mkdirSync(asyncFolder);
  }

  // file created
  const asyncFilePath = path.join(asyncFolder, 'async-file.txt');

  // data added in async-file and read it
  fs.writeFile(asyncFilePath, 'Hello node js with asynchronous way', (err) => {
    if (err) throw err;
  });

  fs.readFile(asyncFilePath, 'utf-8', (err, data) => {
    if (err) throw err;
    console.log(data);
  });

  // new data added in existing file
  fs.appendFile(asyncFilePath, '\nsomething added for file update', (err) => {
    if (err) throw err;
  });

  // read updated file
  fs.readFile(asyncFilePath, 'utf-8', (err, updatedData) => {
    if (err) throw err;
    console.log('After updated:');
    console.log(updatedData);
  });
}

// function calling
createFolderAndFileWithAsync();

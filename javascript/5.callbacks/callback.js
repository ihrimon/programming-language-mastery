// require fs module from node module
const fs = require('fs')

// understanding concept of callback function
fs.readFile('input.txt', 'utf-8', (err, data) => {
    if(err) {
        console.error('error reading file', err);
        return;
    }
    
    const modifyFileData = data.toUpperCase();
    fs.writeFile('output.txt', modifyFileData, (err) => {
        if(err) {
            console.error('error reading file', err);
            return;
        }
        console.log('data written to the new file');

        fs.readFile('output.txt', 'utf-8', (err, data) => {
            if(err) {
                console.error('error reading file', err);
                return;
            }
            console.log(data);
        })
    })
})
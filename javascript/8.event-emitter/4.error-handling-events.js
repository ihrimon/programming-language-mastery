// require event emitter from node module
const EventEmitter = require('events');

// create an instance of event emitter
const eventEmitter = new EventEmitter();

// error listener
eventEmitter.on('error', (err) => {
  console.log('An error occurred: ', err.message);
});

// emit an error event
eventEmitter.emit('error', new Error('Someting went wrong!'));

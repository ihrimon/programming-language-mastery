// require event emitter from node module
const EventEmitter = require('events');

// create an instance of event emitter
const eventEmitter = new EventEmitter();

// define an event listener
eventEmitter.on('greet', (name) => {
  console.log(`Hello ${name}`);
});

// emit the event
eventEmitter.emit('greet', 'Rimon');

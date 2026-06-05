// require event emitter from node module
const EventEmitter = require('events');

const eventEmitter = new EventEmitter();

// listener that triggers only once
eventEmitter.once('connect', () => {
  console.log('connected to the server!');
});

// emit the event twice
eventEmitter.emit('connect');
eventEmitter.emit('connect');

// require event emitter from node module
const EventEmitter = require('events');

// create an instance of event emitter
const eventEmitter = new EventEmitter();

// listener for 'start'
eventEmitter.on('start', () => {
  console.log('Start event is triggered!');
});

// listener for 'data'
eventEmitter.on('data', (data) => {
  console.log(data);
});

// emit events
eventEmitter.emit('start');
eventEmitter.emit('data', {
  id: 1,
  name: 'Imam Hassan Rimon',
  professon: 'Web developer',
});

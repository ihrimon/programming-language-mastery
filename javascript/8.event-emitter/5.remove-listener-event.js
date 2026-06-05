// require event emitter from node module
const EventEmitter = require('events');

// create an instace of event emmiter
const eventEmitter = new EventEmitter();

function listener() {
    console.log("This will be removed!");
}

// Add the listener
eventEmitter.on('test', listener);

// Emit the event
eventEmitter.emit('test');

// Remove the listener
eventEmitter.off('test', listener);

// Try emitting again but not found
eventEmitter.emit('test');

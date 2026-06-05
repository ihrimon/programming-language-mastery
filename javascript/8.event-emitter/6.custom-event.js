// require event emitter from node module
const EventEmitter = require('events');

class MyCustomEmitter extends EventEmitter {
  constructor() {
    super();
    this.greeting = 'Hello';
  }

  greet(name) {
    this.emit('greeting', `${this.greeting}, ${name}`);
  }
}

// create an instace
const myCustomEmitter = new MyCustomEmitter();

myCustomEmitter.on('greeting', (value) => {
  console.log('Greeting event: ', value);
});

myCustomEmitter.greet('Imam Hassan Rimon');

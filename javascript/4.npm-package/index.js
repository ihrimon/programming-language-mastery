const lodash = require('lodash');

const names = ['imam', 'hassan', 'rimon'];
const capitalize = lodash.map(names, lodash.capitalize);

console.log(capitalize);
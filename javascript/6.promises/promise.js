// understanding of promise concepts
function divideFn(num1, num2) {
  return new Promise((resolve, reject) => {
    if (typeof num1 === 'number' && typeof num2 === 'number') {
      if (num2 === 0) {
        reject('can not perform division by 0');
      } else {
        resolve(num1 / num2);
      }
    } else {
      reject('Invalid input, please provide a number value');
    }
  });
}

divideFn(10, 5)
  .then((result) => console.log('result:', result))
  .catch((error) => console.log('error:', error));

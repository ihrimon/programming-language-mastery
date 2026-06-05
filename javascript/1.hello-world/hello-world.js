// function call asynchronously 
function helloWorld() {
  // hello world print
  console.log("Hello world!");

  // array print
  const array = [1, 2, 3, 4, 5];
  console.log("array", array);

  // print this console after 2 seconds
  setTimeout(() => {
    console.log("This message is delayed by 2 seconds");
  }, 2000);

  
  console.log("This is the last line of the sync code.");
}

helloWorld();

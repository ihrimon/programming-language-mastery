// data fetching using async await function
async function fetchAPI() {
  const url = 'https://jsonplaceholder.typicode.com/posts/1';

  try {
    const response = await fetch(url);

    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }
    const data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('error message:', error.message);
  }
}

fetchAPI();

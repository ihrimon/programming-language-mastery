// =============================================================================
// 03. Functions & Function Typing
// =============================================================================
// Typed functions, parameters, return types, optional & default values
// =============================================================================

// -----------------------------------------------------------------------------
// 1. Function Type Annotations
// -----------------------------------------------------------------------------
// Function type annotations explicitly define parameter types and return types
// for functions, enabling type-safe callbacks, APIs, and higher-order functions.

// 1.1 PARAMETER ANNOTATIONS
function addToCart(productId: number, quantity: number): string {
  return `Added ${quantity} of product ${productId}`;
}

// 1.2 RETURN TYPE ANNOTATION
function calculateTotal(items: { price: number }[]): number {
  return items.reduce((sum, item) => sum + item.price, 0);
}

// 1.3 CALLBACK TYPING (Most important!)
type OnSuccess = (orderId: string) => void;
type OnError = (error: string) => void;

function processOrder(
  cart: { price: number }[],
  onSuccess: OnSuccess,
  onError: OnError,
): void {
  try {
    const total = calculateTotal(cart);
    const orderId = `ORD-${Date.now()}`;
    onSuccess(orderId);
  } catch (error) {
    onError('Payment failed');
  }
}

processOrder(
  [{ price: 999 }],
  (orderId) => console.log(`Order ${orderId} confirmed!`),
  (error) => console.error(`${error}`),
);

// -----------------------------------------------------------------------------
// 2. Parameter & Return Type Definitions
// -----------------------------------------------------------------------------
// Parameter types define input expectations (param: Type), return types specify
// output (): ReturnType). Essential for APIs, callbacks, and type-safe contracts.

type Product = {
  id: number;
  name: string;
  price: number;
  category: string;
  inStock: boolean;
};

type SearchResponse = {
  products: Product[];
  total: number;
  filters: { category: string; priceRange: [number, number] };
};

function searchProducts(params: {
  query?: string;
  category?: string;
  maxPrice?: number;
  limit?: number;
  page?: number;
}): SearchResponse {
  const allProducts: Product[] = [
    { id: 1, name: 'iPhone 15', price: 999, category: 'electronics', inStock: true },
    { id: 2, name: 'MacBook Pro', price: 1999, category: 'electronics', inStock: false },
    { id: 3, name: 'Levis Jeans', price: 89, category: 'clothing', inStock: true },
  ];

  let filtered = allProducts;

  if (params.query) {
    filtered = filtered.filter((p) =>
      p.name.toLowerCase().includes(params.query!.toLowerCase()),
    );
  }

  if (params.category) {
    filtered = filtered.filter((p) => p.category === params.category);
  }

  if (params.maxPrice) {
    filtered = filtered.filter((p) => p.price <= params.maxPrice);
  }

  const limit = params.limit ?? 10;
  const page = params.page ?? 1;
  const start = (page - 1) * limit;
  const paginated = filtered.slice(start, start + limit);

  return {
    products: paginated,
    total: filtered.length,
    filters: {
      category: params.category || 'all',
      priceRange: [0, params.maxPrice || 5000],
    },
  };
}

const electronics = searchProducts({ category: 'electronics', maxPrice: 1500 });
console.log(electronics.products[0].name);
console.log(electronics.products[0].price.toFixed(2));
console.log(electronics.total);
console.log(electronics.filters.category);

// -----------------------------------------------------------------------------
// 3. Optional, Default & Rest Parameters
// -----------------------------------------------------------------------------

// 3.1 OPTIONAL PARAMETERS (marked with ?)
function greetOptional(name: string, greeting?: string): string {
  return `${greeting ?? 'Hello'}, ${name}!`;
}
console.log(greetOptional('Alice'));
console.log(greetOptional('Alice', 'Hi'));

// 3.2 DEFAULT PARAMETERS
function greetDefault(name: string, greeting: string = 'Hello'): string {
  return `${greeting}, ${name}!`;
}
console.log(greetDefault('Bob'));
console.log(greetDefault('Bob', 'Hey'));

// 3.3 REST PARAMETERS (capture variable number of arguments)
function sumAll(...numbers: number[]): number {
  return numbers.reduce((sum, n) => sum + n, 0);
}
console.log(sumAll(1, 2, 3));
console.log(sumAll(10, 20, 30, 40, 50));

// 3.4 REST PARAMETERS WITH TYPED TUPLE
function logEvents(eventName: string, ...timestamps: [number, number, number]): void {
  console.log(`${eventName}: ${timestamps.join(', ')}`);
}
logEvents('click', 100, 200, 300);

// 3.5 OPTIONAL + DEFAULT + REST combined
function createUser(
  name: string,
  age?: number,
  role: string = 'user',
  ...tags: string[]
): object {
  return { name, age: age ?? null, role, tags };
}
console.log(createUser('Alice', 30, 'admin', 'dev', 'ts'));

// -----------------------------------------------------------------------------
// 4. Arrow Functions in TypeScript
// -----------------------------------------------------------------------------

// 4.1 BASIC ARROW FUNCTION
const add = (a: number, b: number): number => a + b;
console.log(add(5, 3));

// 4.2 ARROW FUNCTION WITH BLOCK BODY
const multiply = (a: number, b: number): number => {
  const result = a * b;
  return result;
};
console.log(multiply(4, 7));

// 4.3 ARROW FUNCTION WITH NO PARAMETERS
const getTimestamp = (): number => Date.now();
console.log(getTimestamp());

// 4.4 ARROW FUNCTION WITH SINGLE PARAMETER (parens optional)
const square = (x: number): number => x * x;
console.log(square(9));

// 4.5 ARROW FUNCTION AS CALLBACK
const doubled = [1, 2, 3].map((n: number): number => n * 2);
console.log(doubled);

// 4.6 ARROW FUNCTION WITH VOID RETURN
const logMessage = (msg: string): void => console.log(msg);
logMessage('Arrow function with void return');

// 4.7 ARROW FUNCTION TYPE ALIAS
type Transformer = (input: string) => string;
const toUpper: Transformer = (input) => input.toUpperCase();
const reverse: Transformer = (input) => input.split('').reverse().join('');
console.log(toUpper('hello'));
console.log(reverse('typescript'));

// 4.8 ASYNC ARROW FUNCTION
const fetchData = async (url: string): Promise<object> => {
  const response = await fetch(url);
  return response.json();
};

// -----------------------------------------------------------------------------
// 5. Function Type Expressions (Callback Typing)
// -----------------------------------------------------------------------------

// 5.1 FUNCTION TYPE EXPRESSION ALIAS
type NumberHandler = (value: number, index: number) => string;

function processNumbers(
  numbers: number[],
  handler: NumberHandler,
): string[] {
  return numbers.map(handler);
}

const result = processNumbers([1, 2, 3], (val, idx) => `Item ${idx}: ${val}`);
console.log(result);

// 5.2 INLINE FUNCTION TYPE EXPRESSION
function executeQuery(
  query: string,
  onResult: (rows: object[]) => void,
  onError: (code: number, message: string) => void,
): void {
  try {
    const rows: object[] = [{ id: 1, name: 'Alice' }];
    onResult(rows);
  } catch (err) {
    onError(500, 'Query failed');
  }
}

executeQuery(
  'SELECT * FROM users',
  (rows) => console.log(`Fetched ${rows.length} rows`),
  (code, message) => console.error(`Error ${code}: ${message}`),
);

// 5.3 FUNCTION TYPE EXPRESSION IN OBJECT TYPE
type EventListener = {
  on: (event: string, callback: (data: unknown) => void) => void;
  emit: (event: string, data: unknown) => void;
};

const emitter: EventListener = {
  on(event, callback) {},
  emit(event, data) {},
};

// 5.4 FUNCTION CONSTRUCTOR SIGNATURE
type UserConstructor = new (name: string, age: number) => { name: string; age: number };

class User {
  constructor(
    public name: string,
    public age: number,
  ) {}
}

function createInstance(Ctor: UserConstructor, name: string, age: number) {
  return new Ctor(name, age);
}

const instance = createInstance(User, 'Alice', 30);
console.log(instance);

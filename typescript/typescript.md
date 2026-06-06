## 📑 TypeScript

| Topics                                                                                | Overview                                                               |
| ------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| [01. Introduction & Project Setup](#01-introduction--project-setup)                   | TypeScript basics, setup, and project initialization workflow          |
| [02. Core Types & Type System Foundations](#02-core-types--type-system-foundations)   | Primitive types, arrays, objects, unions, literals, and fundamentals   |
| [03. Functions & Function Typing](#03-functions--function-typing)                     | Typed functions, parameters, return types, optional & default values   |
| [04. Type Narrowing & Type System Analysis](#04-type-narrowing--type-system-analysis) | Conditional checks, control flow, and safe type refinement             |
| [05. Generics & Reusable Type Patterns](#05-generics--reusable-type-patterns)         | Writing flexible, reusable, and type-safe components using generics    |
| [06. Classes & OOP in TypeScript](#06-classes--oop-in-typescript)                     | Classes, interfaces, access modifiers, inheritance, and OOP principles |
| [07. Built-in Utility Types](#07-built-in-utility-types)                              | Leveraging Partial, Pick, Omit, and other utility types effectively    |

### 01. Introduction & Project Setup

- [x] What is TypeScript ?
- [x] Why Use TypeScript ?
- [x] TypeScript vs JavaScript
- [x] How TypeScript Works ?
- [x] Installation & Environment Setup
- [x] Basic Overview of tsconfig.json

### 02. Core Types & Type System Foundations

- [x] Primitive Types
- [x] any vs unknown
- [x] void, null, undefined, never
- [x] Literal Types & Template Literal Types
- [x] Type Inference
- [x] Type Aliases
- [x] Union Types
- [x] Intersection Types
- [x] Object Type Annotations
- [ ] Array & Tuple Types
- [ ] Enum Types
- [ ] Interfaces vs Type Aliases
- [ ] Declaration Files (.d.ts)


### 03. Functions & Function Typing

<details>
<summary><b >Function Type Annotations</b></summary>

Function type annotations explicitly define parameter types and return types for functions, enabling type-safe callbacks, APIs, and higher-order functions.

```typescript
/*** Production shopping cart with typed callbacks ***/

// 1. PARAMETER ANNOTATIONS
function addToCart(productId: number, quantity: number): string {
  return `Added ${quantity} of product ${productId}`;
}

// 2. RETURN TYPE ANNOTATION
function calculateTotal(items: { price: number }[]): number {
  return items.reduce((sum, item) => sum + item.price, 0);
}

// 3. CALLBACK TYPING (Most important!)
type OnSuccess = (orderId: string) => void;
type OnError = (error: string) => void;

function processOrder(
  cart: { price: number }[],
  onSuccess: OnSuccess, // Explicit callback type
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

// Real usage - Type safe callbacks!
processOrder(
  [{ price: 999 }],
  (orderId) => console.log(`Order ${orderId} confirmed!`),
  (error) => console.error(`${error}`),
);
```

</details>
<details>
<summary><b >Parameter & Return Type Definitions</b></summary>

Parameter types define input expectations (param: Type), return types specify output (): ReturnType). Essential for APIs, callbacks, and type-safe contracts.

```typescript
/*** Complete e-commerce search with FULL type safety ***/
// 1. TYPES (Real production shapes)
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

// 2. MAIN FUNCTION - Parameter & Return types
function searchProducts(params: {
  query?: string; // Optional search term
  category?: string; // Optional filter
  maxPrice?: number; // Optional price limit
  limit?: number; // Pagination
  page?: number; // Pagination
}): SearchResponse {
  // Simulate database query
  const allProducts: Product[] = [
    {
      id: 1,
      name: 'iPhone 15',
      price: 999,
      category: 'electronics',
      inStock: true,
    },
    {
      id: 2,
      name: 'MacBook Pro',
      price: 1999,
      category: 'electronics',
      inStock: false,
    },
    {
      id: 3,
      name: 'Levis Jeans',
      price: 89,
      category: 'clothing',
      inStock: true,
    },
  ];

  // TypeScript KNOWS params.query exists (or undefined)
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

// 3. USAGE - PERFECT AUTOCOMPLETE
const electronics = searchProducts({
  category: 'electronics',
  maxPrice: 1500,
});

console.log(electronics.products[0].name); // "iPhone 15" - autocomplete works!
console.log(electronics.products[0].price.toFixed(2)); // Works!
console.log(electronics.total); // number
console.log(electronics.filters.category); // string
```

</details>
- 
- Optional, Default & Rest Parameters
- Arrow Functions in TypeScript
- Function Type Expressions (Callback Typing)

### 04. Type Narrowing & Type System Analysis

<details>
<summary><b >Type Guards</b></summary>

Type Guards are functions or expressions that narrow union types to specific types within a conditional block. TypeScript uses control flow analysis to "remember" these checks.

**Types of Type Guards:**

- Built-in: `typeof`, `instanceof`, `in`
- Custom: Functions returning `param is Type`
- Discriminated: Unions with `type: 'literal'`

```typescript
/*** Production payment system ***/

// Bank payment as class (for instanceof)
class BankPayment {
  type: 'bank' = 'bank';
  constructor(
    public account: string,
    public routing: string,
  ) {}
}

type Payment =
  | { type: 'credit-card'; cardNumber: string; expiry: string; cvv: string }
  | { type: 'paypal'; email: string; payerId: string }
  | BankPayment
  | { type: 'error'; message: string };

function processPayment(payment: Payment): string {
  // 1. DISCRIMINATED UNION
  if (payment.type === 'credit-card') {
    return `Charged via CC ending ${payment.cardNumber.slice(-4)}`;
  }

  // 2. CUSTOM TYPE GUARD
  if (isPaypalPayment(payment)) {
    return `PayPal payment from ${payment.email}`;
  }

  // 3. INSTANCEOF (works with class only)
  if (payment instanceof BankPayment) {
    // TypeScript KNOWS: account & routing exist
    return `Bank transfer to ${payment.account}`;
  }

  // 4. Fallback (error type)
  return `Error: ${payment.message}`;
}

// Custom type guard
function isPaypalPayment(
  p: Payment,
): p is { type: 'paypal'; email: string; payerId: string } {
  return p.type === 'paypal';
}

// Usage

processPayment({
  type: 'credit-card',
  cardNumber: '****1234',
  expiry: '12/25',
  cvv: '123',
});

processPayment({
  type: 'paypal',
  email: 'alice@paypal.com',
  payerId: 'PP123',
});

processPayment(new BankPayment('123456789', '987654321'));
```

</details>

<details>
<summary><b >Custom Type Guards</b></summary>

Custom Type Guards are functions returning param is Type that narrow union types to specific types. TypeScript uses the return type to automatically refine types within the true branch.

**Key Features:**

- Syntax: function isType(value: unknown): value is SpecificType
- Purpose: Narrow unions safely
- Return: Boolean + type predicate
- Better than: Manual casting/assertions

```typescript
/*** Production file upload handler***/
type Document =
  | { type: 'pdf'; pages: number; filename: string }
  | { type: 'docx'; words: number; filename: string }
  | { type: 'image'; width: number; height: number; filename: string }
  | { type: 'unknown'; error: string };

// function declaration for parseFile from any other source
declare function parseFile(file: unknown): Document;

// CUSTOM TYPE GUARDS
function isPdfDocument(
  doc: Document,
): doc is { type: 'pdf'; pages: number; filename: string } {
  return doc.type === 'pdf';
}

function isImageDocument(
  doc: Document,
): doc is { type: 'image'; width: number; height: number; filename: string } {
  return doc.type === 'image';
}

function isValidDocument(
  doc: Document,
): doc is Exclude<Document, { type: 'unknown' }> {
  return doc.type !== 'unknown';
}

// MAIN PROCESSOR - 100% TYPE SAFE
function processDocument(file: unknown): string {
  const doc = parseFile(file);

  // CUSTOM GUARD #1
  if (isPdfDocument(doc)) {
    // TypeScript KNOWS: pages, filename exist!
    return `📄 PDF: ${doc.filename} (${doc.pages} pages)`;
  }

  // CUSTOM GUARD #2
  if (isImageDocument(doc)) {
    // TypeScript KNOWS: width, height, filename exist!
    return `🖼️  Image: ${doc.filename} (${doc.width}x${doc.height})`;
  }

  // COMPOUND GUARD
  if (isValidDocument(doc)) {
    // TypeScript KNOWS: NOT unknown type!
    return `✅ Valid: ${doc.filename}`;
  }

  // 4. NARROWED TO ERROR
  return `❌ ${doc.error}`;
}

// USAGE
processDocument(uploadedFile1); // "PDF: report.pdf (12 pages)"
processDocument(uploadedFile2); // "Image: photo.jpg (1920x1080)"
```

</details>

<details>
<summary><b >Type Assertions and Non-null Assertion Operator (!)</b></summary>

Type Assertions and Non-null Assertion Operator (!) are used to tell TypeScript to treat a value as a specific type, even if TypeScript can't infer it automatically.

**Type Assertions `(as Type)`:** : "Treat this value as this specific type". Bypasses type checking.

**Non-null Assertion `(!)`:** : "This value is definitely not null/undefined". Removes nullability.

```typescript
/*** Production file upload handler ***/
// 1. DOM (Most common)
const button = document.getElementById('submit') as HTMLButtonElement;
// Now: button.click(), button.value, button.disabled work perfectly

// 2. Non-null (After validation)
const user = getUser(id);
if (!user) return;
user!.name.toUpperCase(); // Safe non-null

// 3. JSON Parsing
const data = JSON.parse(json) as User[]; // Full autocomplete

// 4. React Refs
inputRef.current!.focus(); // Safe after mount

// 5. Event Casting
(event.target as HTMLInputElement).value;
```

</details>

<details>
<summary><b >Type Narrowing</b></summary>

Type Narrowing refines broad types (unions, unknown) to specific types using TypeScript's control flow analysis. TypeScript "remembers" checks to enable safe property access.

**Core Narrowing Techniques:**

- typeof - Primitive narrowing (string, number, boolean)
- Equality (===) - Literal narrowing
- `in` operator - Property existence
- instanceof - Class/constructor narrowing
- Truthiness - null/undefined removal
- Custom Type Guards - `param is Type`
- Discriminated Unions - `type: 'literal'`

```typescript
/*** Production file upload system - ALL techniques! ***/

// 1. DISCRIMINATED UNION (type: 'literal')
type MediaFile =
  | { type: 'image'; width: number; height: number; filename: string }
  | { type: 'video'; duration: number; filename: string }
  | { type: 'audio'; bitrate: number; filename: string }
  | { type: 'error'; message: string };

// 2. CLASS FOR INSTANCEOF
class ImageProcessor {
  constructor(
    public width: number,
    public height: number,
  ) {}
  getSize() {
    return this.width * this.height;
  }
}

// 3. PROCESSOR WITH ALL TECHNIQUES
function processMedia(file: unknown): string {
  const media = file as MediaFile; // Safe after API validation

  // TECHNIQUE 1: TRUTHINESS (null check)
  if (!media) {
    return 'No file provided';
  }

  // TECHNIQUE 2: EQUALITY (Discriminated Union)
  if (media.type === 'image') {
    return `Image: ${media.filename} (${media.width}x${media.height})`;
  }

  // TECHNIQUE 3: TYPEOF (Primitive narrowing)
  if (typeof media.duration === 'number') {
    return `🎥 Video: ${media.filename} (${media.duration}s)`;
  }

  // TECHNIQUE 4: CUSTOM TYPE GUARD
  if (isAudioFile(media)) {
    return `🎵 Audio: ${media.filename} (${media.bitrate}kbps)`;
  }

  // TECHNIQUE 5: `in` OPERATOR
  if ('bitrate' in media) {
    return `🔊 Audio detected: ${media.bitrate}`;
  }

  // TECHNIQUE 6: INSTANCEOF
  if (media instanceof ImageProcessor) {
    return `Processed: ${media.getSize()} pixels`;
  }

  // TECHNIQUE 7: FALLBACK (narrowed to error)
  return `Error: ${media.message}`;
}

// TECHNIQUE 4: Custom Type Guard
function isAudioFile(
  file: MediaFile,
): file is { type: 'audio'; bitrate: number; filename: string } {
  return file.type === 'audio';
}

// REAL USAGE
const files: (MediaFile | ImageProcessor | null)[] = [
  { type: 'image', width: 1920, height: 1080, filename: 'photo.jpg' },
  { type: 'video', duration: 125, filename: 'movie.mp4' },
  { type: 'audio', bitrate: 128, filename: 'song.mp3' },
  new ImageProcessor(800, 600),
  { type: 'error', message: 'File too large' },
];

files.forEach((file) => console.log(processMedia(file)));
```

</details>

<details>
<summary><b >Control Flow Based Type Analysis</b></summary>

Control Flow Based Type Analysis is TypeScript's ability to track variable types through code execution paths (if/else, switch, loops). The compiler analyzes all possible flows to determine the most specific type at each location.

**How It Works:**

- TypeScript simulates: "What type can this be here?"
- Tracks assignments through if/else branches
- Remembers narrowing in conditional blocks
- Never forgets previous checks
- Provides precise autocomplete (knows what type it is)

```typescript
/*** Easy e-commerce checkout - Control flow in action! ***/
type CartItem = { name: string; price: number };

type CheckoutState =
  | { step: 'cart'; items: CartItem[] }
  | { step: 'payment'; amount: number }
  | { step: 'complete'; orderId: string }
  | { step: 'error'; message: string };

let checkout: CheckoutState = { step: 'cart', items: [] };

// Simulate user actions
function nextStep(current: CheckoutState): CheckoutState {
  // CONTROL FLOW ANALYSIS TRACKS TYPE THROUGH PATHS
  if (current.step === 'cart') {
    const total = current.items.reduce((sum, item) => sum + item.price, 0);
    return { step: 'payment', amount: total };
  }

  if (current.step === 'payment') {
    return { step: 'complete', orderId: `ORD-${Date.now()}` };
  }

  if (current.step === 'complete') {
    return { step: 'error', message: 'Cannot restart complete order' };
  }

  return current;
}

// USAGE - Perfect autocomplete everywhere!
checkout = nextStep(checkout); // → { step: 'payment', amount: number }
console.log(`Pay $${checkout.amount}`); // amount autocomplete!

checkout = nextStep(checkout); // → { step: 'complete', orderId: string }
console.log(`Order ${checkout.orderId}`); // orderId autocomplete!

checkout = nextStep(checkout); // → { step: 'error', message: string }
console.log(`Error: ${checkout.message}`); // message autocomplete!
```

</details>

### 05. Generics & Reusable Type Patterns

- Generic Fundamentals
- What are Generics?
- Why Generics are Needed
- Basic Generic Syntax (<T>)
- Generic Functions
- Generic Function Definitions
- Generic Arrow Functions
- Inference vs Explicit Generic Types
- Generic Interfaces & Type Aliases
- Generic Interfaces
- Generic Type Aliases
- Extending Generic Interfaces
- Generic Constraints (<T extends ...>)
- Constraining Generics (<T extends ...>)
- Using keyof with Generics
- Multiple Constraints
- Default Generic Types
- Advanced Generic Patterns
- Multiple Generic Parameters
- Conditional Generics (intro-level)
- Generic Utility Patterns

### 06. Classes & OOP in TypeScript

- Class Syntax in TypeScript
- Constructors
- Access Modifiers (public, private, protected, readonly)
- Inheritance
- Method Overriding
- Polymorphism
- Abstract Classes
- Static Properties & Methods
- Implementing Interfaces in Classes

### 07. Built-in Utility Types

<details>
<summary><b >Partial, Required, Readonly</b></summary>

Utility types transform existing types: `Partial<T>` (all optional), `Required<T>` (all mandatory), `Readonly<T>` (immutable).

```typescript
type User = {
  name: string;
  email?: string;
  role?: string;
};

// 1. Partial - Update any field
function updateUser(id: string, updates: Partial<User>) {
  // updates.name? OR updates.email? OR updates.role?
}

updateUser('u1', { name: 'Alice' }); // ✅ OK
updateUser('u2', { email: 'bob@test.com' }); // ✅ OK

// 2. Required - Create complete user
function createUser(data: Required<User>) {
  // ALL fields required
}

createUser({ name: 'Alice', email: 'a@test.com', role: 'admin' }); // ✅ OK

// 3. Readonly - Cannot change
function getUser(): Readonly<User> {
  return { name: 'Alice', email: 'a@test.com' };
}

const user = getUser();
user.name = 'Bob'; // ❌ Error! readonly
```

</details>

<details>
<summary><b >Pick, Omit</b></summary>

`Pick<T, K>` extracts specific properties from type T. `Omit<T, K>` excludes specified properties from type T.

```typescript
type User = {
  id: string;
  name: string;
  email: string;
  password: string;
  role: string;
};

// API Responses - Perfect use case!

// 1. Pick - Public profile (ONLY needed fields)
type PublicUser = Pick<User, 'id' | 'name' | 'email'>;
// Result: { id: string; name: string; email: string }

// 2. Omit - Hide sensitive data
type LoginResponse = Omit<User, 'password'>;
// Result: { id: string; name: string; email: string; role: string }

// Real API usage
function getPublicProfile(user: User): PublicUser {
  return { id: user.id, name: user.name, email: user.email };
}

function loginResponse(user: User): LoginResponse {
  return { id: user.id, name: user.name, email: user.email, role: user.role };
}

// ✅ Type safe - no password leaks!
const profile: PublicUser = getPublicProfile(fullUser);
```

</details>

<details>
<summary><b >Record</b></summary>

`Record<K, T>` creates an object type where keys are type `K` and all values are type `T`. Perfect for lookup tables, configs, and API response maps.

```typescript
Record<Keys, ValueType>

Keys: string | number | symbol (union or literal)
Values: Any type (string, object, function, etc.)
```

```typescript
/*** 🎯 Role-based permissions lookup ***/
type Role = 'admin' | 'user' | 'guest';
type Permission = string[];

// Perfect lookup table!
const permissions: Record<Role, Permission> = {
  admin: ['read', 'write', 'delete', 'ban'],
  user: ['read', 'write'],
  guest: ['read'],
};

// ✅ Type safe access
function checkPermission(role: Role, action: string): boolean {
  return permissions[role].includes(action);
}

checkPermission('admin', 'delete'); // true
checkPermission('guest', 'delete'); // false
// checkPermission('moderator', 'read'); // ❌ Type error!
```

</details>

<details>
<summary><b >Exclude, Extract</b></summary>

`Exclude<T, U>` removes types from T that are assignable to U. `Extract<T, U>` extracts types from T that are assignable to U.

```typescript
// Example: Extract only string literals from a union
const strings: Extract<'a' | 'b' | 1 | 2> = 'a';
const numbers: Exclude<'a' | 'b' | 1 | 2> = 1;
```

</details>

<details>
<summary><b >NonNullable</b></summary>

`NonNullable<T>` removes null and undefined from type T.

```typescript
// Example: Remove null and undefined from a type
const nonNullable: NonNullable<string | null | undefined> = 'hello';
```

</details>

<details>
<summary><b >ReturnType, Parameters</b></summary>

`ReturnType<T>` extracts the return type of a function type T. `Parameters<T>` extracts the parameter types of a function type T.

```typescript
// Example: Extract return type of a function
const result: ReturnType<() => string> = 'hello';

// Example: Extract parameter types of a function
const params: Parameters<(a: number, b: string) => void> = [1, 'hello'];
```

</details>

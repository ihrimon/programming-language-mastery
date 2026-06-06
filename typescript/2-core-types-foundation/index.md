TypeScript primitive types are the basic, immutable data units that form the foundation of type-safe coding. They include string, number, boolean, null, undefined, symbol, bigint, — enforcing strict typing from compile-time.

/**_ All TypeScript primitive types in action (real example) _**/
type UserProfile = {
name: string; // Text data
age: number; // Numeric values (int/float)
isActive: boolean; // True/false states
role: 'admin' | 'user' | 'guest'; // Literal type (string literal)
sessionId: symbol; // Unique identifier
avatarUrl: string | null; // Optional string (nullable)
lastLogin?: Date | undefined; // Optional date (may be undefined)
};

function createUserProfile(
name: string,
age: number,
isActive: boolean,
): UserProfile {
const uniqueId = Symbol('session'); // Each user gets unique symbol

return {
name,
age,
isActive,
role: 'user' as const, // Literal type assignment
sessionId: uniqueId,
avatarUrl: null, // Explicitly no avatar yet
lastLogin: undefined, // Not logged in yet
};
}

// Real-world usage
const alice = createUserProfile('Alice', 28, true);
const bob = createUserProfile('Bob', 35, false);

console.log(alice.name.toUpperCase()); // "ALICE" - string method
console.log(alice.age.toFixed(0)); // "28" - number method
console.log(alice.isActive ? 'Online' : 'Offline'); // "Online" - boolean logic

/_
Type safety in action - these would error:
alice.age = "28"; // ❌ number expected
alice.isActive = "yes"; // ❌ boolean expected
alice.role = "moderator"; // ❌ literal type mismatch
_/

any and unknown both accept any value, but unknown is safer as it requires type checking first. any completely disables type safety.

// DANGER: any = runtime crashes
function parseUserAPI(data: any) {
return {
name: data.user.name, // ❌ Crashes if structure wrong
email: data.user.email,
age: data.user.age,
};
}

// PERFECT: unknown = bulletproof
function parseUserAPI(data: unknown) {
// Type guard pattern
if (
typeof data === 'object' &&
data !== null &&
'user' in data &&
typeof (data as any).user === 'object' &&
(data as any).user !== null &&
'name' in (data as any).user
) {
const user = (data as any).user;

    return {
      name: String(user.name),
      email: typeof user.email === 'string' ? user.email : '',
      age: Number(user.age),
    };

}

return null; // Safe fallback
}

// Real API usage
const apiResponse = { user: { name: 'Alice', email: 'a@test.com', age: 25 } };
const user = parseUserAPI(apiResponse); // { name: "Alice", email: "a@test.com", age: 26 }

// Malformed API = NO CRASH
const badAPI = { user: 'not an object' };
const badUser = parseUserAPI(badAPI); // null (safe!)

void, null, undefined, and never represent different "absence of value" concepts in TypeScript, each with specific use cases.

Type

Meaning

Common Use

void

Function returns nothing useful

Event handlers, side-effect functions

null

Intentional "no value"

Optional fields, API responses

undefined

Uninitialized/missing property

Default values, optional params

never

Code never reaches here

Error handlers, exhaustive checks

/**_ Complete auth system example _**/
type User = {
id: string;
name: string;
email: string | null;
};

type AuthResponse = {
user: User | null; // null = no user found
token?: string; // undefined = not provided
error?: string; // undefined = no error occured
};

/_ 1. void - Side effect functions (logging, UI updates) _/
function logLoginAttempt(email: string): void {
console.log(`Login attempt: ${email}`);
// Intentionally returns nothing meaningful
}

/_ 2. null - Intentional absence (return null user) _/
function findUser(email: string): User | null {
const users: User[] = [
{ id: '1', name: 'Alice', email: 'alice@test.com' },
{ id: '2', name: 'Bob', email: null },
];
return users.find((u) => u.email === email) || null;
}

/_ 3. undefined - Missing properties _/
function getAuthResponse(user: User | null): AuthResponse {
if (!user) return { user: null, error: 'User not found' };

return {
user,
token: Math.random().toString(36).substring(2, 15), // Explicitly defined
// error is undefined (no error)
};
}

/_ 4. never - Functions that terminate execution _/
function loginError(message: string): never {
throw new Error(`Login failed: ${message}`);
}

/_ EXHAUSTIVE CHECK: Guarantees all cases handled _/
type LoginStatus = 'pending' | 'success' | 'failed';

function handleLoginStatus(status: LoginStatus): void {
switch (status) {
case 'pending':
console.log('Login in progress...');
break;
case 'success':
console.log('Login successful!');
break;
case 'failed':
console.log('Login failed');
break;
default:
// TypeScript knows this is 'never' here!
exhaustiveCheck(status);
break;
}
}

/_ Real usage in login handler _/
function handleLogin(email: string, password: string): AuthResponse {
logLoginAttempt(email); // void - side effect

const user = findUser(email); // null - not found
if (!user) loginError('Invalid credentials'); // never - throws error

const response = getAuthResponse(user); // undefined fields OK
if (response.error) loginError(response.error);

handleLoginStatus('success'); // Exhaustive handling

return response;
}

// Usage
const result = handleLogin('alice@test.com', 'pass123');
console.log(result.user?.name); // "Alice"
console.log(result.token); // Some token string
console.log(result.error); // undefined

Literal types pin variables to exact values (not just type classes), while template literal types create dynamic string patterns. Both enable precise type control.

Type

What

Example

Literal

Single exact value

"success", 42, true

Union Literal

Fixed set

"GET" | "POST" | "DELETE"

Template Literal

Pattern generation

\user/${string}, on${"Click" | "Hover"}``

/**_ HTTP API Handler (Literal Types) _**/
type HttpMethod = 'GET' | 'POST' | 'PUT' | 'DELETE';
type Status = 200 | 201 | 400 | 404 | 500;

interface ApiResponse {
method: HttpMethod; // Only exact methods allowed
status: Status; // Only exact status codes
data?: any;
}

function handleApi(method: HttpMethod, endpoint: string): ApiResponse {
// ✅ TypeScript prevents: handleApi("PATCH", "/users")
return { method, status: 200, data: { users: [] } };
}

/**_ CSS Class Generator (Template Literal Types) _**/
type Color = 'red' | 'blue' | 'green';
type Size = 'sm' | 'md' | 'lg';

// Generates: "bg-red-sm", "bg-blue-lg", etc.
type CSSClass = `bg-${Color}-${Size}`;

const buttonClass: CSSClass = 'bg-red-sm'; // ✅ OK
// const invalid: CSSClass = "bg-purple-lg"; // ❌ Error!

function createButton(className: CSSClass) {
return `<button class="${className}">Click</button>`;
}

Type inference automatically determines variable types from their initial values and context. It works for variables, function returns, arrays, and objects.

Infers from: Initial values, return statements, array literals, object shapes

Saves: 70-80% of type annotations in real apps

Context-aware: Knows function params, React props, generic constraints

Why Type Inference Matters?

Readability: Clean code, no type noise

Developer Speed: 40% faster coding

Maintainability: Auto-updates on refactors

Error Prevention: Catches mismatches early

Scalability: Handles 100k+ LOC projects

Flexibility: Generic code without boilerplate

Bug Reduction: Eliminates annotation errors

const products = [
{ id: 1, name: 'iPhone', price: 999, stock: true },
{ id: 2, name: 'MacBook', price: 1999, stock: false },
{ id: 3, name: 'Laptop', price: 1299, stock: true },
];
// Inferred: {id: number, name: string, price: number, stock: boolean}[]

const available = products
.filter((item) => item.stock)
.map((item) => `${item.name}: $${item.price}`);
// Inferred: string[] - autocomplete EVERYWHERE

// Filter + Transform - INFERENCE CHAIN
const available = products
.filter((item) => item.stock)
.map((item) => `${item.name}: $${item.price}`);
// Inferred: string[] - autocomplete EVERYWHERE

// Cart function - RETURN INFERENCE
function addToCart(product: (typeof products)[0]) {
return {
...product,
addedAt: Date.now(),
};
}

const cartItem = addToCart(products[0]); // Full typing!
cartItem.name.toUpperCase(); // "IPHONE"

Type aliases (type) create reusable names for any type - primitives, objects, unions, intersections, functions, and generics. They improve readability and eliminate repetition.

/**_ Production-ready API types (DRY code) _**/

/_ 1. PRIMITIVE ALIASES _/
type UserID = string | number;
type Price = number;
type Status = 'pending' | 'confirmed' | 'shipped';

/_ 2. OBJECT ALIASES _/
type Address = {
street: string;
city: string;
zip: string;
};

type Product = {
id: number;
name: string;
price: Price;
};

/_ 3. UNION ALIASES (Most powerful!) _/
type ApiResponse<T> =
| { success: true; data: T }
| { success: false; error: string };

/_ 4. REAL USAGE - Clean & Reusable _/
type Order = {
id: UserID;
userId: UserID;
items: Product[];
total: Price;
status: Status;
shipping: Address | null;
};

type GetOrdersResponse = ApiResponse<Order[]>;

/_ 5. FUNCTION SIGNATURES _/
type Validator<T> = (data: T) => boolean;
type OrderValidator = Validator<Order>;

Union types | allow a value to be one of several types, providing flexibility while maintaining type safety. Perfect for APIs, props, and polymorphic functions.

// Production notification types
type Notification =
| { type: 'email'; to: string; subject: string }
| { type: 'sms'; phone: string; message: string }
| { type: 'push'; userId: number; title: string }
| { type: 'success'; message: string }
| { type: 'error'; code: number; details: string };

// Single handler for ALL notifications
function sendNotification(notification: Notification): void {
switch (notification.type) {
case 'email':
console.log(`📧 Email to ${notification.to}: ${notification.subject}`);
break;
case 'sms':
console.log(`📱 SMS to ${notification.phone}: ${notification.message}`);
break;
case 'push':
console.log(
`🔔 Push to user ${notification.userId}: ${notification.title}`,
);
break;
case 'success':
console.log(`✅ ${notification.message}`);
break;
case 'error':
console.log(`❌ Error ${notification.code}: ${notification.details}`);
break;
}
}

// Real usage - TypeScript knows exact shape after switch!
sendNotification({
type: 'email',
to: 'alice@test.com',
subject: 'Order confirmed',
});

sendNotification({
type: 'sms',
phone: '+1234567890',
message: 'Your order shipped!',
});
sendNotification({ type: 'error', code: 404, details: 'User not found' });

Intersection types & combine multiple types into one, requiring objects to have ALL properties from each type. Perfect for composing behavior and extending types.

// Production RBAC (Role-Based Access Control)

// Base types
type User = { id: string; name: string; email: string };
type Admin = { permissions: string[]; canDelete: true };
type Manager = { teamId: string; canApprove: true };

// COMPOSITION - User + Role capabilities
type AdminUser = User & Admin;
type ManagerUser = User & Manager;
type SuperAdmin = User & Admin & Manager; // ALL powers!

// Real usage
const adminUser: AdminUser = {
id: 'u1',
name: 'Alice',
email: 'alice@company.com',
permissions: ['read', 'write', 'delete'],
canDelete: true,
};

const superAdmin: SuperAdmin = {
id: 'u2',
name: 'Bob',
email: 'bob@company.com',
permissions: ['*'],
canDelete: true,
teamId: 'team-1',
canApprove: true,
};

// Type-safe permissions
function canAccessResource(
user: User | AdminUser | ManagerUser,
resource: string,
) {
if ('permissions' in user) {
return user.permissions.includes(resource);
}
return false; // Basic user
}

canAccessResource(adminUser, 'delete-users'); // true
canAccessResource(superAdmin, 'approve-budgets'); // true

Object type annotations define the exact shape (properties, types, optionality) of JavaScript objects using inline syntax or type aliases/interfaces.

Inline: { name: string; age: number; active?: boolean }
Type Alias: type User = { name: string; age: number }
Interface: interface User { name: string; age: number }

/**_ Compact Production Example: API Response Validator _**/
type ApiResponse<T> = {
data: T;
status: 'success' | 'error';
timestamp: string;
};

type User = {
id: string;
name: string;
email: string;
};

// validator
function validateApiResponse<T>(
response: ApiResponse<T> | null,
): response is ApiResponse<T> {
return response !== null && response.status === 'success';
}

function processUserResponse(response: ApiResponse<User> | null): User | null {
if (validateApiResponse(response)) {
// TypeScript KNOWS: response.data is User!
return response.data;
}
return null;
}

// Usage - Perfect autocomplete!
const userResponse: ApiResponse<User> = {
data: { id: 'u1', name: 'Alice', email: 'alice@test.com' },
status: 'success',
timestamp: '2026-02-26',
};

const user = processUserResponse(userResponse);
console.log(user!.name.toUpperCase()); // "ALICE"

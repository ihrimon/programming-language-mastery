# 📑 JavaScript — Complete Roadmap & Checklist

I'm starting my JavaScript journey here, phase by phase, one topic at a time.

| #   | Phase                                                                         | Overview                                                              |
| --- | ----------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| 01  | [Introduction](#01-introduction)                                              | What is JS, ECMAScript, engines, runtimes, how JS runs                |
| 02  | [Fundamentals & Data Types](#02-fundamentals--data-types)                     | Variables, primitives, references, type coercion, equality            |
| 03  | [Operators & Control Flow](#03-operators--control-flow)                       | Operators, conditionals, loops, labels, short-circuiting              |
| 04  | [Functions](#04-functions)                                                    | Declarations, expressions, arrows, params, callbacks, recursion       |
| 05  | [Execution Context, Scope & Closures](#05-execution-context-scope--closures)  | Call stack, hoisting, TDZ, scope chain, closures                      |
| 06  | [Objects & `this`](#06-objects--this)                                         | Object internals, descriptors, copying, `this` binding rules          |
| 07  | [Arrays & Iteration](#07-arrays--iteration)                                   | Array methods, sorting, destructuring, spread, iteration protocols    |
| 08  | [Strings, Numbers, Math, Date & RegExp](#08-strings-numbers-math-date--regexp) | Built-in objects and text/number/date handling                        |
| 09  | [Prototypes & OOP](#09-prototypes--oop)                                       | Prototype chain, constructors, classes, inheritance, mixins           |
| 10  | [Modern JavaScript (ES6 → ES2025)](#10-modern-javascript-es6--es2025)         | Modern syntax, Map/Set, Symbol, generators, Proxy, new features       |
| 11  | [Asynchronous JavaScript](#11-asynchronous-javascript)                        | Event loop, callbacks, promises, async/await, fetch, concurrency      |
| 12  | [Error Handling & Debugging](#12-error-handling--debugging)                   | try/catch, custom errors, DevTools, source maps, logging              |
| 13  | [Modules & Tooling](#13-modules--tooling)                                     | ESM/CommonJS, npm, bundlers, linting, formatting, Babel               |
| 14  | [The DOM](#14-the-dom)                                                        | Selecting, manipulating, traversing, forms, observers                 |
| 15  | [Events](#15-events)                                                          | Event model, bubbling, delegation, custom events                      |
| 16  | [Browser APIs](#16-browser-apis)                                              | Storage, History, Workers, IntersectionObserver, Canvas, and more     |
| 17  | [Functional Programming & Design Patterns](#17-functional-programming--design-patterns) | Pure functions, currying, composition, common patterns      |
| 18  | [Testing](#18-testing)                                                        | Unit, integration, e2e tests, mocking, TDD                            |
| 19  | [Performance & Memory](#19-performance--memory)                               | Rendering cost, memory leaks, debounce/throttle, profiling            |
| 20  | [Security](#20-security)                                                      | XSS, CSRF, CORS, CSP, secure auth, dependency safety                  |

> Suggested folder naming (same as the C roadmap): `01-introduction/`, `02-fundamentals-and-data-types/`, ... Each folder holds one `.md` per topic with short explanations and runnable JavaScript examples.

## 01. Introduction

- [x] What is JavaScript? (high-level, interpreted/JIT, dynamically typed, multi-paradigm)
- [x] History of JavaScript (Mocha → LiveScript → JavaScript, Netscape, Brendan Eich)
- [x] ECMAScript vs JavaScript (TC39, yearly releases, proposal stages)
- [x] Where JavaScript Runs (browser, Node.js, Deno, Bun, edge runtimes)
- [x] JavaScript Engines (V8, SpiderMonkey, JavaScriptCore) & JIT Compilation
- [x] How JS Runs in the Browser (parsing → AST → bytecode → optimized machine code)
- [x] Single-Threaded Model (overview of call stack, Web APIs, event loop)
- [x] `<script>` Loading (`defer`, `async`, `type="module"`, placement)
- [x] Comments, Statements, Semicolons & ASI (Automatic Semicolon Insertion)
- [x] Strict Mode (`"use strict"`) & What It Changes
- [x] `console` Methods (`log`, `error`, `warn`, `table`, `dir`, `group`, `time`, `assert`)
- [x] Browser DevTools Basics (Console, Sources, Network, Elements)

## 02. Fundamentals & Data Types

- [ ] Variables — `var`, `let`, `const` (scope, re-declaration, re-assignment)
- [ ] Naming Rules, Conventions & Reserved Words
- [ ] Primitive Data Types
  - [ ] `string`
  - [ ] `number` (floating point, `NaN`, `Infinity`, `Number.EPSILON`, safe integers)
  - [ ] `bigint`
  - [ ] `boolean`
  - [ ] `undefined`
  - [ ] `null`
  - [ ] `symbol`
- [ ] Non-Primitive (Reference) Types — Object, Array, Function, Date, RegExp, Map, Set
- [ ] `typeof` Operator & Its Quirks (`typeof null`, `typeof []`)
- [ ] Primitives vs References (copy by value vs by reference, stack vs heap)
- [ ] Immutability of Primitives & `const` with Objects
- [ ] Template Literals & Tagged Templates
- [ ] Type Conversion & Coercion
  - [ ] Implicit Coercion (`+`, `==`, boolean contexts)
  - [ ] Explicit Conversion (`Number()`, `String()`, `Boolean()`, `parseInt`, `parseFloat`)
  - [ ] Truthy & Falsy Values
  - [ ] Abstract Equality Algorithm (why `[] == ![]`)
- [ ] Equality — `==` vs `===` vs `Object.is()`
- [ ] Floating-Point Precision (`0.1 + 0.2`) & Working with Money
- [ ] `null` vs `undefined` vs Undeclared vs `NaN`
- [ ] User Input & Output (`prompt`, `alert`, `confirm`, DOM output, `readline` in Node)

## 03. Operators & Control Flow

- [ ] Arithmetic Operators (`+`, `-`, `*`, `/`, `%`, `**`, `++`, `--`)
- [ ] Assignment Operators (`=`, `+=`, `-=`, `**=`, `&&=`, `||=`, `??=`)
- [ ] Comparison Operators (`>`, `<`, `>=`, `<=`)
- [ ] Logical Operators (`&&`, `||`, `!`) & Short-Circuit Evaluation
- [ ] Nullish Coalescing (`??`) vs Logical OR (`||`)
- [ ] Optional Chaining (`?.`)
- [ ] Ternary Operator (`? :`)
- [ ] Bitwise Operators (`&`, `|`, `^`, `~`, `<<`, `>>`, `>>>`)
- [ ] Comma, `void`, `in`, `instanceof`, `delete`, `typeof` Operators
- [ ] Operator Precedence & Associativity
- [ ] `if` / `else if` / `else`
- [ ] `switch` Statement (fall-through, `break`, `default`, strict comparison)
- [ ] Loops
  - [ ] `for`
  - [ ] `while`
  - [ ] `do...while`
  - [ ] `for...in` (and why not for arrays)
  - [ ] `for...of`
- [ ] `break`, `continue` & Labeled Statements
- [ ] Infinite Loops & Loop Pitfalls (closures in loops with `var` vs `let`)
- [ ] Guard Clauses & Early Returns

## 04. Functions

- [ ] Function Declaration vs Function Expression
- [ ] Arrow Functions (syntax, implicit return, no own `this`/`arguments`)
- [ ] Parameters & Arguments (default values, rest `...args`)
- [ ] `arguments` Object
- [ ] Return Values & Implicit `undefined`
- [ ] First-Class Functions (functions as values)
- [ ] Higher-Order Functions
- [ ] Callback Functions
- [ ] IIFE (Immediately Invoked Function Expression)
- [ ] Pure vs Impure Functions & Side Effects
- [ ] Recursion (base case, call stack depth, memoization)
- [ ] Tail Calls & Stack Overflow
- [ ] Named Function Expressions
- [ ] Function Properties (`name`, `length`)
- [ ] Constructor Functions & `new.target`
- [ ] Generator Functions (intro — full coverage in Phase 10)
- [ ] `call()`, `apply()`, `bind()`
- [ ] Function Overloading Patterns (no native overloading in JS)

## 05. Execution Context, Scope & Closures

- [ ] Execution Context (Global, Function, Eval)
- [ ] Creation Phase vs Execution Phase
- [ ] Call Stack (push/pop, stack trace, stack overflow)
- [ ] Hoisting (`var`, function declarations, `let`/`const`, classes)
- [ ] Temporal Dead Zone (TDZ)
- [ ] Scope Types (global, function, block, module)
- [ ] Lexical Scope & Scope Chain
- [ ] Variable Shadowing & Illegal Shadowing
- [ ] Global Object (`window`, `globalThis`, `global`)
- [ ] Accidental Globals & Strict Mode
- [ ] Closures (definition, how they capture variables, lexical environment)
- [ ] Closure Use Cases (data privacy, factories, once, memoize, partial application)
- [ ] Closures in Loops (classic `var` bug)
- [ ] Closures & Memory (leaks, garbage collection)
- [ ] Module Pattern & Revealing Module Pattern

## 06. Objects & `this`

- [ ] Object Literals & Property Shorthand
- [ ] Computed Property Names
- [ ] Accessing Properties (dot vs bracket notation)
- [ ] Adding, Updating & Deleting Properties
- [ ] Methods & Method Shorthand
- [ ] Checking Properties (`in`, `hasOwn`, `hasOwnProperty`, optional chaining)
- [ ] Looping Over Objects (`Object.keys`, `values`, `entries`, `for...in`)
- [ ] Property Descriptors (`writable`, `enumerable`, `configurable`)
- [ ] `Object.defineProperty` / `defineProperties`
- [ ] Getters & Setters
- [ ] `Object.freeze`, `seal`, `preventExtensions`
- [ ] Copying Objects (reference copy, shallow copy, `structuredClone`, deep copy)
- [ ] Spread & Rest with Objects, `Object.assign`
- [ ] Object Destructuring (nested, defaults, renaming)
- [ ] `Object.fromEntries`, `Object.entries` Patterns
- [ ] Comparing Objects
- [ ] `this` Keyword
  - [ ] Global Binding
  - [ ] Implicit Binding (method call)
  - [ ] Explicit Binding (`call`, `apply`, `bind`)
  - [ ] `new` Binding
  - [ ] Arrow Function `this` (lexical)
  - [ ] Losing `this` (callbacks, event handlers, extracted methods)
  - [ ] `this` Binding Priority
- [ ] JSON (`JSON.stringify`, `JSON.parse`, replacer/reviver, `toJSON`, limitations)
- [ ] Optional Chaining & Nullish Patterns with Nested Data

## 07. Arrays & Iteration

- [ ] Creating Arrays (`[]`, `Array()`, `Array.of`, `Array.from`)
- [ ] Indexing, `length` & Sparse Arrays
- [ ] Mutating Methods (`push`, `pop`, `shift`, `unshift`, `splice`, `sort`, `reverse`, `fill`)
- [ ] Non-Mutating Methods (`slice`, `concat`, `flat`, `flatMap`, `at`, `join`)
- [ ] Immutable Updates (`toSorted`, `toReversed`, `toSpliced`, `with`)
- [ ] Searching (`indexOf`, `includes`, `find`, `findIndex`, `findLast`, `some`, `every`)
- [ ] Transformation (`map`, `filter`, `reduce`, `reduceRight`)
- [ ] `forEach` vs `for...of` vs `map` (when to use which)
- [ ] Sorting (default lexicographic sort, comparator functions, stability)
- [ ] Array Destructuring (skipping, defaults, swapping, rest)
- [ ] Spread Operator with Arrays
- [ ] Multi-Dimensional Arrays
- [ ] Array-Like Objects & Conversion
- [ ] Grouping (`Object.groupBy`, `Map.groupBy`)
- [ ] Typed Arrays & `ArrayBuffer` (overview)
- [ ] Iteration Protocols (iterable & iterator)
- [ ] Common Array Problems (remove duplicates, chunk, flatten, group, intersect)
- [ ] Big-O of Array Operations

## 08. Strings, Numbers, Math, Date & RegExp

- [ ] String Basics (immutability, UTF-16, escape sequences)
- [ ] String Methods (`slice`, `substring`, `split`, `replace`, `replaceAll`, `trim`, `padStart`, `at`, `includes`, `startsWith`)
- [ ] String Comparison & `localeCompare`
- [ ] Unicode, Emoji & Code Points (`codePointAt`, `normalize`)
- [ ] `Number` Methods (`toFixed`, `toPrecision`, `isInteger`, `isSafeInteger`, `parseFloat`)
- [ ] `BigInt` Operations
- [ ] `Math` Object (`round`, `floor`, `ceil`, `trunc`, `random`, `max`, `min`, `pow`, `hypot`)
- [ ] Random Numbers & Ranges
- [ ] `Date` Object (creating, getters/setters, timestamps, timezones)
- [ ] Date Pitfalls & Parsing
- [ ] `Intl` API (`DateTimeFormat`, `NumberFormat`, `RelativeTimeFormat`, `PluralRules`)
- [ ] Temporal API (modern date/time proposal)
- [ ] Regular Expressions
  - [ ] Literals & `RegExp` Constructor
  - [ ] Flags (`g`, `i`, `m`, `s`, `u`, `y`, `d`, `v`)
  - [ ] Character Classes, Quantifiers, Anchors
  - [ ] Groups, Named Groups & Backreferences
  - [ ] Lookahead & Lookbehind
  - [ ] `test`, `exec`, `match`, `matchAll`, `replace`
  - [ ] Greedy vs Lazy Matching & Catastrophic Backtracking

## 09. Prototypes & OOP

- [ ] Prototype & `__proto__` vs `prototype`
- [ ] Prototype Chain & Property Lookup
- [ ] `Object.create`, `Object.getPrototypeOf`, `Object.setPrototypeOf`
- [ ] Constructor Functions & `new` Keyword (what `new` actually does)
- [ ] Prototype Methods vs Instance Methods
- [ ] `instanceof` & `isPrototypeOf`
- [ ] ES6 Classes (syntax sugar over prototypes)
- [ ] `constructor`, Methods, Static Methods
- [ ] Getters & Setters in Classes
- [ ] Private Fields & Methods (`#private`)
- [ ] Static Blocks & Static Fields
- [ ] Inheritance (`extends`, `super`)
- [ ] Method Overriding
- [ ] Inheritance Pitfalls (Fragile Base Class)
- [ ] Composition over Inheritance
- [ ] Mixins
- [ ] Abstract-Class-Like Patterns (`new.target`)
- [ ] Polymorphism, Encapsulation, Abstraction in JS
- [ ] Extending Built-ins (`Array`, `Error`)
- [ ] `Symbol.toPrimitive`, `toString`, `valueOf`
- [ ] Factory Functions vs Classes

## 10. Modern JavaScript (ES6 → ES2025)

- [ ] `let` / `const` & Block Scope (recap)
- [ ] Destructuring, Spread & Rest (consolidated)
- [ ] Default Parameters & Enhanced Object Literals
- [ ] `Symbol` & Well-Known Symbols (`Symbol.iterator`, `Symbol.asyncIterator`)
- [ ] `Map` & `WeakMap`
- [ ] `Set` & `WeakSet`
- [ ] `WeakRef` & `FinalizationRegistry`
- [ ] Iterators & Iterables (custom iterators)
- [ ] Generators (`function*`, `yield`, `yield*`, two-way communication)
- [ ] Async Generators & `for await...of`
- [ ] Iterator Helpers (`map`, `filter`, `take` on iterators)
- [ ] `Proxy` & `Reflect` (traps, validation, reactivity basics)
- [ ] Tagged Templates (advanced)
- [ ] Optional Chaining, Nullish Coalescing, Logical Assignment
- [ ] `Array.prototype.at`, `Object.hasOwn`, `structuredClone`
- [ ] Top-Level `await`
- [ ] Class Fields, Private Methods, Static Blocks
- [ ] Set Methods (`union`, `intersection`, `difference`)
- [ ] `Promise.withResolvers`, `Promise.try`
- [ ] Decorators & Import Attributes (stage / support overview)
- [ ] Reading the ECMAScript Spec & Tracking TC39 Proposals
- [ ] Feature Detection, Polyfills & Browser Support (Can I Use, browserslist)

## 11. Asynchronous JavaScript

- [ ] Synchronous vs Asynchronous Code
- [ ] Blocking vs Non-Blocking
- [ ] Event Loop (call stack, Web APIs, task queue, microtask queue)
- [ ] Macrotasks vs Microtasks (`setTimeout` vs `Promise.then` order)
- [ ] `setTimeout`, `setInterval`, `requestAnimationFrame`, `queueMicrotask`
- [ ] Callbacks & Callback Hell
- [ ] Error-First Callbacks
- [ ] Promises (states, `then`, `catch`, `finally`, chaining)
- [ ] Creating Promises & Promisification
- [ ] Promise Combinators (`all`, `allSettled`, `race`, `any`)
- [ ] Error Propagation in Promise Chains
- [ ] `async` / `await` (syntax, return values, error handling)
- [ ] Sequential vs Parallel Execution with `await`
- [ ] `await` in Loops (`for...of` vs `forEach` pitfall)
- [ ] Fetch API (GET/POST, headers, JSON, status handling)
- [ ] `AbortController` & Cancellation
- [ ] Timeouts, Retries & Exponential Backoff
- [ ] Concurrency Control (limit parallel requests, queues)
- [ ] Race Conditions & Stale Responses
- [ ] Unhandled Promise Rejections
- [ ] Async Iteration & Streams (`ReadableStream`)
- [ ] XMLHttpRequest (legacy, for understanding)
- [ ] WebSockets & Server-Sent Events (overview)
- [ ] Web Workers for Parallelism (intro)

## 12. Error Handling & Debugging

- [ ] Error Types (`Error`, `TypeError`, `ReferenceError`, `SyntaxError`, `RangeError`)
- [ ] `try` / `catch` / `finally`
- [ ] `throw` & Throwing Non-Errors
- [ ] Custom Error Classes
- [ ] `Error.cause` & Error Chaining
- [ ] `AggregateError`
- [ ] Error Handling in Async Code
- [ ] Global Handlers (`window.onerror`, `unhandledrejection`, `process.on`)
- [ ] Defensive Programming & Input Validation
- [ ] Reading Stack Traces
- [ ] Breakpoints, `debugger`, Step Through, Watch & Call Stack Panel
- [ ] Network Panel & Performance Panel Basics
- [ ] Source Maps
- [ ] Logging Strategies & Structured Logs
- [ ] Common Bugs Catalogue (`this`, async order, mutation, off-by-one, coercion)

## 13. Modules & Tooling

- [ ] Why Modules? (global namespace pollution, IIFE era)
- [ ] CommonJS (`require`, `module.exports`)
- [ ] ES Modules (`import`, `export`, default vs named)
- [ ] Dynamic `import()` & Lazy Loading
- [ ] Module Resolution & Circular Dependencies
- [ ] ESM vs CommonJS Interop
- [ ] npm Basics (`init`, `install`, `scripts`, `package.json`, `package-lock.json`)
- [ ] Semantic Versioning & Dependency Types
- [ ] `npx`, pnpm, Yarn (differences)
- [ ] Bundlers (Vite, esbuild, Rollup, webpack — concepts)
- [ ] Tree Shaking & Code Splitting
- [ ] Transpilers (Babel, SWC) & TypeScript Awareness
- [ ] ESLint (rules, config, plugins)
- [ ] Project Structure & Naming Conventions
- [ ] Reading and Evaluating Third-Party Libraries

## 14. The DOM

- [ ] What is the DOM? (tree, nodes, `document`, `window`)
- [ ] Node Types (element, text, comment, document, fragment)
- [ ] Selecting Elements (`getElementById`, `querySelector`, `querySelectorAll`)
- [ ] Live vs Static Collections (`HTMLCollection` vs `NodeList`)
- [ ] Traversing the DOM (parent, children, siblings, `closest`)
- [ ] Creating & Inserting Elements (`createElement`, `append`, `prepend`, `before`, `after`)
- [ ] Removing & Replacing Nodes
- [ ] `innerHTML` vs `textContent` vs `innerText` (and security)
- [ ] Attributes vs Properties
- [ ] `classList`, `dataset` & Inline Styles
- [ ] Computed Styles (`getComputedStyle`)
- [ ] Element Dimensions & Positioning (`getBoundingClientRect`, `offsetWidth`, scroll APIs)
- [ ] `DocumentFragment` & Batch Updates
- [ ] Forms & Form Elements (`FormData`, validation API, `input`/`change`/`submit`)
- [ ] `<template>` Element & Cloning
- [ ] Reflow vs Repaint
- [ ] `MutationObserver`
- [ ] Shadow DOM & Custom Elements (Web Components)
- [ ] Page Lifecycle (`DOMContentLoaded`, `load`, `beforeunload`, `visibilitychange`)

## 15. Events

- [ ] Event Handling Approaches (inline, property, `addEventListener`)
- [ ] The Event Object (`target`, `currentTarget`, `type`, `key`, coordinates)
- [ ] Event Propagation — Capturing, Target, Bubbling
- [ ] `stopPropagation`, `stopImmediatePropagation`, `preventDefault`
- [ ] Event Delegation
- [ ] Listener Options (`once`, `capture`, `passive`, `signal`)
- [ ] Removing Listeners & Memory Leaks
- [ ] Mouse, Keyboard, Focus, Input & Touch Events
- [ ] Pointer Events & Drag and Drop
- [ ] Scroll & Resize Events
- [ ] Custom Events (`CustomEvent`, `dispatchEvent`)
- [ ] `EventTarget` & Building an Event Emitter
- [ ] Pub/Sub Pattern
- [ ] Accessibility & Keyboard Support

## 16. Browser APIs

- [ ] `window`, `location`, `navigator`, `screen` Objects
- [ ] `localStorage` & `sessionStorage`
- [ ] Cookies (attributes, `HttpOnly`, `Secure`, `SameSite`)
- [ ] IndexedDB
- [ ] Cache API & Service Workers
- [ ] Progressive Web Apps (manifest, offline, install)
- [ ] History API & Client-Side Routing
- [ ] URL & `URLSearchParams`
- [ ] Fetch, `Request`, `Response`, `Headers`
- [ ] Web Workers & `SharedWorker`
- [ ] `IntersectionObserver` (lazy loading, infinite scroll)
- [ ] `ResizeObserver` & `PerformanceObserver`
- [ ] Clipboard API
- [ ] File API, `Blob`, `FileReader`, File Uploads
- [ ] Drag & Drop File Upload
- [ ] Geolocation API
- [ ] Notifications & Push API
- [ ] Canvas API
- [ ] Web Audio, Media Devices (camera/mic)
- [ ] Web Animations API & `requestAnimationFrame` Loops
- [ ] BroadcastChannel & `postMessage`
- [ ] Web Crypto API
- [ ] Permissions API
- [ ] Intl & Internationalization Basics

## 17. Functional Programming & Design Patterns

- [ ] Functional Programming Principles (pure, immutable, declarative)
- [ ] Immutability Techniques (spread, `Object.freeze`, structural sharing)
- [ ] Currying & Partial Application
- [ ] Function Composition & Pipe
- [ ] Memoization
- [ ] Debounce & Throttle (implementation)
- [ ] Higher-Order Function Patterns
- [ ] Functors, Monads (`Maybe`, `Either`) — conceptual
- [ ] Creational Patterns (Singleton, Factory, Builder, Prototype)
- [ ] Structural Patterns (Module, Facade, Decorator, Adapter, Proxy)
- [ ] Behavioral Patterns (Observer, Strategy, Command, State, Iterator, Mediator)
- [ ] Dependency Injection
- [ ] MVC / MVVM / Flux Concepts
- [ ] State Management Concepts (store, reducer, immutable updates)
- [ ] SOLID Principles in JavaScript
- [ ] Clean Code (naming, small functions, DRY, KISS, YAGNI)
- [ ] Algorithms & Data Structures in JS (stack, queue, linked list, tree, graph, hash map, sorting, searching)

## 18. Testing

- [ ] Why Test? (testing pyramid)
- [ ] Unit Testing Basics (Arrange–Act–Assert)
- [ ] Jest / Vitest (setup, matchers, `describe`, `it`)
- [ ] Mocks, Stubs & Spies
- [ ] Testing Async Code
- [ ] Testing the DOM (Testing Library)
- [ ] Integration Testing
- [ ] End-to-End Testing (Playwright / Cypress)
- [ ] Code Coverage (and its limits)
- [ ] TDD Workflow (Red → Green → Refactor)
- [ ] Snapshot Testing (when to avoid)
- [ ] Testing in CI
- [ ] Linting, Type Checking (JSDoc / TypeScript) as Testing Layers

## 19. Performance & Memory

- [ ] Measuring First (`performance.now`, `console.time`, DevTools Performance panel)
- [ ] Core Web Vitals (LCP, INP, CLS)
- [ ] Big-O Notation & Algorithmic Efficiency
- [ ] Garbage Collection (mark-and-sweep, generations)
- [ ] Common Memory Leaks (listeners, timers, closures, detached DOM, globals)
- [ ] Heap Snapshots & Memory Profiling
- [ ] Debounce, Throttle, Memoization for Performance
- [ ] Minimizing Reflow/Repaint & Layout Thrashing
- [ ] Virtualization (long lists) & Pagination
- [ ] Lazy Loading (modules, images, routes)
- [ ] Code Splitting & Bundle Size Analysis
- [ ] Web Workers for Heavy Computation
- [ ] `requestIdleCallback` & Task Scheduling
- [ ] Caching Strategies (HTTP cache, Service Worker, in-memory)
- [ ] Network Optimization (compression, HTTP/2, preloading, CDN)
- [ ] Writing JIT-Friendly Code (stable shapes, avoid deopts)
- [ ] Performance Budgets & Monitoring

## 20. Security

- [ ] Cross-Site Scripting (XSS) — Stored, Reflected, DOM-based
- [ ] Output Encoding & Sanitization (DOMPurify, Trusted Types)
- [ ] Cross-Site Request Forgery (CSRF)
- [ ] CORS (preflight, headers, credentials)
- [ ] Content Security Policy (CSP)
- [ ] Same-Origin Policy
- [ ] Secure Cookies & Token Storage (JWT pitfalls, `HttpOnly`)
- [ ] Authentication vs Authorization (sessions, OAuth 2.0, OIDC overview)
- [ ] Input Validation (client and server) & Schema Validation (Zod / Joi)
- [ ] Prototype Pollution
- [ ] `eval`, `new Function` & Injection Risks
- [ ] ReDoS (regex denial of service)
- [ ] Dependency Security (`npm audit`, lockfiles, supply-chain attacks)
- [ ] Secrets Management (`.env`, never commit keys)
- [ ] HTTPS, HSTS & Secure Headers
- [ ] OWASP Top 10 Awareness

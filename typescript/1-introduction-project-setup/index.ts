/**
 * ==========================================================
 * WHAT IS TYPESCRIPT?
 * ==========================================================
 *
 * TypeScript is an open-source programming language developed
 * by Microsoft. It is a superset of JavaScript that adds
 * optional static typing and advanced language features such
 * as interfaces, generics, enums, and decorators.
 *
 * TypeScript code is compiled (transpiled) into plain
 * JavaScript, making it fully compatible with browsers,
 * Node.js, and existing JavaScript ecosystems.
 *
 * Main Benefit:
 * Catch errors during development instead of runtime.
 */

/**
 * ==========================================================
 * WHY USE TYPESCRIPT?
 * ==========================================================
 *
 * 1. Superior Tooling
 *    - IntelliSense
 *    - Autocompletion
 *    - Refactoring support
 *    - Better navigation in IDEs
 *
 * 2. Early Error Detection
 *    - Detects type-related issues before execution
 *
 * 3. Enhanced Code Quality
 *    - Predictable data structures
 *    - Safer refactoring
 *    - Reduced runtime bugs
 *
 * 4. Better Maintainability
 *    - Easier to understand
 *    - Easier to debug
 *    - Easier to extend
 *
 * 5. Improved Team Collaboration
 *    - Explicit contracts through types
 *    - Better communication between developers
 *
 * 6. Scalability
 *    - Suitable for large applications
 *    - Encourages modular architecture
 *
 * 7. Smart Type Inference
 *    - Less manual type annotation
 *    - Better developer experience
 *
 * 8. Framework Support
 *    - React
 *    - Next.js
 *    - Angular
 *    - NestJS
 *
 * 9. Strong Ecosystem
 *    - Large community
 *    - Active maintenance
 *    - Long-term reliability
 */

/**
 * ==========================================================
 * TYPESCRIPT VS JAVASCRIPT
 * ==========================================================
 *
 * JavaScript
 * ----------
 * - Dynamically Typed
 * - Errors occur at runtime
 * - Uses .js files
 * - No compilation required
 * - Suitable for small to medium projects
 *
 * TypeScript
 * ----------
 * - Statically Typed
 * - Errors detected during compilation
 * - Uses .ts / .tsx files
 * - Requires transpilation
 * - Ideal for large-scale applications
 */

/**
 * ==========================================================
 * HOW TYPESCRIPT WORKS?
 * ==========================================================
 *
 * TypeScript Compilation Pipeline
 *
 * TypeScript Source (.ts / .tsx)
 *            ↓
 *         Parsing
 *            ↓
 *         Binding
 *            ↓
 *      Type Checking
 *            ↓
 *   Emission / Transpilation
 *            ↓
 *    JavaScript Output (.js)
 *            ↓
 *      Browser / Node.js
 *
 * Stages:
 *
 * 1. Parsing
 *    - Converts source code into AST
 *
 * 2. Binding
 *    - Resolves identifiers, scopes, imports, exports
 *
 * 3. Type Checking
 *    - Validates types and catches errors
 *
 * 4. Emission
 *    - Removes TypeScript syntax
 *    - Generates JavaScript
 *
 * 5. Execution
 *    - JavaScript runs normally
 */

/**
 * ==========================================================
 * INSTALLATION & ENVIRONMENT SETUP
 * ==========================================================
 *
 * Requirements:
 * - Node.js
 * - npm
 * - TypeScript Compiler (tsc)
 *
 * Setup Flow:
 *
 * Install Node.js
 *       ↓
 * Install TypeScript
 *       ↓
 * Create Project
 *       ↓
 * Initialize tsconfig.json
 *       ↓
 * Write .ts Files
 *       ↓
 * Compile with tsc
 *       ↓
 * Run JavaScript Output
 */

/**
 * Install TypeScript Globally
 *
 * npm install -g typescript
 */

/**
 * Create Project
 *
 * mkdir ts-app
 * cd ts-app
 * npm init -y
 */

/**
 * Initialize TypeScript
 *
 * tsc --init
 */

/**
 * Essential Development Tools
 *
 * npm i -D typescript ts-node nodemon @types/node
 */

/**
 * Run TypeScript Directly
 *
 * npx ts-node src/index.ts
 */

/**
 * ==========================================================
 * TSCONFIG.JSON OVERVIEW
 * ==========================================================
 *
 * tsconfig.json is the configuration file for the
 * TypeScript compiler.
 *
 * Responsibilities:
 *
 * - Compiler behavior
 * - Type checking rules
 * - Output configuration
 * - Module system
 * - Project structure
 * - Build optimization
 */

/**
 * Common Compiler Options
 *
 * target
 * - Output JavaScript version
 *
 * module
 * - CommonJS
 * - ESNext
 * - NodeNext
 *
 * strict
 * - Enables strict type checking
 *
 * rootDir
 * - TypeScript source directory
 *
 * outDir
 * - Compiled JavaScript output directory
 *
 * esModuleInterop
 * - Improves compatibility with CommonJS packages
 *
 * skipLibCheck
 * - Skips declaration file checking
 */


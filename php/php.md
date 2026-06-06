# PHP Learning Checklist

## Phase 1 — Data Types & Variables

### Variables & Data Types

- [ ] Declare variables (`$name = "Ali"`)
- [ ] Understand String, Integer, Float, and Boolean types
- [ ] Learn about `NULL` and type casting
- [ ] Use `var_dump()` and `gettype()` to inspect variables

### String Operations

- [ ] Concatenate strings using the `.` operator
- [ ] Use `strlen()`, `strtolower()`, `strtoupper()`
- [ ] Use `str_replace()` and `substr()`
- [ ] Learn Heredoc and Nowdoc syntax

## Phase 2 — Operators & Control Flow

### Operators

- [ ] Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- [ ] Comparison operators: `==`, `===`, `!=`, `!==`
- [ ] Logical operators: `&&`, `||`, `!`
- [ ] Assignment operators: `=`, `+=`, `-=`

### Conditionals

- [ ] Write `if` / `else` / `elseif` statements
- [ ] Use `switch` / `case`
- [ ] Use the ternary operator `? :`
- [ ] Explore `match` expression (PHP 8+)

### Loops

- [ ] Use `while` and `do-while` loops
- [ ] Use `for` loops
- [ ] Use `foreach` loops (for arrays)
- [ ] Understand `break` and `continue`

## Phase 3 — Arrays & Functions

### Arrays

- [ ] Create and use indexed arrays
- [ ] Work with associative arrays (`key => value`)
- [ ] Understand multidimensional arrays
- [ ] Use `array_push()`, `array_pop()`, `array_merge()`
- [ ] Use `array_map()`, `array_filter()`, `array_search()`

### Functions

- [ ] Define and call functions
- [ ] Understand parameters and return values
- [ ] Use default parameter values
- [ ] Understand variable scope: global vs local
- [ ] Write anonymous functions and arrow functions

## Phase 4 — Form Handling & HTTP

### GET & POST

- [ ] Build an HTML form
- [ ] Understand `$_GET` and `$_POST` superglobals
- [ ] Perform basic form validation
- [ ] Prevent XSS attacks using `htmlspecialchars()`

### Superglobals

- [ ] Use `$_SERVER` to get request info
- [ ] Start and manage sessions with `$_SESSION`
- [ ] Work with cookies using `$_COOKIE`
- [ ] Handle file uploads using `$_FILES`

## Phase 5 — File Operations & Database

### File Operations

- [ ] Use `fopen()`, `fread()`, `fwrite()`, `fclose()`
- [ ] Use `file_get_contents()` and `file_put_contents()`
- [ ] Check file existence with `file_exists()` and `is_dir()`
- [ ] Create and delete directories

### MySQL Database (PDO)

- [ ] Connect to a MySQL database using PDO
- [ ] Perform CRUD: SELECT, INSERT, UPDATE, DELETE
- [ ] Use prepared statements to prevent SQL injection
- [ ] Handle database errors with `try-catch`

## Phase 6 — Error Handling & Modern PHP

### Error Handling

- [ ] Use `try` / `catch` / `finally`
- [ ] Create custom Exception classes
- [ ] Configure `error_reporting` and `ini_set`
- [ ] Log errors using `error_log()`

### Modern PHP (PHP 8+)

- [ ] Use named arguments
- [ ] Use the null coalescing operator `??`
- [ ] Use `match` expressions
- [ ] Learn about Fibers and Enums
- [ ] Install and use Composer for dependency management
- [ ] Understand PSR-4 autoloading

# 📑 C Programming — Complete Roadmap & Checklist

| # | Topics | Overview |
|---|--------|----------|
| 01 | [Introduction & Environment Setup](#01-introduction--environment-setup) | What is C, history, compilation pipeline, toolchain setup |
| 02 | [Fundamentals & Data Types](#02-fundamentals--data-types) | Variables, constants, keywords, data types, I/O, operators |
| 03 | [Control Flow & Decision Making](#03-control-flow--decision-making) | Conditionals, loops, branching, and program flow |
| 04 | [Functions & Program Structure](#04-functions--program-structure) | Functions, scope, storage classes, recursion, header files |
| 05 | [Arrays & Strings](#05-arrays--strings) | 1D/2D arrays, character arrays, string functions |
| 06 | [Pointers & Memory Management](#06-pointers--memory-management) | Pointer basics, arithmetic, dynamic memory, memory errors |
| 07 | [Structures, Unions & Enums](#07-structures-unions--enums) | User-defined types, bit-fields, alignment |
| 08 | [File I/O & The Preprocessor](#08-file-io--the-preprocessor) | File handling, macros, header guards, command-line args |
| 09 | [Advanced Concepts](#09-advanced-concepts) | Bitwise ops, error handling, advanced pointers, concurrency |
| 10 | [Data Structures in C](#10-data-structures-in-c) | Linked lists, stacks, queues, trees, hash tables from scratch |
| 11 | [Professional Tooling & Best Practices](#11-professional-tooling--best-practices) | GDB, Valgrind, Makefiles, secure coding, C standards |
| 12 | [Mini Projects & Practice](#12-mini-projects--practice) | Hands-on projects to consolidate all concepts |


## 01. Introduction & Environment Setup

- [ ] What is C?
- [ ] History of C Language (K&R C, ANSI C, C99, C11, C17, C23)
- [ ] Why Learn C? (Use cases: OS, embedded systems, performance-critical apps)
- [ ] C vs C++ vs Other Languages (key differences)
- [ ] Structure of a C Program (`#include`, `main()`, statements, blocks)
- [ ] Installation & Compiler Setup (GCC, Clang, MSVC)
- [ ] IDE & Editor Setup (VS Code, CLion, Vim/Neovim)
- [ ] GCC Compiler Basics (`gcc`, `clang` commands)
- [ ] Compilation Pipeline (Preprocessing → Compiling → Assembling → Linking)
- [ ] Compilation Flags (`-o`, `-Wall`, `-Wextra`, `-pedantic`, `-std=c99`, `-g`, `-O2`)
- [ ] Understanding Object Files & Executables (`.o`, `.out`, `.exe`)
- [ ] The Role of the Linker & Standard Library (`libc`)
- [ ] Using `make` for simple builds

## 02. Fundamentals & Data Types

- [ ] Keywords & Identifiers (reserved words, naming rules)
- [ ] Variables — Declaration, Initialization, Assignment
- [ ] Constants (`const`, `#define` literals)
- [ ] Primitive Data Types (`int`, `char`, `float`, `double`, `void`)
- [ ] Type Modifiers (`signed`, `unsigned`, `short`, `long`, `long long`)
- [ ] `_Bool` / `stdbool.h` (`true`, `false`)
- [ ] Size of Types (`sizeof` operator, platform differences)
- [ ] Fixed-Width Integer Types (`<stdint.h>`: `int8_t`, `uint32_t`, `int64_t`, etc.)
- [ ] Limits of Types (`<limits.h>`, `<float.h>`)
- [ ] Escape Sequences (`\n`, `\t`, `\\`, `\"`, `\0`, `\xNN`, `\oNNN`)
- [ ] Character Literals and ASCII Table
- [ ] Format Specifiers (`%d`, `%f`, `%c`, `%s`, `%p`, `%x`, `%u`, `%ld`, etc.)
- [ ] Standard Input / Output (`printf`, `scanf`, `getchar`, `putchar`, `gets` dangers)
- [ ] `<stdio.h>` Overview
- [ ] Operators in C
  - [ ] Arithmetic Operators (`+`, `-`, `*`, `/`, `%`)
  - [ ] Relational Operators (`==`, `!=`, `<`, `>`, `<=`, `>=`)
  - [ ] Logical Operators (`&&`, `||`, `!`)
  - [ ] Bitwise Operators (`&`, `|`, `^`, `~`, `<<`, `>>`)
  - [ ] Assignment Operators (`=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`)
  - [ ] Increment & Decrement (`++`, `--`, prefix vs postfix)
  - [ ] Ternary / Conditional Operator (`? :`)
  - [ ] `sizeof` Operator
  - [ ] Comma Operator
  - [ ] Operator Precedence & Associativity
- [ ] Implicit Type Conversion (Integer Promotion, Usual Arithmetic Conversions)
- [ ] Explicit Type Casting (`(type)expression`)
- [ ] Integer Overflow & Undefined Behavior


## 03. Control Flow & Decision Making

- [ ] `if` Statement
- [ ] `if...else` Statement
- [ ] `else if` Ladder
- [ ] Nested `if` Statements
- [ ] `switch` Statement (fall-through, `break`, `default`)
- [ ] `switch` with Ranges (GCC extension)
- [ ] `for` Loop (initialization, condition, update)
- [ ] `while` Loop
- [ ] `do...while` Loop
- [ ] Nested Loops
- [ ] `break` Statement
- [ ] `continue` Statement
- [ ] `goto` Statement (and why to avoid it)
- [ ] Infinite Loops & Loop Control Patterns
- [ ] Short-Circuit Evaluation (`&&`, `||`)


## 04. Functions & Program Structure

- [ ] Function Basics (definition, call, return)
- [ ] Function Declaration vs. Definition (Prototypes)
- [ ] Return Types (`int`, `void`, `float`, pointers, etc.)
- [ ] Function Arguments — Pass by Value
- [ ] Pass by Reference via Pointers
- [ ] Default Arguments (not in C — how to work around)
- [ ] Variadic Functions (`stdarg.h`, `va_list`, `va_start`, `va_arg`, `va_end`)
- [ ] `main()` Signatures (`int main(void)` vs `int main(int argc, char *argv[])`)
- [ ] Variable Scope (Local, Global, Block Scope)
- [ ] Shadowing Variables
- [ ] Storage Classes
  - [ ] `auto` (default for local variables)
  - [ ] `register` (hint to compiler)
  - [ ] `static` (persists across calls; file-local linkage)
  - [ ] `extern` (shared across translation units)
- [ ] Inline Functions (`inline` keyword, `static inline`)
- [ ] Recursion — Basics & Call Stack
- [ ] Tail Recursion & Optimization
- [ ] Mutual Recursion
- [ ] Header Files (`.h`) — Purpose & Structure
- [ ] Separating Interface (`.h`) from Implementation (`.c`)
- [ ] Multiple Source File Projects
- [ ] Translation Units & Linkage (internal vs external)

## 05. Arrays & Strings

- [ ] One-Dimensional Arrays — Declaration, Initialization, Access
- [ ] Array Bounds and Undefined Behavior (out-of-bounds access)
- [ ] Iterating Arrays (loops, pointer-style)
- [ ] Multi-Dimensional Arrays (2D, 3D)
- [ ] Arrays as Function Arguments (decay to pointer)
- [ ] Variable-Length Arrays — VLA (`int arr[n]`, C99+)
- [ ] Character Arrays & C-Strings (`char[]`, null terminator `\0`)
- [ ] String Literals (read-only, stored in `.rodata`)
- [ ] String I/O (`scanf("%s")`, `fgets`, `puts`, `fputs`)
- [ ] `<string.h>` Functions
  - [ ] `strlen` — string length
  - [ ] `strcpy` / `strncpy` — copy
  - [ ] `strcat` / `strncat` — concatenate
  - [ ] `strcmp` / `strncmp` — compare
  - [ ] `strchr` / `strrchr` — find character
  - [ ] `strstr` — find substring
  - [ ] `strtok` — tokenize
  - [ ] `memcpy` / `memmove` / `memset` / `memcmp`
- [ ] String-to-Number Conversions (`atoi`, `atof`, `strtol`, `strtod`)
- [ ] `sprintf` / `snprintf` for string formatting

## 06. Pointers & Memory Management

- [ ] What is a Pointer? (memory address concept)
- [ ] Pointer Declaration & Initialization (`int *p = &x;`)
- [ ] Address-of Operator (`&`) and Dereference Operator (`*`)
- [ ] `NULL` Pointer and its importance
- [ ] Pointer to Different Types (`int*`, `char*`, `float*`, `void*`)
- [ ] `void*` — Generic Pointer
- [ ] Pointer Arithmetic (`p++`, `p--`, `p+n`, `p-q`)
- [ ] Relationship Between Arrays and Pointers
- [ ] Pointer vs Array (similarities and key differences)
- [ ] Pointers and Strings (`char *str = "hello"` vs `char str[] = "hello"`)
- [ ] Pointers to Pointers (`**`, `***`)
- [ ] Pointer to Pointer for 2D Arrays
- [ ] `const` and Pointers (`const int*`, `int* const`, `const int* const`)
- [ ] Pointers as Function Parameters (modifying caller's data)
- [ ] Returning Pointers from Functions (stack vs heap safety)
- [ ] Function Pointers — Declaration & Calling
- [ ] Function Pointer Arrays
- [ ] Callbacks using Function Pointers
- [ ] Dynamic Memory Allocation
  - [ ] `malloc` — allocate uninitialized memory
  - [ ] `calloc` — allocate zero-initialized memory
  - [ ] `realloc` — resize allocation
  - [ ] `free` — release memory
  - [ ] Checking `malloc` return value (never assume success)
- [ ] Memory Layout of a C Program (Stack, Heap, BSS, Data, Text segments)
- [ ] Stack vs Heap (lifetime, size, usage)
- [ ] Common Memory Errors
  - [ ] Memory Leaks
  - [ ] Dangling Pointers
  - [ ] Double Free
  - [ ] Buffer Overflow / Overread
  - [ ] Use-After-Free
  - [ ] Stack Overflow (deep recursion)
- [ ] Pointer Aliasing & `restrict` Keyword

## 07. Structures, Unions & Enums

- [ ] `struct` — Definition & Declaration
- [ ] `struct` Initialization (designated initializers, C99+)
- [ ] Accessing Members (`.` operator)
- [ ] Nested Structures
- [ ] Array of Structures
- [ ] Pointers to Structures (`->` operator)
- [ ] Passing Structs to Functions (by value vs by pointer)
- [ ] Returning Structs from Functions
- [ ] Self-Referential Structs (for linked lists, trees)
- [ ] `union` — Definition & Memory Overlap
- [ ] `union` Use Cases (type punning, memory-efficient storage)
- [ ] Anonymous Unions & Structs (C11+)
- [ ] `enum` — Enumeration for Named Constants
- [ ] `enum` with Explicit Values
- [ ] `typedef` — Creating Type Aliases
- [ ] `typedef` with Structs, Unions, Enums, Function Pointers
- [ ] Struct Padding & Alignment (`__attribute__((packed))`, `#pragma pack`)
- [ ] `alignof` and `alignas` (C11+)
- [ ] Bit-fields inside Structs
- [ ] Flexible Array Members (C99+)

## 08. File I/O & The Preprocessor

### File Handling
- [ ] File Handling Basics — the `FILE*` type
- [ ] Opening & Closing Files (`fopen`, `fclose`)
- [ ] File Modes (`"r"`, `"w"`, `"a"`, `"r+"`, `"w+"`, `"a+"`, `"b"` suffix)
- [ ] Text vs Binary File Operations
- [ ] Reading Files (`fgetc`, `fgets`, `fscanf`, `fread`)
- [ ] Writing Files (`fputc`, `fputs`, `fprintf`, `fwrite`)
- [ ] File Position (`fseek`, `ftell`, `rewind`, `fgetpos`, `fsetpos`)
- [ ] End-of-File Detection (`feof`, `EOF`)
- [ ] Error Checking (`ferror`, `clearerr`, `perror`, `strerror`)
- [ ] Formatted I/O (`fprintf`, `fscanf`, `sprintf`, `snprintf`, `sscanf`)
- [ ] Temporary Files (`tmpfile`, `tmpnam`)
- [ ] Renaming & Deleting Files (`rename`, `remove`)

### The C Preprocessor
- [ ] `#include` — File Inclusion (`<>` vs `""`)
- [ ] `#define` — Object-like Macros (constants)
- [ ] `#define` — Function-like Macros
- [ ] Macro Pitfalls (operator precedence, side effects — always use parentheses)
- [ ] `#undef` — Undefining Macros
- [ ] Header Guards (`#ifndef`, `#define`, `#endif`)
- [ ] `#pragma once` (non-standard but widely supported)
- [ ] Conditional Compilation (`#if`, `#ifdef`, `#ifndef`, `#elif`, `#else`, `#endif`)
- [ ] Predefined Macros (`__FILE__`, `__LINE__`, `__DATE__`, `__TIME__`, `__func__`)
- [ ] Stringification (`#`) and Token Pasting (`##`)
- [ ] Variadic Macros (`__VA_ARGS__`, C99+)
- [ ] `_Static_assert` / `static_assert` (C11+)
- [ ] `#line` Directive
- [ ] `#error` and `#warning` Directives

### Command-Line Arguments
- [ ] `int main(int argc, char *argv[])`
- [ ] Parsing Arguments Manually
- [ ] Using `getopt` / `getopt_long` (POSIX)

## 09. Advanced Concepts

### Bitwise Operations & Bit Manipulation
- [ ] Bitwise AND, OR, XOR, NOT, Left/Right Shift
- [ ] Setting, Clearing, Toggling, Checking a Bit
- [ ] Bit Masks and Flags
- [ ] Signed vs Unsigned Shift Behavior
- [ ] Practical Uses (permissions, packed data, hardware registers)

### Error Handling
- [ ] `errno` and `<errno.h>`
- [ ] `perror` and `strerror`
- [ ] Return-Code Conventions (returning `-1`, `NULL`, `0`)
- [ ] `setjmp` / `longjmp` — Non-Local Jumps (`<setjmp.h>`)

### Advanced Pointer Concepts
- [ ] Pointer to Array (`int (*p)[N]`)
- [ ] Array of Pointers (`int *p[N]`)
- [ ] Multi-Level Pointer Dereferencing
- [ ] `void*` Casting and Generic Containers
- [ ] `intptr_t` / `uintptr_t` (pointer-sized integers)
- [ ] `ptrdiff_t` and pointer subtraction
- [ ] Opaque Pointers (forward declarations, information hiding)

### Type System & Expressions
- [ ] Integer Promotion Rules
- [ ] Usual Arithmetic Conversions
- [ ] Sequence Points & Undefined Behavior
- [ ] Lvalues and Rvalues
- [ ] Compound Literals (C99+)
- [ ] Designated Initializers for Structs & Arrays (C99+)
- [ ] `_Generic` — Type-Generic Macros (C11+)

### Standard Library Deep Dive
- [ ] `<stdlib.h>` — `abs`, `div`, `rand`, `srand`, `exit`, `atexit`, `qsort`, `bsearch`
- [ ] `<math.h>` — `sqrt`, `pow`, `sin`, `cos`, `ceil`, `floor`, `fabs`, `log`, `exp`
- [ ] `<time.h>` — `time`, `clock`, `difftime`, `mktime`, `strftime`, `struct tm`
- [ ] `<ctype.h>` — `isalpha`, `isdigit`, `isspace`, `toupper`, `tolower`
- [ ] `<assert.h>` — `assert` macro for debugging
- [ ] `<stdarg.h>` — Variadic function support
- [ ] `<complex.h>` — Complex number support (C99+)
- [ ] `<tgmath.h>` — Type-generic math (C99+)
- [ ] `<stdalign.h>`, `<stdnoreturn.h>` (C11+)
- [ ] `<threads.h>` — C11 threads (overview)

### Signals & Process Control
- [ ] Signal Handling (`signal`, `raise`, `<signal.h>`)
- [ ] Common Signals (`SIGINT`, `SIGSEGV`, `SIGTERM`, `SIGFPE`)
- [ ] `exit`, `_Exit`, `atexit`, `abort`

### Concurrency (C11 & POSIX)
- [ ] Overview of Concurrency in C
- [ ] C11 Threads (`<threads.h>`) — `thrd_create`, `thrd_join`
- [ ] Mutexes (`mtx_t`, `mtx_lock`, `mtx_unlock`)
- [ ] Condition Variables (`cnd_t`)
- [ ] Atomic Operations (`<stdatomic.h>`, `_Atomic`, C11+)
- [ ] POSIX Threads (`pthreads`) — Overview

### Undefined Behavior & Platform Portability
- [ ] What is Undefined Behavior (UB)?
- [ ] Common Sources of UB (signed overflow, null deref, strict aliasing)
- [ ] Strict Aliasing Rule
- [ ] `volatile` Keyword (memory-mapped I/O, signal handlers)
- [ ] Endianness (big-endian vs little-endian, byte swapping)
- [ ] Platform-Specific Sizes and `<stdint.h>` best practices

## 10. Data Structures in C

- [ ] Dynamic Array (resizable array with `realloc`)
- [ ] Singly Linked List (create, insert, delete, search, free)
- [ ] Doubly Linked List
- [ ] Circular Linked List
- [ ] Stack (array-based and linked-list-based)
- [ ] Queue (array-based and linked-list-based)
- [ ] Deque (Double-Ended Queue)
- [ ] Binary Tree (insert, traverse: inorder, preorder, postorder)
- [ ] Binary Search Tree (BST) — search, insert, delete
- [ ] Heap / Priority Queue (min-heap, max-heap)
- [ ] Hash Table (separate chaining, open addressing)
- [ ] Graph Representation (adjacency matrix, adjacency list)
- [ ] Graph Traversal (BFS, DFS) in C
- [ ] Implementing `qsort` and `bsearch` with custom comparators
- [ ] Generic Containers using `void*` and function pointers

## 11. Professional Tooling & Best Practices

### Modular Code & Build Systems
- [ ] Writing Modular Code (`.c` implementation + `.h` interface)
- [ ] Forward Declarations & Dependency Management
- [ ] Writing Basic Makefiles (`CC`, `CFLAGS`, `all`, `clean`, pattern rules)
- [ ] Introduction to `CMakeLists.txt` and CMake
- [ ] pkg-config for external libraries
- [ ] Version Control with Git (basic workflow for C projects)

### Debugging
- [ ] Debugging with GDB — launching, breakpoints, stepping (`next`, `step`)
- [ ] GDB — Inspecting Variables, Call Stack, Registers
- [ ] GDB — Watchpoints, Conditional Breakpoints
- [ ] LLDB Basics (macOS alternative)
- [ ] Core Dumps (generating and analyzing with GDB)
- [ ] `printf` Debugging Patterns (flushing with `fflush`)

### Memory Debugging & Analysis
- [ ] Valgrind — `memcheck` tool (leaks, invalid reads/writes)
- [ ] Valgrind — `callgrind` for profiling
- [ ] AddressSanitizer (`-fsanitize=address`)
- [ ] UndefinedBehaviorSanitizer (`-fsanitize=undefined`)
- [ ] ThreadSanitizer (`-fsanitize=thread`)
- [ ] Static Analysis Tools (`clang-tidy`, `cppcheck`, `splint`)

### Secure Coding Practices
- [ ] Never use `gets()` — use `fgets()` instead
- [ ] Use `strncpy`, `strncat` over unsafe variants
- [ ] Always check return values of `malloc`, `fopen`, etc.
- [ ] Preventing Buffer Overflows
- [ ] Integer Overflow Checks
- [ ] Format String Vulnerabilities (never use user input as format string)
- [ ] CERT C Coding Standard overview

### C Standards
- [ ] C89/C90 — ANSI C, original standard
- [ ] C99 — VLAs, `//` comments, `<stdint.h>`, `<stdbool.h>`, designated initializers
- [ ] C11 — `_Generic`, `_Static_assert`, atomics, threads, anonymous structs
- [ ] C17 (C18) — Bug-fix release, no new features
- [ ] C23 — `#embed`, `nullptr`, `typeof`, attributes, `bool`/`true`/`false` as keywords

### Code Quality
- [ ] Consistent Coding Style (K&R, Allman, Google C Style Guide)
- [ ] Using `clang-format` for auto-formatting
- [ ] Writing Meaningful Comments and Documentation
- [ ] `assert()` for Defensive Programming
- [ ] Writing Unit Tests in C (using frameworks like `Unity`, `CUnit`, or hand-rolled)

## 12. Mini Projects & Practice

- [ ] **Calculator** — arithmetic parser with operator precedence
- [ ] **Student Record System** — structs, file I/O, CRUD operations
- [ ] **Library Management System** — dynamic array or linked list + file persistence
- [ ] **Custom `malloc`** — implement a simple memory allocator
- [ ] **Shell / Command Interpreter** — `fork`, `exec`, `wait` (POSIX)
- [ ] **Text File Word Counter** — file I/O, string tokenization, hash table
- [ ] **Matrix Operations Library** — 2D arrays, dynamic allocation, functions
- [ ] **Sorting Algorithm Visualizer** — implement bubble, selection, insertion, merge, quick sort
- [ ] **Binary Search Tree Library** — full BST with insert, delete, search, traversals
- [ ] **Simple HTTP Server** (sockets, `<sys/socket.h>`) — advanced project
- [ ] **Implement a Mini `printf`** — `va_list`, format parsing
- [ ] **Tic-Tac-Toe Game** — 2D arrays, functions, game loop
- [ ] **CSV Parser** — file I/O, string parsing, dynamic memory
- [ ] **Blockchain Concept Demo** — structs, hashing (`<openssl/sha.h>` or custom)

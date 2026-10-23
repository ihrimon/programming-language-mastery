# Strict Mode (`"use strict"`)

## 🤔 এটা আসলে কী জিনিস?

Strict Mode হলো JavaScript এর একটা কঠোর সংস্করণ, ES5 (2009) এ এসেছে। চালু করলে আগে যে ভুলগুলো চুপচাপ উপেক্ষা হতো, সেগুলো এখন **error** দেয়।

চালু করার উপায়:

```js
"use strict"; // ফাইলের একদম প্রথম statement হিসেবে

function f() {
  "use strict"; // অথবা শুধু একটা function এর ভেতরে
}
```

## 🎯 এটা না থাকলে কী সমস্যা হতো?

ডিফল্ট ("sloppy") mode এ অনেক ভুল চুপচাপ পার হয়ে যায়, আর bug খুঁজে বের করা কঠিন হয়:

- `userNmae = "Rimon"` লিখলে (বানান ভুল) নতুন global variable তৈরি হয়ে যায়।
- Read-only property তে লিখলে কিছুই ঘটে না, কিন্তু মান বদলায়ও না।
- Function এর ভেতরে `this` চুপচাপ `window` হয়ে যায়।

Strict mode এই ভুলগুলোকে স্পষ্ট error বানিয়ে ধরিয়ে দেয়।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

Strict mode চালু থাকলে engine এর আচরণ বদলায়:

| বিষয় | Sloppy mode | Strict mode |
|-------|-------------|-------------|
| Declare না করা variable এ মান দেওয়া | নতুন global তৈরি | `ReferenceError` |
| Plain function call এ `this` | global object | `undefined` |
| Read-only property তে লেখা | নীরবে ব্যর্থ | `TypeError` |
| Function এ একই নামের দুই parameter | চলে | `SyntaxError` |
| `delete` দিয়ে variable মোছা | নীরবে ব্যর্থ | `SyntaxError` |
| `with` statement | চলে | `SyntaxError` |
| পুরনো octal `010` | `8` | `SyntaxError` |
| Reserved word (`let`, `static`...) নাম হিসেবে | চলে | `SyntaxError` |

**স্বয়ংক্রিয়ভাবে strict:**

- ES Module (`import` / `export` ওয়ালা ফাইল)
- `class` এর ভেতরের কোড

## 💻 কোডে দেখলে কেমন?

```js
"use strict";

// ১. বানান ভুলে নতুন global আর তৈরি হয় না
let userName = "Rimon";
try {
  userNmae = "Karim"; // বানান ভুল
} catch (e) {
  console.log(e.name); // "ReferenceError"
}

// ২. this হয় undefined
function show() {
  return this;
}
console.log(show()); // undefined (sloppy mode এ window/global)

// ৩. Read-only property
const user = Object.freeze({ name: "Rimon" });
try {
  user.name = "Karim";
} catch (e) {
  console.log(e.name); // "TypeError"
}
```

`"use strict"` সরিয়ে ফেললে ১, ২, ৩ এর কোনোটাতেই error আসবে না, বরং ভুল চুপচাপ লুকিয়ে থাকবে।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- আধুনিক project এ আলাদা করে লিখতে হয় না, ES Module আর class এ স্বয়ংক্রিয়ভাবে চালু।
- TypeScript compile করার সময় `alwaysStrict` দিয়ে আউটপুটে `"use strict"` বসানো যায়।
- ESLint এর `strict` নিয়ম এটা যাচাই করে।

**Production এ:**

- পুরনো CommonJS বা script ফাইলে এখনো `"use strict"` লাগে।
- Strict mode এ engine অনেক সময় বেশি ভালো optimize করতে পারে।
- নীরব ব্যর্থতা কম হওয়ায় production bug কমে।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- `"use strict"` ফাইল বা function এর **প্রথম statement** হতে হবে (শুধু comment এর আগে থাকতে পারে)।
- Module আর class এ আলাদা করে লেখা লাগে না।
- Strict mode চালু থাকলে function এ `this` `undefined`।

**যে ভুল সাধারণত হয়:**

- **ফাইলের মাঝখানে `"use strict"` লেখা।** কাজ করে না, সাধারণ string হিসেবে উপেক্ষিত হয়।
- **পুরনো library মিলিয়ে একটা বড় ফাইলে ব্যবহার করা।** Concatenate করলে strict-মুক্ত কোড ভেঙে যেতে পারে। তাই function-level এ দেওয়া হয়েছিল।
- **Strict mode এর আচরণ জেনেও `this` নিয়ে ভুল ধারণা রাখা।** `const f = obj.method; f()` এ `this` হারিয়ে যায় (Phase 06)।

**Edge case:**

- Function এর parameter default, rest বা destructuring থাকলে সেই function এর ভেতরে `"use strict"` directive লেখা যায় না (SyntaxError)।
- Strict mode শুধু যে scope এ লেখা হয়েছে সেখানেই কাজ করে, অন্য ফাইলে নয়।
- `eval` এর ভেতরে declare করা variable বাইরে ছড়ায় না।

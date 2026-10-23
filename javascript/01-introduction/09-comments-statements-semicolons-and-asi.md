# Comment, Statement, Semicolon ও ASI

## 🤔 এটা আসলে কী জিনিস?

- **Comment:** কোডের মধ্যে মানুষের জন্য নোট, engine এটা উপেক্ষা করে।
- **Statement:** একটা সম্পূর্ণ নির্দেশ, যেমন `let x = 5;`। একটা প্রোগ্রাম হলো statement এর তালিকা।
- **Semicolon (`;`):** statement শেষ বোঝানোর চিহ্ন।
- **ASI (Automatic Semicolon Insertion):** আপনি semicolon না দিলে engine নিজে কিছু জায়গায় বসিয়ে নেয়।

```js
// এক লাইনের comment

/* অনেক লাইনের
   comment */

/** JSDoc: function এর বিবরণ */
```

## 🎯 এটা না থাকলে কী সমস্যা হতো?

ASI না থাকলে প্রতিটা লাইনের শেষে semicolon বাধ্যতামূলক হতো, ভুলে গেলে `SyntaxError`। ASI এই সুবিধা দেয়, কিন্তু একটা মূল্যে: **engine সবসময় আপনার মনের মতো সিদ্ধান্ত নেয় না**। তাই ASI এর নিয়ম জানা না থাকলে অদ্ভুত bug আসে।

Comment না থাকলে কোডের "কেন" ব্যাখ্যা করার জায়গা থাকত না। কোড বলে "কী", comment বলে "কেন"।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

ASI এর মূল নিয়ম: parser একটা token পেল যা বৈধ নয়, আর তার আগে newline আছে, তখন সেখানে `;` বসায়। তাছাড়া `}` এর আগে এবং ফাইলের শেষে বসায়।

কিন্তু যদি পরের লাইন মিলিয়ে পড়লেও বৈধ কোড হয়, তখন `;` বসায় **না**। এখানেই বিপদ।

তিনটা বিখ্যাত ফাঁদ:

1. **`return` এর পরে newline:** `return` এর পরেই `;` বসে যায়।
2. **লাইন `(`, `[`, `` ` `` দিয়ে শুরু হলে:** আগের লাইনের সাথে জুড়ে যায়।
3. **`++` / `--` পরের লাইনে:** পরের statement এর সাথে বাঁধা পড়ে।

## 💻 কোডে দেখলে কেমন?

```js
// ফাঁদ ১: return এর পরে newline
function getUser() {
  return
  {
    name: "Rimon",
  };
}
console.log(getUser()); // undefined  ← engine লেখে: return; { ... }

// ঠিক করার উপায়: return এর সাথে একই লাইনে শুরু
function getUserFixed() {
  return {
    name: "Rimon",
  };
}
```

```js
// ফাঁদ ২: ( দিয়ে শুরু হওয়া লাইন
const a = 1
const b = a
(function () {
  console.log("hi")
})()
// TypeError: a is not a function
// engine পড়ে: const b = a(function(){...})()
```

```js
// ঠিক করার উপায়: semicolon দিন
const a = 1;
const b = a;
(function () {
  console.log("hi");
})();
```

Comment এর ভালো ও খারাপ ব্যবহার:

```js
// ❌ খারাপ: কোড যা বলছে তাই বলছে
// i এর মান ১ বাড়াও
i++;

// ✅ ভালো: কেন করছি তা বলছে
// API rate limit এড়াতে প্রতিবার ১ সেকেন্ড অপেক্ষা
await delay(1000);
```

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- Prettier ও ESLint এর `semi` নিয়ম দিয়ে পুরো টিমে একই স্টাইল রাখা হয়।
- JSDoc comment (`/** ... */`) দিলে VS Code এ function এর hover info ও auto-complete পাওয়া যায়।
- `TODO`, `FIXME` comment দিয়ে কাজ চিহ্নিত করা হয়।

**Production এ:**

- Build এর সময় minifier (Terser) comment সরিয়ে ফেলে ও লাইন জুড়ে দেয়। তখন ASI এ নির্ভর করা কোড ভাঙতে পারে।
- Commented-out পুরনো কোড repository তে রাখা ঠিক নয়, Git আছে ইতিহাসের জন্য।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- Semicolon দেওয়াই নিরাপদ, ASI এর উপর ভরসা না করা।
- যদি semicolon না দেন (standard style), তাহলে `(`, `[`, `` ` `` দিয়ে শুরু হওয়া লাইনের আগে সতর্ক থাকুন।
- `return`, `break`, `continue`, `throw` এর পরে newline দেবেন না।
- Comment এ "কেন" লিখুন, "কী" নয়।

**যে ভুল সাধারণত হয়:**

- **`return` এর পরের লাইনে object/value শুরু করা।** `undefined` ফেরত আসে, কোনো error ছাড়াই।
- **Semicolon ছাড়া IIFE বা array literal দিয়ে লাইন শুরু করা।** আগের লাইনের সাথে জুড়ে যায়।
- **পুরনো কোড comment করে রেখে দেওয়া।** কোড নোংরা হয়, ভ্রান্তি বাড়ে।

**Edge case:**

- `for (;;)` এর ভেতরের semicolon গুলোতে ASI কাজ করে না।
- `//` comment এ `\u000A` জাতীয় line terminator থাকলে comment সেখানেই শেষ হয়।
- Hashbang comment `#!/usr/bin/env node` ফাইলের একদম প্রথম লাইনে বৈধ। CLI script এ দরকার হয়।

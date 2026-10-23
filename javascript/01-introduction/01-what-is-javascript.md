# JavaScript কী?

## 🤔 এটা আসলে কী জিনিস?

JavaScript একটা **programming language**। এই ভাষায় লেখা কোড browser বা Node.js এর মতো কোনো পরিবেশে চলে এবং সেখানে কাজ ঘটায়।

ভাষাটার বৈশিষ্ট্য:

- **High-level:** memory সরাসরি সামলাতে হয় না, engine নিজে করে দেয়।
- **Dynamically typed:** variable এর type আগে থেকে ঠিক করতে হয় না, চলার সময় নির্ধারিত হয়।
- **Multi-paradigm:** procedural, object-oriented এবং functional, তিন ধরনের স্টাইলেই লেখা যায়।
- **Single-threaded:** একটা সময়ে একটাই কাজ চালায়। তবুও event loop এর কারণে async কাজ সামলাতে পারে।
- **Standardized:** ভাষার নিয়ম ঠিক করে **ECMAScript** (ECMA-262), JavaScript হলো তার বাস্তবায়ন।

## 🎯 এটা না থাকলে কী সমস্যা হতো?

শুরুর দিকে ওয়েবপেজ ছিল শুধু HTML আর CSS। মানে একটা স্থির ছবির মতো: লেখা দেখা যায়, কিন্তু ক্লিক করলে কিছু ঘটে না।

JavaScript না থাকলে:

- ফর্ম জমা দেওয়ার আগে ভুল ধরা যেত না, প্রতিবার সার্ভারে গিয়ে ফিরে আসতে হতো।
- পেজ রিলোড না করে নতুন ডেটা আনা যেত না (Facebook এর feed, Gmail এর inbox)।
- বাটনে ক্লিক, মেনু খোলা, slider, dark mode, কোনোটাই সম্ভব হতো না।

JavaScript পেজকে **আচরণ** দিয়েছে। HTML হলো কাঠামো, CSS হলো সাজ, আর JS হলো সেই কাঠামো ও সাজের উপর কাজ।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

```
আমার লেখা JS কোড
      ↓
JavaScript Engine (V8, SpiderMonkey, JavaScriptCore)
      ↓  parse → bytecode → machine code
CPU তে চলে
      ↓
Host environment এর API ব্যবহার করে কাজ ঘটায়
  • Browser: DOM, fetch, localStorage, setTimeout
  • Node.js: fs, http, process
```

একটা জিনিস গুলিয়ে ফেলবেন না:

- **ভাষা** (variable, function, object, loop) আসে JavaScript থেকে।
- **DOM, fetch, setTimeout** ভাষার অংশ নয়। এগুলো browser দেয় এবং আমাদের JS তাদের ডাকে।

তাই একই ভাষা browser এ DOM ধরতে পারে, আর Node.js এ ফাইল পড়তে পারে। ভাষা এক, পরিবেশ আলাদা।

## 💻 কোডে দেখলে কেমন?

```js
// ১. ভাষার নিজের জিনিস: variable, function, logic
const price = 100;
const quantity = 3;

function total(p, q) {
  return p * q;
}

console.log(total(price, quantity)); // 300

// ২. Dynamic typing: একই variable এ ভিন্ন type, চলার সময় ঠিক হয়
let value = 10;
console.log(typeof value); // "number"
value = "ten";
console.log(typeof value); // "string"

// ৩. Browser এর API (ভাষার অংশ নয়, browser দেয়)
// document.querySelector("button").addEventListener("click", () => {
//   console.log("ক্লিক হয়েছে");
// });
```

প্রথম দুই ভাগ browser আর Node.js, দুই জায়গাতেই চলবে। তৃতীয় ভাগ শুধু browser এ চলবে, কারণ `document` Node.js এ নেই।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- Frontend: React, Vue, Angular সবই JavaScript এর উপর দাঁড়িয়ে।
- Backend: Node.js, Express দিয়ে API বানানো।
- Tooling: build tool, linter, test runner (Vite, ESLint, Jest) সবই JS এ লেখা।

**Production এ:**

- User এর browser এ JS চলে, তাই JS এর আকার ও গতি সরাসরি page speed ঠিক করে।
- Error হলে user এর স্ক্রিন সাদা হয়ে যেতে পারে, তাই error handling জরুরি।
- User এর browser আমাদের নিয়ন্ত্রণে নেই, তাই client-side কোড কখনো সম্পূর্ণ বিশ্বাস করা যায় না (security)।

একই ভাষায় frontend আর backend লেখা যায়, এটাই এর সবচেয়ে বড় ব্যবহারিক সুবিধা।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- JavaScript আর ECMAScript এক জিনিস নয়। ECMAScript হলো স্পেসিফিকেশন, JavaScript তার বাস্তবায়ন।
- ভাষা আর পরিবেশ আলাদা: `document`, `window`, `fetch`, `setTimeout` ভাষার অংশ নয়, host environment এর API।
- JavaScript শুধু browser এর ভাষা নয়, Node.js, Deno, Bun এও চলে।

**যে ভুল সাধারণত হয়:**

- **Java আর JavaScript গুলিয়ে ফেলা।** দুটো সম্পূর্ণ আলাদা ভাষা। নামটা শুধু মার্কেটিংয়ের ফল।
- **"Single-threaded মানে async কাজ করতে পারে না" ভাবা।** পারে। event loop আর browser/Node এর API এর সাহায্যে করে। বিস্তারিত Phase 11 এ।
- **Dynamic typing কে সুবিধা ভেবে type নিয়ে অসতর্ক হওয়া।** `"5" + 1` আর `"5" - 1` এর ফল আলাদা। বড় প্রজেক্টে এটাই bug এর বড় উৎস। বিস্তারিত Phase 02 এ।

**Edge case:**

- `typeof null` এর ফল `"object"`, এটা ভাষার প্রথম সংস্করণের পুরনো bug, এখনো রয়ে গেছে।
- JavaScript কে শুধু "interpreted" বলা অসম্পূর্ণ। আধুনিক engine এ JIT compilation হয়। দেখুন `05-javascript-engines-and-jit.md`।

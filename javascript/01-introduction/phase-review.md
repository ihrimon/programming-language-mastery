# Phase 01 — Introduction: Review

## 📌 সারাংশ

### যে ৩টা মূল জিনিস মাথায় রাখব

1. **ভাষা আর পরিবেশ আলাদা।** ECMAScript হলো নিয়ম, engine তা চালায়, আর `document`, `fetch`, `setTimeout`, `console` আসে host environment থেকে। এটাই Phase 01 এর সবচেয়ে বড় ধারণা।
2. **JS একটাই thread এ চলে, তবু async কাজ করে।** Call stack, Web API, queue আর event loop মিলে কাজটা করে। Microtask (Promise) সবসময় task (`setTimeout`) এর আগে চলে।
3. **কোড কখন ও কীভাবে লোড হয় তা ফলাফল বদলে দেয়।** `<script>` এর ধরন (`defer` / `async` / `module`), strict mode আর ASI, তিনটাই "কোড ঠিক, কিন্তু আচরণ ভুল" ধরনের bug এর উৎস।

### আমার অস্পষ্ট জিনিস (পড়ার পর নিজে পূরণ করব)

- [ ]
- [ ]

> অস্পষ্ট জিনিস সমাধান হলে এখানে টিক দেব, নইলে Phase 02 শুরুর আগে আবার দেখব।

### টপিক ম্যাপ

| ফাইল | এক লাইনে মূল কথা |
|------|------------------|
| 01 What is JavaScript | High-level, dynamically typed, multi-paradigm, single-threaded |
| 02 History | 1995 Netscape → 1997 ECMAScript → 2009 Node.js → 2015 ES6 |
| 03 ECMAScript vs JS | Spec বনাম বাস্তবায়ন, TC39 stage 0–4, বার্ষিক release |
| 04 Where JS Runs | Runtime = engine + host API |
| 05 Engines & JIT | Interpreter + JIT, hot code optimize, type বদলালে deopt |
| 06 Browser flow | HTML parse → script blocking → DOM → render, সব main thread এ |
| 07 Single-threaded | Stack, Web API, microtask, task, event loop |
| 08 Script loading | default / `defer` / `async` / `module` |
| 09 Comments & ASI | Semicolon ঐচ্ছিক নয়, `return` newline ফাঁদ |
| 10 Strict mode | নীরব ভুল এখন error |
| 11 console | `table`, `group`, `time`, `assert`, object এর live reference |
| 12 DevTools | Elements, Console, Sources, Network, `debugger` |

---

## 🎯 Interview Questions

### Q1. JavaScript কি compiled নাকি interpreted ভাষা?

**সংক্ষিপ্ত উত্তর (৩০ সেকেন্ড):** দুটোই বলা যায়। আধুনিক engine প্রথমে কোডকে bytecode এ রূপান্তর করে interpreter দিয়ে চালায়। যে কোড বারবার চলে (hot), তাকে JIT compiler দিয়ে optimized machine code এ compile করে।

**বিস্তারিত:**
- V8 এ পথটা এমন: Parser → AST → Ignition (interpreter, bytecode) → TurboFan (optimizing compiler) → machine code।
- Engine চলার সময় type সম্পর্কে অনুমান করে optimize করে।
- অনুমান ভুল হলে (যেমন number এর জায়গায় string এল) **deoptimization** হয়ে bytecode এ ফিরে যায়।
- তাই শুধু "interpreted" বলা অসম্পূর্ণ।

**সম্ভাব্য Follow-up:** JIT কী? Deoptimization কখন হয়? Hot code কীভাবে চেনে?

> ⚠️ **ফাঁদ:** সোজা "interpreted" বা "compiled" বলে থেমে যাবেন না, JIT এর কথা বলুন।

---

### Q2. JavaScript আর ECMAScript এর পার্থক্য কী?

**সংক্ষিপ্ত উত্তর:** ECMAScript হলো ভাষার স্পেসিফিকেশন (ECMA-262), JavaScript হলো তার বাস্তবায়ন যা engine গুলো চালায়।

**বিস্তারিত:**
- ECMAScript শুধু ভাষার মূল অংশ ঠিক করে: syntax, `Array`, `Promise`, `Map`, class ইত্যাদি।
- `document`, `fetch`, `setTimeout`, `console` ECMAScript এ নেই, এগুলো browser বা Node দেয়।
- নিয়ম ঠিক করে **TC39** কমিটি। প্রতি বছর জুনে নতুন সংস্করণ বের হয়।
- ES6 = ES2015।

**সম্ভাব্য Follow-up:** TC39 proposal এর stage গুলো কী? `fetch` ECMAScript এর অংশ কিনা?

---

### Q3. Java আর JavaScript কি একই?

**সংক্ষিপ্ত উত্তর:** না। দুটো সম্পূর্ণ আলাদা ভাষা। নামের মিল শুধু মার্কেটিংয়ের ফল।

**বিস্তারিত:** JS এর আগের নাম ছিল Mocha, তারপর LiveScript। Java তখন জনপ্রিয় ছিল বলে Netscape নাম বদলে JavaScript রাখে। Java হলো class-based, statically typed, JVM এ চলে। JS dynamically typed, prototype-based।

**সম্ভাব্য Follow-up:** JS কে কে বানিয়েছে? কত দিনে?

---

### Q4. JavaScript single-threaded হলে async কাজ কীভাবে করে?

**সংক্ষিপ্ত উত্তর:** JS নিজে একবারে একটাই কাজ চালায়। Timer, network ইত্যাদি async কাজ runtime (browser/Node) করে দেয়। কাজ শেষ হলে callback queue তে জমা হয়, আর **event loop** stack খালি হলে সেটা stack এ তুলে আনে।

**বিস্তারিত:**
- অংশ: Call Stack, Web APIs, Microtask Queue, Task Queue, Event Loop।
- Event loop নিয়ম: stack খালি না হলে কিছু তোলে না। আর microtask queue পুরো খালি করে তারপর পরের task এ যায়।
- Browser নিজে multi-threaded (network, rendering আলাদা thread), শুধু JS execution single thread এ।

**সম্ভাব্য Follow-up:** Microtask আর task এর পার্থক্য? Web Worker কী?

---

### Q5. এই কোডের আউটপুট কী হবে?

```js
console.log("1");
setTimeout(() => console.log("2"), 0);
Promise.resolve().then(() => console.log("3"));
console.log("4");
```

**সংক্ষিপ্ত উত্তর:** `1, 4, 3, 2`

**বিস্তারিত:**
1. `1` আর `4` synchronous, সরাসরি stack এ চলে।
2. `setTimeout` এর callback task queue এ যায় (delay 0 হলেও)।
3. Promise এর callback microtask queue এ যায়।
4. Stack খালি হলে microtask আগে চলে (`3`), তারপর task (`2`)।

**সম্ভাব্য Follow-up:** `await` এর পরের কোড কোন queue তে যায়? Microtask এর ভেতর আবার microtask ঢোকালে কী হয়? (উত্তর: সব microtask শেষ না হওয়া পর্যন্ত task চলে না, তাই এটা অনন্ত লুপে UI আটকাতে পারে)

---

### Q6. `setTimeout(fn, 0)` কি সাথে সাথে চলে?

**সংক্ষিপ্ত উত্তর:** না। এর মানে "অন্তত এই সময় পরে, stack খালি হলে যত তাড়াতাড়ি সম্ভব"।

**বিস্তারিত:** Callback task queue এ যায়। Stack ব্যস্ত থাকলে বা microtask থাকলে সেগুলো আগে শেষ হয়। তাছাড়া browser এ nested timer এর সর্বনিম্ন সময় কিছুটা থাকতে পারে।

**সম্ভাব্য Follow-up:** `setTimeout` JS এর অংশ কিনা? (না, host API)

---

### Q7. `defer` আর `async` এর পার্থক্য কী?

**সংক্ষিপ্ত উত্তর:** দুটোতেই script সমান্তরালে ডাউনলোড হয়, HTML parsing আটকায় না। পার্থক্য execute হওয়ার সময়ে: `defer` HTML পার্স শেষে লেখার ক্রমে চলে, `async` ডাউনলোড শেষ হওয়া মাত্র চলে, ক্রম নিশ্চিত নয়।

**বিস্তারিত:**
- নিজের অ্যাপের কোডে `defer` (বা `type="module"`)।
- Analytics, ads এর মতো স্বাধীন তৃতীয় পক্ষের কোডে `async`।
- ডিফল্ট `<script>` HTML parsing আটকে দেয়।
- `type="module"` ডিফল্টে `defer` এর মতো, নিজস্ব scope, স্বয়ংক্রিয় strict mode।

**সম্ভাব্য Follow-up:** `<head>` এ ডিফল্ট script রাখলে `getElementById` `null` দেয় কেন? পরস্পর নির্ভরশীল script এ `async` কেন বিপজ্জনক?

---

### Q8. Strict mode কী এবং কী বদলায়?

**সংক্ষিপ্ত উত্তর:** Strict mode (`"use strict"`) ভাষার একটা কঠোর সংস্করণ, যেখানে আগে নীরবে উপেক্ষা হওয়া ভুলগুলো error দেয়।

**বিস্তারিত (উদাহরণ):**
- Declare না করা variable এ মান দিলে `ReferenceError` (আগে নতুন global হতো)।
- Plain function call এ `this` হয় `undefined` (আগে global object)।
- Read-only property তে লিখলে `TypeError`।
- একই নামের দুই parameter, `with`, পুরনো octal, `SyntaxError`।
- ES Module আর class এর ভেতরে স্বয়ংক্রিয়ভাবে চালু।

**সম্ভাব্য Follow-up:** ফাইলের মাঝখানে `"use strict"` লিখলে কী হয়? (কাজ করে না, শুধু string)। Default parameter ওয়ালা function এ কেন লেখা যায় না?

---

### Q9. ASI (Automatic Semicolon Insertion) কী? কখন সমস্যা করে?

**সংক্ষিপ্ত উত্তর:** Semicolon না দিলে engine নির্দিষ্ট নিয়মে নিজে বসিয়ে নেয়। কিন্তু সব সময় আপনার ইচ্ছামতো নয়।

**বিস্তারিত (তিনটা ফাঁদ):**
1. `return` এর পরে newline: `return` এর পরেই `;` বসে, ফলে `undefined` ফেরত আসে।
2. লাইন `(`, `[`, `` ` `` দিয়ে শুরু হলে আগের লাইনের সাথে জুড়ে যায়।
3. `++` / `--` পরের লাইনে থাকলে পরের statement এর সাথে বাঁধা পড়ে।

**উদাহরণ:**
```js
function f() {
  return
  { a: 1 };
}
f(); // undefined
```

**সম্ভাব্য Follow-up:** Semicolon দেওয়া উচিত কেন? Minifier এ কী ঘটে?

---

### Q10. `typeof null` কী দেয় এবং কেন?

**সংক্ষিপ্ত উত্তর:** `"object"`। এটা ভাষার প্রথম সংস্করণের একটা bug।

**বিস্তারিত:** Backward compatibility ভাঙবে বলে এটা কখনো ঠিক করা হয়নি। `null` সত্যিকারের object নয়। নিরাপদভাবে যাচাই করতে `value === null` ব্যবহার করুন।

**সম্ভাব্য Follow-up:** Array এর `typeof` কী? Array কীভাবে চেনা যায়? (`Array.isArray`) *(বিস্তারিত Phase 02 এ)*

---

### Q11. JavaScript কোথায় কোথায় চলে? Node.js আর browser এর পার্থক্য কী?

**সংক্ষিপ্ত উত্তর:** Browser, Node.js, Deno, Bun, edge runtime, Electron, React Native এ। ভাষা একই, কিন্তু **host API আলাদা**।

**বিস্তারিত:**
- Browser এ `window`, `document`, DOM। Node এ `fs`, `http`, `process`।
- Global object আলাদা (`window` / `global`), সব জায়গায় নিরাপদ নাম `globalThis`।
- Node আর Deno দুটোই V8 ব্যবহার করে, কিন্তু API আলাদা।

**সম্ভাব্য Follow-up:** SSR এ `window is not defined` কেন আসে? Edge runtime এর সীমাবদ্ধতা কী?

---

### Q12. JS Engine কী? V8 কীভাবে কাজ করে?

**সংক্ষিপ্ত উত্তর:** Engine হলো সেই প্রোগ্রাম যা JS পড়ে machine code এ রূপান্তর করে চালায়। V8 (Chrome, Node), SpiderMonkey (Firefox), JavaScriptCore (Safari)।

**বিস্তারিত:** Parse করে AST বানায়, Ignition bytecode চালায়, hot function কে TurboFan optimize করে। এছাড়া **garbage collection** করে যাতে অব্যবহৃত memory মুক্ত হয়।

**সম্ভাব্য Follow-up:** Garbage collection কীভাবে কাজ করে? Memory leak কী?

---

### Q13. "JavaScript একটা dynamically typed ভাষা", এর মানে কী?

**সংক্ষিপ্ত উত্তর:** Variable এর type আগে থেকে ঘোষণা করতে হয় না। Type মানের সাথে যুক্ত, আর তা চলার সময় নির্ধারিত হয়।

**বিস্তারিত:** একই variable এ আগে number, পরে string রাখা যায়। সুবিধা: নমনীয়তা। অসুবিধা: type সংক্রান্ত ভুল চলার সময় ধরা পড়ে (`"5" + 1` বনাম `"5" - 1`)। তাই বড় project এ TypeScript ব্যবহার হয়।

**সম্ভাব্য Follow-up:** Dynamic typing আর weak typing কি একই? (না) *(বিস্তারিত Phase 02 এ)*

---

### Q14. `console.log(obj)` করার পর `obj` বদলালে DevTools এ কী দেখায়?

**সংক্ষিপ্ত উত্তর:** Browser এ object log করলে রেফারেন্স দেখায়, তাই ভাঁজ খুললে log এর মুহূর্তের মান নয়, **এখনকার** মান দেখাতে পারে।

**বিস্তারিত:** Snapshot চাইলে `console.log(JSON.parse(JSON.stringify(obj)))` বা `structuredClone(obj)` ব্যবহার করুন। তাছাড়া `console.assert` শর্ত মিথ্যা হলে তবেই ছাপে।

**সম্ভাব্য Follow-up:** Production এ `console.log` সম্পর্কে সতর্কতা কী?

---

## ⚠️ এই Phase এর Top সতর্কতা

| # | সতর্কতা | কোন ফাইল |
|---|---------|----------|
| 1 | `fetch`, `document`, `setTimeout`, `console` ভাষার অংশ নয়, host API | 03, 04, 11 |
| 2 | "JS interpreted" বলা অসম্পূর্ণ, JIT ও আছে | 05 |
| 3 | `<head>` এ ডিফল্ট script রেখে DOM খুঁজলে `null` | 06, 08 |
| 4 | ভারী synchronous কাজ main thread আটকে পেজ জমিয়ে দেয় | 06, 07 |
| 5 | Promise (microtask) সবসময় `setTimeout` (task) এর আগে | 07 |
| 6 | পরস্পর নির্ভরশীল script এ `async` নয়, `defer` | 08 |
| 7 | `return` এর পরে newline দেবেন না, লাইন `(` / `[` দিয়ে শুরু করার আগে semicolon | 09 |
| 8 | `"use strict"` ফাইলের প্রথম statement হতে হবে, module ও class এ আলাদা লাগে না | 10 |
| 9 | Production এ `console.log` রাখবেন না, token বা ব্যক্তিগত তথ্য log করবেন না | 11 |
| 10 | API সমস্যায় আগে Network ট্যাব দেখুন, তারপর কোড | 12 |

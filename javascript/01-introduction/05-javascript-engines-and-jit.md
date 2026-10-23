# JavaScript Engine ও JIT Compilation

## 🤔 এটা আসলে কী জিনিস?

**JavaScript Engine** হলো সেই প্রোগ্রাম যা আমাদের লেখা JS কোড পড়ে CPU এর বোঝার মতো করে চালায়।

| Engine | কোথায় |
|--------|-------|
| **V8** | Chrome, Edge, Node.js, Deno |
| **SpiderMonkey** | Firefox |
| **JavaScriptCore** | Safari, Bun |

**JIT (Just-In-Time) Compilation** মানে কোড চলার সময়ই তাকে machine code এ রূপান্তর করে দ্রুত করা।

## 🎯 এটা না থাকলে কী সমস্যা হতো?

CPU শুধু machine code বোঝে, JS বোঝে না। দুটো সরল উপায় আছে, কিন্তু দুটোতেই সমস্যা:

- **শুধু interpret করলে** (লাইন ধরে ধরে চালালে): শুরু দ্রুত, কিন্তু চলা ধীর।
- **আগেভাগে পুরোটা compile করলে**: চলা দ্রুত, কিন্তু শুরু ধীর। তাছাড়া JS এর type চলার সময় বদলায়, তাই আগে থেকে সবকিছু optimize করা কঠিন।

JIT এই দুটোর মাঝামাঝি: আগে দ্রুত শুরু করে, তারপর যে কোড বারবার চলে তাকে optimize করে।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে? (V8 এর সরলীকৃত ছবি)

```
Source code
   ↓ Parser
AST (Abstract Syntax Tree)
   ↓ Ignition (interpreter)
Bytecode  ──→ চলতে শুরু করে
   ↓ (profiling: কোন function "hot"?)
TurboFan (optimizing compiler)
   ↓
Optimized machine code
   ↓ (অনুমান ভুল হলে)
Deoptimization → Bytecode এ ফেরত
```

- Engine চলার সময় লক্ষ্য রাখে কোন function বারবার চলছে (**hot**) এবং কোন type এর data আসছে।
- Hot function কে অনুমানের ভিত্তিতে optimize করে। যেমন: "এই `add(a, b)` সবসময় number পায়।"
- হঠাৎ string এলে অনুমান ভেঙে যায়, তখন **deoptimization** হয় (ধীর)।

আরেকটা কাজ: **garbage collection**। যে memory আর কেউ ব্যবহার করছে না, engine নিজে তা মুক্ত করে।

## 💻 কোডে দেখলে কেমন?

```js
function add(a, b) {
  return a + b;
}

// V8 দেখে: সবসময় number, তাই দ্রুত number-add code বানায়
for (let i = 0; i < 1_000_000; i++) {
  add(i, 1);
}

// এখন অনুমান ভাঙল: deoptimization হতে পারে
console.log(add("a", "b")); // "ab"
```

ফল সবসময় ঠিক থাকে। শুধু type বদলালে engine কে আবার অনুমান বদলাতে হয়, ফলে সামান্য ধীর হয়।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- Chrome DevTools এর Performance tab এ দেখা যায় কোন function সময় নিচ্ছে।
- নিজের পরিবেশে (Node বনাম browser) কোন engine, সেটা জানা থাকলে আচরণের পার্থক্য বোঝা সহজ।

**Production এ:**

- Hot path (loop, ঘন ঘন call হওয়া function) এ type স্থির রাখলে performance ভালো থাকে।
- "JS ধীর" ধারণাটা পুরনো। Modern engine এ JIT এর কারণে numeric কাজ অনেক দ্রুত।
- Memory leak ও GC pause বড় web app এর বাস্তব সমস্যা।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- JS = interpreter + JIT compiler, শুধু "interpreted" বলা অসম্পূর্ণ।
- ভাষা আর engine আলাদা: নিয়ম ECMAScript এর, সেগুলো চালায় engine।
- Optimize করার আগে **মাপুন** (DevTools), তারপর বদলান।

**যে ভুল সাধারণত হয়:**

- **আগেভাগে micro-optimize করা।** বেশিরভাগ ক্ষেত্রে engine নিজেই ভালো করে।
- **Hot code এ একই variable এ কখনো number কখনো string রাখা।** Optimization নষ্ট হয়।
- **Micro-benchmark এর ফল সরাসরি বিশ্বাস করা।** Engine warm-up এর আগে আর পরে আলাদা আচরণ করে।

**Edge case:**

- Object এ property পরে যোগ বা মুছলে (shape বদলালে) optimization নষ্ট হতে পারে।
- একই function কে ভিন্ন type দিয়ে ডাকলে (polymorphic) ধীর হতে পারে।

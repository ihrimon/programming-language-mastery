# `console` Methods

## 🤔 এটা আসলে কী জিনিস?

`console` হলো একটা built-in object, যা দিয়ে কোড চলার সময় তথ্য দেখা যায়। Browser এর DevTools Console এবং Node এর terminal, দুই জায়গাতেই কাজ করে।

(মনে রাখুন: `console` ECMAScript এর অংশ নয়, এটা host environment এর API।)

| Method | কাজ |
|--------|-----|
| `log` / `info` | সাধারণ আউটপুট |
| `warn` | সতর্কবার্তা (হলুদ) |
| `error` | ত্রুটি (লাল), Node এ stderr এ যায় |
| `table` | array/object টেবিল আকারে |
| `dir` | object এর পুরো গঠন |
| `group` / `groupEnd` | আউটপুট ভাঁজ করা গ্রুপে |
| `time` / `timeEnd` | সময় মাপা |
| `assert` | শর্ত **মিথ্যা** হলে তবেই বার্তা |
| `count` | কতবার ডাকা হয়েছে |
| `trace` | কোথা থেকে ডাকা হয়েছে (stack trace) |

## 🎯 এটা না থাকলে কী সমস্যা হতো?

কোড চলার সময় ভেতরে কী ঘটছে দেখার উপায় থাকত না। তখন পুরো কাজ অনুমানের ওপর নির্ভর করত। `alert()` ব্যবহার করলে পেজ আটকে যায়, আর DOM এ লিখলে ঝামেলা। `console` বিনা বাধায় তথ্য দেখায়।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

- `console.log` host environment এর কাছে বার্তা পাঠায়, সেটা DevTools বা terminal এ দেখায়।
- Method গুলোর **স্তর (level)** আছে (log, info, warn, error)। DevTools এ স্তর অনুযায়ী ফিল্টার করা যায়।
- `console.log("%s is %d", "Rimon", 25)` এর মতো format specifier কাজ করে: `%s` string, `%d` সংখ্যা, `%o` object, `%c` CSS স্টাইল।
- Browser এ object log করলে সেটা **রেফারেন্স** দেখায়। আপনি পরে খুললে তখনকার মান দেখাবে, log করার মুহূর্তের নয়।

## 💻 কোডে দেখলে কেমন?

```js
console.log("সাধারণ", 42, { a: 1 });
console.warn("সতর্কতা");
console.error("ত্রুটি");

// table: array of object এর জন্য দারুণ
console.table([
  { name: "Rimon", age: 25 },
  { name: "Karim", age: 30 },
]);

// group
console.group("User লোড");
console.log("API ডাকা হচ্ছে");
console.log("ডেটা এসেছে");
console.groupEnd();

// সময় মাপা: label দুই জায়গায় একই হতে হবে
console.time("loop");
for (let i = 0; i < 1e6; i++) {}
console.timeEnd("loop"); // loop: 2.1ms

// assert: শর্ত মিথ্যা হলে তবেই ছাপে
console.assert(1 === 2, "এই বার্তা দেখা যাবে");
console.assert(1 === 1, "এটা দেখা যাবে না");

// count
console.count("click"); // click: 1
console.count("click"); // click: 2

// ক্রমে ক্রমে বদলানো object এর ফাঁদ
const obj = { count: 1 };
console.log(obj);
obj.count = 2;
// DevTools এ ভাঁজ খুললে count: 2 দেখাতে পারে
console.log(JSON.parse(JSON.stringify(obj))); // snapshot পেতে এটা করুন
```

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- দ্রুত debug: ভ্যারিয়েবলের মান দেখা (`console.log`)।
- API থেকে আসা তালিকা দেখতে `console.table`।
- Performance এর প্রাথমিক ধারণা পেতে `console.time`।
- কোন function কোথা থেকে ডাকা হয়েছে জানতে `console.trace`।

**Production এ:**

- ছাড়ার আগে `console.log` সরানো হয় (build tool বা ESLint `no-console` নিয়ম)।
- **কখনো পাসওয়ার্ড, token, ব্যক্তিগত তথ্য log করবেন না।** Browser এ যে কেউ DevTools খুলে দেখতে পারে।
- Server এ সঠিক logger (pino, winston) ব্যবহার হয়, `console.log` নয়। কারণ log level, ফাইল, পরিদর্শন দরকার।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- `console.assert` শর্ত **ভুল** হলে ছাপে, ঠিক হলে চুপ।
- `time` ও `timeEnd` এ **একই label** দিতে হবে।
- `console.error` Node এ stderr এ যায়, `log` stdout এ। পাইপ করার সময় এই পার্থক্য কাজে লাগে।

**যে ভুল সাধারণত হয়:**

- **Production এ `console.log` রেখে দেওয়া।** পারফরম্যান্স ও নিরাপত্তা, দুই দিকেই ক্ষতি।
- **Object log করে ভাবা এটা সেই মুহূর্তের মান।** Browser এ live রেফারেন্স দেখায়।
- **ডিবাগ শেষে console.log গুলো না মোছা।** কোড নোংরা হয়।

**Edge case:**

- `console.log` এর নিজস্ব খরচ আছে। ঘন লুপে লক্ষ লক্ষ log পারফরম্যান্স নষ্ট করে।
- কিছু পরিবেশে (পুরনো IE) `console` DevTools বন্ধ থাকলে `undefined` ছিল।
- `console.log("%c Hello", "color: red")` দিয়ে CSS স্টাইল করা যায়, তবে শুধু browser এ।

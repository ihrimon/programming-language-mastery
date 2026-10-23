# ECMAScript বনাম JavaScript

## 🤔 এটা আসলে কী জিনিস?

- **ECMAScript (ES)** হলো ভাষার **স্পেসিফিকেশন**, মানে একটা নিয়মের দলিল (ECMA-262)। এখানে লেখা থাকে ভাষা কেমন হবে।
- **JavaScript** হলো সেই দলিলের **বাস্তবায়ন**, যা browser বা runtime এ চলে।

রান্নার সাথে তুলনা: ECMAScript হলো রেসিপি, JavaScript হলো রান্না করা খাবার। V8, SpiderMonkey, JavaScriptCore হলো আলাদা আলাদা রাঁধুনি, যারা একই রেসিপি অনুযায়ী রাঁধে।

ভাষার নিয়ম ঠিক করে **TC39** (Technical Committee 39), যেখানে browser কোম্পানি (Google, Mozilla, Apple) ও অন্যান্য সদস্য থাকে।

## 🎯 এটা না থাকলে কী সমস্যা হতো?

১৯৯৬ সালে Netscape এর JavaScript আর Microsoft এর JScript আলাদা হয়ে গিয়েছিল। একই কোড এক browser এ চলত, অন্যটায় ভাঙত। Developer দের প্রতিটা browser এর জন্য আলাদা কোড লিখতে হতো।

প্রমিতকরণের ফলে:

- সব engine একই নিয়ম মানে, তাই কোড সব জায়গায় একই চলে।
- নতুন feature আসার একটা স্বচ্ছ প্রক্রিয়া আছে।
- যে কেউ প্রস্তাব দেখতে ও মতামত দিতে পারে।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

নতুন feature যোগ হওয়ার পথ হলো **proposal stages**:

```
Stage 0  → ধারণা (strawperson)
Stage 1  → প্রস্তাব: সমস্যাটা বুঝিয়ে বলা হয়েছে
Stage 2  → খসড়া: syntax ও আচরণের প্রাথমিক বর্ণনা
Stage 2.7 → খসড়া প্রায় চূড়ান্ত, test লেখা বাকি
Stage 3  → প্রার্থী: engine রা এখন বাস্তবায়ন করছে
Stage 4  → সম্পন্ন: পরবর্তী বার্ষিক release এ যাবে
```

প্রতি বছর **জুন মাসে** নতুন ECMAScript সংস্করণ বের হয় (ES2015, ES2016 ... ES2025)। Stage 4 এ পৌঁছানো feature গুলো সেই বছরের তালিকায় ঢোকে।

Engine রা নিজেরাও Stage 3 এর feature আগে থেকেই বাস্তবায়ন করতে শুরু করে। তাই কোনো feature স্পেসিফিকেশনে ঢোকার আগেই browser এ চলতে পারে।

## 💻 কোডে দেখলে কেমন?

কোনো feature চলবে কিনা, তা আগে থেকে যাচাই করা যায় (feature detection):

```js
// ES2022 এ এসেছে: Array.prototype.at
const items = ["a", "b", "c"];

if (typeof items.at === "function") {
  console.log(items.at(-1)); // "c"
} else {
  // পুরনো environment এর জন্য বিকল্প
  console.log(items[items.length - 1]);
}

// ভাষার অংশ বনাম পরিবেশের অংশ
console.log(typeof Array);    // "function"  → ECMAScript এর অংশ
console.log(typeof Promise);  // "function"  → ECMAScript এর অংশ
console.log(typeof fetch);    // browser/Node এ আছে, কিন্তু ECMAScript এ নেই
console.log(typeof document); // শুধু browser এ
```

`Array`, `Promise`, `Map` ECMAScript এর অংশ। `fetch`, `document`, `setTimeout` পরিবেশের API।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- নতুন syntax ব্যবহারের আগে [caniuse.com](https://caniuse.com) বা MDN এর compatibility table দেখে নিই।
- `browserslist` ও Babel কনফিগ করার সময় target হিসেবে ES সংস্করণ বেছে নিতে হয়।
- MDN এ "ECMAScript specification" লিংক থেকে মূল আচরণ দেখা যায়।

**Production এ:**

- ব্যবহারকারীর browser পুরনো হলে নতুন feature ভেঙে যেতে পারে। তাই polyfill বা transpile প্রয়োজন হয়।
- Node.js এর সংস্করণ অনুযায়ী ES feature সমর্থন ভিন্ন, তাই server এর version জানা জরুরি।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- ECMAScript = স্পেসিফিকেশন, JavaScript = বাস্তবায়ন।
- ES6 = ES2015। ২০১৫ এর পর বছর ধরে নাম।
- Stage 4 মানে সম্পন্ন। Stage 3 মানে প্রায় তৈরি, কিন্তু সবখানে চলার নিশ্চয়তা নেই।

**যে ভুল সাধারণত হয়:**

- **`fetch`, `setTimeout`, `document` কে ভাষার অংশ ভাবা।** এগুলো ECMAScript এ নেই, host environment দেয়।
- **নতুন feature সব browser এ চলবে ধরে নেওয়া।** Production এ ছাড়ার আগে support যাচাই করুন।
- **Stage 2 বা তার আগের proposal production এ ব্যবহার করা।** পরিবর্তন হতে পারে, এমনকি বাতিলও।

**Edge case:**

- ECMAScript শুধু JavaScript এর জন্য নয়, ActionScript ও JScript ও এর বাস্তবায়ন ছিল।

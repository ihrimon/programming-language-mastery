# Browser DevTools এর মূল বিষয়

## 🤔 এটা আসলে কী জিনিস?

DevTools হলো browser এর ভেতরে থাকা developer টুলের সেট। খোলার উপায়: `F12` বা `Ctrl + Shift + I` (Mac এ `Cmd + Option + I`)।

প্রধান প্যানেলগুলো:

| প্যানেল | কাজ |
|---------|-----|
| **Elements** | বর্তমান DOM ও CSS দেখা ও বদলানো |
| **Console** | JS চালানো, log দেখা, error দেখা |
| **Sources** | কোড দেখা, breakpoint দেওয়া, debug করা |
| **Network** | প্রতিটা request/response দেখা |
| **Performance** | কোথায় সময় যাচ্ছে তার প্রোফাইল |
| **Application** | localStorage, cookie, cache, service worker |
| **Memory** | memory ব্যবহার ও leak খোঁজা |

## 🎯 এটা না থাকলে কী সমস্যা হতো?

DevTools ছাড়া ওয়েব অ্যাপ debug করা অন্ধকারে হাতড়ানোর মতো:

- API থেকে কী উত্তর এল, দেখা যেত না।
- কোন CSS কেন প্রয়োগ হচ্ছে না, বোঝা যেত না।
- কোড কোন লাইনে ভাঙছে তা জানার জন্য শুধু `console.log` ছড়াতে হতো।
- পেজ কেন ধীর, তার কোনো প্রমাণ থাকত না।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

DevTools browser এর সাথে সরাসরি যুক্ত, তাই সে **চলমান অবস্থা** দেখতে পারে:

- **Elements** দেখায় বর্তমান **live DOM**, মূল HTML ফাইল নয়। JS যা বদলায় সেটাও এখানে দেখা যায়।
- **Sources** এ breakpoint দিলে engine ওই লাইনে থেমে যায়, তখন call stack, scope আর প্রতিটি variable এর মান দেখা যায়।
- **Network** প্রতিটা request এর URL, method, status, header, payload, সময় রেকর্ড করে।
- **Source map** থাকলে minified কোডের বদলে আপনার মূল কোড দেখায়।

কিছু কাজের কৌশল:

- `$0` = Elements এ সর্বশেষ নির্বাচিত element, Console এ ব্যবহারযোগ্য।
- `$_` = আগের expression এর ফল।
- Network এ **Throttling** দিয়ে ধীর ইন্টারনেট অনুকরণ করা যায়।

## 💻 কোডে দেখলে কেমন?

Sources প্যানেলের বদলে কোডের ভেতর থেকেও থামানো যায়:

```js
function calculateTotal(items) {
  let total = 0;
  for (const item of items) {
    debugger; // DevTools খোলা থাকলে এখানে থেমে যাবে
    total += item.price * item.qty;
  }
  return total;
}

calculateTotal([
  { price: 100, qty: 2 },
  { price: 50, qty: 1 },
]);
```

থামার পর কী দেখবেন:

- **Scope** প্যানেলে `total`, `item` এর বর্তমান মান।
- **Call Stack** এ কে কাকে ডেকেছে।
- `F10` পরের লাইন, `F11` function এর ভেতরে, `F8` চালিয়ে যাওয়া।

Console এ দ্রুত পরীক্ষা:

```js
$0.textContent;             // নির্বাচিত element এর লেখা
copy(JSON.stringify(data)); // clipboard এ কপি
monitorEvents($0, "click"); // element এর click event গুলো দেখা
```

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- "API কী ফেরত দিচ্ছে?" → Network প্যানেল (Response ট্যাব)।
- "কেন এই স্টাইল কাজ করছে না?" → Elements → Styles।
- "কোড কোথায় ভাঙছে?" → Sources এ breakpoint।
- Error এ ক্লিক করলে সরাসরি সেই লাইনে যাওয়া যায়।

**Production এ:**

- ব্যবহারকারীর সমস্যা পুনরুৎপাদনে Network ও Console দেখে কারণ বের করা হয়।
- Performance ও Lighthouse দিয়ে ধীর অংশ ধরা হয়।
- Application ট্যাবে localStorage/cookie যাচাই করা হয়।
- Production এ minified কোড debug করতে source map দরকার।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- Elements = এখনকার live DOM, মূল HTML নয়।
- API সমস্যা হলে আগে Network ট্যাব দেখুন, তারপর কোড।
- `debugger` statement DevTools বন্ধ থাকলে কিছু করে না, কিন্তু production এ রেখে দেওয়া ঠিক নয়।

**যে ভুল সাধারণত হয়:**

- **শুধু `console.log` দিয়ে debug করা।** Breakpoint অনেক দ্রুত ও গভীর তথ্য দেয়।
- **Network এ "Preserve log" না দিয়ে redirect এর request হারানো।**
- **Console এ error দেখে Network না দেখা।** অনেক সময় আসল কারণ 404 বা CORS, যা Network এ স্পষ্ট।
- **Production কোডে `debugger` ফেলে রাখা।**

**Edge case:**

- "Disable cache" শুধু DevTools খোলা থাকলে কাজ করে, ব্যবহারকারীর অভিজ্ঞতা আলাদা হতে পারে।
- Extension (ad blocker ইত্যাদি) আপনার পেজের আচরণ বদলে দিতে পারে। Incognito এ পরীক্ষা করে দেখুন।
- Console এ চালানো কোড পেজ রিলোডে হারিয়ে যায়।

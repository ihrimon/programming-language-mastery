# Browser এ JavaScript কীভাবে চলে?

## 🤔 এটা আসলে কী জিনিস?

Browser একটা ওয়েবপেজ খোলার সময় HTML, CSS আর JS ধাপে ধাপে প্রক্রিয়া করে। এই ফাইলে দেখব **পুরো পেজ লোডের ভেতরে JS কোথায় বসে**। Engine এর ভেতরের কাজ আলাদা ফাইলে (`05`) আছে।

সংক্ষেপে: HTML পড়তে পড়তে `<script>` পেলে browser সাধারণত থেমে JS চালায়, তারপর বাকি HTML পড়ে।

## 🎯 এটা না থাকলে কী সমস্যা হতো?

এই প্রবাহ না বুঝলে এই প্রশ্নগুলোর উত্তর মেলে না:

- আমার script `document.getElementById(...)` করলে `null` কেন আসে?
- ভারী JS চালালে পেজ জমে যায় কেন?
- `<script>` কোথায় রাখলে পেজ দ্রুত লোড হয়?
- First paint এত দেরিতে হয় কেন?

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

```
1. Network থেকে HTML আসে
        ↓
2. HTML Parser উপরে থেকে নিচে পড়ে → DOM তৈরি করে
        ↓  <script> পেল?
3. Parsing থামে (ডিফল্টে) → JS ডাউনলোড → engine এ চলে
        ↓  (Parse → Bytecode → JIT)
4. JS DOM বদলাতে পারে, নতুন request পাঠাতে পারে
        ↓
5. বাকি HTML পড়া চলে → DOM সম্পূর্ণ
        ↓
6. CSS থেকে CSSOM, DOM + CSSOM = Render Tree
        ↓
7. Layout → Paint → পর্দায় দেখা যায়
```

গুরুত্বপূর্ণ ফলাফল:

- **JS main thread এ চলে।** Layout ও paint ও সেই thread এ। JS ভারী হলে স্ক্রিন আপডেট আটকে যায়।
- JS চলার সময় DOM তখন পর্যন্ত যতটুকু পড়া হয়েছে ততটুকুই থাকে।
- JS DOM বা CSS বদলালে browser কে আবার layout/paint করতে হতে পারে।

## 💻 কোডে দেখলে কেমন?

```html
<!DOCTYPE html>
<html>
  <head>
    <script>
      // এখানে body এখনো তৈরি হয়নি!
      console.log(document.body); // null
      console.log(document.getElementById("title")); // null
    </script>
  </head>
  <body>
    <h1 id="title">Hello</h1>

    <script>
      // এখানে h1 আগেই পড়া হয়েছে
      console.log(document.getElementById("title").textContent); // "Hello"
    </script>
  </body>
</html>
```

প্রথম script চলার সময় `<body>` পার্স হয়নি, তাই `null`। দ্বিতীয় script এর সময় element আছে।

সমাধান: `defer` ব্যবহার করা (দেখুন `08-script-loading.md`), অথবা `DOMContentLoaded` event এর জন্য অপেক্ষা করা।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- "element পাচ্ছি না" ধরনের bug এর বড় কারণ হলো script এর সময়। এই প্রবাহ জানা থাকলে সরাসরি ধরা যায়।
- DevTools এর Performance tab এ পেজ লোডের প্রতিটা ধাপ দেখা যায়।

**Production এ:**

- বড় JS bundle ডাউনলোড ও parse এ সময় নেয়, তাই পেজ দেরিতে ইন্টারঅ্যাকটিভ হয়।
- Core Web Vitals (LCP, INP) সরাসরি এই প্রবাহের উপর নির্ভর করে।
- মোবাইল ডিভাইসে CPU ধীর, তাই একই JS সেখানে বেশি সময় নেয়।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- ডিফল্টে `<script>` HTML parsing আটকে দেয়।
- JS, layout, paint, সবই একই main thread এ, ভারী JS মানে জমে যাওয়া পেজ।
- DOM এ হাত দেওয়ার আগে নিশ্চিত হোন element তৈরি হয়েছে।

**যে ভুল সাধারণত হয়:**

- **`<head>` এ ডিফল্ট script রেখে DOM খোঁজা।** `null` আসবে।
- **একটা বিশাল JS ফাইল পাঠানো।** Parse ও execute এর সময় বাড়ে।
- **লোডের সময় ভারী synchronous কাজ করা।** পেজ জমে যায়।

**Edge case:**

- Browser `<script>` পড়ার সময় আগাম অন্য ফাইল ডাউনলোড শুরু করে (preload scanner), তাই সবকিছু একেবারে সিরিয়ালে চলে না।
- Inline script ডাউনলোডের অপেক্ষা করে না, কিন্তু parsing ঠিকই আটকায়।

# Single-Threaded Model

## 🤔 এটা আসলে কী জিনিস?

JavaScript এ **একটা সময়ে একটাই কাজ** চলে। এর একটাই **call stack** আছে। এক লাইনের কাজ শেষ না হলে পরের লাইনে যায় না।

তবুও async কাজ (timer, network request, user click) সামলানো যায়, কারণ এই কাজগুলো **runtime/browser** করে দেয়, আর শেষে ফলাফল **event loop** এর মাধ্যমে ফিরে আসে।

চারটা অংশ মনে রাখুন:

| অংশ | কাজ |
|-----|-----|
| **Call Stack** | এখন কোন function চলছে তার তালিকা |
| **Web APIs / Node APIs** | Timer, network, DOM event এর মতো কাজ ভাষার বাইরে সামলায় |
| **Task Queue** | সম্পন্ন callback গুলো অপেক্ষায় থাকে (`setTimeout` ইত্যাদি) |
| **Microtask Queue** | Promise এর callback, task queue এর আগে চলে |
| **Event Loop** | Stack খালি হলে queue থেকে পরের কাজ তুলে আনে |

## 🎯 এটা না থাকলে কী সমস্যা হতো?

- **Multi-thread হলে** দুই thread একই DOM বদলাতে গেলে race condition আর deadlock এর ঝামেলা হতো। এড়াতেই JS কে সরল রাখা হয়েছে।
- **Single-thread কিন্তু async না থাকলে** একটা network request এর জন্য পুরো পেজ আটকে থাকত। Event loop এই সমস্যার সমাধান।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

```
        ┌─────────────┐
        │ Call Stack  │  ← JS এখানে চলে (একবারে একটা)
        └──────┬──────┘
               │ async কাজ ডাকলে
               ▼
        ┌─────────────┐
        │  Web APIs   │  ← timer, fetch, DOM events (ভাষার বাইরে)
        └──────┬──────┘
               │ কাজ শেষ → callback জমা
               ▼
   ┌─────────────────────────┐
   │ Microtask Queue (Promise)│ ← আগে চলে
   │ Task Queue (setTimeout)  │ ← পরে চলে
   └───────────┬─────────────┘
               │
        Event Loop: Stack খালি? → পরের callback stack এ তোলো
```

নিয়ম: **Stack খালি না হলে event loop কিছু তোলে না**। এবং Microtask queue সম্পূর্ণ খালি হয়ে তারপর পরবর্তী task এ যায়।

## 💻 কোডে দেখলে কেমন?

```js
console.log("1");

setTimeout(() => console.log("2"), 0);

Promise.resolve().then(() => console.log("3"));

console.log("4");

// আউটপুট: 1, 4, 3, 2
```

কেন এই ক্রম:

1. `1` আর `4` সরাসরি stack এ চলে।
2. `setTimeout` এর callback task queue এ যায়, delay 0 হলেও।
3. Promise এর callback microtask queue এ যায়, যা task queue এর আগে চলে, তাই `3`, তারপর `2`।

Blocking এর উদাহরণ:

```js
// ❌ এটা চললে পুরো পেজ জমে যাবে
const start = Date.now();
while (Date.now() - start < 3000) {
  // ৩ সেকেন্ড ধরে stack আটকে আছে
}
console.log("শেষ");
```

এই ৩ সেকেন্ডে click, scroll, animation কিছুই কাজ করবে না।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- Async কোডের আউটপুটের ক্রম বোঝার জন্য এটাই ভিত্তি (Phase 11 এ বিস্তারিত)।
- `await` বা `.then` কেন পরে চলে, তার উত্তর এখানে।

**Production এ:**

- ভারী গণনা (বড় array সাজানো, বড় JSON parse) main thread আটকে UI জমিয়ে দেয়।
- সমাধান: কাজ ভেঙে ভেঙে করা, অথবা **Web Worker** এ সরানো।
- Node.js এ একটা ভারী synchronous কাজ সব ব্যবহারকারীর request আটকে দিতে পারে।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- একবারে একটাই কাজ চলে, stack খালি না হলে অন্য কিছু ঢোকে না।
- Microtask (Promise) আগে, Task (`setTimeout`) পরে।
- `setTimeout(fn, 0)` মানে "এখনই" নয়, "stack খালি হলে যত তাড়াতাড়ি সম্ভব"।

**যে ভুল সাধারণত হয়:**

- **"Single-threaded মানে async নেই" ভাবা।** Async আছে, event loop এর কল্যাণে।
- **ভাবা যে JS নিজে timer চালায়।** Timer চালায় browser বা Node, JS শুধু callback চালায়।
- **লুপের ভেতরে ভারী synchronous কাজ রাখা।** UI বা server আটকে যায়।

**Edge case:**

- `setTimeout(fn, 100)` মানে "অন্তত ১০০ms পরে", ঠিক ১০০ms নয়। Stack ব্যস্ত থাকলে দেরি হয়।
- JS single-threaded হলেও browser নিজে multi-threaded। Network, rendering আলাদা thread এ হয়।
- Web Worker আলাদা thread, কিন্তু DOM ধরতে পারে না।

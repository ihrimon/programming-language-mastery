# JavaScript এর ইতিহাস

## 🤔 এটা আসলে কী জিনিস?

JavaScript এর জন্ম ১৯৯৫ সালে, **Netscape** কোম্পানিতে, **Brendan Eich** এর হাতে। Netscape Navigator browser এর জন্য একটা হালকা scripting ভাষা দরকার ছিল, যাতে সাধারণ মানুষও ওয়েবপেজে সামান্য আচরণ যোগ করতে পারে।

নামের যাত্রা: **Mocha → LiveScript → JavaScript**।

সময়রেখা:

| সাল | ঘটনা |
|-----|------|
| 1995 | Brendan Eich প্রায় ১০ দিনে প্রথম সংস্করণ বানান। শেষে নাম হয় JavaScript |
| 1996 | Microsoft নিজের সংস্করণ **JScript** বের করে (IE এর জন্য) |
| 1997 | ভাষাটি **ECMAScript** নামে প্রমিত হয় (ES1) |
| 1999 | ES3, যা অনেক বছর ধরে ভিত্তি ছিল |
| 2005 | **AJAX** জনপ্রিয় হয়, পেজ রিলোড ছাড়া ডেটা আনা শুরু |
| 2008 | Google এর **V8** engine, JS অনেক দ্রুত হয়ে যায় |
| 2009 | **Node.js** আসে, JS server এও চলতে শুরু করে। ES5 ও এই বছরেই |
| 2015 | **ES6 / ES2015**, ভাষার সবচেয়ে বড় আপডেট (`let`, `const`, class, arrow function, promise) |
| 2015 থেকে | প্রতি বছর একটা করে ছোট release |

## 🎯 এটা না থাকলে কী সমস্যা হতো?

ইতিহাস না জানলে ভাষার অদ্ভুত জিনিসগুলো অযৌক্তিক মনে হয়। জানলে প্রতিটার কারণ পাওয়া যায়:

- `var` কেন function-scoped, আর `let`/`const` কেন এলো (ES6)
- `typeof null === "object"` কেন (প্রথম সংস্করণের bug)
- Callback থেকে Promise, তারপর async/await কেন এলো
- পুরনো কোডে কেন `var`, IIFE আর `prototype` ভরা

পুরনো project এ কাজ করার সময় এই জ্ঞান সরাসরি কাজে লাগে।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

ইতিহাসের তিনটা পর্ব বুঝলে বর্তমান ছবিটা পরিষ্কার হয়:

```
পর্ব ১ (1995–2008): ছোট scripting ভাষা
   Browser আলাদা আলাদা নিয়ম, ধীর engine
        ↓ V8 আসে (2008)
পর্ব ২ (2009–2014): ভাষা পরিণত হয়
   Node.js, AJAX, jQuery, ES5
        ↓ ES6 (2015)
পর্ব ৩ (2015–এখন): আধুনিক JavaScript
   বার্ষিক release, module, async/await, framework যুগ
```

একটা গুরুত্বপূর্ণ নীতি: **backward compatibility**। ভাষা পুরনো কোড ভাঙে না। ১৯৯৯ সালের কোডও আজকের browser এ চলে। তাই ভুল সিদ্ধান্তও (`typeof null`) ঠিক করা যায়নি, শুধু নতুন বিকল্প যোগ হয়েছে।

## 💻 কোডে দেখলে কেমন?

একই কাজ, তিন যুগে:

```js
// ১৯৯০–২০০০ এর যুগ: var আর callback
var numbers = [1, 2, 3];
var doubled = [];
for (var i = 0; i < numbers.length; i++) {
  doubled.push(numbers[i] * 2);
}

// ES5 (2009): map
var doubled2 = numbers.map(function (n) {
  return n * 2;
});

// ES6+ (2015 থেকে): arrow function, const
const doubled3 = numbers.map((n) => n * 2);

console.log(doubled3); // [2, 4, 6]
```

ফলাফল একই, কিন্তু পড়তে সহজ ও ভুলের সুযোগ কম।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- পুরনো codebase এ `var`, `function` দিয়ে লেখা কোড পেলে বোঝা যায় কেন এমন, আর কীভাবে আধুনিক রূপে বদলাতে হবে (refactoring)।
- কোন syntax কোন বছরের, জানলে browser support (`browserslist`, Babel) সিদ্ধান্ত নেওয়া সহজ।

**Production এ:**

- পুরনো browser (বিশেষ করে IE) এর জন্য code transpile করতে হতো। এখন বেশিরভাগ project এ লাগে না, কিন্তু কিছু enterprise project এ এখনো লাগে।
- Library এর পুরনো সংস্করণে পুরনো pattern থাকে, যা আপনার আধুনিক কোডের সাথে মেলে না।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- 1995 জন্ম, 1997 ECMAScript, 2009 Node.js, 2015 ES6, এই চারটা সাল মনে রাখলেই যথেষ্ট।
- ES6 = ES2015 (একই জিনিস)। এরপর নাম বছর ধরে: ES2016, ES2017...
- নামের ক্রম: Mocha → LiveScript → JavaScript।

**যে ভুল সাধারণত হয়:**

- **Java ও JavaScript এক ভাবা।** Netscape তখন Sun এর Java জনপ্রিয়তার সুযোগ নিতে নামটা রেখেছিল। দুটো সম্পূর্ণ আলাদা ভাষা।
- **"১০ দিনে বানানো তাই খারাপ ভাষা" ভাবা।** প্রথম সংস্করণ ১০ দিনে হলেও ভাষা ৩০ বছর ধরে উন্নত হয়েছে।

**Edge case:**

- ES4 কখনো release হয়নি। কমিটির মতবিরোধে বাতিল হয়, তাই ES3 থেকে সোজা ES5 এ লাফ।

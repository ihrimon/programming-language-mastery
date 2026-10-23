# JavaScript কোথায় চলে?

## 🤔 এটা আসলে কী জিনিস?

JavaScript চলার জন্য একটা **runtime (host environment)** দরকার। Runtime = engine + সেই পরিবেশের নিজস্ব API।

| Runtime | কোথায় চলে | Engine | উদাহরণ |
|---------|-----------|--------|--------|
| **Browser** | ব্যবহারকারীর ব্রাউজারে | V8 / SpiderMonkey / JavaScriptCore | ওয়েবসাইট, web app |
| **Node.js** | Server বা কম্পিউটারে | V8 | API server, CLI tool |
| **Deno** | Server এ | V8 | Node এর বিকল্প, built-in TypeScript |
| **Bun** | Server এ | JavaScriptCore | দ্রুত runtime, bundler ও package manager সহ |
| **Edge runtime** | CDN এর কাছাকাছি server এ | V8 isolate | Cloudflare Workers, Vercel Edge |

অন্যান্য জায়গাও আছে: **Electron** (desktop app), **React Native** (mobile app, Hermes engine)।

## 🎯 এটা না থাকলে কী সমস্যা হতো?

JavaScript যদি শুধু browser এ আটকে থাকত:

- Frontend আর backend এর জন্য দুটো আলাদা ভাষা শিখতে হতো।
- Build tool, test runner, linter বানানো যেত না।
- Desktop বা mobile app এর জন্য আলাদা টিম দরকার হতো।

Runtime গুলো থাকায় একই ভাষা দিয়ে প্রায় সব স্তরের কাজ করা যায়।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

প্রতিটা runtime এর গঠন একই রকম:

```
┌─────────────────────────────────────┐
│           Runtime (Host)            │
│  ┌───────────────────────────────┐  │
│  │  JS Engine (ভাষা চালায়)      │  │
│  │  Array, Promise, Map, class   │  │ ← ECMAScript
│  └───────────────────────────────┘  │
│  Host API (পরিবেশ অনুযায়ী আলাদা)   │
│  Browser: DOM, fetch, localStorage  │
│  Node:    fs, http, process         │
└─────────────────────────────────────┘
```

- **Engine** সব runtime এ প্রায় একই, ভাষার নিয়ম চালায়।
- **Host API** আলাদা, তাই `document` Node এ নেই আর `fs` browser এ নেই।
- Global object ও আলাদা: browser এ `window`, Node এ `global`। আধুনিক সমাধান হলো `globalThis`, যা সব জায়গায় কাজ করে।

Edge runtime এ আরও সীমাবদ্ধতা আছে: ফাইল সিস্টেম নেই, কিছু Node API নেই, execution সময় কম।

## 💻 কোডে দেখলে কেমন?

কোন পরিবেশে চলছে, তা কোডে ধরা যায়:

```js
const isBrowser = typeof window !== "undefined" && typeof document !== "undefined";
const isNode = typeof process !== "undefined" && process.versions?.node != null;

console.log({ isBrowser, isNode });

// সব runtime এ কাজ করে এমন global
console.log(typeof globalThis); // "object"

// একই ভাষা, ভিন্ন API
if (isBrowser) {
  document.title = "Hello";
}
if (isNode) {
  console.log(process.version); // যেমন "v22.0.0"
}
```

Browser এ `isBrowser` true, Node এ `isNode` true।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- একটা project এ প্রায়ই একসাথে একাধিক runtime থাকে: browser এ UI, Node এ API ও build tool।
- Next.js, Nuxt এর মতো framework এ একই কোড server ও browser দুই জায়গায় চলে (SSR), তাই `window` ব্যবহার করলে server এ error আসে।
- Library লেখার সময় ঠিক করতে হয় কোন runtime এ চলবে।

**Production এ:**

- Server এর Node সংস্করণ আর local সংস্করণ আলাদা হলে "আমার মেশিনে চলে" সমস্যা হয়।
- Edge এ deploy করলে Node এর সব API ব্যবহার করা যায় না।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- Runtime = engine + host API। ভাষা এক, API আলাদা।
- সব পরিবেশে সুরক্ষিত global হলো `globalThis`।
- Browser এর কোড user এর হাতে, সেটা কখনো সম্পূর্ণ বিশ্বাস করা যায় না।

**যে ভুল সাধারণত হয়:**

- **Server-side এ `window` বা `document` ব্যবহার করা।** SSR এ `ReferenceError: window is not defined` আসে।
- **"JavaScript = Node.js" ভাবা।** Node হলো একটা runtime, ভাষা নয়।
- **Browser কোডে secret key রাখা।** যা browser এ যায়, user তা দেখতে পারে।

**Edge case:**

- Node আর Deno দুটোই V8 ব্যবহার করে, তবুও API ভিন্ন। Engine এক হলেই runtime এক নয়।
- Web Worker ও আলাদা runtime এর মতো: সেখানে `document` নেই।

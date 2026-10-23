# `<script>` Loading: `defer`, `async`, `type="module"`

## 🤔 এটা আসলে কী জিনিস?

`<script>` ট্যাগ কীভাবে লোড ও execute হবে, সেটা তিনটা বৈশিষ্ট্য দিয়ে ঠিক করা যায়:

| ধরন | ডাউনলোড | Execute কখন | ক্রম |
|-----|---------|------------|------|
| **ডিফল্ট** | থেমে থেমে | ডাউনলোডের সাথে সাথে, HTML parsing আটকে | লেখার ক্রমে |
| **`defer`** | HTML পড়ার সাথে সমান্তরালে | HTML পার্স শেষ হলে | লেখার ক্রমে |
| **`async`** | HTML পড়ার সাথে সমান্তরালে | ডাউনলোড শেষ হওয়া মাত্র | যে আগে আসে |
| **`type="module"`** | সমান্তরালে | `defer` এর মতো, HTML পার্স শেষে | লেখার ক্রমে |

## 🎯 এটা না থাকলে কী সমস্যা হতো?

ডিফল্টে `<script>` পেলে browser HTML পড়া থামিয়ে ডাউনলোড ও execute করে। ফলে:

- পেজ দেখাতে দেরি হয় (render blocking)।
- `<head>` এ রাখলে DOM তৈরি হয়নি, `document.getElementById` `null` দেয়।
- পুরনো সমাধান ছিল `<script>` `</body>` এর ঠিক আগে রাখা। কাজ করে, কিন্তু ডাউনলোড শুরু হয় দেরিতে।

`defer` ও `async` এই দুটো সমস্যারই আধুনিক সমাধান।

## ⚙️ ভেতরে ভেতরে কীভাবে কাজ করে?

```
ডিফল্ট:
HTML parse ──■■■ থামে ■■■──→ ডাউনলোড + Execute ──→ HTML parse চলে
                  (পেজ আটকে)

defer:
HTML parse ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━→ শেষ → Execute (ক্রমে)
JS ডাউনলোড ━━━━━━━━━━━━━┛ (পাশাপাশি)

async:
HTML parse ━━━━━━━━■ থামে ■━━━━━━━━━━━━→ শেষ
JS ডাউনলোড ━━━━━━┛ → ডাউনলোড শেষ হওয়া মাত্র Execute (parsing থামিয়ে)
```

**`type="module"`** এ আরও কিছু আলাদা:

- ডিফল্টে `defer` এর মতো আচরণ করে।
- নিজস্ব scope থাকে, global এ variable ছড়ায় না।
- স্বয়ংক্রিয়ভাবে **strict mode**।
- `import` / `export` ব্যবহার করা যায়।
- একই module দুইবার লিখলেও একবারই চলে।

## 💻 কোডে দেখলে কেমন?

```html
<!-- ১. ডিফল্ট: parsing আটকায় -->
<script src="blocking.js"></script>

<!-- ২. defer: DOM তৈরি হওয়ার পর, লেখার ক্রমে -->
<script src="app.js" defer></script>
<script src="extra.js" defer></script> <!-- app.js এর পরে চলবে -->

<!-- ৩. async: স্বাধীন script, ক্রম নিশ্চিত নয় -->
<script src="analytics.js" async></script>

<!-- ৪. module -->
<script type="module" src="main.js"></script>
```

```js
// main.js (type="module")
import { greet } from "./greet.js";
console.log(greet("Rimon"));
console.log(this); // undefined, module এর top-level this
```

কখন কোনটা:

- নিজের অ্যাপের কোড, **`defer`** (বা `module`)।
- Analytics, ads এর মতো স্বাধীন তৃতীয় পক্ষের কোড, **`async`**।

## 🏭 Real project এ কোথায় লাগে?

**Development এ:**

- Vite, Next.js এর মতো টুল `type="module"` ব্যবহার করে অ্যাপ লোড করে।
- DOM নিয়ে কাজ করা script এ `defer` দিলে `DOMContentLoaded` এর অপেক্ষা লাগে না।

**Production এ:**

- ডিফল্ট script এর কারণে First Paint দেরি হয়, সরাসরি Core Web Vitals খারাপ করে।
- Analytics, chat widget জাতীয় তৃতীয় পক্ষের script `async` না করলে পুরো পেজ ধীর করে দিতে পারে।
- `defer` script গুলো `DOMContentLoaded` এর আগে চলে, তাই সেখানে DOM সুরক্ষিত।

## ⚠️ কোথায় ভুল হয়, কী মনে রাখব?

**মনে রাখার নিয়ম:**

- `defer` = ক্রম বজায় রেখে, পার্সিং শেষে।
- `async` = ক্রম নিশ্চিত নয়, ডাউনলোড হওয়া মাত্র।
- নিজের অ্যাপে `defer` বা `module`, স্বাধীন বাইরের কোডে `async`।

**যে ভুল সাধারণত হয়:**

- **পরস্পর নির্ভরশীল script এ `async` দেওয়া।** `b.js` যদি `a.js` এর উপর নির্ভর করে, `async` এ আগে চলে ভাঙতে পারে।
- **Inline script এ `defer` দিয়ে কাজ হবে ভাবা।** `src` ছাড়া inline script এ `defer` প্রভাব ফেলে না।
- **`file://` খুলে `type="module"` চালানো।** CORS এর কারণে অনেক browser এ error আসে, local server লাগে।

**Edge case:**

- `defer` ও `async` একসাথে দিলে (শুধু `src` সহ) `async` প্রাধান্য পায়।
- `async` script `DOMContentLoaded` এর আগেও চলতে পারে, পরেও চলতে পারে।
- `nomodule` attribute দিয়ে পুরনো browser এ আলাদা fallback script দেওয়া যায়।

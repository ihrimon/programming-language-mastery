// =============================================================================
// 04. Type Narrowing & Type System Analysis
// =============================================================================
// Conditional checks, control flow, and safe type refinement
// =============================================================================

// -----------------------------------------------------------------------------
// 1. Type Guards
// -----------------------------------------------------------------------------
// Type Guards are functions or expressions that narrow union types to specific
// types within a conditional block. TypeScript uses control flow analysis to
// "remember" these checks.
//
// Types:
//   - Built-in: typeof, instanceof, in
//   - Custom: Functions returning param is Type
//   - Discriminated: Unions with type: 'literal'

class BankPayment {
  type: 'bank' = 'bank';
  constructor(
    public account: string,
    public routing: string,
  ) {}
}

type Payment =
  | { type: 'credit-card'; cardNumber: string; expiry: string; cvv: string }
  | { type: 'paypal'; email: string; payerId: string }
  | BankPayment
  | { type: 'error'; message: string };

function processPayment(payment: Payment): string {
  // 1. DISCRIMINATED UNION
  if (payment.type === 'credit-card') {
    return `Charged via CC ending ${payment.cardNumber.slice(-4)}`;
  }

  // 2. CUSTOM TYPE GUARD
  if (isPaypalPayment(payment)) {
    return `PayPal payment from ${payment.email}`;
  }

  // 3. INSTANCEOF (works with class only)
  if (payment instanceof BankPayment) {
    return `Bank transfer to ${payment.account}`;
  }

  // 4. Fallback (error type)
  return `Error: ${payment.message}`;
}

function isPaypalPayment(
  p: Payment,
): p is { type: 'paypal'; email: string; payerId: string } {
  return p.type === 'paypal';
}

processPayment({
  type: 'credit-card',
  cardNumber: '****1234',
  expiry: '12/25',
  cvv: '123',
});

processPayment({
  type: 'paypal',
  email: 'alice@paypal.com',
  payerId: 'PP123',
});

processPayment(new BankPayment('123456789', '987654321'));

// -----------------------------------------------------------------------------
// 2. Custom Type Guards
// -----------------------------------------------------------------------------
// Custom Type Guards are functions returning param is Type that narrow union
// types to specific types. TypeScript uses the return type to automatically
// refine types within the true branch.

type Document =
  | { type: 'pdf'; pages: number; filename: string }
  | { type: 'docx'; words: number; filename: string }
  | { type: 'image'; width: number; height: number; filename: string }
  | { type: 'unknown'; error: string };

declare function parseFile(file: unknown): Document;

function isPdfDocument(
  doc: Document,
): doc is { type: 'pdf'; pages: number; filename: string } {
  return doc.type === 'pdf';
}

function isImageDocument(
  doc: Document,
): doc is { type: 'image'; width: number; height: number; filename: string } {
  return doc.type === 'image';
}

function isValidDocument(
  doc: Document,
): doc is Exclude<Document, { type: 'unknown' }> {
  return doc.type !== 'unknown';
}

function processDocument(file: unknown): string {
  const doc = parseFile(file);

  if (isPdfDocument(doc)) {
    return `PDF: ${doc.filename} (${doc.pages} pages)`;
  }

  if (isImageDocument(doc)) {
    return `Image: ${doc.filename} (${doc.width}x${doc.height})`;
  }

  if (isValidDocument(doc)) {
    return `Valid: ${doc.filename}`;
  }

  return `Error: ${doc.error}`;
}

// -----------------------------------------------------------------------------
// 3. Type Assertions and Non-null Assertion Operator (!)
// -----------------------------------------------------------------------------
// Type assertions (as Type) tell TypeScript to treat a value as a specific type.
// Non-null assertion (!) tells TypeScript a value is definitely not null/undefined.

// 3.1 DOM (Most common)
const button = document.getElementById('submit') as HTMLButtonElement;

// 3.2 Non-null (After validation)
// const user = getUser(id);
// if (!user) return;
// user!.name.toUpperCase();

// 3.3 JSON Parsing
// const data = JSON.parse(json) as User[];

// 3.4 React Refs
// inputRef.current!.focus();

// 3.5 Event Casting
// (event.target as HTMLInputElement).value;

// -----------------------------------------------------------------------------
// 4. Type Narrowing
// -----------------------------------------------------------------------------
// Type Narrowing refines broad types (unions, unknown) to specific types using
// TypeScript's control flow analysis.
//
// Core Techniques:
//   - typeof - Primitive narrowing
//   - Equality (===) - Literal narrowing
//   - in operator - Property existence
//   - instanceof - Class/constructor narrowing
//   - Truthiness - null/undefined removal
//   - Custom Type Guards - param is Type
//   - Discriminated Unions - type: 'literal'

type MediaFile =
  | { type: 'image'; width: number; height: number; filename: string }
  | { type: 'video'; duration: number; filename: string }
  | { type: 'audio'; bitrate: number; filename: string }
  | { type: 'error'; message: string };

class ImageProcessor {
  constructor(
    public width: number,
    public height: number,
  ) {}
  getSize() {
    return this.width * this.height;
  }
}

function isAudioFile(
  file: MediaFile,
): file is { type: 'audio'; bitrate: number; filename: string } {
  return file.type === 'audio';
}

function processMedia(file: unknown): string {
  const media = file as MediaFile;

  // TECHNIQUE 1: TRUTHINESS (null check)
  if (!media) {
    return 'No file provided';
  }

  // TECHNIQUE 2: EQUALITY (Discriminated Union)
  if (media.type === 'image') {
    return `Image: ${media.filename} (${media.width}x${media.height})`;
  }

  // TECHNIQUE 3: TYPEOF (Primitive narrowing)
  if (typeof media.duration === 'number') {
    return `Video: ${media.filename} (${media.duration}s)`;
  }

  // TECHNIQUE 4: CUSTOM TYPE GUARD
  if (isAudioFile(media)) {
    return `Audio: ${media.filename} (${media.bitrate}kbps)`;
  }

  // TECHNIQUE 5: `in` OPERATOR
  if ('bitrate' in media) {
    return `Audio detected: ${media.bitrate}`;
  }

  // TECHNIQUE 6: INSTANCEOF
  if (media instanceof ImageProcessor) {
    return `Processed: ${media.getSize()} pixels`;
  }

  // TECHNIQUE 7: FALLBACK (narrowed to error)
  return `Error: ${media.message}`;
}

const files: (MediaFile | ImageProcessor | null)[] = [
  { type: 'image', width: 1920, height: 1080, filename: 'photo.jpg' },
  { type: 'video', duration: 125, filename: 'movie.mp4' },
  { type: 'audio', bitrate: 128, filename: 'song.mp3' },
  new ImageProcessor(800, 600),
  { type: 'error', message: 'File too large' },
];

files.forEach((file) => console.log(processMedia(file)));

// -----------------------------------------------------------------------------
// 5. Control Flow Based Type Analysis
// -----------------------------------------------------------------------------
// TypeScript's ability to track variable types through code execution paths
// (if/else, switch, loops). The compiler analyzes all possible flows to
// determine the most specific type at each location.

type CartItem = { name: string; price: number };

type CheckoutState =
  | { step: 'cart'; items: CartItem[] }
  | { step: 'payment'; amount: number }
  | { step: 'complete'; orderId: string }
  | { step: 'error'; message: string };

let checkout: CheckoutState = { step: 'cart', items: [] };

function nextStep(current: CheckoutState): CheckoutState {
  if (current.step === 'cart') {
    const total = current.items.reduce((sum, item) => sum + item.price, 0);
    return { step: 'payment', amount: total };
  }

  if (current.step === 'payment') {
    return { step: 'complete', orderId: `ORD-${Date.now()}` };
  }

  if (current.step === 'complete') {
    return { step: 'error', message: 'Cannot restart complete order' };
  }

  return current;
}

checkout = nextStep(checkout);
console.log(`Pay $${checkout.amount}`);

checkout = nextStep(checkout);
console.log(`Order ${checkout.orderId}`);

checkout = nextStep(checkout);
console.log(`Error: ${checkout.message}`);

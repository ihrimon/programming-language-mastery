<?php
$name = "Ali";
$lang = "PHP";

// ── HEREDOC ─────────────────────────────
// Like double quotes — variables ARE parsed
$message = <<<EOT
Hello, $name!
You are learning $lang.
This is a multi-line string.
No need to escape "quotes" or 'apostrophes' here.
EOT;

echo $message;
echo "<br><br>";

// Heredoc with HTML
$html = <<<HTML
<div>
    <h2>Welcome, $name!</h2>
    <p>Learning: $lang</p>
</div>
HTML;

echo $html;
echo "<br>";

// ── NOWDOC ──────────────────────────────
// Like single quotes — variables are NOT parsed
$raw = <<<'EOT'
Hello, $name!
This will print $name literally.
Variables are NOT parsed here.
EOT;

echo $raw;
echo "<br>";

/*
  When to use:
  - Heredoc  → long strings WITH variable interpolation
  - Nowdoc   → long strings WITHOUT variable interpolation (raw text, SQL, HTML templates)
*/
?>

```

- [ ]

```php
<?php
$text = "  Hello, PHP World!  ";

// Length
echo strlen($text);             // 22 (including spaces)
echo "<br>";

// Remove whitespace from both ends
echo trim($text);               // "Hello, PHP World!"
echo "<br>";

// Case conversion
echo strtolower("HELLO");       // hello
echo strtoupper("hello");       // HELLO
echo ucfirst("hello world");    // Hello world
echo ucwords("hello world");    // Hello World
echo "<br>";

// Search & Replace
$str = "I love Java";
echo str_replace("Java", "PHP", $str);  // I love PHP
echo "<br>";

// Check if substring exists
$email = "ali@example.com";
echo str_contains($email, "@");   // 1 (true) — PHP 8+
echo "<br>";
echo strpos($email, "@");         // 3 (position index)
echo "<br>";

// Extract part of string
echo substr("Hello World", 6);       // World
echo substr("Hello World", 0, 5);    // Hello
echo "<br>";

// Repeat a string
echo str_repeat("Ha", 3);        // HaHaHa
echo "<br>";

// Reverse a string
echo strrev("PHP");               // PHP  (same!) try with "Hello"
echo strrev("Hello");             // olleH
echo "<br>";

// Split string into array
$csv = "red,green,blue";
$arr = explode(",", $csv);
print_r($arr); // Array ( [0] => red [1] => green [2] => blue )
echo "<br>";

// Join array into string
echo implode(" | ", $arr);  // red | green | blue
?>

```

```php
// phase 2 practice project

<?php
// File: user_profile.php
// Uses everything from Phase 2

$firstName = "Ali";
$lastName  = "Hassan";
$age       = 20;
$height    = 5.9;
$city      = "Chattogram";
$country   = "Bangladesh";
$isStudent = true;
$gpa       = 3.85;
$email     = "ali@example.com";
$bio       = null;

// Build full name
$fullName = $firstName . " " . $lastName;

// Check student status
$status = $isStudent ? "Student" : "Professional";

// Check bio
$displayBio = is_null($bio) ? "No bio provided." : $bio;

// Check email validity
$hasAt = str_contains($email, "@");
$emailStatus = $hasAt ? "Valid email" : "Invalid email";
?>

<!DOCTYPE html>
<html lang="en">
<head><title>User Profile</title></head>
<body>

<h2>User Profile Card</h2>

<?php
echo <<<HTML
<table border="1" cellpadding="8">
  <tr><td>Full Name</td><td>$fullName</td></tr>
  <tr><td>Age</td><td>$age</td></tr>
  <tr><td>Height</td><td>$height ft</td></tr>
  <tr><td>Location</td><td>$city, $country</td></tr>
  <tr><td>Status</td><td>$status</td></tr>
  <tr><td>GPA</td><td>$gpa</td></tr>
  <tr><td>Email</td><td>$email ($emailStatus)</td></tr>
  <tr><td>Bio</td><td>$displayBio</td></tr>
</table>
HTML;
?>

<h3>Debug Info (var_dump)</h3>
<pre>
<?php
var_dump($fullName);
var_dump($age);
var_dump($gpa);
var_dump($isStudent);
var_dump($bio);
?>
</pre>

</body>
</html>

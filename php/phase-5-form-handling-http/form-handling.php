<?php
// File: contact_form.php
// Complete contact form with: validation + session + XSS protection

session_start();

$errors      = [];
$successMsg  = "";
$formData    = [];

// ── Submission count via session ─────────
$_SESSION["form_visits"] = ($_SESSION["form_visits"] ?? 0) + 1;

if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["send"])) {

    // Get inputs
    $name    = trim($_POST["name"]    ?? "");
    $email   = trim($_POST["email"]   ?? "");
    $subject = trim($_POST["subject"] ?? "");
    $message = trim($_POST["message"] ?? "");
    $phone   = trim($_POST["phone"]   ?? "");

    $formData = compact("name","email","subject","message","phone");

    // Validate
    if (empty($name) || strlen($name) < 2)
        $errors["name"] = "Name must be at least 2 characters.";

    if (empty($email) || !filter_var($email, FILTER_VALIDATE_EMAIL))
        $errors["email"] = "Enter a valid email address.";

    if (!empty($phone) && !preg_match("/^[0-9]{11}$/", $phone))
        $errors["phone"] = "Phone must be exactly 11 digits.";

    if (empty($subject) || strlen($subject) < 5)
        $errors["subject"] = "Subject must be at least 5 characters.";

    if (empty($message) || strlen($message) < 20)
        $errors["message"] = "Message must be at least 20 characters.";

    // Success
    if (empty($errors)) {
        // Store last submission in session
        $_SESSION["last_submission"] = [
            "name"    => $name,
            "email"   => $email,
            "time"    => date("Y-m-d H:i:s"),
        ];
        $successMsg = "✅ Message sent! We'll reply to $email soon.";
        $formData   = [];
    }
}

function safe(string $v): string {
    return htmlspecialchars(trim($v), ENT_QUOTES, "UTF-8");
}

function err(array $e, string $f): string {
    return isset($e[$f])
        ? "<span style='color:red;font-size:13px;'>" . safe($e[$f]) . "</span><br>"
        : "";
}
?>

<!DOCTYPE html>
<html lang="en">
<head><title>Contact Us</title></head>
<body>

<h2>Contact Us</h2>
<small>Page visits this session:
  <?= $_SESSION["form_visits"] ?>
</small>

<?php if (isset($_SESSION["last_submission"])): ?>
<p style="color:#555;">
  Last submission by:
  <b><?= safe($_SESSION["last_submission"]["name"]) ?></b>
  at <?= $_SESSION["last_submission"]["time"] ?>
</p>
<?php endif; ?>

<?php if ($successMsg): ?>
  <div style="color:green; border:1px solid green; padding:12px; margin:10px 0;">
    <?= $successMsg ?>
  </div>
<?php endif; ?>

<?php if (!empty($errors)): ?>
  <div style="color:red; border:1px solid red; padding:12px; margin:10px 0;">
    ⚠️ Please fix <?= count($errors) ?> error(s) below.
  </div>
<?php endif; ?>

<form action="contact_form.php" method="POST" novalidate>

  <label>Full Name *</label><br>
  <input type="text" name="name"
    value="<?= safe($formData["name"] ?? "") ?>"><br>
  <?= err($errors, "name") ?><br>

  <label>Email *</label><br>
  <input type="email" name="email"
    value="<?= safe($formData["email"] ?? "") ?>"><br>
  <?= err($errors, "email") ?><br>

  <label>Phone (optional)</label><br>
  <input type="text" name="phone"
    value="<?= safe($formData["phone"] ?? "") ?>"><br>
  <?= err($errors, "phone") ?><br>

  <label>Subject *</label><br>
  <input type="text" name="subject"
    value="<?= safe($formData["subject"] ?? "") ?>"><br>
  <?= err($errors, "subject") ?><br>

  <label>Message * (min 20 chars)</label><br>
  <textarea name="message" rows="5" cols="40"><?=
    safe($formData["message"] ?? "") ?></textarea><br>
  <?= err($errors, "message") ?><br>

  <button type="submit" name="send">Send Message</button>
  <button type="reset">Clear</button>

</form>

<br>
<b>Server Info:</b><br>
IP: <?= htmlspecialchars($_SERVER["REMOTE_ADDR"]) ?> |
Method: <?= $_SERVER["REQUEST_METHOD"] ?> |
Time: <?= date("H:i:s") ?>

</body>
</html>
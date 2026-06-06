<?php
// File: grade_report.php
// Uses: operators, if/else, switch, loops, match

$students = [
    ["name" => "Ali",   "marks" => 88],
    ["name" => "Riya",  "marks" => 72],
    ["name" => "Karim", "marks" => 55],
    ["name" => "Sadia", "marks" => 40],
    ["name" => "Nabil", "marks" => 95],
];

$totalMarks = 0;
$passed     = 0;
$failed     = 0;
?>

<!DOCTYPE html>
<html lang="en">
<head><title>Grade Report</title></head>
<body>
<h2>Student Grade Report</h2>
<table border="1" cellpadding="8">
  <tr>
    <th>#</th>
    <th>Name</th>
    <th>Marks</th>
    <th>Grade</th>
    <th>Status</th>
    <th>Remark</th>
  </tr>

<?php
foreach ($students as $i => $student) {
    $name   = $student['name'];
    $marks  = $student['marks'];

    // Grade using match
    $grade = match(true) {
        $marks >= 90 => "A+",
        $marks >= 80 => "A",
        $marks >= 70 => "B",
        $marks >= 60 => "C",
        $marks >= 50 => "D",
        default      => "F"
    };

    // Status using ternary
    $status = ($marks >= 50) ? "✅ Pass" : "❌ Fail";

    // Remark using if/elseif
    if ($marks >= 90) {
        $remark = "Excellent!";
    } elseif ($marks >= 70) {
        $remark = "Good job!";
    } elseif ($marks >= 50) {
        $remark = "Keep it up.";
    } else {
        $remark = "Needs improvement.";
    }

    // Counters
    $totalMarks += $marks;
    ($marks >= 50) ? $passed++ : $failed++;

    echo "<tr>
        <td>" . ($i + 1) . "</td>
        <td>$name</td>
        <td>$marks</td>
        <td>$grade</td>
        <td>$status</td>
        <td>$remark</td>
    </tr>";
}

$average    = $totalMarks / count($students);
$passRate   = ($passed / count($students)) * 100;
?>

</table>

<h3>Summary</h3>
<p>Total Students : <?= count($students) ?></p>
<p>Average Marks  : <?= number_format($average, 2) ?></p>
<p>Passed         : <?= $passed ?></p>
<p>Failed         : <?= $failed ?></p>
<p>Pass Rate      : <?= number_format($passRate, 1) ?>%</p>

</body>
</html>

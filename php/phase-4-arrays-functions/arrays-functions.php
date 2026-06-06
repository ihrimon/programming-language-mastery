<?php
// File: product_store.php
// Uses: all array functions + all function concepts

// ── Data ──────────────────────────────────
$products = [
    ["id" => 1, "name" => "Laptop",     "price" => 55000, "category" => "Electronics", "stock" => 10],
    ["id" => 2, "name" => "Phone",      "price" => 25000, "category" => "Electronics", "stock" => 0],
    ["id" => 3, "name" => "T-Shirt",    "price" => 800,   "category" => "Clothing",    "stock" => 50],
    ["id" => 4, "name" => "Headphones", "price" => 3500,  "category" => "Electronics", "stock" => 15],
    ["id" => 5, "name" => "Jeans",      "price" => 1500,  "category" => "Clothing",    "stock" => 30],
    ["id" => 6, "name" => "Tablet",     "price" => 35000, "category" => "Electronics", "stock" => 5],
];

// ── Functions ─────────────────────────────

// Apply discount to a price
function applyDiscount(float $price, float $pct = 10): float {
    return round($price - ($price * $pct / 100), 2);
}

// Get grade based on stock
function stockStatus(int $stock): string {
    return match(true) {
        $stock === 0  => "❌ Out of Stock",
        $stock <= 5   => "⚠️ Low Stock",
        $stock <= 20  => "✅ Available",
        default       => "🏬 Plenty in Stock"
    };
}

// Get products by category
function filterByCategory(array $products, string $cat): array {
    return array_values(array_filter(
        $products,
        fn($p) => $p["category"] === $cat
    ));
}

// Get total inventory value
function totalValue(array $products): float {
    return array_sum(
        array_map(fn($p) => $p["price"] * $p["stock"], $products)
    );
}

// Sort products by price
function sortByPrice(array $products, string $dir = "asc"): array {
    usort($products, fn($a, $b) =>
        $dir === "asc"
            ? $a["price"] - $b["price"]
            : $b["price"] - $a["price"]
    );
    return $products;
}

// ── Output ────────────────────────────────
$discountPct    = 10;
$inStock        = array_filter($products, fn($p) => $p["stock"] > 0);
$electronics    = filterByCategory($products, "Electronics");
$sortedByPrice  = sortByPrice($products, "desc");
?>

<!DOCTYPE html>
<html lang="en">
<head><title>Product Store</title></head>
<body>

<h2>All Products (<?= count($products) ?> items)</h2>
<table border="1" cellpadding="8">
  <tr>
    <th>ID</th><th>Name</th><th>Category</th>
    <th>Original Price</th><th>After <?= $discountPct ?>% Off</th>
    <th>Stock</th><th>Status</th>
  </tr>
  <?php foreach ($sortedByPrice as $p): ?>
  <tr>
    <td><?= $p["id"] ?></td>
    <td><?= $p["name"] ?></td>
    <td><?= $p["category"] ?></td>
    <td><?= number_format($p["price"]) ?> BDT</td>
    <td><?= number_format(applyDiscount($p["price"], $discountPct)) ?> BDT</td>
    <td><?= $p["stock"] ?></td>
    <td><?= stockStatus($p["stock"]) ?></td>
  </tr>
  <?php endforeach; ?>
</table>

<h3>Summary</h3>
<p>Total Products       : <?= count($products) ?></p>
<p>In Stock             : <?= count($inStock) ?></p>
<p>Electronics          : <?= count($electronics) ?></p>
<p>Total Inventory Value: <?= number_format(totalValue($products)) ?> BDT</p>

</body>
</html>
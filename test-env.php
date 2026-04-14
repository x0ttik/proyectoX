<?php
require_once __DIR__ . '/config/db.php';
$result = $conn->query("SELECT * FROM productos");
?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Test .env</title>
</head>
<body>
    <h2>Prueba de conexion</h2>
    <p class="ok">Conectado a "<?= $_ENV['DB_NAME'] ?>"</p>
    <table>
        <tr>
            <th>ID</th>
            <th>Nombre</th>
            <th>Precio</th>
        </tr>
        <?php while ($row = $result->fetch_assoc()): ?>
            <tr>
                <td><?= $row['id'] ?></td>
                <td><?= $row['nombre'] ?></td>
                <td><?= $row['precio'] ?></td>
            </tr>
        <?php endwhile; ?>
    </table>
</body>
</html>

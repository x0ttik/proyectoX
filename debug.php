<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

echo "<pre>";

// 1. Rutas
echo "Raíz del proyecto:\n";
echo __DIR__ . "\n\n";

// 2. ¿Existe vendor/autoload.php?
$autoload = __DIR__ . '/vendor/autoload.php';
echo "vendor/autoload.php existe: " . (file_exists($autoload) ? "SI" : "NO") . "\n";

// 3. ¿Existe .env?
$env = __DIR__ . '/.env';
echo ".env existe: " . (file_exists($env) ? "SI" : "NO") . "\n\n";

// 4. Cargar dotenv
require_once $autoload;
$dotenv = Dotenv\Dotenv::createImmutable(__DIR__);
$dotenv->load();

// 5. Variables cargadas
echo "DB_HOST: " . getenv('DB_HOST') . "\n";
echo "DB_USER: " . getenv('DB_USER') . "\n";
echo "DB_NAME: " . getenv('DB_NAME') . "\n\n";

// 6. Conexión
$conn = new mysqli(getenv('DB_HOST'), getenv('DB_USER'), getenv('DB_PASS'), getenv('DB_NAME'));
echo "Conexión: " . ($conn->connect_error ? "ERROR — " . $conn->connect_error : "OK") . "\n";

echo shell_exec("find " . dirname(__DIR__) . " -name '.env' -o -name 'autoload.php' 2>/dev/null");
echo "</pre>";
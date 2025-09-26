<?php
$username = 'miguelde_modulo4';
$password = 'modulo4';
$dbname = 'miguelde_modulo4';
$host = 'localhost';
$sql = "mysql:host=$host;dbname=$dbname;";
$dsn_Options = [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION];

try {
    $conn = new PDO($sql, $username, $password, $dsn_Options);
    echo "Conectado com sucesso<br>";
} catch (PDOException $error) {
    echo 'Erro na conexão: ' . $error->getMessage();
    exit;
}

// MAC a ser desativado
$mac = 'CC:50:E3:05:19:BB';

// Prepara o UPDATE para desativar (ativo = 0)
$stmt = $conn->prepare("UPDATE mackaua SET ativo = 0 WHERE idmackaua = :mac");
$stmt->bindParam(':mac', $mac);

if ($stmt->execute()) {
    if ($stmt->rowCount() > 0) {
        echo "Placa $mac desativada com sucesso.";
    } else {
        echo "Nenhuma placa encontrada com o MAC $mac.";
    }
} else {
    echo "Erro ao desativar/ativar placa $mac.";
}
?>
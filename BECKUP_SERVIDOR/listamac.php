<?php
$username = 'miguelde_modulo4';
$password = 'modulo4';
$dbname = 'miguelde_modulo4';
$host = 'localhost';

try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    echo '<!DOCTYPE html>
    <html>
    <head>
        <meta charset="UTF-8">
        <title>Lista de MACs</title>
    </head>
    <body>
    <main>
        <table border="1">
            <tr>
                <th>ID MAC</th>
                <th>Nome</th>
                <th>Contador</th>
                <th>Ativo</th>
            </tr>';

    $sql = 'SELECT mac.idmac as "IDMAC", mac.nome as "NOME", mac.contador as "CONTADOR", mac.ativo as "ATIVO" FROM mac';
    $data = $conn->query($sql);

    foreach ($data as $row) {
        echo '<tr>';
        echo '<td>' . htmlspecialchars($row['IDMAC']) . '</td>';
        echo '<td>' . htmlspecialchars($row['NOME']) . '</td>';
        echo '<td>' . htmlspecialchars($row['CONTADOR']) . '</td>';
        echo '<td>' . htmlspecialchars($row['ATIVO']) . '</td>';
        echo '</tr>';
    }

    echo '</table>
    </main>
    </body>
    </html>';

} catch (PDOException $e) {
    echo 'ERROR: ' . $e->getMessage();
}
?>

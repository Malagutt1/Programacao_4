<!DOCTYPE html>
<html lang="pt-BR">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
 <head>
    <title>Leitura Placas</title>
<link rel="stylesheet" href="https://www.modulo4.migueldebarba.com.br/kaua/style.css" type="text/css" />
</head>

<?php
$username = 'miguelde_modulo4';
$password = 'modulo4';
$dbname = 'miguelde_modulo4'; 
$host = 'localhost';

try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); ?>

<body>
<main>
    <div class= 'container'>
        <h2>Página Kauã</h2>
        <h3>Leitura ESP8266</h2>
    </div>

    <div class = 'container'>
    <table border="1">
        <tr>
            <th>IDLEITURA</th>
            <th>DATA</th>
            <th>HORA</th>
            <th>UMIDADE</th>
            <th>TEMPERATURA</th>
            <th>UMIDADE</th>
        </tr> 
        <?php
    $sql = 'SELECT leiturakaua.idleiturakaua as "IDLEITURA", leiturakaua.dataleitura as "DATA", leiturakaua.horaleitura as "HORA", leiturakaua.umidade as "UMIDADE", leiturakaua.temperatura as "TEMPERATURA" FROM leiturakaua';
    $data = $conn->query($sql);

    foreach ($data as $row) {
        echo '<tr>';
        echo '<td>' . htmlspecialchars($row['IDLEITURA']) . '</td>';
        echo '<td>' . htmlspecialchars($row['DATA']) . '</td>';
        echo '<td>' . htmlspecialchars($row['HORA']) . '</td>';
        echo '<td>' . htmlspecialchars($row['UMIDADE']) . '</td>';
        echo '<td>' . htmlspecialchars($row['TEMPERATURA']) . '</td>';
        echo '<td>' . htmlspecialchars($row['UMIDADE']) . '</td>';
        echo '</tr>';
    }

    echo '</table> </div>
    </main>
    </body>
    </html>';

} catch (PDOException $e) {
    echo 'ERROR: ' . $e->getMessage();
}
?>

<!DOCTYPE html>
<html lang="pt-BR">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
 <head>
    <title>LISTA MACs</title>
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
        <h3>Listagem de placas MACs</h2>
    </div>

    <div class = 'container'>
    <table border="1">
        <tr>
            <th>ID MAC</th>
            <th>Nome</th>
            <th>Contador</th>
        </tr> 
<?php
    $sql = 'SELECT mackaua.idmackaua as "IDMAC", mackaua.nome as "NOME", mackaua.contador as "CONTADOR" FROM mackaua';
    $data = $conn->query($sql);

    foreach ($data as $row) {
        echo '<tr>';
        echo '<td>' . htmlspecialchars($row['IDMAC']) . '</td>';
        echo '<td>' . htmlspecialchars($row['NOME']) . '</td>';
        echo '<td>' . htmlspecialchars($row['CONTADOR']) . '</td>';
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

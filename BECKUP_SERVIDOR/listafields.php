<?php
include 'conectabanco.php';
$charset = 'utf8mb4';

// Cria a conexão PDO
try {

    // Nome da tabela que você quer inspecionar
    $tabela = 'leiturakaua';

    // Executa a consulta para obter informações das colunas
    $stmt = $conn->query("DESCRIBE `$tabela`");

echo' Atributos da tabela '.$tabela.'<br><br>';
echo'
<table border=2>
<tr>
<th>Nome</th>
<th>Tipo</th>
<th>Null</th>
<th>Chave</th>
<th>Padrão</th>
<th>Extra</th>

</tr>';
    while ($coluna = $stmt->fetch(PDO::FETCH_ASSOC)) {
        echo '<tr><td>' . $coluna['Field'] . '</td>';
        echo '<td>'  . $coluna['Type'] . '</td>';
        echo '<td>' . $coluna['Null'] . '</td>';
        echo '<td>' . $coluna['Key'] . '</td>';
        echo '<td>' . $coluna['Default'] . '</td>';
        echo '<td>' . $coluna['Extra'] . '</td></tr>';
    }echo'</table>';

} catch (PDOException $e) {
    echo "Erro na conexão: " . $e->getMessage();
}
?>

<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Placas Cadastradas</title>
    <link rel="stylesheet" href="https://www.modulo4.migueldebarba.com.br/kaua/style.css" type="text/css" />
</head>
<body>
<main>
    <div class="container">
        <h2>Placas Cadastradas</h2>
    </div>
    <div class="container">
        <table border="1">
            <tr>
                <th>ID da Placa</th>
                <th>Nome</th>
                <th>Contador</th>
                <th>Ativo</th>
            </tr>
            <?php
            $username = 'miguelde_modulo4';
            $password = 'modulo4';
            $dbname = 'miguelde_modulo4';
            $host = 'localhost';

            try {
                $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
                $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                $sql = 'SELECT idmackaua, nome, contador, ativo FROM mackaua';
                $data = $conn->query($sql);

                foreach ($data as $row) {
                    echo '<tr>';
                    echo '<td>' . htmlspecialchars($row['idmackaua']) . '</td>';
                    echo '<td>' . htmlspecialchars($row['nome']) . '</td>';
                    echo '<td>' . htmlspecialchars($row['contador']) . '</td>';
                    echo '<td>' . ($row['ativo'] ? 'Sim' : 'Não') . '</td>';
                    echo '</tr>';
                }
            } catch (PDOException $e) {
                echo '<tr><td colspan="4">Erro: ' . htmlspecialchars($e->getMessage()) . '</td></tr>';
            }
            ?>
        </table>
    </div>
</main>
</body>
</html>
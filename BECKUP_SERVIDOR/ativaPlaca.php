<?php
$username = 'miguelde_modulo4';
$password = 'modulo4';
$dbname   = 'miguelde_modulo4';
$host     = 'localhost';
$sql      = "mysql:host=$host;dbname=$dbname;charset=utf8mb4";
$dsn_Options = [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION];

try {
    $conn = new PDO($sql, $username, $password, $dsn_Options);
} catch (PDOException $error) {
    die("Erro na conexão: " . $error->getMessage());
}

// Processa ativar/desativar
if (isset($_POST['acao'], $_POST['mac'])) {
    $mac = $_POST['mac'];
    $acao = $_POST['acao'] === 'ativar' ? 1 : 0;

    $stmt = $conn->prepare("UPDATE mackaua SET ativo = :ativo WHERE idmackaua = :mac");
    $stmt->execute([':ativo' => $acao, ':mac' => $mac]);

    if ($stmt->rowCount() > 0) {
        $msg = "Placa $mac " . ($acao ? "ativada" : "desativada") . " com sucesso!";
    } else {
        $msg = "Nenhuma alteração feita.";
    }
}

// Buscar todas as placas
$stmt = $conn->query("SELECT idmackaua, nome, ativo FROM mackaua");
$placas = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Gerenciar Placas</title>
    <link rel="stylesheet" href="https://www.modulo4.migueldebarba.com.br/kaua/style.css" type="text/css" />
</head>
<body>
    <div class="container">
        <h2>Lista de Placas</h2>
        <?php if (!empty($msg)): ?>
            <h3><?= htmlspecialchars($msg) ?></h3>
        <?php endif; ?>

        <table>
            <tr>
                <th>MAC</th>
                <th>Nome</th>
                <th>Status</th>
                <th>Ação</th>
            </tr>
            <?php foreach ($placas as $placa): ?>
            <tr>
                <td><?= htmlspecialchars($placa['idmackaua']) ?></td>
                <td><?= htmlspecialchars($placa['nome']) ?></td>
                <td>
                    <?= $placa['ativo'] ? 'Ativo' : 'Inativo' ?>
                </td>
                <td>
                    <form method="post" style="display:inline;">
                        <input type="hidden" name="mac" value="<?= htmlspecialchars($placa['idmackaua']) ?>">
                        <?php if ($placa['ativo']): ?>
                            <button type="submit" name="acao" value="desativar">Desativar</button>
                        <?php else: ?>
                            <button type="submit" name="acao" value="ativar">Ativar</button>
                        <?php endif; ?>
                    </form>
                </td>
            </tr>
            <?php endforeach; ?>
        </table>
    </div>
</body>
</html>

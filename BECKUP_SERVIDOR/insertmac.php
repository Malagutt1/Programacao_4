<?php
$username='miguelde_modulo4';
$password='modulo4';
$dbname='miguelde_modulo4';
$host='localhost';
$sql = "mysql:host=$host;dbname=$dbname;";
$dsn_Options = [PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION];
try { 
  $my_Db_Connection = new PDO($sql, $username, $password, $dsn_Options);
  echo "Connected successfully<br>"; // Mensagem se a conexão der certo
} catch (PDOException $error) {
  echo 'Connection error: ' . $error->getMessage(); // Mensagem de erro se falhar
}



// Insere os dados na lista "mac"
// Recebe os dados do formulário via POST
$idmackaua = $_POST['idmackaua'];
$nome = $_POST['nome'];

// Prepara o comando para inserir na tabela 'mackaua'
$my_Insert_Statement = $my_Db_Connection->prepare("INSERT INTO mackaua (idmackaua, nome) VALUES (:idmackaua, :nome)");
$my_Insert_Statement->bindParam(':idmackaua', $idmackaua);
$my_Insert_Statement->bindParam(':nome', $nome);


if ($my_Insert_Statement->execute()) {
  print "Placa inserida com sucesso"; // Mensagem se inserção for bem-sucedida
} 
else {
  echo "Não foi possivel adicionar as placas a DataBase"; // Mensagem se falhar
}
?>

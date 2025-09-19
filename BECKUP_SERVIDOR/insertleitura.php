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

// Recebe os dados do formulario
$mc_idkaua = $_POST['idmac'];
$d_leitura   = $_POST['dataleitura'];
$h_leitura   = $_POST['horaleitura'];
$umd   = $_POST['umidade'];
$temp   = $_POST['temperatura'];


// Insere os dados na lista "mac"
$my_Insert_Statement = $my_Db_Connection->prepare("INSERT INTO leiturakaua (mackaua_idmackaua, dataleitura, horaleitura, umidade, temperatura) 
VALUES (:mackaua_idmackaua, :d_leitura, :h_leitura, :umd, :temp)");

// recebe os dados para a variavel
$my_Insert_Statement->bindParam(':mackaua_idmackaua', $mc_idkaua);
$my_Insert_Statement->bindParam(':d_leitura', $d_leitura);
$my_Insert_Statement->bindParam(':h_leitura', $h_leitura);
$my_Insert_Statement->bindParam(':umd', $umd);
$my_Insert_Statement->bindParam(':temp', $temp);

if ($my_Insert_Statement->execute()) {
  print "Leitura <b>inserida com sucesso</b>"; // Mensagem se inserção for bem-sucedida
} 
else {
  echo "<b>Não foi possivel</b> inserir alguma leitura a DataBase"; // Mensagem se falhar
}
?>

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

  if (($_POST['from']!='esp8266')){
    $dataleitura = $_POST['dataleitura'];
    $horaleitura = $_POST['horaleitura'];

  }else{
    $h = "3"; //HORAS DO FUSO ((BRASÃLIA = -3) COLOCA-SE SEM O SINAL -).
    $hm = $h * 60;
    $ms = $hm * 60;
    //COLOCA-SE O SINAL DO FUSO ((BRASÃLIA = -3) SINAL -) ANTES DO ($ms). DATA
    $dataleitura = gmdate("Y/m/d", time()-($ms)); 
    $horaleitura = gmdate("H:i:s", time()-($ms));     
}

} catch (PDOException $error) {
  echo 'Connection error: ' . $error->getMessage(); // Mensagem de erro se falhar
}

// Recebe os dados do formulario
$mc_idkaua = $_POST['idmac'];

$umd   = $_POST['umidade'];
$temp   = $_POST['temperatura'];


// Insere os dados na lista "mac"
$my_Insert_Statement = $my_Db_Connection->prepare("INSERT INTO leiturakaua (mackaua_idmackaua, dataleitura, horaleitura, umidade, temperatura) 
VALUES (:mackaua_idmackaua, :dataleitura, :horaleitura, :umd, :temp)");

// recebe os dados para a variavel
$my_Insert_Statement->bindParam(':mackaua_idmackaua', $mc_idkaua);
$my_Insert_Statement->bindParam(':dataleitura', $dataleitura);
$my_Insert_Statement->bindParam(':horaleitura', $horaleitura);
$my_Insert_Statement->bindParam(':umd', $umd);
$my_Insert_Statement->bindParam(':temp', $temp);

if ($my_Insert_Statement->execute()) {
  print "Leitura <b>inserida com sucesso</b>"; // Mensagem se inserção for bem-sucedida
} 
else {
  echo "<b>Não foi possivel</b> inserir alguma leitura a DataBase"; // Mensagem se falhar
}
?>

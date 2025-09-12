<?php
$username='miguelde_modulo4';
$password='modulo4';
$dbname='miguelde_modulo4';
$host='localhost';
try {
 $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
 $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
 $sql='SELECT * FROM leitura';
 $data = $conn->query($sql);
 foreach($data as $row) {
 print_r($row);
 }
} catch(PDOException $e) {
 echo 'ERROR: ' . $e->getMessage();
}
 ?>
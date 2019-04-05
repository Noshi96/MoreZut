<?php

echo'<link rel="stylesheet" href="style.css" type="text/css">';

echo'<div id="log">
 <form method="POST" action="index.php?loguj=true">
		Login: <input type="text" name="login" /><br>
		Hasło: <input type="password" name="haslo" /><br>
		<center>
		<input type="submit" name="Zaloguj" value="Zaloguj"> 
		
		</form>
		</div>
		';
		

 if (isset($_POST['Zaloguj'])) {
	 
	 $login1=$_POST['login'];
	 $haslo1=$_POST['haslo'];
	 
	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM uzytkownicy");
	
	while ($rekord = $stmt->fetch()){
		if($rekord['login']==$login1 && $rekord['haslo']==$haslo1){
			echo 'Dobrze';
			
			$id_log=$rekord['id'];
			
			header('Location: index.php?hello=true&log='.$id_log.'');
			
			break;
		}
	}
	
 }


?>
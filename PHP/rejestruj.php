<?php

$spr=0;
$suma=0;


$imieErr = $loginErr = $hasloErr = $haslo1Err = $nazwiskoErr = "";
$imie = $nazwisko = $haslo = $haslo1 =$login = "";

$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');


if ($_SERVER["REQUEST_METHOD"] == "POST") {
  if (empty($_POST["imie"])) {
    $imieErr = "*Imie jest wymagane<br>";
	$spr=1;
  } else {
    $imie = test_input($_POST["imie"]);
	$spr=2;
	$suma++;
  }
  	
  
    
  if (empty($_POST["nazwisko"])) {
    $nazwiskoErr = "*Nazwisko jest wymagane<br>";
	$spr=1;
  } else {
    $nazwisko = test_input($_POST["nazwisko"]);
	$spr=2;
	$suma++;
  }
  
  
  $stmt = $pdo->query ("SELECT * FROM uzytkownicy");
	
	while ($rekord = $stmt->fetch()){
		if($rekord['login']==$_POST["login"]){
			$spr=3;
			break;
		}else{
			$spr=2;
		}
	}

  if (empty($_POST["login"])) {
    $loginErr = "*Login jest wymagane<br>";
	$spr=1;
  }else if(strlen($_POST["login"])<6 ){
	  $loginErr="*Login ma mieć więcej niż 5 znaków<br>";
	  $spr=1;
  }else if($spr==3){
	  $loginErr="*Taki login już istnieje w bazie<br>";
	  $spr=1;
  } 
  else {
    $login = test_input($_POST["login"]);
	$spr=2;
	$suma++;
  }

  
  if (empty($_POST["haslo"])) {
    $hasloErr = "*haslo jest wymagana<br>";
	$spr=1;
  } else {
    $haslo = test_input($_POST["haslo"]);
	$spr=2;
	$suma++;
  }
  
   if (empty($_POST["haslo1"])) {
    $haslo1Err = "*haslo jest wymagany<br>";
	$spr=1;
  } else if($_POST['haslo']!=$_POST['haslo1']){
	  $haslo1Err = "*Podane hasła są różne <br>";
	  $spr=1;
  }else if(strlen($_POST["haslo"])<6 || strlen($_POST["haslo1"])<6){
	  $haslo1Err="*Hasło ma mieć więcej niż 5 znaków<br>";
	  $spr=1;
  }
	  else{
    $haslo1 = test_input($_POST["haslo1"]);
	$spr=2;
	$suma++;
  }
  
  
  

  
  
 
 if($spr==2 && $suma==5){
	 
	 echo 'Zarejestrowano użytkownika '.$_POST['imie'].' '.$_POST['nazwisko'].'';
		
	 $pdo->beginTransaction();
	 $dodaj = "INSERT INTO uzytkownicy (id, login,haslo, uprawnienia, imie, nazwisko) VALUES ('','$login', '$haslo', '0', '$imie', '$nazwisko')";
	 $pdo->exec($dodaj);
	 $pdo->commit();
	 $pdo=null;
	 
 
 }

}

function test_input($data) {
  $data = trim($data);			//przyciecia
  $data = stripslashes($data); //backslash
  $data = htmlspecialchars($data);
  return $data;
}



?>

<?php
if($spr!=2 || $suma!=5){


echo '
<link rel="stylesheet" href="style.css" type="text/css">

<div style="position:absolute;">
	<p id=tekst_lewo>Login: </p>
<p id=tekst_lewo>Hasło:  </p>
<span id=tekst_lewo>Powtórz hasło:
    </span><p>
<p id=tekst_lewo>Imię:  </p>
<p id=tekst_lewo>Nazwisko:  </p>


	</div>
	';
	
	echo'
	<div style="text-align:center;margin-top:-2px;">
	
	<form method="POST" action="index.php?rejestruj=true"><p>  
<input type="text" name="login" /> <span id="error">';echo $loginErr;  echo '</span></p>';
echo '
<p><input type="password" name="haslo" /> <span id=error>';echo $hasloErr;  echo '</span></p>';
echo '
<p><input type="password" name="haslo1" /> <span id=error>';echo $haslo1Err;  echo '</span></p>';

echo '  
<p> <input type="text" name="imie" /><span id="error">';echo $imieErr;  echo '</span></p>';
echo ' 
<p> <input type="text" name="nazwisko" /> <span id="error"> ';echo $nazwiskoErr;  echo '</span></p>';

echo'
<p><input type="submit" name="submit" value="Zarejestruj"> </p>

</form>

</div>



';
}

?>
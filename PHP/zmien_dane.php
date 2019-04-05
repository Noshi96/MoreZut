<?php

$spr=0;
$suma=0;
$id_user=0;

if(isset($_GET['id2'])){
$id_user=$_GET['id2'];
}

$imieErr = $loginErr = $hasloErr = $haslo1Err = $nazwiskoErr = "";
$imie = $nazwisko = $haslo = $haslo1 =$login = "";

$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
$stmt1 = $pdo->query ("SELECT * FROM uzytkownicy WHERE id='$id_user'");


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
  
  
  
if(isset($_POST['odrzuc1'])){
	header('Location: index.php?hello=true');
}
  
  
 
 if($spr==2 && $suma==5 && isset($_POST['potwierdz1'])){
	 
	 echo 'Zmieniono użytkownika na '.$_POST['imie'].' '.$_POST['nazwisko'].' z loginem '.$_POST['login'].'';
	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	
	 $pdo->beginTransaction(); 
	 $dodaj = "UPDATE uzytkownicy
		SET login='$login', haslo='$haslo', imie='$imie', nazwisko='$nazwisko'
		WHERE id='$id_user'";
	 
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

while ($rekord = $stmt1->fetch()){

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
	
	<form method="POST" action="index.php?zmiendane=true&id2='.$rekord["id"].'"><p>  
<input type="text" name="login" value="'.$rekord['login'].'" /> <span id="error">';echo $loginErr;  echo '</span></p>';
echo '
<p><input type="password" name="haslo" value="'.$rekord['haslo'].'" /> <span id=error>';echo $hasloErr;  echo '</span></p>';
echo '
<p><input type="text" name="haslo1" value="'.$rekord['haslo'].'" /> <span id=error>';echo $haslo1Err;  echo '</span></p>';

echo '  
<p> <input type="text" name="imie" value="'.$rekord['imie'].'" /><span id="error">';echo $imieErr;  echo '</span></p>';
echo ' 
<p> <input type="text" name="nazwisko" value="'.$rekord['nazwisko'].'" /> <span id="error"> ';echo $nazwiskoErr;  echo '</span></p>';

echo'
<center>
<div style="display:inline">
<input type="submit" name="potwierdz1" value="Potwierdź zmiany"> 
</div>
<div style="display:inline">
<input type="submit" name="odrzuc1" value="Odrzuć zmiany"> 
</div>
</center>

</form>

</div>



';
}

}




?>
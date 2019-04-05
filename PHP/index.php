<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta http-equiv="Content-type" content="text/html; charset=utf-8">
 <meta name="Description" content=" wszystko co musisz wiedziec  ">
 <meta name="Author" content=" Paweł ">

<title>Strona główna</title>
<link rel="stylesheet" href="style.css" type="text/css">
</head>

<body>
<?php 

session_start();
$licznik=0;

$jakie_prawa=0;

$logowanie=0;

function strglowna(){
	echo 'Witaj &nbsp;';
	if(isset($_GET['log'])){
	
	
	$log=$_GET['log'];
	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM uzytkownicy WHERE id='$log'");
	
	while ($rekord = $stmt->fetch()){
		echo $rekord['imie'];
		
	}
	$pdo=null;
	$logowanie=1;
}

}

function prawa(){
	$prawo=0;
	
	if(isset($_GET['log'])){
	$log=$_GET['log'];
	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM uzytkownicy WHERE id='$log'");
	
	while ($rekord = $stmt->fetch()){
		$prawo=$rekord['uprawnienia'];
		$_SESSION["prawa"]=$rekord['uprawnienia'];
		$_SESSION["id_user"]=$log;
	}
	$pdo=null;
	$logowanie=1;
}

	return $prawo;
}

?>

<div id="box">
<div id="naglowek">LOGO</div>
<div id="menu">



<ul id="dolewej">

<?php

if(isset($_GET['formu']) || isset($_GET['sesja']) || isset($_GET['page']) || isset($_GET['strona']) || isset($_GET['usun']) || isset($_GET['hello']) || isset($_GET['zmiendane']) || isset($_GET['zpd']) || isset($_GET['usunuser'])){
	$logowanie=1;
}




prawa();
//echo $_SESSION["prawa"];


if($logowanie==0 || $_SESSION["prawa"]==0){
	echo'
<li id="news"><a href="index.php">Strona główna</a></li>
';
}
else if($_SESSION["prawa"]==1){
	echo '
	<li id="news"><a href="index.php?hello=true">Strona główna</a></li>
<li id="news"><a href="index.php?formu=true">Formularz</a></li>
<li id="news"><a href="index.php?sesja=true">Zawartość sesji</a></li>
<li id="news"><a href="index.php?page=1">Baza pracowników</a></li><br>
<li id="news"><a href="index.php?zmiendane=true&id2='.$_SESSION["id_user"].'">Zmień dane</a></li>
';
}
else if($_SESSION["prawa"]==2){
	echo '
	<li id="news"><a href="index.php?hello=true">Strona główna</a></li>
<li id="news"><a href="index.php?formu=true">Formularz</a></li>
<li id="news"><a href="index.php?sesja=true">Zawartość sesji</a></li>
<li id="news"><a href="index.php?page=1">Baza pracowników</a></li>
<li id="news"><a href="index.php?strona=1">Edycja pracownika</a></li><br>
<li id="news"><a href="index.php?zmiendane=true&id2='.$_SESSION["id_user"].'">Zmień dane</a></li>
';
}
else if($_SESSION["prawa"]==3){
	echo '
	<li id="news"><a href="index.php?hello=true">Strona główna</a></li>
<li id="news"><a href="index.php?formu=true">Formularz</a></li>
<li id="news"><a href="index.php?sesja=true">Zawartość sesji</a></li>
<li id="news"><a href="index.php?page=1">Baza pracowników</a></li>
<li id="news"><a href="index.php?strona=1">Edycja pracownika</a></li>
<li id="news"><a href="index.php?usun=1">Usunięcie pracownika</a></li><br>
<li id="news"><a href="index.php?zmiendane=true&id2='.$_SESSION["id_user"].'">Zmień dane</a></li>
';
}
else if($_SESSION["prawa"]==4){
	
	
	echo '
	<li id="news"><a href="index.php?hello=true">Strona główna</a></li>
<li id="news"><a href="index.php?formu=true">Formularz</a></li>
<li id="news"><a href="index.php?sesja=true">Zawartość sesji</a></li>
<li id="news"><a href="index.php?page=1">Baza pracowników</a></li>
<li id="news"><a href="index.php?strona=1">Edycja pracownika</a></li>
<li id="news"><a href="index.php?usun=1">Usunięcie pracownika</a></li><br>
<li id="news"><a href="index.php?zmiendane=true&id2='.$_SESSION["id_user"].'">Zmień dane</a></li>
<li id="news"><a href="index.php?zpd=1">Zmień poziom dostępu</a></li>
<li id="news"><a href="index.php?usunuser=1">Usuń użytkownika</a></li>
';
}
?>

</ul>

</div>
<div id="tresc">




<?php


//Mozna zrobić na caseach żeby nie było tyle ifów



if(isset($_GET['hello'])){
	strglowna();
	
	$logowanie=1;
}

else if(isset($_GET['formu'])){
	$logowanie=1;
	require 'form.php';
}

else if(isset($_GET['sesja'])){
	$logowanie=1;
	require 'sesja.php';
}
else if(isset($_GET['page'])){
	$logowanie=1;
	require 'baza.php';
}
else if(isset($_GET['strona'])){
	$logowanie=1;
	require 'baza_edycja.php';
}
else if(isset($_GET['usun'])){
	$logowanie=1;
	require 'baza_usun.php';
}

else if(isset($_GET['loguj'])){
	require 'logowanie.php';
}

else if(isset($_GET['rejestruj'])){
	require 'rejestruj.php';
}
else if (isset($_GET['zmiendane'])){	
	require 'zmien_dane.php';
}
else if (isset($_GET['zpd'])){	
	require 'zmien_poziom_dostepu.php';
	}
else if (isset($_GET['usunuser'])){	
	require 'usun_user.php';
}else{
	
	echo '
	<div id=str_g>
	Strona główna
	</div>
	';
	
	
	
}



?>



</div>


<div id="menu2">
<form action="index.php" method="get"><button type="submit" name="reset">reset</button></form>
<?php
if(isset($_GET["reset"]))
{
    session_destroy();
    session_start();
}


if(isset($_GET['page'])){
	
	echo'
	<link rel="stylesheet" href="style.css" type="text/css">
	<div id="menu3">
	<form method="POST" action="index.php?page=1">
	<input type="text" name="szukaj" /></br>
	<input type="submit" name="submit" value="Szukaj">
	
	</form>
	</div>
	';
	echo $cur_page;
}else if(isset($_GET['strona'])){
	echo'
	<link rel="stylesheet" href="style.css" type="text/css">
	<div id="menu3">
	<form method="POST" action="index.php?strona=1">
	<input type="text" name="szukaj1" /></br>
	<input type="submit" name="submit" value="Szukaj">
	
	</form>
	</div>
	';
}else if(isset($_GET['usun'])){
	echo'
	<link rel="stylesheet" href="style.css" type="text/css">
	<div id="menu3">
	<form method="POST" action="index.php?usun=1">
	<input type="text" name="szukaj1" /></br>
	<input type="submit" name="submit" value="Szukaj">
	
	</form>
	</div>
	';

}else if(isset($_GET['zpd'])){
	echo'
	<link rel="stylesheet" href="style.css" type="text/css">
	<div id="menu3">
	<form method="POST" action="index.php?zpd=1">
	<input type="text" name="szukaj3" /></br>
	<input type="submit" name="submit" value="Szukaj">
	
	</form>
	</div>
	';
}
else if(isset($_GET['usunuser'])){
	echo'
	<link rel="stylesheet" href="style.css" type="text/css">
	<div id="menu3">
	<form method="POST" action="index.php?usunuser=1">
	<input type="text" name="szukaj1" /></br>
	<input type="submit" name="submit" value="Szukaj">
	
	</form>
	</div>
	';
}
else{

}

echo '
<ul style="list-style-type:circle">
';
if($logowanie==0){
	echo'
  <li><u><a href="index.php?loguj=true">Zaloguj</a></u></li><br>
  ';
}else if($logowanie==1){
	echo'
	<li><u><a href="index.php">Wyloguj</a></u></li><br>
	';
}
echo '
  <li><u><a href="index.php?rejestruj=true">Rejestracja</a></u></li>
</ul>
';




?>

 

</div>
<div id="stopka">

&copy; Wszelkie prawa zastrzeżone 

<?php
	if(isset($_SESSION['licznik']) && $_SESSION['licznik'] > 0){
		echo 'Ilość dodanych pracowników: '.$_SESSION['licznik'];
	}
	//input php value post imie w formularzu
?>

</div>
</div>









</body>

</html>
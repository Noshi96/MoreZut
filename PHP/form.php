<?php
$spr=0;
$suma=0;
$sesja=0;
$imieErr = $emailErr = $genderErr = $nazwisko_panienskieErr =$kod_pocztowyErr = $nazwiskoErr = "";
$imie = $email = $gender = $nazwisko =$kod_pocztowy = $nazwisko_panienskie = "";


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
  
  if (empty($_POST["email"])) {
    $emailErr = "*Email jest wymagany<br>";
	$spr=1;
  } else {
    $email = test_input($_POST["email"]);
	$spr=2;
	$suma++;
	if (!preg_match("/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,})$/i",$email)) {
      $emailErr = "*Zły email<br>"; 
	  $spr=1;
	  $suma--;
    }
	
  }
    
  if (empty($_POST["nazwisko"])) {
    $nazwiskoErr = "*Nazwisko jest wymagane<br>";
	$spr=1;
  } else {
    $nazwisko = test_input($_POST["nazwisko"]);
	$spr=2;
	$suma++;
  }

  if (empty($_POST["nazwisko_panienskie"])) {
    $nazwisko_panienskieErr = "*Nazwisko panieńskie jest wymagane<br>";
	$spr=1;
  } else {
    $nazwisko_panienskie = test_input($_POST["nazwisko_panienskie"]);
	$spr=2;
	$suma++;
  }

  
  if (empty($_POST["gender"])) {
    $genderErr = "*Płeć jest wymagana<br>";
	$spr=1;
  } else {
    $gender = test_input($_POST["gender"]);
	$spr=2;
	$suma++;
  }
  
   if (empty($_POST["kod_pocztowy"])) {
    $kod_pocztowyErr = "*Kod pocztowy jest wymagany<br>";
	$spr=1;
  } else {
    $kod_pocztowy = test_input($_POST["kod_pocztowy"]);
	$spr=2;
	$suma++;
	if (!preg_match("/^([0-9]{2})(-[0-9]{3})?$/i",$kod_pocztowy)) {
      $kod_pocztowyErr = "*Zły adres<br>"; 
	  $spr=1;
	  $suma--;
    }
  }
  
  
  
 
 if($spr==2 && $suma==6){
	 
		echo 'Imię '.$_POST['imie']. '</br>';
		echo 'Nazwisko '.$_POST['nazwisko']. '</br>';
		echo 'Nazwisko_panienskie '.$_POST['nazwisko_panienskie']. '</br>';
		echo 'Płeć '.$_POST['gender']. '</br>';
		echo 'Email '.$_POST['email']. '</br>';
		echo 'Kod_pocztowy '.$_POST['kod_pocztowy']. '</br>';
		
	 if(!isset($_SESSION['licznik'])){
		 $_SESSION['licznik']=0;
		 }
		 $_SESSION['licznik']++;
	 $_SESSION['imie'][$_SESSION['licznik']-1] = $_POST['imie'];
	 $_SESSION['nazwisko'][$_SESSION['licznik']-1] = $_POST['nazwisko'];
	 $_SESSION['nazwisko_panienskie'][$_SESSION['licznik']-1] = $_POST['nazwisko_panienskie'];
	 $_SESSION['email'][$_SESSION['licznik']-1] = $_POST['email'];
	 $_SESSION['gender'][$_SESSION['licznik']-1] = $_POST['gender'];
	 $_SESSION['kod_pocztowy'][$_SESSION['licznik']-1] = $_POST['kod_pocztowy'];
	 
	 
	 /*
	 $polaczenie = mysql_connect('localhost','root') or die ("Brak polączenia: ".mysql_error());
	 if($polaczenie){
	 $baza = mysql_select_db('zadanie',$polaczenie) or exit ("Nie wybrano bazy, bląd: ".mysql_error());
	 
	 if($baza){
			$dane = "INSERT INTO pracownik (id, imie, nazwisko, nazwisko_panienskie, email, gender, kod_pocztowy) VALUES ('$licznik','$imie', '$nazwisko', '$nazwisko_panienskie', '$email', '$gender', '$kod_pocztowy')";
			$zapisano = mysql_query($dane);
				if($zapisano){
					echo 'Dodano pracownika do bazy danych';
				}
				else{
					echo "Nie dodane pracownika do bazy danych".mysql_error();
				}
	 }
	 else{
		 echo "Błąd".mysql_error();
	 }
	 mysql_close($polaczenie);
	 
 }else{
	 echo "blad".mysql_error();
 }
 
 
 */
	 $pdo->beginTransaction();
	 $dodaj = "INSERT INTO pracownik (id, imie, nazwisko, nazwisko_panienskie, email, gender, kod_pocztowy) VALUES ('','$imie', '$nazwisko', '$nazwisko_panienskie', '$email', '$gender', '$kod_pocztowy')";
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
if($spr!=2 || $suma!=6){
echo '
<link rel="stylesheet" href="style.css" type="text/css">

<div style="position:absolute;">
	<p id=tekst_lewo>Imię: </p>
<p id=tekst_lewo>Nazwisko:  </p>
<span id=tekst_lewo>Płeć:
    </span><br>
	<br>
<p id=tekst_lewo>Nazwisko panieńskie:  </p>
<p id=tekst_lewo>Email:  </p>
<p id=tekst_lewo>Kod pocztowy  </p>

	</div>
	';
	
	echo'
	<div style="text-align:center;margin-top:17px;">
	
	<form method="POST" action="index.php?formu=true"><p>  
<input type="text" name="imie" /> <span id="error">'; echo $imieErr; echo '</span></p>';
echo '
<p><input type="text" name="nazwisko" /> <span id=error>'; echo $nazwiskoErr; echo '</span></p>';
echo '
<span style="margin-left:-85px;">
  <input type="radio" name="gender" value="kobieta"> Kobieta<br> 
  </span>
  <span style="margin-left:-60px;">
  <input type="radio" name="gender" value="mezczyzna">Mężczyzna 
  </span> <span id="error">
  ';  echo $genderErr; echo '</span>';

echo '  
<p> <input type="text" name="nazwisko_panienskie" /><span id="error"> '; echo $nazwisko_panienskieErr; echo '</span></p>';
echo ' 
<p> <input type="text" name="email" /> <span id="error"> '; echo $emailErr; echo '</span></p>';
echo'
<p><input type="text" name="kod_pocztowy" />  <span id="error"> ';echo $kod_pocztowyErr; echo '</span></p>';
echo'
<p><input type="submit" name="submit" value="Submit"> </p>

</form>

</div>



';
}

?>





<?php

//Tablica postów errorów, np wyświetlać errory w formularzu koło imienia itp.


 //echo $imieErr;
 //echo $emailErr; 
 //echo $genderErr;
 //echo $nazwisko_panienskieErr; 
 //echo $kod_pocztowyErr;
 //echo $nazwiskoErr;
 
 ?>
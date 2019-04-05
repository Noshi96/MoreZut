<?php

$zmiennaid=0;
$id1=0;
$help=0;

if(isset($_GET['id1'])){
$zmiennaid=$_GET['id1'];

function test_input($data) {
  $data = trim($data);			//przyciecia
  $data = stripslashes($data); //backslash
  $data = htmlspecialchars($data);
  return $data;
}


	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM pracownik WHERE id='$zmiennaid'");



	while ($rekord = $stmt->fetch()){
		
		
		$spr=0;
$suma=0;
$sesja=0;
$imieErr = $emailErr = $genderErr = $nazwisko_panienskieErr =$kod_pocztowyErr = $nazwiskoErr = "";
$imie = $email = $gender = $nazwisko =$kod_pocztowy = $nazwisko_panienskie = "";




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
  
  
  if(isset($_POST['odrzuc'])){
	header('Location: index.php?strona=1');
}
 
 if($spr==2 && $suma==6 && isset($_POST['potwierdz'])){
	 	
	 $pdo->beginTransaction();
	 $dodaj = "UPDATE pracownik
		SET imie='$imie', nazwisko='$nazwisko', nazwisko_panienskie='$nazwisko_panienskie', email='$email', gender='$gender', kod_pocztowy='$kod_pocztowy'
		WHERE id='$zmiennaid'";
	 $pdo->exec($dodaj);
	 $pdo->commit();
	 $pdo=null;
	 
	 
	  header('Location: index.php?strona=1');
 
 }
  
  
  
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
	
	<form method="POST" action="index.php?strona=1&id1='.$zmiennaid.'"><p>  
<input type="text" name="imie" value="'.$rekord['imie'].'"/> <span id="error">'; echo $imieErr; echo '</span></p>';
echo '
<p><input type="text" name="nazwisko" value="'.$rekord['nazwisko'].'" /> <span id=error>'; echo $nazwiskoErr; echo '</span></p>';
echo '
<span style="margin-left:-85px;">
  <input type="radio" name="gender" value="kobieta"'; if($rekord['gender']=='kobieta'){echo'checked';} echo '> Kobieta<br> 
  </span>
  <span style="margin-left:-60px;">
  <input type="radio" name="gender" value="mezczyzna"'; if($rekord['gender']=='mezczyzna'){echo'checked';} echo '>Mężczyzna 
  </span> <span id="error">
  ';  echo $genderErr; echo '</span>';

echo '  
<p> <input type="text" name="nazwisko_panienskie" value="'.$rekord['nazwisko_panienskie'].'"/><span id="error"> '; echo $nazwisko_panienskieErr; echo '</span></p>';
echo ' 
<p> <input type="text" name="email" value="'.$rekord['email'].'"/> <span id="error"> '; echo $emailErr; echo '</span></p>';
echo'
<p><input type="text" name="kod_pocztowy" value="'.$rekord['kod_pocztowy'].'"/>  <span id="error"> ';echo $kod_pocztowyErr; echo '</span></p>';
echo'
<center>
<div style="display:inline">
<input type="submit" name="potwierdz" value="Potwierdź zmiany"> 
</div>
<div style="display:inline">
<input type="submit" name="odrzuc" value="Odrzuć zmiany"> 
</div>
</center>

</form>

</div>



';



}
		
		
		
		
	}


























}else if($zmiennaid==0){
	


//Wyświetlać to w cześniej stworzonej tabeli bo może przydać się później tr td
$SQL_String='';
	echo'<link rel="stylesheet" href="style.css" type="text/css">';
	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM pracownik");
	$sprr = $pdo->query ("SELECT id FROM pracownik");
	
	echo '<div style="font-size:17.5px;"><table> ';
	
	$ile_wierszy=$sprr->rowCount();
	
	
	//obliczanie danych na potrzeby stronicowania
$cur_page = isset($_GET['strona']) ? $_GET['strona'] : 1;
$results_per_page = 3; //Liczba wyników na stronę
$skip = (($cur_page - 1) * $results_per_page); //liczba pomijanych wierszy na potrzeby stronicowania

$total=$ile_wierszy;
$num_pages = ceil($total / $results_per_page); //określenie liczby stron

 //dopisujemy do wcześniejszego zapytania, klauzule LIMIT

$stmt = $pdo->query ("SELECT * FROM pracownik Orders LIMIT $skip, $results_per_page");

//wykonanie kwerendy

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if (empty($_POST["szukaj1"])) {
    echo '*Nic nie podales<br>';
  } else {
    
	$SQL_String = "SELECT * FROM pracownik WHERE nazwisko LIKE \"%".$_POST["szukaj1"]."%\"";
	
	//$SQL_String = "SELECT * FROM pracownik WHERE name LIKE \"%".$_GET["Phrase"]."%\"";
	
	$stmt = $pdo->query ("SELECT * FROM pracownik WHERE nazwisko LIKE \"%".$_POST["szukaj1"]."%\"");
	$ile_wierszy=$stmt->rowCount();
	$total=$ile_wierszy;
	$num_pages = ceil($total / $results_per_page); //określenie liczby stron
	
	$SQL_String = "SELECT * FROM pracownik Orders LIMIT $skip, $results_per_page WHERE nazwisko LIKE \"%".$_POST["szukaj1"]."%\"";
	$stmt = $pdo->query ("SELECT * FROM pracownik WHERE nazwisko LIKE \"%".$_POST["szukaj1"]."%\" LIMIT $skip, $results_per_page");
	
  }
}

	
	
////////////////////////////////////////////////////////////

	

	
	if($sprr->rowCount()<1){
			echo '<tr>
			<td>Brak bazy</td>
			</tr>
			';
		}else{
	
	echo '
		<tr>
			<td>Edycja</td>
			<td>Id</td>
			<td>Imię </td>
			<td>Nazwisko </td>
			<td>Nazwisko_pan. </td>
			<td>Płeć </td>
			<td>Email </td>
			<td>Kod_pocztowy</td>
		</tr>
		';
		
		
		
	while ($rekord = $stmt->fetch()){
		
		
		
		if($rekord['imie']==''){
			echo '<tr>
			<td>Brak bazy</td>
			</tr>
			';
		}
		else{
		echo '
		<tr>
			<td><u><a href="index.php?strona=1&id1='.$rekord['id'].'">Edycja</a></u></td>
			<td>'.$rekord['id'].' </td>
			<td>'.$rekord['imie'].' </td>
			<td>'.$rekord['nazwisko'].' </td>
			<td>'.$rekord['nazwisko_panienskie'].' </td>
			<td>'.$rekord['gender'].' </td>
			<td>'.$rekord['email'].' </td>
			<td>'.$rekord['kod_pocztowy'].' </td>
			
			
		</tr>
		';
		
		
		}
	}
	
		}
/////////////////////////////////////////////////////////////		
		
$pdo =null;	
	echo '</table></div>';
		
		
		
		
		
		
		
		function generate_page_links($cur_page, $num_pages) {
     $page_links = '';

     // odnośnik do poprzedniej strony (-1)
     if ($cur_page > 1) {
          $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?strona=' . ($cur_page - 1) . '"><-</a> ';
     }

     $i = $cur_page - 4;
     $page = $i + 8;

     for ($i; $i <= $page; $i++) {

          if ($i > 0 && $i <= $num_pages) {
               
               //jeżeli jesteśmy na danej stronie to nie wyświetlamy jej jako link    
               if ($cur_page == $i  && $i != 0) {
                    $page_links .= '' . $i;
               }
               else {

                    //wyświetlamy odnośnik do 1 strony
                    if ($i == ($cur_page - 4) && ($cur_page - 5) != 0) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?strona=1">1</a> '; 
                    }
               
                    //wyświetlamy "kropki", jako odnośnik do poprzedniego bloku stron
                    if ($i == ($cur_page - 4) && (($cur_page - 6)) > 0) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?strona=' . ($cur_page - 5) . '">...</a> '; 
                    } 
               
                    //wyświetlamy liki do bieżących stron
                    $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?strona=' . $i . '"> ' . $i . '</a> ';
          
                    //wyświetlamy "kropki", jako odnośnik do następnego bloku stron
                    if ($i == $page && (($cur_page + 4) - ($num_pages)) < -1) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?strona=' . ($cur_page + 5) . '">...</a>'; 
                    } 
               
                    //wyświetlamy odnośnik do ostatniej strony
                    if ($i == $page && ($cur_page + 4) != $num_pages) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?strona=' . $num_pages . '">' . $num_pages . '</a> '; 
                    }
               }
          }
     }

     //odnośnik do następnej strony (+1)
     if ($cur_page < $num_pages) {
          $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?strona=' . ($cur_page + 1) . '">-></a>';
     }

     return $page_links;
}
		


		
     echo generate_page_links($cur_page, $num_pages);

	


//Czyszczenie sesji, media css żeby było responsywne

if($zmiennaid!=0){



}

}

?>


























<?php

$zmiennaid=0;
$id1=0;


if(isset($_GET['id1'])){
$zmiennaid=$_GET['id1'];




	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM pracownik WHERE id='$zmiennaid'");

	
	echo'
	<br>
	
	<div style="margin-left:20px">
	Czy na pewno usunąć rekord 
	<br>
<form method="POST" action="index.php?usun=1&id1='.$zmiennaid.'"><p> 
<div style="display:inline">
<input type="submit" name="usuntak" value="Tak"> 
</div>
<div style="display:inline">
<input type="submit" name="usunnie" value="Nie"> 
</div>

</div>


</form>';


 if (isset($_POST['usuntak'])) {
        $pdo->beginTransaction();
	 $dodaj = "DELETE FROM pracownik WHERE id='$zmiennaid'";
	 $pdo->exec($dodaj);
	 $pdo->commit();
	 $pdo=null;
	 
	 
	  header('Location: index.php?usun=1');
    }
    elseif (isset($_POST['usunnie'])) {
        header('Location: index.php?usun=1');
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
$cur_page = isset($_GET['usun']) ? $_GET['usun'] : 1;
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
			<td>Usuń</td>
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
			<td><u><a href="index.php?usun=1&id1='.$rekord['id'].'">Usuń</a></u></td>
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
          $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?usun=' . ($cur_page - 1) . '"><-</a> ';
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
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?usun=1">1</a> '; 
                    }
               
                    //wyświetlamy "kropki", jako odnośnik do poprzedniego bloku stron
                    if ($i == ($cur_page - 4) && (($cur_page - 6)) > 0) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?usun=' . ($cur_page - 5) . '">...</a> '; 
                    } 
               
                    //wyświetlamy liki do bieżących stron
                    $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?usun=' . $i . '"> ' . $i . '</a> ';
          
                    //wyświetlamy "kropki", jako odnośnik do następnego bloku stron
                    if ($i == $page && (($cur_page + 4) - ($num_pages)) < -1) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?usun=' . ($cur_page + 5) . '">...</a>'; 
                    } 
               
                    //wyświetlamy odnośnik do ostatniej strony
                    if ($i == $page && ($cur_page + 4) != $num_pages) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?usun=' . $num_pages . '">' . $num_pages . '</a> '; 
                    }
               }
          }
     }

     //odnośnik do następnej strony (+1)
     if ($cur_page < $num_pages) {
          $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?usun=' . ($cur_page + 1) . '">-></a>';
     }

     return $page_links;
}
		


		
     echo generate_page_links($cur_page, $num_pages);

	


//Czyszczenie sesji, media css żeby było responsywne

if($zmiennaid!=0){



}

}

?>


























<?php
$op0=0;
$op1=1;
$op2=2;
$op3=3;
$op4=4;
//Wyświetlać to w cześniej stworzonej tabeli bo może przydać się później tr td
$SQL_String='';
	echo'<link rel="stylesheet" href="style.css" type="text/css">';
	$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
	$stmt = $pdo->query ("SELECT * FROM uzytkownicy");
	$sprr = $pdo->query ("SELECT id FROM uzytkownicy");
	
	echo '<div style="font-size:17.5px;"><table> ';
	
	$ile_wierszy=$sprr->rowCount();
	
	
	//obliczanie danych na potrzeby stronicowania
$cur_page = isset($_GET['zpd']) ? $_GET['zpd'] : 1;
$results_per_page = 4; //Liczba wyników na stronę
$skip = (($cur_page - 1) * $results_per_page); //liczba pomijanych wierszy na potrzeby stronicowania

$total=$ile_wierszy;
$num_pages = ceil($total / $results_per_page); //określenie liczby stron

 //dopisujemy do wcześniejszego zapytania, klauzule LIMIT

$stmt = $pdo->query ("SELECT * FROM uzytkownicy Orders LIMIT $skip, $results_per_page");

//wykonanie kwerendy

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if (empty($_POST["szukaj3"])) {
    //echo '*Nic nie podales<br>';
  } else {
    
	$SQL_String = "SELECT * FROM uzytkownicy WHERE nazwisko LIKE \"%".$_POST["szukaj3"]."%\"";
	
	//$SQL_String = "SELECT * FROM pracownik WHERE name LIKE \"%".$_GET["Phrase"]."%\"";
	
	$stmt = $pdo->query ("SELECT * FROM uzytkownicy WHERE nazwisko LIKE \"%".$_POST["szukaj3"]."%\"");
	$ile_wierszy=$stmt->rowCount();
	$total=$ile_wierszy;
	$num_pages = ceil($total / $results_per_page); //określenie liczby stron
	
	$SQL_String = "SELECT * FROM uzytkownicy Orders LIMIT $skip, $results_per_page WHERE nazwisko LIKE \"%".$_POST["szukaj3"]."%\"";
	$stmt = $pdo->query ("SELECT * FROM uzytkownicy WHERE nazwisko LIKE \"%".$_POST["szukaj3"]."%\" LIMIT $skip, $results_per_page");
	
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
			<td>Login</td>
			<td>Imię</td>
			<td>Nazwisko </td>
			<td>Poziom</td>
			<td>Potwierdź</td>
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
		<tr><form method="POST" action="index.php?zpd='.$_GET['zpd'].'&id3='.$rekord['id'].'">
			<td>'.$rekord['login'].' </td>
			<td>'.$rekord['imie'].' </td>
			<td>'.$rekord['nazwisko'].' </td>
			<td> 
				<select name="prawo">';
				if($rekord['uprawnienia']==4){
					
			   echo'<option value="'.$op4.'"selected>'.$rekord['uprawnienia'].'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op3.'">'.$op3.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op2.'">'.$op2.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op1.'">'.$op1.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op0.'">'.$op0.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					';
					}
					else if($rekord['uprawnienia']==3){
						echo'<option value="'.$op4.'">'.$op4.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op3.'"selected>'.$rekord['uprawnienia'].'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op2.'">'.$op2.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op1.'">'.$op1.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op0.'">'.$op0.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					';
					}
					else if($rekord['uprawnienia']==2){
						echo'<option value="'.$op4.'">'.$op4.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op3.'">'.$op3.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op2.'"selected>'.$rekord['uprawnienia'].'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op1.'">'.$op1.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op0.'">'.$op0.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					';
					}
					else if($rekord['uprawnienia']==1){
						echo'<option value="'.$op4.'">'.$op4.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op3.'">'.$op3.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op2.'">'.$op2.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op1.'"selected>'.$rekord['uprawnienia'].'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op0.'">'.$op0.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					';
					}
					else if($rekord['uprawnienia']==0){
						echo'<option value="'.$op4.'">'.$op4.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op3.'">'.$op3.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op2.'">'.$op2.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op1.'">'.$op1.'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					<option value="'.$op0.'"selected>'.$rekord['uprawnienia'].'&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</option>
					';
					}
						
					echo'
				</select>
			</td>
			<td>
			
			<input type="submit" name="okej" value="Potwierdź">
			
			</td>
			</form>
		</tr>
		';
		
		}
		
		
		
	}
		}
/////////////////////////////////////////////////////////////		
		
$pdo =null;	
	echo '</table></div>';
		
		if(isset($_POST['okej'])){
			$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
			$stmta = $pdo->query ("SELECT uprawnienia FROM uzytkownicy WHERE id=".$_GET['id3']."");
			$aktualne_upr=0;
			
			while ($rekorda = $stmta->fetch()){
				$aktualne_upr=$rekorda['uprawnienia'];
			}
			
			$noweprawa=$_POST['prawo'];
			$id_u=$_GET['id3'];
			
			if($aktualne_upr!=4){
			
	 $pdo->beginTransaction(); 
	 $dodaj = "UPDATE uzytkownicy
		SET uprawnienia='$noweprawa'
		WHERE id='$id_u'";
	 
	 
	 $pdo->exec($dodaj);
	 $pdo->commit();
	 $pdo=null;
	 header('Location: index.php?zpd='.$_GET['zpd'].'');
			}
	
}	
		
		
		
		
		
		function generate_page_links($cur_page, $num_pages) {
     $page_links = '';

     // odnośnik do poprzedniej strony (-1)
     if ($cur_page > 1) {
          $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?zpd=' . ($cur_page - 1) . '"><-</a> ';
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
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?zpd=1">1</a> '; 
                    }
               
                    //wyświetlamy "kropki", jako odnośnik do poprzedniego bloku stron
                    if ($i == ($cur_page - 4) && (($cur_page - 6)) > 0) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?zpd=' . ($cur_page - 5) . '">...</a> '; 
                    } 
               
                    //wyświetlamy liki do bieżących stron
                    $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?zpd=' . $i . '"> ' . $i . '</a> ';
          
                    //wyświetlamy "kropki", jako odnośnik do następnego bloku stron
                    if ($i == $page && (($cur_page + 4) - ($num_pages)) < -1) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?zpd=' . ($cur_page + 5) . '">...</a>'; 
                    } 
               
                    //wyświetlamy odnośnik do ostatniej strony
                    if ($i == $page && ($cur_page + 4) != $num_pages) { 
                         $page_links .= ' <a href="' . $_SERVER['PHP_SELF'] . '?zpd=' . $num_pages . '">' . $num_pages . '</a> '; 
                    }
               }
          }
     }

     //odnośnik do następnej strony (+1)
     if ($cur_page < $num_pages) {
          $page_links .= '<a href="' . $_SERVER['PHP_SELF'] . '?zpd=' . ($cur_page + 1) . '">-></a>';
     }

     return $page_links;
}
		
	

		
     echo generate_page_links($cur_page, $num_pages);

	 
	 if(isset($_POST['okej'])){
			$pdo = new PDO('mysql:host=localhost;dbname=zadanie','root');
			$stmta = $pdo->query ("SELECT uprawnienia FROM uzytkownicy WHERE id=".$_GET['id3']."");
			$aktualne_upr=0;
			
			while ($rekorda = $stmta->fetch()){
				$aktualne_upr=$rekorda['uprawnienia'];
			}
			if($aktualne_upr!=4){
			}else{
					echo '<br><br><span id="error">*Nie możesz zmienić uprawnień administratora</span>';
			}
	
}	
	
		


//Czyszczenie sesji, media css żeby było responsywne

?>
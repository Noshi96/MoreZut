<?php

//Wyświetlać to w cześniej stworzonej tabeli bo może przydać się później tr td
if(!isset($_SESSION['licznik'])){
	
}else{
	echo'<link rel="stylesheet" href="style.css" type="text/css">';
	
	echo '<div style="font-size:17.5px;"><table> ';
	echo '
		<tr>
			<td>Id</td>
			<td>Imię </td>
			<td>Nazwisko </td>
			<td>Nazwisko_panienskie </td>
			<td>Płeć </td>
			<td>Email </td>
			<td>Kod_pocztowy</td>
		</tr>
		';
	for($i=0; $i < $_SESSION['licznik']; $i++){
		echo '
		<tr>
			<td>'.($i).' </td>
			<td>'.$_SESSION['imie'][$i].' </td>
			<td>'.$_SESSION['nazwisko'][$i].' </td>
			<td>'.$_SESSION['nazwisko_panienskie'][$i].' </td>
			<td>'.$_SESSION['gender'][$i].' </td>
			<td>'.$_SESSION['email'][$i].' </td>
			<td>'.$_SESSION['kod_pocztowy'][$i].' </td>
		</tr>
		';
	}
	echo '</table></div>';
}




?>
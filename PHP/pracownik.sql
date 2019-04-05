-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 18 Gru 2018, 17:21
-- Wersja serwera: 10.1.36-MariaDB
-- Wersja PHP: 7.2.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `zadanie`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `pracownik`
--

CREATE TABLE `pracownik` (
  `id` int(60) NOT NULL,
  `imie` varchar(60) COLLATE utf8_polish_ci NOT NULL,
  `nazwisko` varchar(60) COLLATE utf8_polish_ci NOT NULL,
  `gender` varchar(60) COLLATE utf8_polish_ci NOT NULL,
  `nazwisko_panienskie` varchar(60) COLLATE utf8_polish_ci NOT NULL,
  `email` varchar(60) COLLATE utf8_polish_ci NOT NULL,
  `kod_pocztowy` varchar(60) COLLATE utf8_polish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

--
-- Zrzut danych tabeli `pracownik`
--

INSERT INTO `pracownik` (`id`, `imie`, `nazwisko`, `gender`, `nazwisko_panienskie`, `email`, `kod_pocztowy`) VALUES
(8, '5656', '1410', 'mezczyzna', 'dsadsa', 'wel2@gmail.com', '71-111'),
(9, 'dsadsa1', '2019', 'mezczyzna', 'dsadsa', 'awel2@gmail.com', '71-111'),
(12, '21', '1992', 'kobieta', 'dsadsa', '2spawel2@gmail.com', '71-111'),
(13, 'dsadsa', '1410', 'mezczyzna', 'dsadsa', '2spawel2@gmail.com', '71-111'),
(15, 'dsadsa', 'alupa', 'kobieta', 'dsadsa', '2spawel2@gmail.com', '71-111'),
(17, 'dsdsf', 'fdsfds', 'mezczyzna', 'fdfdsfds', '2spawel2@gmail.com', '71-111'),
(18, '99999', '99999', 'kobieta', '9999999', '2spawel2@gmail.com', '71-111'),
(19, 'Å‚Ä…ka', '3333', 'kobieta', 'Å‚Ä…ka', 'laka@gmail.com', '71-111'),
(20, 'dsadsa', 'dsadabc', 'mezczyzna', 'dsadsa', '2spawel2@gmail.com', '71-111'),
(21, 'dsadsa', 'dsakula', 'kobieta', 'dsadsa', '2spawel2@gmail.com', '71-111'),
(22, 'dsadsa', 'dsada', 'mezczyzna', 'dsadsa', '2spawel2@gmail.com', '71-111'),
(24, '111', '999', 'mezczyzna', '999', '999999@gmail.com', '71-111'),
(25, 'panpan1', 'panpan1', 'mezczyzna', 'panpan', 'panpan@gmail.com', '71-111'),
(26, 'panpan33', 'panpan33', 'mezczyzna', 'panpan33', 'panpan33@o2.pl', '71-111');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `pracownik`
--
ALTER TABLE `pracownik`
  ADD UNIQUE KEY `id` (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `pracownik`
--
ALTER TABLE `pracownik`
  MODIFY `id` int(60) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=27;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 18, 2024 at 05:23 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `database_two`
--

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `Bid` int(11) NOT NULL,
  `Btitle` varchar(40) DEFAULT NULL,
  `BAuther` varchar(50) DEFAULT NULL,
  `Bpublisher` varchar(50) DEFAULT NULL,
  `Bprice` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`Bid`, `Btitle`, `BAuther`, `Bpublisher`, `Bprice`) VALUES
(101, 'Database System', 'Raghu Lal', 'Read More', 2500.00),
(102, 'Introduction to Computer', 'Gyani Ray', 'KEC', 500.00),
(103, 'Think and Grow Rich', 'Oliver Napoleon', 'Asia Publication', 1300.00);

-- --------------------------------------------------------

--
-- Table structure for table `members`
--

CREATE TABLE `members` (
  `mid` int(11) NOT NULL,
  `name` varchar(30) DEFAULT NULL,
  `design` varchar(40) DEFAULT NULL,
  `age` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members`
--

INSERT INTO `members` (`mid`, `name`, `design`, `age`) VALUES
(1, 'Arjun Rokka', 'Professor', 46),
(2, 'Arun Chaudary', 'Student', 25),
(3, 'Aayush Gautam', 'Professor', 35);

-- --------------------------------------------------------

--
-- Table structure for table `reserves`
--

CREATE TABLE `reserves` (
  `mid` int(11) NOT NULL,
  `Bid` int(11) NOT NULL,
  `date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `reserves`
--

INSERT INTO `reserves` (`mid`, `Bid`, `date`) VALUES
(1, 101, '2023-09-12'),
(2, 102, '2024-05-31'),
(3, 103, '2007-05-27');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`Bid`);

--
-- Indexes for table `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`mid`);

--
-- Indexes for table `reserves`
--
ALTER TABLE `reserves`
  ADD PRIMARY KEY (`mid`,`Bid`),
  ADD KEY `Bid` (`Bid`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `reserves`
--
ALTER TABLE `reserves`
  ADD CONSTRAINT `reserves_ibfk_1` FOREIGN KEY (`mid`) REFERENCES `members` (`mid`),
  ADD CONSTRAINT `reserves_ibfk_2` FOREIGN KEY (`Bid`) REFERENCES `books` (`Bid`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

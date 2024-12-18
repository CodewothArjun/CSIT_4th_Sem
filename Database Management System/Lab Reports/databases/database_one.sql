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
-- Database: `database_one`
--

-- --------------------------------------------------------

--
-- Table structure for table `company`
--

CREATE TABLE `company` (
  `company_name` varchar(30) NOT NULL,
  `city` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `company`
--

INSERT INTO `company` (`company_name`, `city`) VALUES
('First Bank Corporation', 'Kathmandu'),
('Logix Computer', 'Bhaktapur'),
('Tech Innovators', 'Lalitpur');

-- --------------------------------------------------------

--
-- Table structure for table `employee`
--

CREATE TABLE `employee` (
  `person_name` varchar(40) NOT NULL,
  `street` varchar(50) DEFAULT NULL,
  `city` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `employee`
--

INSERT INTO `employee` (`person_name`, `street`, `city`) VALUES
('Arjun', 'Devinagar 10', 'Kathmandu'),
('Arjun Mijar', 'Madan Bhandari Margh 08', 'Kathmandu'),
('Roman', 'Madhevstan 4', 'Bhaktapur'),
('Sitaram', 'Nayaneshwor 21', 'Lalitpur');

-- --------------------------------------------------------

--
-- Stand-in structure for view `highearners`
-- (See below for the actual view)
--
CREATE TABLE `highearners` (
`person_name` varchar(40)
,`street` varchar(50)
,`city` varchar(50)
);

-- --------------------------------------------------------

--
-- Table structure for table `manages`
--

CREATE TABLE `manages` (
  `person_name` varchar(40) NOT NULL,
  `manager_name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `manages`
--

INSERT INTO `manages` (`person_name`, `manager_name`) VALUES
('Roman', 'Arjun'),
('Sitaram', 'Roman'),
('Arjun', 'Sitaram');

-- --------------------------------------------------------

--
-- Table structure for table `works`
--

CREATE TABLE `works` (
  `person_name` varchar(30) NOT NULL,
  `company_name` varchar(40) DEFAULT NULL,
  `salary` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `works`
--

INSERT INTO `works` (`person_name`, `company_name`, `salary`) VALUES
('Arjun Mijar', 'First Bank Corporation', 21500.00),
('Roman', 'Tech Innovators', 30000.00),
('Sitaram', 'Logix Computer', 35000.00);

-- --------------------------------------------------------

--
-- Structure for view `highearners`
--
DROP TABLE IF EXISTS `highearners`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `highearners`  AS SELECT `e`.`person_name` AS `person_name`, `e`.`street` AS `street`, `e`.`city` AS `city` FROM (`employee` `e` join `works` `w`) WHERE `e`.`person_name` = `w`.`person_name` AND `w`.`company_name` = 'First Bank Corporation' AND `w`.`salary` > 10000 ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `company`
--
ALTER TABLE `company`
  ADD PRIMARY KEY (`company_name`);

--
-- Indexes for table `employee`
--
ALTER TABLE `employee`
  ADD PRIMARY KEY (`person_name`);

--
-- Indexes for table `manages`
--
ALTER TABLE `manages`
  ADD PRIMARY KEY (`person_name`),
  ADD KEY `manager_name` (`manager_name`);

--
-- Indexes for table `works`
--
ALTER TABLE `works`
  ADD PRIMARY KEY (`person_name`),
  ADD KEY `company_name` (`company_name`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `manages`
--
ALTER TABLE `manages`
  ADD CONSTRAINT `manages_ibfk_1` FOREIGN KEY (`person_name`) REFERENCES `employee` (`person_name`),
  ADD CONSTRAINT `manages_ibfk_2` FOREIGN KEY (`manager_name`) REFERENCES `employee` (`person_name`);

--
-- Constraints for table `works`
--
ALTER TABLE `works`
  ADD CONSTRAINT `works_ibfk_1` FOREIGN KEY (`person_name`) REFERENCES `employee` (`person_name`),
  ADD CONSTRAINT `works_ibfk_2` FOREIGN KEY (`company_name`) REFERENCES `company` (`company_name`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

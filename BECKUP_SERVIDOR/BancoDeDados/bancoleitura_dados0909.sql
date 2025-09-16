-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 09-Set-2025 às 20:15
-- Versão do servidor: 10.4.27-MariaDB
-- versão do PHP: 8.0.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `bancoleitura`
--

DELIMITER $$
--
-- Procedimentos
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `validamackaua` (IN `$mackaua` VARCHAR(17), OUT `$ativo` BOOLEAN)   BEGIN
select ativo into $ativo from mackaua
WHERE idmackaua =$mackaua;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Estrutura da tabela `leiturakaua`
--

CREATE TABLE `leiturakaua` (
  `idleiturakaua` int(10) UNSIGNED NOT NULL,
  `mackaua_idmackaua` varchar(17) NOT NULL,
  `dataleitura` date DEFAULT NULL,
  `horaleitura` time DEFAULT NULL,
  `umidade` double DEFAULT NULL,
  `temperatura` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `leiturakaua`
--

INSERT INTO `leiturakaua` (`idleiturakaua`, `mackaua_idmackaua`, `dataleitura`, `horaleitura`, `umidade`, `temperatura`) VALUES
(1, 'CC:50:E3:05:19:BA', '2025-09-09', '14:47:00', 93, 20),
(2, 'CC:50:E3:05:19:BA', '2025-09-09', '15:14:00', 90, 21);

--
-- Acionadores `leiturakaua`
--
DELIMITER $$
CREATE TRIGGER `tgdeleteleiturakaua` AFTER DELETE ON `leiturakaua` FOR EACH ROW BEGIN
UPDATE mackaua
SET contador = contador - 1
WHERE idmackaua = old.mackaua_idmackaua;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `tginserleiturakaua` AFTER INSERT ON `leiturakaua` FOR EACH ROW BEGIN
UPDATE mackaua
SET contador = contador + 1
WHERE idmackaua = new.mackaua_idmackaua;

END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `tgverificaativakaua` BEFORE INSERT ON `leiturakaua` FOR EACH ROW begin
CALL validamackaua(new.mackaua_idmackaua,@$ativo);
if @$ativo=0
then SIGNAL SQLSTATE '45000' SET
MESSAGE_TEXT = 'Placa inativa';
end if;
end
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estrutura da tabela `mackaua`
--

CREATE TABLE `mackaua` (
  `idmackaua` varchar(17) NOT NULL,
  `nome` varchar(30) NOT NULL,
  `contador` int(10) UNSIGNED DEFAULT 0,
  `ativo` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `mackaua`
--

INSERT INTO `mackaua` (`idmackaua`, `nome`, `contador`, `ativo`) VALUES
('CC:50:E3:05:19:BA', 'PLACA DIA 09/09', 2, 1),
('CC:50:E3:05:19:BB', 'PLACA DIA 09/09 Teste 2', 5, 1),
('CC:50:E3:05:19:BC', 'PLACA TESTE 01', 0, 0),
('CC:50:E3:05:19:BD', 'PLACA BACKUP', 1, 1),
('CC:50:E3:05:19:BE', 'PLACA INATIVA', 12, 0),

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `leiturakaua`
--
ALTER TABLE `leiturakaua`
  ADD PRIMARY KEY (`idleiturakaua`),
  ADD KEY `leiturakaua_FKIndex1` (`mackaua_idmackaua`);

--
-- Índices para tabela `mackaua`
--
ALTER TABLE `mackaua`
  ADD PRIMARY KEY (`idmackaua`);

--
-- AUTO_INCREMENT de tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `leiturakaua`
--
ALTER TABLE `leiturakaua`
  MODIFY `idleiturakaua` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Restrições para despejos de tabelas
--

--
-- Limitadores para a tabela `leiturakaua`
--
ALTER TABLE `leiturakaua`
  ADD CONSTRAINT `leiturakaua_ibfk_1` FOREIGN KEY (`mackaua_idmackaua`) REFERENCES `mackaua` (`idmackaua`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

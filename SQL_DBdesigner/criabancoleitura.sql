CREATE TABLE mackaua (
  idmackaua VARCHAR(17)  NOT NULL  ,
  nome VARCHAR(30)  NOT NULL  ,
  contador INTEGER UNSIGNED  NULL DEFAULT 0 ,
  ativo BOOL  NOT NULL DEFAULT 0   ,
PRIMARY KEY(idmackaua));



CREATE TABLE leiturakaua (
  idleiturakaua INTEGER UNSIGNED  NOT NULL   AUTO_INCREMENT,
  mackaua_idmackaua VARCHAR(17)  NOT NULL  ,
  dataleitura DATE  NULL  ,
  horaleitura TIME  NULL  ,
  umidade REAL  NULL  ,
  temperatura REAL  NULL    ,
PRIMARY KEY(idleiturakaua)  ,
INDEX leiturakaua_FKIndex1(mackaua_idmackaua),
  FOREIGN KEY(mackaua_idmackaua)
    REFERENCES mackaua(idmackaua)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION);





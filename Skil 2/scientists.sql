DROP TABLE IF EXISTS "scientists";
CREATE TABLE "scientists" ("id" INTEGER PRIMARY KEY  
AUTOINCREMENT  NOT NULL  UNIQUE , 
"first_name" VARCHAR NOT NULL , "middle_name" 
VARCHAR, "last_name" VARCHAR NOT NULL , 
"gender" VARCHAR NOT NULL , "birth_year" 
INTEGER NOT NULL , "death_year" INTEGER NOT NULL , 
"valid" BOOL NOT NULL );

INSERT INTO "scientists" VALUES(1,'Charles',NULL,'Babbage','male',1791,1871,0);
INSERT INTO "scientists" VALUES(2,'Ada',NULL,'Lovelace','female',1815,1852,0);
INSERT INTO "scientists" VALUES(3,'Blaise',NULL,'Pascal','male',1623,1662,0);
INSERT INTO "scientists" VALUES(4,'John','Vincent','Atanasoff','male',1903,1995,0);
INSERT INTO "scientists" VALUES(5,'John','William','Mauchly','male',1907,1980,0);
INSERT INTO "scientists" VALUES(6,'John','Presper','Eckert','male',1919,1995,0);
INSERT INTO "scientists" VALUES(7,'Grace',NULL,'Hopper','female',1906,1992,0);
INSERT INTO "scientists" VALUES(8,'Margaret','Heafield','Hamilton','female',1936,'',0);
INSERT INTO "scientists" VALUES(9,'Mark','Elliot','Zuckerberg','male',1984,'',0);
INSERT INTO "scientists" VALUES(10,'Alan',NULL,'Turing','male',1912,1954,0);
INSERT INTO "scientists" VALUES(11,'Donald',NULL,'Knuth','male',1938,'',0);
INSERT INTO "scientists" VALUES(12,'Tim',NULL,'Berners-Lee','male',1955,'',0);
INSERT INTO "scientists" VALUES(13,'john',NULL,'von Neumann','male',1903,1957,0);
INSERT INTO "scientists" VALUES(14,'Larry',NULL,'Page','male',1973,'',0);
INSERT INTO "scientists" VALUES(15,'Edsger','W.','Dijkstra','male',1930,2002,0);
INSERT INTO "scientists" VALUES(16,'John',NULL,'Backus','male',1924,2007,0);
INSERT INTO "scientists" VALUES(17,'Claude',NULL,'Shannon','male',1916,2001,0);
INSERT INTO "scientists" VALUES(18,'Sergey',NULL,'Brin','male',1973,'',0);
INSERT INTO "scientists" VALUES(19,'Niklaus',NULL,'Wirth','male',1934,'',0);
INSERT INTO "scientists" VALUES(20,'Dennis',NULL,'Ritchie','male',1942,2011,0);
INSERT INTO "scientists" VALUES(21,'Ken',NULL,'Thompson','male',1943,'',0);
INSERT INTO "scientists" VALUES(22,'Larry',NULL,'Wall','male',1954,'',0);
INSERT INTO "scientists" VALUES(23,'James',NULL,'Gosling','male',1955,'',0);
INSERT INTO "scientists" VALUES(24,'Brian',NULL,'Kernighan','male',1942,'',0);
INSERT INTO "scientists" VALUES(25,'Ivan',NULL,'Sutherland','male',1938,'',0);
INSERT INTO "scientists" VALUES(26,'John',NULL,'McCarthy','male',1927,2011,0);
INSERT INTO "scientists" VALUES(27,'Maurice',NULL,'Wilkes','male',1913,2010,0);
INSERT INTO "scientists" VALUES(28,'Anita',NULL,'Borg','female',1949,2003,0);
INSERT INTO "scientists" VALUES(29,'Vint',NULL,'Cerf','male',1943,'',0);
INSERT INTO "scientists" VALUES(30,'Alan',NULL,'Kay','male',1940,'',0);
INSERT INTO "scientists" VALUES(31,'Ole-Johan',NULL,'Dahl','male',1931,2002,0);
INSERT INTO "scientists" VALUES(32,'Marvin',NULL,'Minsky','male',1927,'',0);
INSERT INTO "scientists" VALUES(33,'Guido',NULL,'van Rossum','male',1956,'',0);
INSERT INTO "scientists" VALUES(34,'Konrad',NULL,'Zuse','male',1910,1995,0);
INSERT INTO "scientists" VALUES(35,'Edgar','F.','Codd','male',1923,2003,0);
INSERT INTO "scientists" VALUES(36,'Steve',NULL,'Wozniak','male',1950,'',0);
INSERT INTO "scientists" VALUES(37,'Hal',NULL,'Abelson','male',1947,'',0);
INSERT INTO "scientists" VALUES(38,'Leslie',NULL,'Lamport','male',1941,'',0);
INSERT INTO "scientists" VALUES(39,'Tony',NULL,'Hoare','male',1934,'',0);
INSERT INTO "scientists" VALUES(40,'Stephen','Arthur','Cook','male',1939,'',0);
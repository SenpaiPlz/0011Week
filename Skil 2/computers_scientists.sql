DROP TABLE IF EXISTS "computers_scientists";
CREATE TABLE computers_scientists ( id integer primary key, 
scientists_id integer, computers_id integer, 
FOREIGN KEY(scientists_id) REFERENCES scientists(id), 
FOREIGN KEY(computers_id) REFERENCES computers(id) );

INSERT INTO "computers_scientists" VALUES(1,3,1);
INSERT INTO "computers_scientists" VALUES(2,4,2);
INSERT INTO "computers_scientists" VALUES(3,5,2);
INSERT INTO "computers_scientists" VALUES(4,6,2);
INSERT INTO "computers_scientists" VALUES(5,10,3);
INSERT INTO "computers_scientists" VALUES(6,1,4);
INSERT INTO "computers_scientists" VALUES(7,1,5);
INSERT INTO "computers_scientists" VALUES(8,36,6);
INSERT INTO "computers_scientists" VALUES(9,5,7);
INSERT INTO "computers_scientists" VALUES(10,6,7);

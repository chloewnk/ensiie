drop table if exists todo;
drop table if exists reminder;
drop table if exists habits;

create table todo (
    id integer primary key,
    nom varchar(20),
    desc varchar(100)
);
create table reminder (
    id integer primary key,
    nom varchar(20),
    desc varchar(100),
    date_debut date,
    date_fin date
);
create table habits (
    id integer primary key,
    nom varchar(20),
    duree interger
);

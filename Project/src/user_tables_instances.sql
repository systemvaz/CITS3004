-- create users table
create table users
(
 username varchar(50),
 upassword varchar(50),
 primary key (username)
);

-- insert users rows
insert into users values ('jin.hong', 'jinpassword');
insert into users values ('mark.reynolds', 'markpassword');
insert into users values ('rachel.cardell-oliver', 'rachelpassword');
insert into users values ('mohammed.bennamoun', 'mohammedpassword');
insert into users values ('chris.mcdonald', 'chrispassword');
insert into users values ('tim.french', 'timpassword');
insert into users values ('du.huynh', 'dupassword');
insert into users values ('jianxin.li', 'jianxinpassword');
insert into users values ('wei.liu', 'weipassword');
insert into users values ('ajmal.mian', 'ajmalpassword');
insert into users values ('george.milne', 'georgepassword');
insert into users values ('arran.stewart', 'arranpassword');
insert into users values ('lyndon.while', 'lyndonpassword');
insert into users values ('michael.wise', 'michaelpassword');

create table address
(
 username varchar(50),
 address varchar(50),
 primary key (username)
);

-- insert users rows
insert into address values ('jin.hong', '123 Abc Street');
insert into address values ('mark.reynolds', '88 Hello Avenue');
insert into address values ('rachel.cardell-oliver', '435 Computer Road');
insert into address values ('mohammed.bennamoun', '23A Book Street');
insert into address values ('chris.mcdonald', '76 Assignment Cresent');
insert into address values ('tim.french', '38 Tour Road');
insert into address values ('du.huynh', '39B Goodwill Street');
insert into address values ('jianxin.li', '20 Meeting Road');
insert into address values ('wei.liu', '9C Thinking Street');
insert into address values ('ajmal.mian', '562 Phone Avenue');
insert into address values ('george.milne', '112 Cooking Terrace');
insert into address values ('arran.stewart', '1234 Browser Road');
insert into address values ('lyndon.while', '65A Board Street');
insert into address values ('michael.wise', '23B Book Street');


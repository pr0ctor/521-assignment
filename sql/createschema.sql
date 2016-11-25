drop table Orders;
drop table Users;
drop table Products;
drop table Inventory;
drop table Shipment;
drop table Category;
drop table States;
drop table Sizes;
drop table Brands;

create table Orders 
(
	O_ID int not null auto_increment,
	U_ID int foreign key references Users(U_ID),
	P_ID int foreign key References Product(P_ID),
	quantity int,
	purchaseDate timestamp,
	processed boolean default false,
	primary key(O_ID,P_ID)
);

create table Users
(
	U_ID int not null auto_increment,
	email char(50) not null, --foreign key references Login(email) not null,
	password varchar(64) not null,
	fname varchar(100),
	lname varchar(100),
	address varchar(100),
	city varchar(100),
	add_state char(2) foreign key references States(abbr),
	zipcode int,
	accesslevel int default 10,
	primary key(U_ID)
);

create table Products
(
	P_ID int not null auto_increment, --foreign key references Product(P_ID),
	name varchar(100),
	category varchar(50) foreign key references Category(category),
	metadata varchar(200),
	brand varchar(50),
	image varchar(50),
	price int,
	description text,
	gender char(1),
	primary key(P_ID)
);

create table Inventory
(
	P_ID foreign key references Product(P_ID),
	quantity int default 10,
	primary key(P_ID)
);

create table Shipment
(
	O_ID int foreign key references Orders(O_ID),
	U_ID int key references Users(U_ID),
	address varchar(100) foreign key references Users(address),
	primary key(O_ID,U_ID)
);

create table Category
(
	category varchar(50),
	gender char(1),
	primary key(category,gender)
);

create table States
(
	abbr char(2),
	primary key(abbr)
);

create table Sizes
(
	sizes varchar(20),
	category varchar(50) foreign key references Category(category),
	gender char(1),
	primary key(sizes,category,gender)
);

create table Brands
(
	name varchar(50),
	brand varchar(50),
	primary key(brand)
);

CREATE OR REPLACE VIEW LowInventoryView AS
	SELECT Products.P_ID,Products.name,Products.category,Brands.name,quantity
	FROM Products p, Inventory i, Brands b
	WHERE i.quantity =< 5 and b.brand = p.brand;

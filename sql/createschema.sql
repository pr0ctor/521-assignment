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
	U_ID int,
	P_ID int,
	quantity int,
	purchaseDate timestamp,
	processed boolean default false,
	primary key(O_ID,P_ID),
	foreign key(U_ID) references Users(U_ID),
	foreign key(P_ID) references Product(P_ID)
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
	add_state char(2),
	zipcode int,
	accesslevel int default 10,
	primary key(U_ID),
	foreign key(add_state) refereneces States(abbr)
);

create table Products
(
	P_ID int not null auto_increment, --foreign key references Product(P_ID),
	name varchar(100),
	category varchar(50),
	metadata varchar(200),
	brand varchar(50),
	image varchar(50),
	price int,
	description text,
	gender char(1),
	primary key(P_ID),
	foreign key(category) references Category(category)
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
	address varchar(100),
	primary key(O_ID,U_ID),
	foreign key(O_ID) references Orders(O_ID),
	foreign key(U_ID) references Users(U_ID),
	foreign key(address) references Users(address)
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
	category varchar(50),
	gender char(1),
	primary key(sizes,category,gender),
	foreign key(category) references Category(category)
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

USE supermarketmgt;
CREATE TABLE Store(
store_ID int PRIMARY KEY,
store_Name varchar(30),
store_Address varchar(50),
store_phone varchar(15),
store_managerName varchar(25),
workingHour varchar(10)
);
INSERT INTO Store VALUES
(3,'Rose','AddisAbaba','0988976655','Belete','8hr'),
(4,'Abebe','AddisAbaba','0922334455','Asefa','8hr');
DROP TABLE Store;
CREATE TABLE Product(
	Product_id INT PRIMARY KEY NOT NULL,
	Product_Name VARCHAR (50) NOT NULL,
	product_Price float NOT NULL,
    Product_Category varchar(50),
	product_QuantityInStock INT NOT NULL,
	Shelf_Order INT NOT NULL
);
DROP TABLE Product;

CREATE TABLE Employee (
	employee_ID int PRIMARY KEY NOT NULL,
	employee_FirstName varchar(50) NOT NULL,
	employee_LastName  varchar(50) NOT NULL,
    ContactNumber varchar(15) NOT NULL,
    employee_Position varchar(25) NOT NULL,
    shift_schedule varchar(14) NOT NULL,
    Salary float NOT NULL
);
DROP TABLE Employee;

CREATE TABLE Supplier(
 supp_ID int PRIMARY KEY NOT NULL,
 supp_name varchar(25) NOT NULL,
 Address varchar(50) NOT NULL,
 supp_phone varchar(15) NOT NULL,
 supp_email varchar(50) NOT NULL
);
DROP TABLE Supplier;
  INSERT INTO Supplier VALUES
(1,'Fikadu Belete','Addis Ababa,Ethiopa','0988776655','-------@gmail.com'),
(2,'Abebe Selam','Addis Ababa,Ethiopa','0922334455','-------@gmail.com'),
(3,'Bereket Kiros','Addis Ababa,Ethiopa','0955446677','-------@gmail.com');
CREATE TABLE Customer(
 customerID INT PRIMARY KEY NOT NULL,
 customerName varchar(25) NOT NULL,
 customerAddress varchar(50) NOT NULL,
 customerPhone varchar(10) NOT NULL,
 customerEmail varchar(50) NOT NULL,
 loyaltyPoint decimal
);
INSERT INTO Customer VALUES
(1,'Edilawit Netsanet','Addis Ababa','0978654367','netsanet34@gmail.com',1.0),
(2,'Mengesha Ayalew','Addis Ababa','0967346722','ayalewMe@gmail.com',1.2),
(3,'Amen Semahegn','Addis Ababa','0967899988','semahegnAm@gmil.com',1.1);
CREATE TABLE Transaction(
transaction_ID int PRIMARY KEY NOT NULL,
transaction_date varchar(11),
transaction_time varchar(6),
customer_ID int ,
product_Name varchar(50),
total decimal,
payment varchar(20)
);
DROP TABLE Transaction;
SELECT * FROM Transaction;
SELECT * FROM Supplier;
SELECT * FROM Product;
SELECT*FROM Customer;
SELECT*FROM Store;
SELECT * FROM Employee;
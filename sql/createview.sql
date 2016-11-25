CREATE OR REPLACE VIEW LowInventoryView AS
	SELECT p.P_ID as id,p.name as pname,category,b.name as bname,quantity
	FROM Products p, Inventory i, Brands b
	WHERE i.quantity <= 5 and p.brand = b.brand;

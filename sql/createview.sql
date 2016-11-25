CREATE OR REPLACE VIEW LowInventoryView AS
	SELECT Products.P_ID,name,category,name,quantity
	FROM Products p, Inventory i
	WHERE i.quantity <= 5;

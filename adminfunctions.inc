<?php include('db.inc');  include('validate.inc');

if(!empty($_POST['update-user']))
{
	if(!empty($_POST['user']))
	{
		$userid = stripHTML($_POST['user']);
		
		if(!empty($_POST['email']))
		{
			$email = validateEmail($_POST['email']);
			
			$stmt = $db->prepare("UPDATE Users SET email = ? WHERE U_ID = ?");
			$stmt->bind_param('si',$email,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['fname']))
		{
			$name = stripHTML($_POST['fname']);
			
			$stmt = $db->prepare("UPDATE Users SET fname = ? WHERE U_ID = ?");
			$stmt->bind_param('si',$name,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['lname']))
		{
			$name = stripHTML($_POST['lname']);
			
			$stmt = $db->prepare("UPDATE Users SET lname = ? WHERE U_ID = ?");
			$stmt->bind_param('si',$name,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['address']))
		{
			$address = stripHTML($_POST['address']);
			
			$stmt = $db->prepare("UPDATE Users SET address = ? WHERE U_ID = ?");
			$stmt->bind_param('si',$address,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['city']))
		{
			$city = stripHTML($_POST['city']);
			
			$stmt = $db->prepare("UPDATE Users SET city = ? WHERE U_ID = ?");
			$stmt->bind_param('si',$city,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['state']))
		{
			$state = stripHTML($_POST['state']);
			
			$stmt = $db->prepare("UPDATE Users SET state = ? WHERE U_ID = ?");
			$stmt->bind_param('si',$state,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['zipcode']) && is_numeric($_POST['zipcode']))
		{
			$zipcode = stripHTML($_POST['zipcode']);
			
			$stmt = $db->prepare("UPDATE Users SET zipcode = ? WHERE U_ID = ?");
			$stmt->bind_param('ii',$zipcode,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['accesslevel']) && is_numeric($_POST['accesslevel']))
		{
			if($_POST['accesslevel'] >= 0 && $_POST['accesslevel'] <= 4 || $_POST['accesslevel'] === 10)
			{
				$access = stripHTML($_POST['accesslevel']);
			
				$stmt = $db->prepare("UPDATE Users SET accesslevel = ? WHERE U_ID = ?");
				$stmt->bind_param('ii',$access,$userid);
				$stmt->execute();
			}
		}
	}
}
//INSERT INTO Users(email,password,fname,lname,address,city,stateabbr,zipcode,) VALUES(?,?,?,?,?,?,?,?,?)
if(!empty($_POST['add-user']))
{
	if(!empty($_POST['email']))
	{
		$email = validateEmail($_POST['email']);

		if(!empty($_POST['fname']))
		{
			$fname = stripHTML($_POST['fname']);
			
			if(!empty($_POST['lname']))
			{
				$lname = stripHTML($_POST['lname']);
				
				if(!empty($_POST['address']))
				{
					$address = stripHTML($_POST['address']);
			
					if(!empty($_POST['city']))
					{
						$city = stripHTML($_POST['city']);
			
						if(!empty($_POST['state']))
						{
							$state = stripHTML($_POST['state']);
			
							if(!empty($_POST['zipcode']) && is_numeric($_POST['zipcode']))
							{
								$zipcode = stripHTML($_POST['zipcode']);

								if(!empty($_POST['accesslevel']))
								{
									if($_POST['accesslevel'] >= 0 && $_POST['accesslevel'] <= 4 || $_POST['accesslevel'] == 10)
									{
										$access = stripHTML($_POST['accesslevel']);
										$pass = "tromalsnad"."pass1234";
										$stmt = $db->prepare("INSERT INTO Users(email,password,fname,lname,address,city,stateabbr,zipcode,accesslevel) VALUES(?,password(?),?,?,?,?,?,?,?)");
										$stmt->bind_param('sssssssii',$email,$pass,$fname,$lname,$address,$city,$state,$zipcode,$access);
										$stmt->execute();
									}
									else
									{
										$pass = "tromalsnad"."pass1234";
										$stmt = $db->prepare("INSERT INTO Users(email,password,fname,lname,address,city,stateabbr,zipcode) VALUES(?,password(?),?,?,?,?,?,?)");
										$stmt->bind_param('sssssssi',$email,$pass,$fname,$lname,$address,$city,$state,$zipcode);
										$stmt->execute();
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

if(!empty($_POST['add-new-user']))
{
	if(!empty($_POST['email']))
	{
		$email = validateEmail($_POST['email']);
		
		if(!empty($_POST['password']))
		{
			$pass = stripHTML($_POST['password']);

		if(!empty($_POST['fname']))
		{
			$fname = stripHTML($_POST['fname']);
			
			if(!empty($_POST['lname']))
			{
				$lname = stripHTML($_POST['lname']);
				
				if(!empty($_POST['address']))
				{
					$address = stripHTML($_POST['address']);
			
					if(!empty($_POST['city']))
					{
						$city = stripHTML($_POST['city']);
			
						if(!empty($_POST['state']))
						{
							$state = stripHTML($_POST['state']);
			
							if(!empty($_POST['zipcode']) && is_numeric($_POST['zipcode']))
							{
								$zipcode = stripHTML($_POST['zipcode']);


								//$pass = "tromalsnad"."pass1234";
								$stmt = $db->prepare("INSERT INTO Users(email,password,fname,lname,address,city,stateabbr,zipcode) VALUES(?,password(?),?,?,?,?,?,?)");
								$stmt->bind_param('sssssssi',$email,$pass,$fname,$lname,$address,$city,$state,$zipcode);
								$stmt->execute();
							
						
							}
						}
					}
				}
			}
		}
	}
}

if(!empty($_POST['delete-user']))
{
	if(!empty($_POST['user']))
	{
		$userid = stripHTML($_POST['user']);
		
		$stmt = $db->prepare("UPDATE Users SET disply = false WHERE U_ID = ?");
		$stmt->bind_param('i',$userid);
		$stmt->execute();
		
	}
	
}

if(!empty($_POST['update-product']))
{
	if(!empty($_POST['product']))
	{
		$userid = stripHTML($_POST['product']);
		
		if(!empty($_POST['name']))
		{
			$name = stripHTML($_POST['name']);
			
			$stmt = $db->prepare("UPDATE Products SET name = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$name,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['category']))
		{
			$category = stripHTML($_POST['category']);
			
			$stmt = $db->prepare("UPDATE Products SET category = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$category,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['metadata']))
		{
			$metadata = stripHTML($_POST['metadata']);
			
			$stmt = $db->prepare("UPDATE Products SET metadata = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$metadata,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['brand']))
		{
			$brand = stripHTML($_POST['brand']);
			
			$stmt = $db->prepare("UPDATE Products SET brand = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$brand,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['image']))
		{
			$image = stripHTML($_POST['image']);
			
			$stmt = $db->prepare("UPDATE Products SET image = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$image,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['gender']))
		{
			$gender = substr(strtoupper(stripHTML($_POST['gender'])),0,1);
			
			$stmt = $db->prepare("UPDATE Products SET gender = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$gender,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['price']) && is_numeric($_POST['price']))
		{
			$price = stripHTML($_POST['price']);
			
			$stmt = $db->prepare("UPDATE Products SET price = ? WHERE P_ID = ?");
			$stmt->bind_param('ii',$price,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['description']))
		{
			$description = stripHTML($_POST['gender']);
			
			$stmt = $db->prepare("UPDATE Products SET description = ? WHERE P_ID = ?");
			$stmt->bind_param('si',$description,$userid);
			$stmt->execute();
		}
		
	}
}

//INSERT INTO Products(name,category,metadata,brand,image,price,gender,description) values(?,?,?,?,?,?,?,?)
if(!empty($_POST['add-product']))
{
	//if(!empty($_POST['product']))
	//{
		//$pid = stripHTML($_POST['product']);
		
		if(!empty($_POST['name']))
		{
			$name = stripHTML($_POST['name']);
			
			if(!empty($_POST['category']))
			{
				$category = stripHTML($_POST['category']);
				
				if(!empty($_POST['metadata']))
				{
					$metadata = stripHTML($_POST['metadata']);
			
					if(!empty($_POST['brand']))
					{
						$brand = stripHTML($_POST['brand']);
			
						if(!empty($_POST['image']))
						{
							$image = stripHTML($_POST['image']);
			
							if(!empty($_POST['price']) && is_numeric($_POST['price']))
							{
								$price = stripHTML($_POST['price']);

								if(!empty($_POST['gender']))
								{
									$price = stripHTML($_POST['gender']);
									
									if(!empty($_POST['description']))
									{
										$description = stripHTML($_POST['description']);

										$stmt = $db->prepare("INSERT INTO Products(name,category,metadata,brand,image,price,gender,description) values(?,?,?,?,?,?,?,?)");
										$stmt->bind_param("sssssiss",$name,$category,$metadata,$brand,$image,$price,$gender,$description);
										$stmt->execute();
									}
								
								}
							}
						}
					}
				}
			}
		}
	//}
}


if(!empty($_POST['delete-product']))
{
	if(!empty($_POST['product']))
	{
		$pid = stripHTML($_POST['product']);
		
		$stmt = $db->prepare("UPDATE Products SET disply = false WHERE P_ID = ?");
		$stmt->bind_param('i',$pid);
		$stmt->execute();
		
	}
	
}






function stripHTML($str)
{
	if(strchr($str,"<")){
	$regex = "<(.|\n)*?";

	$str = preg_replace($regex,'',str);
	}
	return $str;
}


?>
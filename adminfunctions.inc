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
		
		if(!empty($_POST['zipcode']) && is_numeric($_POST['accesslevel']))
		{
			$zipcode = stripHTML($_POST['zipcode']);
			
			$stmt = $db->prepare("UPDATE Users SET zipcode = ? WHERE U_ID = ?");
			$stmt->bind_param('ii',$zipcode,$userid);
			$stmt->execute();
		}
		
		if(!empty($_POST['accesslevel']) && is_numeric($_POST['accesslevel']))
		{
			if($_POST['accesslevel'] >==0 && $_POST['accesslevel'] <== 4 || $_POST['accesslevel'] === 10)
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
	if(!empty($_POST['user']))
	{
		$userid = stripHTML($_POST['user']);
		
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
			
							if(!empty($_POST['zipcode']) && is_numeric($_POST['accesslevel']))
							{
								$zipcode = stripHTML($_POST['zipcode']);

								if(!empty($_POST['accesslevel']) && is_numeric($_POST['accesslevel']))
								{
									if($_POST['accesslevel'] >==0 && $_POST['accesslevel'] <== 4 || $_POST['accesslevel'] === 10)
									{
										$access = stripHTML($_POST['accesslevel']);
										$pass = "tromalsnad"."pass1234";
										$stmt = $db->prepare("INSERT INTO Users(email,password,fname,lname,address,city,stateabbr,zipcode,accesslevel) VALUES(?,password(?),?,?,?,?,?,?,?)");
										$stmt->bind_param('sssssssii'$email,$pass,$fname,$lname,$address,$city,$state,$zipcode,$access);
										$stmt->execute();
									}
									else
									{
										$pass = "tromalsnad"."pass1234";
										$stmt = $db->prepare("INSERT INTO Users(email,password,fname,lname,address,city,stateabbr,zipcode) VALUES(?,password(?),?,?,?,?,?,?)");
										$stmt->bind_param('sssssssi'$email,$pass,$fname,$lname,$address,$city,$state,$zipcode);
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

if(!empty($_POST['delete-user']))
{
	if(!empty($_POST['user']))
	{
		$userid = stripHTML($_POST['user']);
		
		$stmt = $db->prepare("UPDATE Users SET display = false WHERE U_ID = ?");
		$stmt->bind_param('i',$userid);
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
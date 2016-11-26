<?php
include('db.inc');
function validateCategory($category)
{
	global $db;
	if(!empty($category))
	{
		$catname = strtolower($category);
		//$stmt = $db->prepare("SELECT count(*) AS num_cat FROM Category WHERE category=?");
		$stmt = $db->query("SELECT category FROM Category");
		//$stmt->bind_param('s',$catname);
		//$stmt->execute();
		$catlist = array();
		while($obj = $stmt->fetch_object()) $catlist[] = $obj;
		
		foreach($catlist as $c)
		{
			if(strcmp($c->category,$category)===0)
			{
				return true;
			}
		}
		return false;
		
		/*if($catlist->num_cat === 0)
		{
			return false;
		}
		else
		{
			return true;
		}*/
	}
	else
	{
		return false;
	}
}

function validateBrand($brand)
{
	global $db;
	if(!empty($category))
	{
		$brandname = strtolower($brand);
		//$stmt = $db->prepare("SELECT count(*) AS num_cat FROM Category WHERE category=?");
		$stmt = $db->query("SELECT brand FROM Brands");
		//$stmt->bind_param('s',$catname);
		//$stmt->execute();
		$brandlist = array();
		while($obj = $stmt->fetch_object()) $brandlist[] = $obj;
		
		foreach($brandlist as $c)
		{
			if(strcmp($c->brand,$brandname)===0)
			{
				return true;
			}
		}
		return false;
		
		/*if($catlist->num_cat === 0)
		{
			return false;
		}
		else
		{
			return true;
		}*/
	}
	else
	{
		return false;
	}
}

function validateGender($gender)
{
	$newgender = strtoupper($gender);
	
	if(!empty($newgender))
	{
		if(strcmp($newgender,"M")===0 || strcmp($newgender,"F")===0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}

function validateEmail($email)
{
	if(filter_var($email, FILTER_VALIDATE_EMAIL)) 
	{
		return $email;
	}
	else
	{
		return false;
	}

}

?>
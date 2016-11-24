<?php
function validateCategory($category)
{
	if(!empty($category))
	{
		$catname = strtolower($category);
		$stmt = mysqli_prepare($db, "SELECT category FROM Category WHERE category=?");
		
		$stmt->bind_param("s",$catname);
		if(!$stmt->execute())
		{
			return false;
		}
		else
		{
			return true;
		}
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

?>
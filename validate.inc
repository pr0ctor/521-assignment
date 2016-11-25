<?php
include('db.inc');
function validateCategory($category)
{
	global $db;
	if(!empty($category))
	{
		$catname = strtolower($category);
		$stmt = $db->prepare("SELECT count(*) AS num_cat FROM Category WHERE category='?'");
		
		$stmt->bind_param('s',$catname);
		$stmt->execute();
		$catlist = array();
		while($obj = $stmt->fetch_object()) $catlist[] = $obj;
		if($catlist->num_cat === 0)
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
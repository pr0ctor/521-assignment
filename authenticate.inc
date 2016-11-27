<?php
session_start(); // Doesn't hurt to call it twice (or more)
// I use $_REQUEST which checks both $_GET and $_POST
if(!empty($_REQUEST['logout'])) unset($_SESSION['user']);
// I'm only using $_POST for logging in – make sure you got your form names correct!
if(!empty($_POST['email']) && !empty($_POST['password'])) 
{
	$salt = "tromalsnad";
	$stmt = $db->prepare("
	select U_ID,fname,lname,accesslevel from Users
	where email='?'
	and password=password('?')
	");
	$stmt->bind_param('ss',$_POST['email'],$salt.$_POST['password']);
	$stmt->execute();
	$stmt->bind_result($id,$fname,$lname,$access);
	if($stmt->fetch()) 
	{
		$array = array(id=>$id,fname=>$fname,lname=>$lname,access=>$access);
		$_SESSION['user']=$array;
	}
}
if(empty($_SESSION['user']))
	header('Location: login.html'); // Redirect if not logged in
?>
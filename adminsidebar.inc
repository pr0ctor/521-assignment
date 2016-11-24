<div id="sidebar-wrapper">
	<ul class="sidebar-nav">
		<li><a href="myaccount.html">My Account</a></li>
		<li><a href="myorders">My Orders</a></li>
		<?php if($_SESSION['access'] < 10) { print "<li>Admin Functions</li>";} ?>
		<?php if($_SESSION['access'] === 0) { print "<li><a href="">Manage Users</a></li>"; ?>
		<?php if($_SESSION['access'] <== 2) { print "<li><a href="">Manage Products</a></li>"; ?>
		<?php if($_SESSION['access'] <== 3) { print "<li><a href="">Manage Inventory</a></li>"; ?>
		<?php if($_SESSION['access'] === 4 || $_SESSION['access'] <== 1) { print "<li><a href="">View Orders</a></li>"; ?>
		<?php if($_SESSION['access'] === 4 || $_SESSION['access'] <== 1) { print "<li><a href="">Process Orders</a></li>"; ?>
	</ul>
</div>
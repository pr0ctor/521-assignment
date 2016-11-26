<div id="sidebar-wrapper">
	<ul class="sidebar-nav">
		<li><a href="myaccount.html">My Account</a></li>
		<li><a href="myorders">My Orders</a></li>
		<?php if($_SESSION['user']['access'] < 10) { print "<li><a>Admin Functions</a></li>";} ?>
		<?php if($_SESSION['user']['access'] === 0) { print "<li><a href='manageusers.html'>Manage Users</a></li>";} ?>
		<?php if($_SESSION['user']['access'] <= 2) { print "<li><a href='manageproducts.html'>Manage Products</a></li>";} ?>
		<?php if($_SESSION['user']['access'] <= 3) { print "<li><a href='manageinventory.html'>Manage Inventory</a></li>";} ?>
		<?php if($_SESSION['user']['access'] == 4 || $_SESSION['user']['access'] <= 1) { print "<li><a href='vieworders.html'>View Orders</a></li>";} ?>
		<?php if($_SESSION['user']['access'] == 4 || $_SESSION['user']['access'] <= 1) { print "<li><a href='processorders.html'>Process Orders</a></li>";} ?>
	</ul>
</div>
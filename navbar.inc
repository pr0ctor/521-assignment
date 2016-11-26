    <div class="navbar navbar-inverse navbar-fixed-top">
      <div class="container">
        <a href="index.html" class="navbar-brand"><img style = "margin-top: -14px;" src="images/DMHeader.png" width="200px"></a>
        <button class="navbar-toggle" data-toggle="collapse" data-target=".navHeaderCollapse">
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>

        <!-- Sets the Mens and Womens dropdown bars -->
        <div class="collapse navbar-collapse navHeaderCollapse">
          <ul class="nav navbar-nav navbar-right">
            <li class = "dropdown">
              <a href="default.asp" class="dropdown-toggle" data-toggle="dropdown">Men <b class="caret"></b></a>
                <ul class="dropdown-menu">
                  <li><a href="products.html?category=shirt&gender=M">Shirts</a></li>
                  <li><a href="products.html?category=sweater&gender=M">Sweaters</a></li>
                  <li><a href="products.html?category=jacket&gender=M">Jackets</a></li>
                  <li><a href="products.html?category=pant&gender=M">Pants</a></li>
                  <li><a href="products.html?category=shoe&gender=M">Shoes</a></li>
                </ul>
            </li>
            <li class = "dropdown">
              <a href="default.asp" class="dropdown-toggle" data-toggle="dropdown">Women <b class="caret"></b></a>
                <ul class="dropdown-menu">
                  <li><a href="products.html?category=top&gender=F">Tops</a></li>
                  <li><a href="products.html?category=jacket&gender=F">Jackets</a></li>
                  <li><a href="products.html?category=dress&gender=F">Dresses</a></li>
                  <li><a href="products.html?category=skirt&gender=F">Skirts</a></li>
                  <li><a href="products.html?category=shoe&gender=F">Shoes</a></li>
                </ul>
            </li>
            <li><a href="brands.html">Brands</a></li>

            <!-- Dropdown for the Login Bar -->
            <?php 
			$login="            <li class='dropdown'>
              <a href='#' class='dropdown-toggle' data-toggle='dropdown'>Login<span class='caret'></span></a>
			          <ul id='login-dp' class='dropdown-menu'>
				          <li>
					          <div class='row'>
							        <div class='col-md-12'>
								        <form class='form' role='form' method='post' action='myaccount.html' method='post' accept-charset='UTF-8'>
										      <div class='form-group'>
											      <label class='sr-only' for='email-entry'>Email Address</label>
											      <input type='email' class='form-control' name='email' id='email-entry' placeholder='Email address' required>
										      </div>
										   <div class='form-group'>
											   <label class='sr-only' for='password-entry'>Password</label>
											   <input type='password' class='form-control' name='password' id='password-entry' placeholder='Password' required>
										   </div>
										   <div class='form-group'>
											   <button type='submit' class='btn btn-primary btn-block' value='login'>Sign in</button>
										   </div>
								       </form>
							       </div>
							       <div class='bottom text-center'>Don't have an account? <a href='signup.html'><b>Sign up</b></a></div>
					         </div>
				         </li>
			         </ul>
             </li>";
			 
			 
			 if(isset($_SESSION['user']))
			 {
				print "<li><a href='myaccount.html'>".$_SESSION['user']['fname']." ".$_SESSION['user']['lname']."</a></li>";
				print "<li><a href='myaccount.html?logout=true'>Logout</a></li>";
			 }
			 else
			 {
				print $login;
			 }
			
			?>
			
			<!--<li class="dropdown">
              <a href="#" class="dropdown-toggle" data-toggle="dropdown">Login<span class="caret"></span></a>
			          <ul id="login-dp" class="dropdown-menu">
				          <li>
					          <div class="row">
							        <div class="col-md-12">
								        <form class="form" role="form" method="post" action="myaccount.html" method="post" accept-charset="UTF-8">
										      <div class="form-group">
											      <label class="sr-only" for="email-entry">Email Address</label>
											      <input type="email" class="form-control" name="email" id="email-entry" placeholder="Email address" required>
										      </div>
										   <div class="form-group">
											   <label class="sr-only" for="password-entry">Password</label>
											   <input type="password" class="form-control" name="password" id="password-entry" placeholder="Password" required>
										   </div>
										   <div class="form-group">
											   <button type="submit" class="btn btn-primary btn-block" value="login">Sign in</button>
										   </div>
								       </form>
							       </div>
							       <div class="bottom text-center">Don't have an account? <a href="signup.html"><b>Sign up</b></a></div>
					         </div>
				         </li>
			         </ul>
             </li>-->

             <!-- Dropdown for the Cart -->
             <li class="dropdown">
               <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button" aria-expanded="false"><span class="glyphicon glyphicon-shopping-cart"></span><span class="caret"></span></a>
               <ul class="dropdown-menu dropdown-cart" role="menu">
               <li>
                 <span class="item">
                   <span class="item-left">
                     <img src="images/placeholder.jpg" alt="" />
                       <span class="item-info">
                         <span>Brand</span>
                         <span>Item Name</span>
                         <span>Price</span>
                         <span>Size</span>
                       </span>
                   </span>
                   <span class="item-right">
                     <button class="btn btn-xs btn-danger pull-right">Remove</button>
                   </span>
                 </span>
               </li>
             </li>
             <li class="divider"></li>
             <li><a class="text-center" href="">View Cart</a></li>
             </ul>

             <!-- Search Bar -->
            <li><input type="search" name="search" placeholder="Search.."></li>
          </ul>
        </div>
      </div>
    </div>
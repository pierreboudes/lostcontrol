<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
	<head>
		<title>test</title>
		<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	</head>

	<body>
		<?php
			if(!isset($GET['coordX']))
			{
				$test='p';
			}
			if($_GET['coordX']<10&&$_GET['coordX']>-10)
			{
				$test ='s';
			}
			else
			{
			
				if($_GET['joyR']=="true")
				{
					$test = "d\n0.5 -0.5";
				}
			
				if($_GET['joyL']=="true")
				{
					$test = "g\n0.5 0.5";
				}
			
				if($_GET['joyU']=="true")
				{
					$test = "a\n2.0 0.0";
				}
			
				if($_GET['joyD']=="true")
				{
					$test = "r\n-2.0 0.0";
				}
			}
			
			$monfichier = '/var/www/commande.txt';
			$fp = fopen($monfichier,'w');
			fputs($fp,$test);
			fclose($fp);
			header('Location: index.html');
		
		?>
	</body>
</html>

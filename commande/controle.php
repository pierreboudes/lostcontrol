<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
	<head>
		<title>controle</title>
		<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	</head>
	<body>
		<p>
			<?php 
				sleep(2);
				$monfichier = 'commande.txt';
				touch($monfichier);
				sleep(2);
				header('Location: commande.html');

			?>

		</p>
	</body>
</html>

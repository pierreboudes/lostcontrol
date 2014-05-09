<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
	<head>
		<title>test</title>
		<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	</head>

	<body>

		<?php


			if(isset($_POST['commande']))
			{
				echo "envoi";?></br><?php
				switch($_POST['commande'])
				{
					case "stop":
						echo "stop";
						$test = "s";
					break;
					case "commencer":
						echo "commencer";
						$test = "c";
					break;
					case "avancer":
						echo "avancer";
						$test = "a\n2.0 0.0";
					break;
					case "gauche":
						echo "gauche";
						$test = "g\n0.5 0.5";
					break;
					case "droite":
						echo "droite";
						$test = "d\n0.5 0.5";
					break;
					case "reculer":
						echo "reculer";
						$test = "r\n-2.0 0.0";
					break;
				}
				$monfichier = 'commande.txt';
				$fp = fopen($monfichier,'w');
				fputs($fp,$test);
				fclose($fp);
			}
			else
			{
				echo "aucun envoi";
			}
			
		?>
		<form method="post" action="test.php">
		
		<button name="commande" value="stop"><img src="stop.jpg" weight="46px" height="40px"/></button>
		<button name="commande" value="commencer"><img src="play.gif" weight="46px" height="40px"/></button></br></br></br>
		<table>
		<tr>
			<td></td>
			<td>
				<button name="commande" value="avancer"><img src="haut.jpg" weight="46px" height="40px"/></button>
			</td>
			<td></td>
		</tr>
			<td>
				<button name="commande" value="gauche"><img src="gauche.jpg" weight="46px" height="40px"/></button>
			</td>
			<td>
				<button name="commande" value="reculer"><img src="bas.jpg" weight="46px" height="40px"/></button>
			</td>
			<td>
				<button name="commande" value="droite"><img src="droite.jpg" weight="46px" height="40px"/></button>
			</td>
		<tr>
		</tr>
		</table>


		</form>

	</body>
</html>

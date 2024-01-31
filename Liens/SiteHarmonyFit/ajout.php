<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Formulaire</title>
</head>
<body>
	<?php 
        $servername = "localhost";
		$username = "root";
		$password = "";
		$dbname = "harmony fit";

		$nom = $_POST['nom'];
		$prenom = $_POST['prenom'];
		$date = $_POST['date'];
        $mail = $_POST['mail'];
        $code = $_POST['code'];

		
		$conn = mysqli_connect($servername, $username, $password, $dbname);
		
		if (!$conn) {
		  die("Connection failed: " . mysqli_connect_error());
		}

		$sql = "INSERT INTO adhrerents (id, Nom, Prenom, Date_Naissance, Email, cp) VALUES (null, '$nom', '$prenom', '$date', '$mail', '$code')";

		if (mysqli_query($conn, $sql)) {
		  echo "Adhrérent ajouté";
		} else {
		  echo "Error: " . $sql . "<br>" . mysqli_error($conn);
		}


		mysqli_close($conn);
    ?>

</body>
</html>
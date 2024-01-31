<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title></title>
	<style>
		body {
			background-color: #f5f5f5;
			font-family: Arial, sans-serif;
		}
		form {
			background-color: #fff;
			padding: 20px;
			border-radius: 5px;
			box-shadow: 0px 0px 10px #ccc;
			max-width: 400px;
			margin: auto;
		}
		input[type="submit"] {
			background-color: #4CAF50;
			color: white;
			cursor: pointer;
			transition: all 0.2s ease-in-out;
		}
		input[type="submit"]:hover {
			background-color: blue;
		}
	</style>
</head>
<body>
	<form action="ajout.php" method="post">
		<input type="text" placeholder="Titre" name="nom">
		<input type="text" placeholder="Auteur" name="prenom">
		<input type="text" placeholder="Genre" name="Date">
        <input type="text" placeholder="Genre" name="mail">
        <input type="text" placeholder="Genre" name="code">
		<input type="submit" value="Ajouter">
	</form>
</body>
</html>
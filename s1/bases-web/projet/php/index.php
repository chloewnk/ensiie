<?php
    $nom = "";
    $desc = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $nom = isset($_POST['nom']) ? htmlspecialchars($_POST['nom']) : "";
        $desc = isset($_POST['desc']) ? htmlspecialchars($_POST['desc']) : "";
    }
?>

<DOCTYPE html>
<html>
    <head>
        <title>idkidk</title>
    </head>

    <body>
        <h1>Site habit tracker & TODO list</h1>

        <div>
            <h2>ToDo</h2>
            <label>

			    <span>Rechercher : </span>
			    <input type="input"  placeholder="Recherche">
                <input type="submit" value="Envoyer">

                <br>

                <span>Ajouter : </span>
                <form action="index.php" method="post"></form>
                    <input type="text" name="nom" value = <?php echo $nom ?>/>
                    <input type="text" name="desc" value = <?php echo $desc ?>/>
                    <input type="text" name="label"/>
                    <button type="submit">Envoyer</button>
                </form>
                test : <?php echo $nom;  ?>


                <table>
                    <tr><th>NOM</th><th>DESC</th><th>ACTION</th></tr>
                    <tr><th> <?php echo $nom; ?> </th><th> <?php echo $desc; ?> </th><th>ACTION</th></tr>

                </table>

		    </label>
        </div>

    </body>
</html>
<?php
$name = $desc = "";
$success_message = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $name = htmlspecialchars($_POST["name"]);
    $desc = htmlspecialchars($_POST["desc"]);

    if (!empty($name) && !empty($desc)) {
        $success_message = "Tâche ajoutée avec succès !";
        
    } else {
        $success_message = "Veuillez remplir tous les champs.";
    }
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Site habit tracker & TODO list</title>
</head>
<body>

    <h1>Site habit tracker & TODO list</h1>

    <div>
        <h2>Mon ToDo</h2>
        
        <?php if (!empty($success_message)): ?>
            <div class="message"><?php echo $success_message; ?></div>
        <?php endif; ?>

        <form action="index.php" method="POST">
            <label for="name">Nom :</label>
            <input type="text" id="name" name="name" value="<?php echo $name; ?>" required>

            <label for="desc">Description :</label>
            <input type="text" id="desc" name="desc" value="<?php echo $desc; ?>" required>

            <button type="submit">Ajouter</button>
        </form>

        <table>
            <thead>
                <tr>
                    <th>NOM</th>
                    <th>DESCRIPTION</th>
                    <th>ACTION</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><?  echo !empty($name) ? $name : "Exemple : Boire de l'eau"; ?></td>
                    <td><?php echo !empty($desc) ? $desc : "Objectif 2L par jour"; ?></td>
                    <td><button>Supprimer</button><button>Modifier</button></td>
                </tr>
            </tbody>
        </table>
    </div>

</body>
</html>

CHEN YuanDong Théo 12212843
LI Christophe 12205895

La partie A est un jeu en 2D :

Il y a 2 manières de lancer le jeu:
- Soit en initialisant manuellement les données du Pion et de la taille de la Grille. Les Pièges et le Trésor seront alors généré aléatoirement en fonction de ces données.
- Soit en important un fichier déjà existant contenant la taille de la Grille ainsi que ses données comprenant la position du Pion, des Pièges et du Trésor.

Les pièges sont signalées en Rouges
le Trésor en Magenta
Le Pion en Vert
Les Murs en Jaunes

On peut jouer au jeu de 2 manières différentes :
- Soit en contrôlant chaque déplacement avec les flèches directionnels du clavier
- Soit en appuyant sur une flèche et le déplacement se poursuivra jusqu'à heurter une structure de la Grille (Mur, Pièges)

Lorsque le Pion atterrit sur un Trésor, alors le nombre total de point augmente de 1, et un nouveau Trésor est généré.
Lorsque le Pion atterrit sur un Piège, alors la partie se termine affichant le nombre total de point accumulé durant la partie.

Il est possible d'écourter la partie en appuyant sur la touche ECHAP pour quitter la partie.

Partie B est aussi un jeu en 2D qui reprend le même principe de la Partie A en rajoutant un Bloc évènement supplémentaire :

Les Téléporteurs en Noir et qui téléportent aléatoirement le Pion à un endroit aléatoire sur la Grille tout en faisant attention à ne pas atterrir sur un Mur, un Piège , un Trésor ou un Téléporteur.

Ce jeu comprend 3 différents niveaux : 
- Niveau 1 : une sorte de niveau d'introduction pour se familiariser avec le jeu, les déplacements et les différentes structures sur la grille.
- Niveau 2 : un Grand labyrinthe avec plusieurs l'implémentation des téléporteurs.
- Niveau 3 : 2 labyrinthes avec le déplacement des 2 Pions synchronisés dont le but est que les 2 Pions arrivent en même temps sur les Trésors. Si un des deux Pions atterrit sur un piège, alors c'est la fin de la partie.

Pour passer d'un niveau à l'autre, il suffit d'appuyer sur la touche ESPACE et le niveau suivant se lance.
Si le Trésor disparaît pour une raison obscure, alors il est possible de le régénérer grâce à la touche BackSpace qui permet de générer un nouveau Trésor sur la Grille.

Les 3 niveaux utilisent la lecture de fichier pour lancer les différents niveaux.

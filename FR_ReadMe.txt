
   ___                   _      _                       _       _    _
  |_  |                 | |    (_)                     (_)     | |  (_)
    | |  ___  _   _     | |     _  _ __    __ _  _   _  _  ___ | |_  _   __ _  _   _   ___
    | | / _ \| | | |    | |    | || '_ \  / _` || | | || |/ __|| __|| | / _` || | | | / _ \
/\__/ /|  __/| |_| |    | |____| || | | || (_| || |_| || |\__ \| |_ | || (_| || |_| ||  __/
\____/  \___| \__,_|    \_____/|_||_| |_| \__, | \__,_||_||___/ \__||_| \__, | \__,_| \___|
                                           __/ |                           | |
                                          |___/                            |_|


PRINCIPE DU JEU

	Le but du jeu est de deviner un mot dans une langue choisie à partir d'une image.


FONCTIONNALITÉS

	Le jeu dispose actuellement :
		- Mode solo
		- Mode 2 joueurs
		- 5 THÈMES (Animaux, Fruits, Légumes, Métiers, Outils, Sports)(environ 1200 mots avec 5 images par mot)
		- 3 NIVEAUX (Facile, Moyen, Difficile)
		- 4 LANGUES (Français, Anglais, Allemand, Espagnol)
		- Ajout d'un mot dans la base de données (Fonctionne pour le mode 2 joueurs uniquement.)
		  (Les images doivent être dans un dossier lui-même dans le bon thème et bien nommé)
		   	Si vous voulez tester cette fonctionnalité :
				- j'ai ajouté un dossier test dans "animaux" contenant 5 fausses images.
				- cliquer sur "animaux"
				- cliquer sur "ajoute un mot"
				- entrer donc le nouveau mot "test" (Si vous entrez un mot déjà existant, le champ s'efface et il faut recommencer)
				- entrer tour à tour les traductions anglaises, allemandes et espagnoles
				- vous pouvez maintenant tester en mode 2 joueurs.
				- le J1 écrit "test" et les images apparaissent pour le J2.
			  //!\\
			On limite cet ajout à 100 mots sur la session et lorsque vous fermez le jeu, les mots ajoutés ne sont pas enregistrer sur la session suivante.
			Cependant, on les enregistre dans un fichier, ils seront peut-être implémentés dans une prochaine mise à jour.


NÉCESSAIRE À L'INSTALLATION

	Installation de gcc (linux):	 		sudo apt-get install gcc
	Les librairies C suivantes (linux):
		~~SDL2~~ 	(core) 			sudo apt-get install libsdl2-2.0-0 && sudo apt-get install libsdl2-dev
		~~SDL2(doc)~~ 	(optionnel) 		sudo apt-get install libsdl2-doc
		~~SDL2_image~~ 	(images) 		sudo apt-get install libsdl2-image-2.0-0 && sudo apt-get install libsdl2-image-dev
		~~SDL2_ttf~~ 	(police) 		sudo apt-get install libsdl2-ttf-2.0-0 && sudo apt-get install libsdl2-ttf-dev


INSTALLATION

	~~1~~ Décompresser l'archive ou vous souhaitez installer le jeu

	~~2~~ À l'aide de votre terminal, un simple "make" suffit pour installer (dans le dossier précédemment décompressé)

	~~3~~ "./jeu" pour lancer le jeu


INFO UTILE
	
	- Tous les mots sont écrits sans caractère spécial.
	- À tout moment, vous pouvez alt+tab. Regardez le terminal, il affiche des infos. Mais jouer sans triche, c'est plus drôle !
	- Une partie est composée de 3 résolutions d'images.
	- En mode 2 joueurs, 6 résolutions d'images et les joueurs alternent leurs rôles
	- En facile et moyen, une aide sur le nombre de caractères du mot apparaît.
	- En moyen, le nombre d'erreurs est limité à 10.
	- En difficile, le nombre d'erreurs est limité à 5.
	- Score = (Entre 0-10s 10 points / 10-15s 7 points / 15-20s 5 points / 20-30s 3 points / >30s 0p) -(nb_essaie)
	- Fonctionnalité en jeu :
		~ touche "del"-----------------efface un caractère
		~ touche "suppr"---------------efface le mot
		~ bouton "del"-----------------efface le mot
		~ bouton "report" (triangle)---report le lien de l'image dans report.csv (l'image ne correspond pas au mot.)

( ͡° ᴗ ͡°) Avez-vous trouvé la touChe qui Change la Couleur du fond ??


DÉROULEMENT PARTI

	-->Dans un premier temps, il faudra sélectionner tous les paramètres de la partie dans le menu :

		- Langue de jeu
		- Nombre de joueurs
		- Thème
		- Difficulté

	~~~1 joueur~~~

		- Appuyer sur le bouton "START".
		- Écrire le nom du joueur.
		- Une image apparaît.
		- Le joueur peut alors écrire le mot correspondant à l'image dans la langue choisie.
		- S'il trouve, le panneau victoire apparaît avec le score sinon le mot apparaît dans l'historique.
		- La fin d'une partie intervient lorsque le joueur à trouver 3 images.

	~~~2 joueurs~~~

		- Appuyer sur le bouton "START".
		- Écrire le nom du joueur 1 puis du joueur 2.
		- Joueur 1 : écrit un mot à trouver par le joueur 2.
		- Si le mot n'existe pas, le champ s'efface et il faut recommencer la saisie.
		- Sinon, l'image s'affiche et le joueur 2 peut alors essayer de deviner le mot grâce à l'image dans la langue sélectionnée.
		- Quand il trouve, l'écran Victoire avec le score apparaît sinon le mot apparaît dans l'historique.
		- Les rôles s'alterne et le Joueur 2 peut écrire son mot.
		- La fin d'une partie intervient lorsque les joueurs ont trouvé 3 images chacun.
	    - Le nom du gagnant apparait alors à l'écran


FICHIERS SOURCE

	main.c 		--> Initialisations des données et gestion du programme
	menu.c 		--> Affichage du menu/gestion des paramètres de la partie
	hash.c 		--> Fonctions liées à la table de hachage
	jeu.c 		--> Fonctions liées au jeu
	fonctions.c 	--> Autres fonctions du jeu


FICHIERS GÉNÉRÉS

	reports_img.txt --> Lien des images reporter lors du jeu
	score.csv       --> CSV contenant les scores des différentes parties (Difficulté;nom;score;score_max(=30 10 par partie)

DONNÉES

	~Fichiers permettant de charger les données :
		"fichiers/mot.csv" 1 ligne --> 1 mot
			STRUCTURE (mot_français;thème;mot_Anglais;mot_Allemand;mot_Espagnol)
	~Images
		"images/jeu/theme/mot/1-5.jpg"
			- 5 thèmes
			- n mots par thème
			- 5 images par mot
	~Les données sont chargées dans un tableau (mots en français) ainsi que dans une table de hachage (toutes les données)
		Fonction de hachage : HachageASCII() "src/hash.c"


MODIFICATION DONNÉES

	//!\\ ATTENTION //!\\
		Si vous voulez modifier ce fichier (ajout ou suppression)
			- Il faut modifier toutes les constantes dans "src/header/constante.h"
				TAB_H_SIZE 	= taille de la table de hachage environ 5 * nb mots = optimisé
				NB_MOTS		= nombre de mots
				THEME_DEBUT 	= numéro de ligne du premier mot - 1
				THEME_FIN	= numéro de ligne du dernier mot - 1
			OUBLIER PAS d'enlever 1 au numéro de ligne
	
			- Il faut ajouter un dossier contenant les 5 images du mot dans "images/jeu/"theme""
				~Le dossier doit être placé dans le bon thème.
				~Le nom du dossier contenant les images doit être le nom du mot en français
				~Le nom des 5 images doit être respectivement de "1.jpg" à "5.jpg"
	
			- Pour télécharger les images, vous pouvez utiliser un des scripts pythons dans "images/google-images-download/google_images_download/script_download"
				- ouvrer d'abord le script dans un éditeur de texte
				- écrire les mots dans la liste search_query sous le même format que l'exemple
				- exécuter : "python3 script_theme.py"
		
			- Pour renommer toutes les images d'un coup, vous pouvez utiliser le script rename.py
				- mettre tous les dossiers dans images/rename
				- exécuter : "python3 rename.py"
	
			- Les dossiers sont nommés au téléchargement (mot thème) vous pouvez supprimer le thème de tous les dossiers en procédant comme ceci.
				- Ctrl + a : sélectionner tous les dossiers
				- F2 : renommer
				-(Debian) Choisir un pattern
					Supprimer les n caractères du thème en partant de la droite
				-(Ubuntu) Rechercher le texte et remplacer le texte
					Ancien texte : "thème" et nouveau texte : "vide"


CONTACT

	Si vous avez des problèmes, idées où des suggestions, merci de me contacter par mail :

		nicolas.auvray@u-picardie.fr

░█████╗░██╗░░░██╗██╗░░░██╗██████╗░░█████╗░██╗░░░██╗░░░░░███╗░░██╗██╗░█████╗░░█████╗░██╗░░░░░░█████╗░░██████╗
██╔══██╗██║░░░██║██║░░░██║██╔══██╗██╔══██╗╚██╗░██╔╝░░░░░████╗░██║██║██╔══██╗██╔══██╗██║░░░░░██╔══██╗██╔════╝
███████║██║░░░██║╚██╗░██╔╝██████╔╝███████║░╚████╔╝░░░░░░██╔██╗██║██║██║░░╚═╝██║░░██║██║░░░░░███████║╚█████╗░
██╔══██║██║░░░██║░╚████╔╝░██╔══██╗██╔══██║░░╚██╔╝░░░░░░░██║╚████║██║██║░░██╗██║░░██║██║░░░░░██╔══██║░╚═══██╗
██║░░██║╚██████╔╝░░╚██╔╝░░██║░░██║██║░░██║░░░██║░░░░░░░░██║░╚███║██║╚█████╔╝╚█████╔╝███████╗██║░░██║██████╔╝
╚═╝░░╚═╝░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░░░░░╚═╝░░╚══╝╚═╝░╚════╝░░╚════╝░╚══════╝╚═╝░░╚═╝╚═════╝░
  _   _   ____        _  __     __
 | | | | |  _ \      | | \ \   / /
 | | | | | |_) |  _  | |  \ \ / / 
 | |_| | |  __/  | |_| |   \ V /  
 | |_| | | |     | |_| |    \ /   
  \___/  |_|      \___/      V  
  	
──────────────────────▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
─────────────────────█▓▓▓▓▓▓▓▓██▓▓▓▓█
────────────────────█▓▓▓▓▓▓▓▓█──█▓▄▄▓█
───────────────────█▓▓▓▓▓▓▓▓█───▀█──█▀
──────────────────█▓▓▓▓▓▓▓▓▓▓█──█────█
─────────────────█▓▓▓▓▓▓▓▓▓▓▓▓█──█──█
────────────────█▓▓▓▓▓▓▓▓▓▓▓▓▓▓█──▀▀
───────────────▄████████████████▄
───────────────██▀────────────▀██
───────────────██──────────────██
──────────────▄██▄────────────▄██▄
──────────────████████████████████
─────────────█────────────────────█
────────────█──────────────────────█
───────────█─────▄████▄──▄████▄─────█
───────────█───██▀────▀██▀────▀██───█
───────────█──██──▄▄▄──██──▄▄▄─▀██──█
──────────▄█████──███──██──███──█████▄
──────────██████──────████──────██████
──────────▀█▀─▀██▄▄▄███▀▀███▄▄▄██▀─▀█▀
───────────█────▀▀▀▀▀──────▀▀▀▀▀────█
───────────█──────▄▄───────▄▄───────█
───────────█▄──────▀▀▀▀▀▀▀▀▀───────▄█
───────────█▓█────────────────────█▓█
───────────█▓▓█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▓▓█
──────────▄██████████████████████████▄
──────────██▀──────────────────────▀██
────────▄█▀──█▄─▄█─█▀▀─█▀█─█▀█─█─█───▀█▄
────────██▀──█▀█▀█─█▄──█▄▀─█▄▀─█▄█───▀██
────────██▀──█───█─█▄▄─█─█─█─█─▄▄█───▀██
────────██▀──────────────────────────▀██
─────────█─█▀▐─█▐▀█▐─█▀─▀█▀▐▄─▄▌▐▀▌█▀─█
─────────█─█─▐▄█▐▄▀▐─▀█──█─▐▀█▀▌▐▄▌▀█─█
─────────█─█▄▐─█▐─█▐─▄█──█─▐───▌▐─▌▄█─█
─────────█▄▄────────────────────────▄▄█
──────────▀▀████████████████████████▀▀
────────────▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌
─────────────▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌
──────────────▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌
───────────────▐▓▓▓▓▓▓▓▌▐▓▓▓▓▓▓▓▌
────────────────▐▓▓▓▓▓▌──▐▓▓▓▓▓▌
────────────────▄████▀────▀████▄




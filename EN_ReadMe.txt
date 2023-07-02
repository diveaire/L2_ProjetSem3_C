
   ___                   _      _                       _       _    _
  |_  |                 | |    (_)                     (_)     | |  (_)
    | |  ___  _   _     | |     _  _ __    __ _  _   _  _  ___ | |_  _   __ _  _   _   ___
    | | / _ \| | | |    | |    | || '_ \  / _` || | | || |/ __|| __|| | / _` || | | | / _ \
/\__/ /|  __/| |_| |    | |____| || | | || (_| || |_| || |\__ \| |_ | || (_| || |_| ||  __/
\____/  \___| \__,_|    \_____/|_||_| |_| \__, | \__,_||_||___/ \__||_| \__, | \__,_| \___|
                                           __/ |                           | |
                                          |___/                            |_|


PRINCIPLE OF THE GAME

	The object of the game is to guess a word from a picture.


FEATURES

	The game features:
		- Single-player mode
		- 2 player mode
		- 5 THEMES (Animals, Fruits, Vegetables, Professions, Tools, Sports)(about 1200 words with 5 pictures per word)
		- 3 DIFFICULTIES (Easy, Medium, Hard)
		- 4 LANGUAGES (French, English, German, Spanish)
		- Added a word in the database (Functional in duo only)
		  (Images must be in the folder of the right theme and well named)
		  If you want to test this feature:
			- I added a test folder in "animaux" containing 5 fake images
			- Click on "animaux"
			- Click on "ajoute un mot !"
			- Therefore enter the new word "test" (If you enter an already existing word, the field is erased and you have to start again)
			- Enter in turn the English, German and Spanish translations
			- You can now test in 2player mode
			- The J1 writes "test" and the images appear for the J2
			//!\\
		We limited this to 100 words on the session and when you close the game, the added words are not saved on the next session
		However, we save them in a file and they may be implemented in a future update.


REQUIREMENTS
	
	Installing gcc (linux): 			sudo apt-get install gcc
	The following C libraries (linux):
		~~SDL2~~	(core)			sudo apt-get install libsdl2-2.0-0 && sudo apt-get install libsdl2-dev 
		~~SDL2(doc)~~	(optionnel)		sudo apt-get install libsdl2-doc 
		~~SDL2_image~~	(images)		sudo apt-get install libsdl2-image-2.0-0 && sudo apt-get install libsdl2-image-dev
		~~SDL2_ttf~~ 	(police)		sudo apt-get install libsdl2-ttf-2.0-0 && sudo apt-get install libsdl2-ttf-dev
	
	
SETUP

	~~1~~ Unzip the archive where you want to install the game.

	~~2~~ Using your terminal, a simple "make" is enough to install (In the folder previously unzipped).

	~~3~~ "./jeu" to launch the game
	
	
USEFUL INFORMATION
	- At any time you can alt+tab. The terminal displays info but playing without cheating is more fun
	- A game is composed of 3 images resolution
    - In 2 player mode, 6 image resolutions and players alternate their roles
	- In easy and medium, help on the number of characters in the word appears
	- On medium, the number of errors is limited to 10
	- In hard, the number of errors is limited to 5.
	- Score = (Between 0-10s 10 points / 10-15s 7 points / 15-20s 5 points / 20-30s 3 points / >30s 0p) -(nb_tries)
	-Game Feature:
		"return" key deletes a character
		"delete" key deletes the word
		"delete" button deletes the word
		"report" button (triangle) report the link of the image in report.csv (the image does not correspond to the word)

  ( ͡° ᴗ ͡°) did you find the button that Changes the background Color??


GAME PROCEDURE

	--> First, you will have to select all the parameters of the game in the menu:

		- Game language
		- Number of players
		- Theme
		- Difficulty

	~~~1 player~~~
	
		- Press the start button
		- Write the name of player
		- As soon as the start button is pressed, a random image appears
		- The player can then write the word corresponding to the image in the chosen language
		- If he finds, the victory panel appears with the score otherwise the word type appears in the history
		- The end of a game occurs when the player finds 3 images.

	~~~2 players~~~
	
		- Press the start button
		- Write the name of player 1 then the name of player 2
		- Player 1: writes a word for player 2 to find
		- If the word does not exist, the field is erased and you have to start typing again
		- Otherwise, the image is displayed and player 2 can then try to guess the word thanks to the image in the selected language
		- When he finds, the Victory screen with the score appears otherwise the word type appears in the history.
		- The roles alternate and Player 2 can write his word.
        - The end of a game occurs when the players have found 3 images each.
        - The name of the winner then appears on the screen

				
SOURCE FILES

	main.c 		--> Data initializations and program management
	menu.c 		--> Menu display / management of game parameters
	hash.c 		--> Functions related to hash tables
	jeu.c 		--> Game-related functions
	fonction.c 	--> Other game functions


FILES GENERATED
	
	reports_img.txt --> Link of images to report during the game
	score.csv	--> CSV containing the scores of the different parts  (difficulty;name1;name2;score;score_max(=30, 10 per game))

	
DATA

	~Files to load data:
		"fichiers/mot.csv" 1 line --> 1 word
		STRUCTURE (French_word; theme; English_word; German_word; Spanish_word)
	~Pictures
		" images/jeu/"theme"/"word"/1-5.jpg "
		-5 themes
		-n words per theme
		-5 images per word
	~The data is loaded into an array (French words) as well as a hash table (all data)
		Hash function: HachageASCII() "src/hash.c"			

DATA MODIFICATION

	//!\\ WARNING //!\\
		If you modify this file (add or delete),
			- You must modify all the constants in "src/header/constante.h"
				TAB_H_SIZE = size of the hash table around 5*nb words = optimized
				NB_MOTS = number of words
				THEME_DEBUT = line number of the first word - 1
				THEME_FIN = line number of the last word - 1
				REMEMBER to remove 1 from the line number

			- You must add a folder containing the 5 images of the word in "images/jeu/"theme""
				The folder must be placed in the correct theme.
				The name of the folder containing the images must be the name of the word in French
				The name of the 5 images must be respectively from "1.jpg" to "5.jpg"

			- To download the images, you can use one of the python scripts in "images/google-images-download/google_images_download/script_download/"
				-first open the script in a text editor
				-write the words in the search_query list in the same format as the example
				-execute: "python3 script_theme.py"

			- To rename all images at once, you can use the rename.py script
				-put all folders in images/rename
				-execute: "python3 rename.py"

			- The folders are named when downloading (word theme) you can remove the theme from all the folders by proceeding like this
				- ctrl + a: select all folders
				- F2: rename
				- (debian) Choose pattern
					remove the n characters from the theme starting from the right
				- (Ubuntu) Find text and replace text
					old text: "theme" and new text: "empty"


CONTACT 

	If you have any problems, ideas or suggestions, please contact me by email:
		 
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



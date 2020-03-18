	/*
	 Projet: snake
	 Auteur: Sylvain Guilbert
	*/
	#include <iostream>
	#include "Point.h"
	#include "Board.h"
	#include "snake.h"
	#include <unistd.h>

	int usleep(useconds_t usec);

	using namespace std;

	//https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c

	#define  TOUCHE_KEY_UP 1 // sert a définir les touche de mouvement
	#define  TOUCHE_KEY_DOWN 2
	#define  TOUCHE_KEY_LEFT 3
	#define  TOUCHE_KEY_RIGHT 4

	int kbhit(void)    /* Cette fonction retourne si une touche est appuyé par l'utilisateur https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c */
	{
		int ch, r;
		nodelay(stdscr, TRUE);

		ch = getch();
		if( ch == ERR)
			r = FALSE; 

		else
		{
			r = TRUE;
			ungetch(ch);
		}


		echo();
		nodelay(stdscr, FALSE);
		return(r);
	}

	int main()
	{
		int dirEnCours=TOUCHE_KEY_DOWN;//DIRECTION PAR DEFAULT: BAS

	  // pointeurs sur l'unique instance de la classe UniqueObject
		Board *fenetre;
	  // initialisation des pointeurs
		fenetre = Board::getInstance ();

		snake serpent(10,4);



		keypad (stdscr,true);
		noecho();
		while (true)
		{


			//SI TOUCHE CLAVIER APPUYEE(HAUT,BAS,GAUCHE,DROITE)
			if(kbhit()) {
				switch (getch()){
					case 259:
					dirEnCours = TOUCHE_KEY_UP;
					serpent.move(TOUCHE_KEY_UP);
					break;
					case 260:
					dirEnCours = TOUCHE_KEY_LEFT;
					serpent.move(TOUCHE_KEY_LEFT);
					break;
					case 258:
					dirEnCours = TOUCHE_KEY_DOWN;
					serpent.move(TOUCHE_KEY_DOWN);
					break;
					case 261:
					dirEnCours = TOUCHE_KEY_RIGHT;
					serpent.move(TOUCHE_KEY_RIGHT);
					break;
				}



			}else{ //move left
				serpent.move (dirEnCours);

			}
			serpent.affichSerpent();
			usleep (150000);// vitesse du serpent en micro seconde

		}
	    //getchar();
		fenetre->kill();
		return 0;
	};

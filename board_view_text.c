#include "board_view.h"
#include <assert.h>
#include <stdio.h>
#include "board.h"

#if defined CONFIG_TEXTUI

extern PieceType _boardSquares[3][3];

void BoardView_init (void)
{
}

void BoardView_free (void)
{
}

void BoardView_displayAll (void)
{
	char ligne[8];
	for(int i = 0; i< 3; i++){
		ligne[0] = '|';
		for(int j = 0; j<3; j++){
			if(_boardSquares[i][j] == NONE){
				ligne[j*2+1] = ' ';
				ligne[j*2+2] = '|';
			} else if(_boardSquares[i][j] == CIRCLE){
				ligne[j*2+1] = 'O';
				ligne[j*2+2] = '|';
			} else if(_boardSquares[i][j] == CROSS){
				ligne[j*2+1] = 'X';
				ligne[j*2+2] = '|';
			}
		}
		ligne[7] = '\0';
		printf("%s\n",ligne);
	}
}

void BoardView_displaySquare (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	BoardView_displayAll();
}

void BoardView_displayEndOfGame (GameResult result)
{
	if (result == DRAW)
		printf("Il n'y a pas de gagnant\n");
	if (result == CROSS)
		printf("Les Croix on gagner\n");
	if (result == CIRCLE)
		printf("Les Cercle on gagner\n");
}

void BoardView_displayPlayersTurn (PieceType thisPlayer)
{
	if (thisPlayer == CROSS)
		printf("Le joueur avec les croix dois joué\n");
	else 
		printf("Le joueur avec les cercle dois joué\n");
}

void BoardView_sayCannotPutPiece (void)
{
  printf("La piece ne peux pas etre posé ici\n");
}

#endif // defined CONFIG_TEXTUI









//
//	
//	| | | |
//	| | | |
//	| | | |
//
//
//
//
//

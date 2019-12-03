#include "board.h"
#include <stdio.h>

/**
 * Check if the game has to be ended. Only alignment from the last
 * modified square are checked.
 *
 * @param [in] boardSquares the board to check
 * @param [in] lastChangeX the colum where the last piece has been put
 * @param [in] lastChangeY the row where the last piece has been put
 * @param [out] gameResult the winning status if the game has ended (value is not set if
 * the game is not finished)
 *
 * @pre lastChangeX must be in [0..2]
 * @pre lastChangeY must be in [0..2]
 * @pre gameResult must point on an allocated GameResult variable
 *
 * @return a boolean that tells if the game is finished
 */
PieceType _boardSquares[3][3];
SquareChangeCallback _onSquareChange;
EndOfGameCallback _onEndOfGame;


	 bool isGameFinished (const PieceType boardSquares[3][3], Coordinate lastChangeX, Coordinate lastChangeY, GameResult *gameResult)
	{
		PieceType temp = boardSquares[0][lastChangeX];
		int compteur = 0;
		for(int j = 0; j < 3; j++){
			if(boardSquares[j][lastChangeX] == NONE){
				break;
			}else {
				
				if(temp != boardSquares[j][lastChangeX]){
					break;
				} else {
					temp = boardSquares[j][lastChangeX];
					compteur++;
				}
				if(compteur == 3){
					*gameResult = temp;
					return true;
				}				
				
			}
		}

			temp = boardSquares[lastChangeY][0];
			compteur = 0;
			for(int j = 0; j < 3; j++){
				if(boardSquares[lastChangeY][j] == NONE){
					break;
				}else {
					if(temp != boardSquares[lastChangeY][j]){
						break;
					} else {
						
						temp = boardSquares[lastChangeY][j];
						compteur++;
					}
					if(compteur == 3){
						*gameResult = temp;
						return true;
					}				
					
				}
			}
			
			if(boardSquares[1][1] != NONE){
				if(boardSquares[0][0] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][2]){
					*gameResult = boardSquares[1][1];
					return true;
				} else if(boardSquares[0][2] == boardSquares[1][1] && boardSquares[1][1] == boardSquares[2][0]){
					*gameResult = boardSquares[1][1];
					return true;
				}
			}

			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					if(boardSquares[i][j] == NONE){
						*gameResult = DRAW;
						return false;
					}
				}
			}

	*gameResult = DRAW;
	return true;
}

void Board_init (SquareChangeCallback onSquareChange, EndOfGameCallback onEndOfGame)
{
	for (int i = 0; i < 3; i++){
		for(int j; j < 3; j++){			
			_boardSquares[i][j] = NONE;
		}
	}
	_onSquareChange = onSquareChange;
	_onEndOfGame = onEndOfGame;
}

void Board_free ()
{
  // TODO: à compléter
}

PutPieceResult Board_putPiece (Coordinate x, Coordinate y, PieceType kindOfPiece)
{
	if (Board_getSquareContent(x, y) == NONE && x <= 2 && x >= 0 && y <= 2 && y >= 0) {
		_boardSquares[y][x] = kindOfPiece;
		_onSquareChange(x, y, kindOfPiece);
		GameResult gameResult;
		if(isGameFinished(_boardSquares, x, y, &gameResult)){
			_onEndOfGame(gameResult);
		}
		return PIECE_IN_PLACE;
	} else{
		printf ("La case n'est pas vide\n");
		return SQUARE_IS_NOT_EMPTY;
	}
}

PieceType Board_getSquareContent (Coordinate x, Coordinate y)
{
	return _boardSquares[y][x];
}	


//
//		onSquareChange = Board_putPiece
//	
//																							Good Luck and Have Fun
//
//	[0][0]	[0][1]	[0][2]
//	[1][0]	[1][1]	[1][2]
//	[2][0]	[2][1]	[2][2]
//
//	[0][0]	[1][0]	[2][0]
//	[0][1]	[1][1]	[2][1]
//	[0][2]	[1][2]	[2][2]
//
//	[0][0]	[1][1]	[2][2]
//	[0][2]	[1][1]	[2][0]
//	

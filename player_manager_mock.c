/**
 * @file player_manager_mock.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "board.h"
#include "board_view.h"
#include <assert.h>
#include <stdio.h>


#if defined CONFIG_PLAYER_MANAGER_MOCK

typedef struct
{
	Coordinate x;
	Coordinate y;
	PieceType player;
} BoardDataTest;

static const BoardDataTest DataTest[] =
{
	{0,0,CROSS},
	{0,1,CIRCLE},
	{0,2,CROSS},
	{1,0,CIRCLE},
	{1,1,CROSS},
	{1,2,CIRCLE},
	{2,0,CROSS},
	{2,1,CIRCLE},
	{2,2,CROSS},
};


void PlayerManager_init (void)
{
}

void PlayerManager_free (void)
{
}

void PlayerManager_oneTurn (void)
{
	static unsigned index = 0;
	BoardView_displayPlayersTurn(DataTest[index].player);
	if(Board_putPiece(DataTest[index].x, DataTest[index].y, DataTest[index].player) == SQUARE_IS_NOT_EMPTY){
		BoardView_sayCannotPutPiece();
	}
	index+=1;
}

#endif //  #if defined CONFIG_PLAYER_MANAGER_MOCK



//  #include "jeuTest.c"
//	|X|O|X|
//	|X|O| |
//	|X| | |
//
//	Board_putPiece(0,1,CIRCLE);
//	Board_putPiece(0,2,CROSS);
//	Board_putPiece(1,0,CROSS);
//	Board_putPiece(1,1,CIRCLE);
//	Board_putPiece(2,0,CROSS);
//
//


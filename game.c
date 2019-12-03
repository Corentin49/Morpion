/**
 * @file main.c
 *
 * @date 7 oct. 2016
 * @author jilias
 */

#include "player_manager.h"
#include "board_view.h"
#include "board.h"
#include <stdbool.h>
#include <stdio.h>

void Game_SquareChangeCallback(Coordinate x, Coordinate y, PieceType newContent){
	BoardView_displaySquare(x, y, newContent);
}


void Game_EndOfGameCallback(GameResult result){
	BoardView_displayEndOfGame(result);
}

void Game_init (void)
{
	Board_init(&Game_SquareChangeCallback, &Game_EndOfGameCallback);
}

void Game_free (void)
{

}

void Game_loop (void)
{
	bool finDePartie = false;
	while(!finDePartie){
		PlayerManager_oneTurn();
	}
}


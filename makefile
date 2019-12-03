CCOPTS = -std=c99

CC = cc $(CCOPTS)

force: clean all

all: etape1

clean:
	rm -f etape1 etape2 etape3 *.o

etape1:
	$(CC) -DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_MOCK -o etape1 main.c board.c game.c board_view_text.c tictactoe_errors.c player_manager_mock.c
	

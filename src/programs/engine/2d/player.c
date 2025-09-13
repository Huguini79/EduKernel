// EduKernel - Huguini79

// 2d game engine player implementation

#include "stdio.h"

#include "player.h"

typedef struct {
	int X;
	int Y;
} Player;

Player player;

void player_move(int x, int y) {
	player.X = x;
	player.Y = y;
	
	for(int i = 0; i < player.Y; i++) {
		printd("\n");
	}
	
	for(int ii = 0; ii < player.X; ii++) {
		printd(" ");
	}
	
	printd("*");
	
}

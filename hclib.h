#ifndef HCLIB
#define HCLIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char board_t[8][8];
/* row - rank; 0-7 corresponods to 1-8
* column - file; 0-7 corresponds to a-h
*/

typedef struct
{
char bprison[16];
char bairfield[16];
board_t board;
char wprison[16];
char wairfield[16];
} exboard_t;

typedef struct
{
int from_i, from_j;
int to_i, to_j;
char promotion;
char hostage;
} move_t;

//returns a pointer to an exboard
exboard_t *newboard();

//takes a pointer to an exboard, returns a pointer to an exboard
exboard_t *copyboard( exboard_t *board );

//takes a pointer to an exboard, returns a pointer to a string
char *stringboard( exboard_t *board);

//helper function to add a prisoner to the according prison
void add_prisoner(char *prison, char prisoner);

//helper function for drops from airfield
void air_drop(exboard_t *board, move_t *move);

//helper function for drops from the prison
void prison_drop(exboard_t *board, move_t *move);

//takes a pointer to an exboard and a pointer to a move, returns a pointer to an exboard
exboard_t *apply_move( exboard_t *board, move_t *move);

//checks if a possible move from a knight piece is valid, returns 1 if valid
int valid_knight(board_t *board, int to_i, int to_j, int colour);

//helper function that returns 1 for valid bishop moves, 2 for a capture, and 0 for invalid moves
int valid_bishop(board_t *board, int to_i, int to_j, int colour);

//helper function that returns 1 for valid rook moves, 2 for a capture, and 0 for invalid moves
int valid_rook(board_t *board, int to_i, int to_j, int colour);

//checks if a possible move from a king piece is valid, returns 1 if valid
int valid_king(board_t *board, int to_i, int to_j, int colour);

//checks if a possible move from a king piece is valid, returns 1 if valid
int valid_pawn(board_t *board, int from_i, int from_j, int to_i, int to_j, int colour);

//helper function to add valid move to the array of move_t
void add_valid(int valid_i, int valid_j, move_t **moves, int *count);

//returns an array of pointers to valid move_t of knight being moved
move_t **knightmoves( board_t *board, int from_i, int from_j, int colour);

//returns an array of pointers to valid move_t of the bishop being moved
move_t **bishopmoves( board_t *board, int from_i, int from_j, int colour );

//returns an array of pointers to valid move_t of the rook being moved
move_t **rookmoves( board_t *board, int from_i, int from_j, int colour );


move_t **moves( board_t *board, int from_i, int from_j );

#endif

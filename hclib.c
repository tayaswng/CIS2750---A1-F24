#include <stdio.h>
#include "hclib.h"
#include <stdlib.h>
#include <string.h>

// returns a pointer to an exboard
exboard_t *newboard()
{

    exboard_t *newboard;
    newboard = (exboard_t *)calloc(1, sizeof(exboard_t));

    if (newboard == NULL)
    {
        return newboard;
    }

    for (int i = 0; i < 8; i++)
    {
        newboard->board[1][i] = 'P';
        newboard->board[6][i] = 'p';
    }
    newboard->board[0][0] = 'R';
    newboard->board[7][0] = 'r';

    newboard->board[0][1] = 'N';
    newboard->board[7][1] = 'n';

    newboard->board[0][2] = 'B';
    newboard->board[7][2] = 'b';

    newboard->board[0][3] = 'Q';
    newboard->board[7][3] = 'q';

    newboard->board[0][4] = 'K';
    newboard->board[7][4] = 'k';

    newboard->board[0][5] = 'B';
    newboard->board[7][5] = 'b';

    newboard->board[0][6] = 'N';
    newboard->board[7][6] = 'n';

    newboard->board[0][7] = 'R';
    newboard->board[7][7] = 'r';

    return newboard;
}

// takes a pointer to an exboard, returns a pointer to an exboard
exboard_t *copyboard(exboard_t *board)
{

    exboard_t *newboard;
    newboard = (exboard_t *)calloc(1, sizeof(exboard_t));

    if (newboard == NULL)
    {
        return newboard;
    }

    memcpy(newboard, board, sizeof(*newboard));

    if (newboard == NULL)
    {
        return newboard;
    }

    return newboard;
}

// takes a pointer to an exboard, returns a pointer to a string
char *stringboard(exboard_t *board)
{

    // malloc string of 162 characters
    char *strboard = malloc(162 * sizeof(char));


    // make every 9th char a newline character
    for (int i = 8; i < 162; i += 9)
    {
        strboard[i] = '\n';
    }

    // make 36-43 filled with '-'
    for (int i = 36; i <= 43; i++)
    {
        strboard[i] = '-';
    }

    for (int i = 0; i <= 7; i++)
    {
        // make 45-52 filled with data rom the 8th row of the board array
        strboard[i + 45] = board->board[7][i];
        // make 54-61 filled with data from the 7th row of the board array
        strboard[i + 54] = board->board[6][i];
        strboard[i + 63] = board->board[5][i];
        strboard[i + 72] = board->board[4][i];
        strboard[i + 81] = board->board[3][i];
        strboard[i + 90] = board->board[2][i];
        strboard[i + 99] = board->board[1][i];
        // make 108-115 filled with data from the 1st row of the board array
        strboard[i + 108] = board->board[0][i];
    }

    // make 117-124 filled with '-'
    for (int i = 117; i <= 124; i++)
    {
        strboard[i] = '-';
    }

    // fill 8 indices at a time with the according string
    for (int i = 0; i < 8; i++)
    {

        if (strlen(board->bprison) > i)
        {
            strboard[i] = board->bprison[i];
        }
        else
        {
            strboard[i] = ' ';
        }

        if (strlen(board->bairfield) > i)
        {
            strboard[i + 18] = board->bairfield[i];
        }
        else
        {
            strboard[i + 18] = ' ';
        }

        if (strlen(board->wairfield) > i)
        {
            strboard[i + 126] = board->wairfield[i];
        }
        else
        {
            strboard[i + 126] = ' ';
        }

        if (strlen(board->wprison) > i)
        {
            strboard[i + 144] = board->wprison[i];
        }
        else
        {
            strboard[i + 144] = ' ';
        }
    }

    // fill the other 8 indices with the remaining chars in the string
    for (int i = 8; i < 16; i++)
    {

        if (strlen(board->bprison) > i)
        {
            strboard[i + 1] = board->bprison[i];
        }
        else
        {
            strboard[i + 1] = ' ';
        }

        if (strlen(board->bairfield) > i)
        {
            strboard[i + 19] = board->bairfield[i];
        }
        else
        {
            strboard[i + 19] = ' ';
        }

        if (strlen(board->wairfield) > i)
        {
            strboard[i + 127] = board->wairfield[i];
        }
        else
        {
            strboard[i + 127] = ' ';
        }

        if (strlen(board->wprison) > i)
        {
            strboard[i + 145] = board->wprison[i];
        }
        else
        {
            strboard[i + 145] = ' ';
        }
    }
    // make the 162nd character the null terminator character
    strboard[161] = '\0';
    return strboard;
}


//used to figure out why i was getting garbage characters at the end of my prison string
//https://www.reddit.com/r/cprogramming/comments/swiz4o/garbage_added_to_end_of_string/
//helper function for adding a prisoner
void add_prisoner(char *prison, char prisoner)
{

    int index = strlen(prison);
    if(index < 16){
        prison[index] = prisoner;
        prison[index+1] = '\0';
    }
    //strcat(prison, &prisoner);

}

//helper function for drops from airfield
void air_drop(exboard_t *board, move_t *move)
{
    printf("\n\n%s\n\n", "drops from airfield");
    // check if from black airfield
    if (move->from_i == 8)
    {
        printf("\n\n%s\n\n", "black airfield");
        // iterate through bairfield to search for character promotion
        for (int i = 0; i < strlen(board->bairfield); i++)
        {

            if (board->bairfield[i] == move->promotion)
            {
                printf("\n\n%s%c\n\n", "found promo: ", move->promotion);
                // place promotion character in the to location
                board->board[move->to_i][move->to_j] = board->bairfield[i];
                // replace the found promotion character with the next character

                for(int j = i; j < strlen(board->bairfield) -1; j++){
                    board->bairfield[j] = board->bairfield[j + 1];
                }
                board->bairfield[strlen(board->bairfield) -1] = '\0';
            }
        }
    }
    //if white airfield
    else if (move->from_i == -1){
        // iterate through wairfield to search for character promotion
       printf("\n\n%s\n\n", "black airfield");
        // iterate through bairfield to search for character promotion
        for (int i = 0; i < strlen(board->wairfield); i++)
        {

            if (board->wairfield[i] == move->promotion)
            {
                printf("\n\n%s%c\n\n", "found promo: ", move->promotion);
                // place promotion character in the to location
                board->board[move->to_i][move->to_j] = board->wairfield[i];
                // replace the found promotion character with the next character

                for(int j = i; j < strlen(board->wairfield) -1; j++){
                    board->wairfield[j] = board->wairfield[j + 1];
                }
                board->wairfield[strlen(board->wairfield) -1] = '\0';
            }
        }
    }

}

//helper function for drops from the prison
void prison_drop(exboard_t *board, move_t *move)
{
    printf("\n\n%s\n\n", "drops from prison");

    // check if from black prison
    if (move->from_i == 9)
    {
        // iterate through bprison to search for character promotion
        for (int i = 0; i < strlen(board->bprison); i++)
        {

            if (board->bprison[i] == move->promotion)
            {
                printf("\n\n%s%c\n\n", "found promo: ", move->promotion);
                // place promotion character in the to location
                board->board[move->to_i][move->to_j] = board->bprison[i];
                // replace the found promotion character with the next character

                for(int j = i; j < strlen(board->bprison) -1; j++){
                    board->bprison[j] = board->bprison[j + 1];
                }
                board->bprison[strlen(board->bprison) -1] = '\0';
            }
        }
    
        // search for hostage in wprison
        for (int i = 0; i < strlen(board->wprison); i++)
        {
            // iterate through the white prison and look for black piece hostage
            if (board->wprison[i] == move->hostage)
            {
                // place the black piece hostage found in wprison into the bairfield
                strcpy(board->bairfield, &board->wprison[i]);

                for(int j = i; j < strlen(board->wprison) -1; j++){
                    board->wprison[j] = board->wprison[j + 1];
                }
                board->wprison[strlen(board->wprison) -1] = '\0';

            }
        }
    }
    else if (move->from_i == -2)
    {
        for (int i = 0; i < strlen(board->wprison); i++)
        {
            if (board->wprison[i] == move->promotion)
            {
                board->board[move->to_i][move->to_j] = board->wprison[i];

                for(int j = i; j < strlen(board->wprison) -1; j++){
                    board->wprison[j] = board->wprison[j + 1];
                }
                board->wprison[strlen(board->wprison) -1] = '\0';
            }
        }
        
        for (int i = 0; i < strlen(board->bprison); i++)
        {
            if (board->bprison[i] == move->hostage)
            {
                strcpy(board->wairfield, &board->bprison[i]);


                for(int j = i; j < strlen(board->bprison) -1; j++){
                    board->bprison[j] = board->bprison[j + 1];
                }
                board->bprison[strlen(board->bprison) -1] = '\0';

            }
        }
    }
}


void normal_move(exboard_t *board, move_t *move){

    printf("\n%s\n", "normal move");
    char move_piece = board->board[move->from_i][move->from_j];

        // place a blank at the from location
        board->board[move->from_i][move->from_j] = ' ';

        //check if the to location is empty or not
        if (board->board[move->to_i][move->to_j] != ' '){


            //make the piece in the to location the prisoner
            char prisoner = board->board[move->to_i][move->to_j];


            //check if the piece in the to location is white and add it to bprison
            if(isupper(prisoner)){

                printf("\n\n%s%c\n\n", "add prisoner to bprison: ", prisoner);

                add_prisoner(board->bprison, prisoner);
            }
            //else the piece in the to location is black and add it to wprison
            else{

                add_prisoner(board->wprison, prisoner);
            }
        }
        if (move->promotion == ' '){
            // if promotion is a blank space, replace char at to location with character you are moving (from location)
            board->board[move->to_i][move->to_j] = move_piece;
        }
        else{
            // if promotion is not blank, copy value of promotion to the to location
            board->board[move->to_i][move->to_j] = move->promotion;
        }
} 


// takes a pointer to an exboard and a pointer to a move, returns a pointer to an exboard
exboard_t *apply_move(exboard_t *board, move_t *move)
{

    // the piece you are moving (ie. character at the from location)
    char move_piece = board->board[move->from_i][move->from_j];

    // handles drops from prison
    if (move->from_i == 9 || move->from_i == -2)
    {
        printf("\n\n%s\n\n", "perform prison drop");

        prison_drop(board, move);
    }
    //check if drops from airfield
    else if (move->from_i == 8 || move->from_i == -1)
    {
        printf("\n\n%s\n\n", "perform air drop");

        air_drop(board, move);
    }
    //Check for conditions of Castling
    //check if the piece you are moving, in the from location is a king
    else if ((move_piece == 'K') || (move_piece == 'k'))
    {
        printf("\n\n%s\n\n", "castling");

        // check if the piece moves right more than 1 space
        if (((move->to_j) - (move->from_j)) > 1)
        {
            char onemore = board->board[move->to_i][(move->to_j) + 1];
            
            // move the piece one right of the king to the left of the king
            board->board[move->to_i][(move->to_j) - 1] = onemore;
            board->board[move->to_i][(move->to_j) + 1] = ' ';

        }
        // check if the piece moves left more than 1 space
        else if (((move->to_j) - (move->from_j)) < -1)
        {
            char onemore = board->board[move->to_i][(move->to_j) - 1];

            // move the piece that is one to the left of the king to the other side of the king
            board->board[move->to_i][(move->to_j) + 1] = onemore;
            // replace the piece that was one to the left of the king with a blank
            board->board[move->to_i][(move->to_j) - 1] = ' ';
        }
        normal_move(board, move);

    }
    //Check for conditions of En passant
    // check if the piece you are moving in the from location is a BLACK pawn and that it moves diagonally
    else if ((move_piece == 'p') && ((abs((move->to_i) - (move->from_i)) == 1) && (abs((move->to_j) - (move->from_j)) == 1)))
    {
        printf("\n\n%s\n\n", "En passant");

        
        // if the pawn moving is black, move the piece to the bprison
        char prisoner = board->board[move->from_i][move->to_j];
        add_prisoner(board->bprison, prisoner);
        // replace the piece with a blank
        board->board[move->from_i][move->to_j] = ' ';
        normal_move(board, move);

    }
    // check if the piece you are moving in the from location is a WHITE pawn and that it moves diagonally
    else if ((move_piece == 'P') && ((abs((move->to_i) - (move->from_i)) == 1) && (abs((move->to_j) - (move->from_j)) == 1)))
    {
        // if the pawn moving is White, move the piece to the wprison
        char prisoner = board->board[move->from_i][move->to_j];
        add_prisoner(board->wprison, prisoner);
        // replace the piece with a blank
        board->board[move->from_i][move->to_j] = ' ';
        normal_move(board, move);

    }
    //if none of the exceptions, apply normal move as turn
    else{
        normal_move(board, move);
    }

    return board;
}


//checks if a possible move from a knight piece is valid, returns 1 if valid
int valid_knight(board_t *board, int to_i, int to_j, int colour){
    
    //check if the to location is on the board

    printf("\ninside valid knight\n");

    printf("\nto location: %d, %d\n", to_i, to_j);


    

    if ((to_i <= 7 && to_i >= 0) && (to_j <= 7 && to_j >= 0)){
        printf("\nin bounds\n");

        //if location is valid, check if it will run into a friendly piece
        char check = (*board)[to_i][to_j]; //*(board[i][j])
        printf("\ncheck: _%c_\n", check);

        if (check != ' '){
            if( colour == 0){
            //check for friendly piece, white is represented by capitals
            
                if (!isupper(check)){
                    //does not run into friendly piece, move is valid
                    printf("\nnot a friendly piece\n");

                    return 1;
                }
                else{
                    //move is not valid
                    printf("\nfriendly pice\n");

                    return 0;
                }

            }
            else{
            //check for friendly piece, black is lowercase    
                if (!islower(check)){
                    //does not run into friendly piece, move is valid
                    return 1;
                }
                else{
                    //move is not valid
                    return 0;
                }
            }
        }
        else{
            printf("\nempty space\n");

            return 1;
        }
    }
    else{
        printf("\nout of bounds\n");

        return 0;
    }
}

//helper function that returns 1 for valid bishop moves, 2 for a capture, and 0 for invalid moves
int valid_bishop(board_t *board, int to_i, int to_j, int colour){
    //check if the to location is on the board
    int capture = 2; //flag to indicate if we ran into a friendly piece or captured

    if ((to_i <= 7 && to_i >= 0) && (to_j <= 7 && to_j >= 0)){
        char check = *board[to_i][to_j];
        //check if there is a character in the destination
        if (check != ' '){
            if( colour == 0){
            //check for friendly piece, white is represented by capitals
                if (!isupper(check)){
                    //does not run into friendly piece, move is valid, but stops moving
                    return capture;
                }
                else{
                    //move is not valid, runs into friendly piece, stop movement
                    return 0;
                }

            }
            
            else{
            //check for friendly piece, black is lowercase    
                if (!islower(check)){
                    //does not run into friendly piece, move is valid, but stops moving 
                    return capture;
                }
                else{
                    //move is not valid
                    return 0;
                }
            }
        }
        else{
            //if the destination is empty, it is valid
            return 1;
        }
    }
    else{
        //if not on the board, not valid
        return 0;
    }
}  

//helper function that returns 1 for valid rook moves, 2 for a capture, and 0 for invalid moves
int valid_rook(board_t *board, int to_i, int to_j, int colour){
    //check if the to location is on the board
    int capture = 2; //flag to indicate if we ran into a friendly piece or captured

    if ((to_i <= 7 && to_i >= 0) && (to_j <= 7 && to_j >= 0)){
        char check = *board[to_i][to_j];
        //check if there is a character in the destination
        if (check != ' '){
            if( colour == 0){
            //check for friendly piece, white is represented by capitals
                if (!isupper(check)){
                    //does not run into friendly piece, move is valid, but stops moving
                    return capture;
                }
                else{
                    //move is not valid, runs into friendly piece, stop movement
                    return 0;
                }

            }
            
            else{
            //check for friendly piece, black is lowercase    
                if (!islower(check)){
                    //does not run into friendly piece, move is valid, but stops moving 
                    return capture;
                }
                else{
                    //move is not valid
                    return 0;
                }
            }
        }
        else{
            //if the destination is empty, it is valid
            return 1;
        }
    }
    else{
        //if not on the board, not valid
        return 0;
    }
}

//checks if a possible move from a king piece is valid, returns 1 if valid
int valid_king(board_t *board, int to_i, int to_j, int colour){
    
    //check if the to location is on the board

    if ((to_i <= 7 && to_i >= 0) && (to_j <= 7 && to_j >= 0)){
        //if location is valid, check if it will run into a friendly piece
        char check = *board[to_i][to_j];
        if (check != ' '){
            if( colour == 0){
            //check for friendly piece, white is represented by capitals
            
                if (!isupper(check)){
                    //does not run into friendly piece, move is valid
                    return 1;
                }
                else{
                    //move is not valid, runs into friendly piece
                    return 0;
                }

            }
            else{
            //check for friendly piece, black is lowercase    
                if (!islower(check)){
                    //does not run into friendly piece, move is valid
                    return 1;
                }
                else{
                    //move is not valid, runs into friendly piece
                    return 0;
                }
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}


//checks if a possible move from a king piece is valid, returns 1 if valid
int valid_pawn(board_t *board, int from_i, int from_j, int to_i, int to_j, int colour){
    //if the moving pawn is white
    if(colour == 0){
        //check if in the starting row and if the spot 2 squares ahead is empty 
        if(from_i == 1 && (to_i - from_i == 2) && (to_j == from_j) && *board[to_i][to_j] == ' ' && *board[to_i-1][to_j] == ' '){
            
            printf("\n\n%s\n\n", "pawn can double jump");
            
            return 1;
        }
        //check if the pawn moves one spot forwards, and if that spot it empty
        else if( ((to_i - from_i == 1)&& (to_j == from_j)) && *board[to_i][to_j] == ' ' ){
            printf("\n\n%s\n\n", "pawn can move forward 1 spot");

            return 1;

        }
        else if( ((to_i - from_i == 1) && (abs(to_j-from_j) == 1) && islower(*board[to_i][to_j]) )){
            printf("\n\n%s\n\n", "pawn can capture");

            return 1;

        }
        else{
            return 0;
        }
    }
    else{
        //check if in the starting row and if the spot 2 squares ahead is empty 
        if(from_i == 1 && (to_i - from_i == -2) && (to_j == from_j) && *board[to_i][to_j] == ' ' && *board[to_i+1][to_j] == ' '){
            return 1;
        }
        //check if the pawn moves one spot forwards, and if that spot it empty
        else if( ((to_i - from_i == -1)&& (to_j == from_j)) && *board[to_i][to_j] == ' ' ){
            return 1;

        }
        else if( ((to_i - from_i == -1) && (abs(to_j-from_j) == 1) && isupper(*board[to_i][to_j]) )){
            return 1;

        }
        else{
            return 0;
        }
    }
}


//helper function to add valid move to the array of move_t
void add_valid(int valid_i, int valid_j, move_t **moves, int *count){

    //allocate memory for a valid move
    move_t *new_valid = malloc(sizeof(move_t));

    new_valid->to_i = valid_i;
    new_valid->to_j = valid_j;

    moves[*count] = new_valid;
}


// inspiration from the geeksforgeeks to make 2-D array to hold the possible knight movesand iterate through it:
//https://www.geeksforgeeks.org/knights-tour-problem-in-c/
//returns an array of pointers to valid move_t of knight being moved
move_t **knightmoves( board_t *board, int from_i, int from_j, int colour ){
    //moves is a pointer to an array of pointers
    move_t **moves;
    //malloc an array of 9 pointers to possible moves
    moves = malloc(9*sizeof(move_t *));

    printf("\nmalloc 9 move_t pointers\n");

    int check_i, check_j; 
    int valid_count = 0;

    /*for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            printf("_%c_", *board[i][j]);

        }
        printf("\n");

    }*/

    int offsets[8][2] = { {2,1}, {2,-1}, {-2, 1}, {-2,-1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    //add the offsets to the current position and call the checking function for each possible move

    printf("\narray of offsets\n");


    for (int i = 0; i<8; i++){
        
        //set the to locations we are checking
        check_i = from_i + offsets[i][0];
        check_j = from_j + offsets[i][1];

        printf("\ncheck location %d,%d\n", check_i, check_j);



        //call the checking function that will return 1 if valid, 0 if not valid
        int isvalid = valid_knight(board, check_i, check_j, colour);
        

        //allocate memory for move_t if its valid
        if(isvalid == 1){

            printf("\nlocation is valid\n");

            
            //add the allocated valid move_t into the array of pointers to move_t structs
            add_valid(check_i, check_j, moves, &valid_count);
            printf("\nvalid moves: %d\n", valid_count);

            valid_count++;
        }
    }
    //realloc the array of pointers to move_t 
    moves = realloc(moves, valid_count+1);
    moves[valid_count+1] = NULL; // invalid size of 8 <- check that you're not going out of bounds

    printf("\nreallocated\n");


    return moves;
}

//returns an array of pointers to valid move_t of the bishop being moved
move_t **bishopmoves( board_t *board, int from_i, int from_j, int colour ){
    move_t **moves;
    //malloc an array of the maximum number of possible moves: 7 diagonal squares * 4 directions
    moves = malloc(28*sizeof(move_t *));

    int check_i, check_j;
    int valid_count = 0;
    int capture = 2;
    //bishop has the possibility of moving diagonally in 4 directions
    int offsets[4][2] = {{1,1}, {1, -1}, {-1, 1}, {-1, -1}};

    for(int i= 0; i<4; i++){
        check_i = from_i + offsets[i][0];
        check_j = from_j + offsets[i][1];

        int isvalid = valid_bishop(board, check_i, check_j, colour);

        while(isvalid == 1 ){
            
            //add the allocated valid move_t into the array of pointers to move_t structs
            add_valid(check_i, check_j, moves, &valid_count);
            valid_count++;

            check_i = from_i + offsets[i][0];
            check_j = from_j + offsets[i][1];

            isvalid = valid_bishop(board, check_i, check_j, colour);

        }
        //if there is a capture or invalid move, stop movement in this direction,
        // but if its a capture, add that move as valid
        if(isvalid == capture){
            add_valid(check_i, check_j, moves, &valid_count);
            valid_count++;
        }
    }
    //realloc the array of pointers to move_t 
    moves = realloc(moves, valid_count+1);
    moves[valid_count+1] = NULL;

    return moves;
}


move_t **rookmoves( board_t *board, int from_i, int from_j, int colour ){

    move_t **moves;
    //malloc an array of the maximum number of possible moves: 7 straight squares * 4 directions
    moves = malloc(28*sizeof(move_t *));

    int check_i, check_j;
    int valid_count = 0;
    int capture = 2;
    //bishop has the possibility of moving diagonally in 4 directions
    int offsets[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};

    for(int i= 0; i<8; i++){
        check_i = from_i + offsets[i][0];
        check_j = from_j + offsets[i][1];

        int isvalid = valid_rook(board, check_i, check_j, colour);

        while(isvalid == 1 ){
            
            //add the allocated valid move_t into the array of pointers to move_t structs
            add_valid(check_i, check_j, moves, &valid_count);
            valid_count++;

            check_i = from_i + offsets[i][0];
            check_j = from_j + offsets[i][1];

            isvalid = valid_rook(board, check_i, check_j, colour);

        }
        //if there is a capture or invalid move, stop movement in this direction,
        // but if its a capture, add that move as valid
        if(isvalid == capture){
            add_valid(check_i, check_j, moves, &valid_count);
            valid_count++;
        }
    }
    //realloc the array of pointers to move_t 
    moves = realloc(moves, valid_count+1);
    moves[valid_count+1] = NULL;

    return moves;

}

move_t **queenmoves( board_t *board, int from_i, int from_j, int colour ){
    move_t **moves;
    //malloc an array of the maximum number of possible moves: 28 bishop moves + 28 rook moves
    moves = malloc(56*sizeof(move_t *));

    move_t **r_moves;
    move_t **b_moves;


    b_moves = bishopmoves(board, from_i, from_j, colour);
    r_moves = rookmoves(board, from_i, from_j, colour);

    int i = 0;

    for(int i = 0; i<28; i++){
        if(b_moves[i] != NULL){
            moves[i] = b_moves[i];
        }
    }
    for(int j = 0; j<28; j++){
    if(r_moves[j] != NULL){
            moves[i+j] = r_moves[j];
            i++;
        }
    }

    //realloc the array of pointers to move_t 
    moves = realloc(moves, i+1);
    moves[i+1] = NULL;

    return moves;
}

move_t **king_moves( board_t *board, int from_i, int from_j, int colour ){
    move_t **moves;
    //malloc an array of the maximum number of possible moves: 8
    moves = malloc(8*sizeof(move_t *));

    int check_i, check_j; 
    int valid_count = 0;

    int offsets[8][2] = { {1,0}, {1,1}, {0, 1}, {-1,1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    //add the offsets to the current position and call the checking function for each possible move

    for (int i = 0; i<8; i++){
        //set the to locations we are checking
        check_i = from_i + offsets[i][0];
        check_j = from_j + offsets[i][1];

        //call the checking function that will return 1 if valid, 0 if not valid
        int isvalid = valid_king(board, check_i, check_j, colour);

        //allocate memory for move_t if its valid
        if(isvalid == 1){
            
            //add the allocated valid move_t into the array of pointers to move_t structs
            add_valid(check_i, check_j, moves, &valid_count);
            valid_count++;
        }
    }
    //realloc the array of pointers to move_t 
    moves = realloc(moves, valid_count+1);
    moves[valid_count+1] = NULL;

    return moves;
}


move_t **pawn_moves( board_t *board, int from_i, int from_j, int colour ){
    int forwards; //to determine which way is forwards for the pawn
    move_t **moves;
    //malloc an array of the maximum number of possible moves: 8
    moves = malloc(8*sizeof(move_t *));

    int check_i, check_j; 
    int valid_count = 0;

    // ASK Do i need to include the possibility of promotion in this function???????

    if(colour == 0){
        //if the colour is white, forwards is positive
        forwards = 1;
       
    }
    else{
        //if the colour is black, forwards is negative
        forwards = -1;
    }
    //list all the possible moves the pawn can do, then call valid_pawn to check for the conditions of each move 

    int offsets[4][2] = {{forwards*2, 0}, {forwards, 0}, {forwards, forwards}, {forwards, forwards*-1}};


    for (int i = 0; i<4; i++){
        check_i = offsets[i][0];
        check_j = offsets[i][1];

        int isvalid = valid_pawn(board, from_i, from_j, check_i, check_j, colour);

        if(isvalid == 1){
            
            //add the allocated valid move_t into the array of pointers to move_t structs
            add_valid(check_i, check_j, moves, &valid_count);
            valid_count++;
        }
    }

    //realloc the array of pointers to move_t 
    moves = realloc(moves, valid_count+1);
    moves[valid_count+1] = NULL;

    return moves;

} 


move_t **moves( board_t *board, int from_i, int from_j ){
    //the piece you are moving
    char move_piece = *board[from_i][from_j];

    move_t **result;
    int blk;
    blk = 1;
    int white;
    white = 0;
    
    switch (move_piece){
        case 'N':
            result = knightmoves(board, from_i, from_j, white);
            break;
            
        case 'n':
            result = knightmoves(board, from_i, from_j, blk);
            break;

        case 'B':
            result = bishopmoves(board, from_i, from_j, white);
            break;
        case 'b':
            result = bishopmoves(board, from_i, from_j, blk);
            break;

        case 'R':
            result = rookmoves(board, from_i, from_j, white);
            break;
        case 'r':
            result = rookmoves(board, from_i, from_j, blk);
            break;

        case 'Q':
            result = queenmoves(board, from_i, from_j, white);
            break;
        case 'q':
            result = queenmoves(board, from_i, from_j, blk);
            break;   

        case 'K':
            result = king_moves(board, from_i, from_j, white);
            break;
        case 'k':
            result = king_moves(board, from_i, from_j, blk);
            break;

        case 'P':
            result = pawn_moves(board, from_i, from_j, white);
            break;
    
        default:
            result = pawn_moves(board, from_i, from_j, blk);
            break;   
    }

    return result;
}




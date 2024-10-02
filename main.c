                                                                                                                                  
#include "hclib.h"

exboard_t *newboardtest()
{

    printf("test newboard.\n");


    exboard_t *newboard;
    newboard = (exboard_t *)calloc(1, sizeof(exboard_t));

    if (newboard == NULL)
    {
        return newboard;
    }

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            newboard->board[i][j] = ' ';
        }
    }

    /*for (int i = 0; i < 8; i++)                                                                                                                                        
    {                                                                                                                                                                    
        newboard->board[1][i] = 'P';                                                                                                                                     
        newboard->board[6][i] = 'p';                                                                                                                                     
    }                                                                                                                                                                    
    newboard->board[0][0] = 'R';                                                                                                                                         
    newboard->board[7][0] = 'r';                                                                                                                                         
                                                                                                                                                                         
    //newboard->board[0][1] = 'N';                                                                                                                                       
    //newboard->board[7][1] = 'n';                                                                                                                                       
                                                                                                                                                                         
    //newboard->board[0][2] = 'B';                                                                                                                                       
    //newboard->board[7][2] = 'b';                                                                                                                                       
                                                                                                                                                                         
    newboard->board[0][3] = 'Q';                                                                                                                                         
    newboard->board[7][3] = 'q';                                                                                                                                         
                                                                                                                                                                         
    newboard->board[0][4] = 'K';                                                                                                                                         
    newboard->board[7][4] = 'k';                                                                                                                                         
                                                                                                                                                                         
    //newboard->board[0][5] = 'B';                                                                                                                                       
    //newboard->board[7][5] = 'b';  

newboard->board[0][3] = 'Q';                                                                                                                                         
    newboard->board[7][3] = 'q';                                                                                                                                         
                                                                                                                                                                         
    newboard->board[0][4] = 'K';                                                                                                                                         
    newboard->board[7][4] = 'k';                                                                                                                                         
                                                                                                                                                                         
    //newboard->board[0][5] = 'B';                                                                                                                                       
    //newboard->board[7][5] = 'b';                                                                                                                                       
                                                                                                                                                                         
    //newboard->board[0][6] = 'N';                                                                                                                                       
    //newboard->board[7][6] = 'n';                                                                                                                                       
                                                                                                                                                                         
    newboard->board[0][7] = 'R';                                                                                                                                         
    newboard->board[7][7] = 'r';                                                                                                                                         
                                                                                                                                                                         
    newboard->board[3][6] = 'P';                                                                                                                                         
    newboard->board[3][7] = 'p';                                                                                                                                         
    newboard->board[3][5] = 'p';*/

    newboard->board[3][3] = 'n';

    //newboard->board[7][1] = 'N';                                                                                                                                       

    //newboard->board[5][3] = 'n';                                                                                                                                       



    return newboard;
}


int main(){

    /*exboard_t *board = newboard();                                                                                                                                     
    if (!board) {                                                                                                                                                        
        printf("Failed to create a new board.\n");                                                                                                                       
        return 1; 
	}*/

    //strcpy(board->bprison, "bprisonnnnnnnnn");                                                                                                                         
    //strcpy(board->bairfield, "bairfielddddddd");                                                                                                                       



    //test for castling                                                                                                                                                  
    exboard_t *board = newboardtest();
    if (!board) {
        printf("Failed to create a new board.\n");
        return 1;
    }

    strcpy(board->bprison, "ABCDEFGHIJK");
    strcpy(board->bairfield, "hijklmnop");
    strcpy(board->wairfield, "HIJKLMNOP");
    strcpy(board->wprison, "abcdefghijk");

    printf("after filling prisons and airfields.\n");



    char *board_str = stringboard(board);

    if (board_str) {
        for(int i = 0; i<162; i++){

            printf("%d%c ", i, board_str[i]);

        }
        free(board_str);  // Free the stringboard's memory                                                                                                               
    }

    printf("after making stringboard.\n");



    /*                                                                                                                                                                   
    //working                                                                                                                                                            
    exboard_t *c_board = copyboard(board);                                                                                                                               
    if (!c_board) {                                                                                                                                                      
        printf("Failed to copy the board.\n");                                                                                                                           
        free(board);  // Clean up the original board before exiting                                                                                                      
        return 1;                                                                                                                                                        
    }                                                                                                                                                                    
                                                                                                                                                                         
    char *cpstr_board = stringboard(c_board);                                                                                                                            
                                                                                                                                                                         
    if (cpstr_board) {                                                                                                                                                   
        printf("\n\n%s\n\n", "copied board:");                                                                                                                           
        for(int i = 0; i<162; i++){                                                                                                                                      
            if (cpstr_board[i] == ' '){                                                                                                                                  
                printf("%d%c ", i, cpstr_board[i]);                                                                                                                      
            }                                                                                                                                                            
            else{                                                                                                                                                        
                printf("%d%c ", i, cpstr_board[i]);                                                                                                                      
            }                                                                                                                                                            
        }                                                                                                                                                                
        free(cpstr_board);  // Free the stringboard's memory                                                                                                             
    }                                                                                                                                                                    
                                                                                                                                                                         
    //tests P takes p                                                                                                                                                    
    move_t move;                                                                                                                                                         
    move.from_i = 1;  // Example move from row 1 (second row)                                                                                                            
    move.from_j = 0;  // Example move from column 0 (a-file)                                                                                                             
    move.to_i = 6;    // Move to row 2                                                                                                                                   
    move.to_j = 0;    // Same column (a-file)                                                                                                                            
    move.promotion = ' ';  // No promotion in this move                                                                                                                  
    move.hostage = ' ';    // No hostage taken in this move     


exboard_t *updated_board = apply_move(board, &move);                                                                                                                 
    if (updated_board) {                                                                                                                                                 
        char *updated_board_str = stringboard(updated_board);                                                                                                            
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }                                                                                                                                                                    
                                                                                                                                                                         
    //tests P takes r, with promotion char                                                                                                                               
    move_t move2;                                                                                                                                                        
    move2.from_i = 1;  // Example move from row 1 (second row)                                                                                                           
    move2.from_j = 0;  // Example move from column 0 (a-file)                                                                                                            
    move2.to_i = 7;    // Move to row 2                                                                                                                                  
    move2.to_j = 0;    // Same column (a-file)  
    move2.promotion = 'Q';  // promotion in this move                                                                                                                    
    move2.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_boardd = apply_move(board, &move2);                                                                                                               
    if (updated_boardd) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_boardd);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }                                                                                                                                                                    
                                                                                                                                                                         
    //tests P moves to empty spot                                                                                                                                        
    move_t move3;                                                                                                                                                        
    move3.from_i = 7;  // Example move from row 1 (second row)                                                                                                           
    move3.from_j = 0;  // Example move from column 0 (a-file)
    move3.to_i = 3;    // Move to row 2                                                                                                                                  
    move3.to_j = 0;    // Same column (a-file)                                                                                                                           
    move3.promotion = 'Q';  // No promotion in this move                                                                                                                 
    move3.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_board3 = apply_move(board, &move3);                                                                                                               
    if (updated_board3) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_board3);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }                                                                                                                                                                    
                                                                                                                                                                         
    //tests q takes Q with promotion char                                                                                                                                
    move_t move4;                                                                                                                                                        
    move4.from_i = 7;  // Example move from row 1 (second row)
    move4.from_j = 3;  // Example move from column 0 (a-file)                                                                                                            
    move4.to_i = 0;    // Move to row 2                                                                                                                                  
    move4.to_j = 3;    // Same column (a-file)                                                                                                                           
    move4.promotion = 'r';  // promotion in this move                                                                                                                    
    move4.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_board4 = apply_move(board, &move4);                                                                                                               
                                                                                                                                                                         
    if (updated_board4) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_board4);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }                                                                                                                                                                    
                                                                                                                                                                         
                                                                                                                                                                         
    //tests for castling                                                                                                                                                 
    move_t moveC;                                                                                                                                                        
    moveC.from_i = 0;  // Example move from row 1 (second row)                                                                                                           
    moveC.from_j = 4;  // Example move from column 0 (a-file)
moveC.to_i = 0;    // Move to row 2                                                                                                                                  
    moveC.to_j = 1;    // Same column (a-file)                                                                                                                           
    moveC.promotion = ' ';  // promotion in this move                                                                                                                    
    moveC.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_boardC = apply_move(board, &moveC);                                                                                                               
                                                                                                                                                                         
    if (updated_boardC) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_boardC);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }

//tests for en passant                                                                                                                                               
    move_t moveE;                                                                                                                                                        
    moveE.from_i = 3;  // Example move from row 1 (second row)                                                                                                           
    moveE.from_j = 6;  // Example move from column 0 (a-file)                                                                                                            
    moveE.to_i = 4;    // Move to row 2                                                                                                                                  
    moveE.to_j = 5;    // Same column (a-file)                                                                                                                           
    moveE.promotion = ' ';  // promotion in this move                                                                                                                    
    moveE.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_boardE = apply_move(board, &moveE);                                                                                                               
                                                                                                                                                                         
    if (updated_boardE) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_boardE);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }                                                                                                                                                                    
                                                                                                                                                                         
                                                                                                                                                                         
    //tests n takes b                                                 

//tests for castling                                                                                                                                                
    move_t moveCb;                                                                                                                                                       
    moveCb.from_i = 3;  // Example move from row 1 (second row)                                                                                                          
    moveCb.from_j = 3;  // Example move from column 0 (a-file)                                                                                                           
    moveCb.to_i = 4;    // Move to row 2                                                                                                                                 
    moveCb.to_j = 2;    // Same column (a-file)                                                                                                                          
    moveCb.promotion = ' ';  // promotion in this move                                                                                                                   
    moveCb.hostage = ' ';    // No hostage taken in this move                                                                                                            
                                                                                                                                                                         
    exboard_t *updated_boardCb = apply_move(board, &moveCb);                                                                                                             
                                                                                                                                                                         
    if (updated_boardCb) {                                                                                                                                               
        char *updated_board_str = stringboard(updated_boardCb);                                                                                                          
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory         
            }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    }                                                                                                                                                                    
                                                                                                                                                                         
                                                                                                                                                                         
    move_t move5;                                                                                                                                                        
    move5.from_i = 7;  // Example move from row 1 (second row)                                                                                                           
    move5.from_j = 6;  // Example move from column 0 (a-file)                                                                                                            
    move5.to_i = 0;    // Move to row 2  
move5.to_j = 3;    // Same column (a-file)                                                                                                                           
    move5.promotion = ' ';  // No promotion in this move                                                                                                                 
    move5.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_board5 = apply_move(board, &move5);                                                                                                               
    for (int i = 0; i<16; i++){                                                                                                                                          
        printf("\n\n%c\n\n", updated_board5->bprison[i]);                                                                                                                
    }                                                                                                                                                                    
                                                                                                                                                                         
    if (updated_board5) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_board5);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n"); 
}



//tests n moves to empty space                                                                                                                                       
    move_t move6;                                                                                                                                                        
    move6.from_i = 0;  // Example move from row 1 (second row)                                                                                                           
    move6.from_j = 3;  // Example move from column 0 (a-file)                                                                                                            
    move6.to_i = 3;    // Move to row 2                                                                                                                                  
    move6.to_j = 3;    // Same column (a-file)                                                                                                                           
    move6.promotion = 'k';  // No promotion in this move                                                                                                                 
    move6.hostage = ' ';    // No hostage taken in this move                                                                                                             
                                                                                                                                                                         
    exboard_t *updated_board6 = apply_move(board, &move6);                                                                                                               
                                                                                                                                                                         
    if (updated_board6) {                                                                                                                                                
        char *updated_board_str = stringboard(updated_board6);                                                                                                           
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                            
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
    } 


//tests drops from airfield                                                                                                                                           
    move_t movead;                                                                                                                                                       
    movead.from_i = -1;  // Example move from row 1 (second row)                                                                                                         
    movead.from_j = 3;  // Example move from column 0 (a-file)                                                                                                           
    movead.to_i = 3;    // Move to row 2                                                                                                                                 
    movead.to_j = 3;    // Same column (a-file)                                                                                                                          
    movead.promotion = 'N';  // No promotion in this move                                                                                                                
    movead.hostage = ' ';    // No hostage taken in this move                                                                                                            
                                                                                                                                                                         
    exboard_t *updated_boardad = apply_move(board, &movead);                                                                                                             
                                                                                                                                                                         
    if (updated_boardad) {                                                                                                                                               
        char *updated_board_str = stringboard(updated_boardad);                                                                                                          
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                                                   
                                                                                                                                                                         
            for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }   
  }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
                                                                                                                                                                         
    }                                                                                                                                                                    
                                                                                                                                                                         
                                                                                                                                                                         
    //tests drops from prison                                                                                                                                            
    move_t movepd;                                                                                                                                                       
    movepd.from_i = 9;  // Example move from row 1 (second row)                                                                                                          
    movepd.from_j = 3;  // Example move from column 0 (a-file)                                                                                                           
    movepd.to_i = 3;    // Move to row 2                                                                                                                                 
    movepd.to_j = 4;    // Same column (a-file)                                                                                                                          
    movepd.promotion = 'B';  // No promotion in this move                                                                                                                
    movepd.hostage = ' ';    // No hostage taken in this move                                                                                                            
                                                                                                                                                                         
    exboard_t *updated_boardpd = apply_move(board, &movepd);                                                                                                             
                                                                                                                                                                         
    if (updated_boardpd) {                                                                                                                                               
        char *updated_board_str = stringboard(updated_boardpd);                                                                                                          
        if (updated_board_str) {                                                                                                                                         
            printf("\n\n%s\n\n", "board after move:");                                                                                       
	    for(int i = 0; i<162; i++){                                                                                                                                  
                printf("%d%c ", i, updated_board_str[i]);                                                                                                                
                                                                                                                                                                         
            }                                                                                                                                                            
            free(updated_board_str);  // Free the updated stringboard's memory                                                                                           
        }                                                                                                                                                                
    }                                                                                                                                                                    
    else {                                                                                                                                                               
        printf("Failed to apply the move.\n");                                                                                                                           
                                                                                                                                                                         
    }*/



    move_t** moves;
    moves = knightmoves(&(board->board), 3, 3, 1);

    /*for (int i =0; i<8; i++){                                                                                                                                          
        printf("%d,%d\n", moves[i]->to_i, moves[i]->to_j);                                                                                                               
    }*/







     // Free the memory allocated for the boards                                                                                                                         
    free(board);
    //free(c_board);                                                                                                                                                     
    //free(updated_board);                                                                                                                                               

    return 0;

}









                                                                                                                                       
                                                                                                                                                                         
-UU-:----F1  main.c         Top L1     (C/*l Abbrev) --------------------------------------------------------------------------------------------------------------------
C-c-

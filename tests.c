File Edit Options Buffers Tools C Help                                          
#include "hclib.h"


//returns a pointer to an exboard                                               
exboard_t *newboard();
    //works                                                                     

//takes a pointer to an exboard, returns a pointer to an exboard                
exboard_t *copyboard( exboard_t *board );
    //works                                                                     

//takes a pointer to an exboard, returns a pointer to a string                  
char *stringboard( exboard_t *board);
    //works                                                                     

//takes a pointer to an exboard and a pointer to a move, returns a pointer to a\
n exboard                                                                       
exboard_t *apply_move( exboard_t *board, move_t *move);

    //tests for normal moves:                                                   
	//helper function to add a prisoner to the according prison             
	void add_prisoner(char *prison, char prisoner);
            //white P takes p and puts it in wprison                                                                                                                     
            //white P takes r and puts it in wprison                                                                                                                     
            //white P takes r, with promotion character 'Q'                                                                                                              
            //white P takes R and puts it in bprison                                                                                                                     
            //black p takes P and puts it in bprison                                                                                                                     
            //black b takes Q and puts it in bprison                                                                                                                     
            //black b takes Q, with promotion character r                                                                                                                
            //black n takes b and puts it in wprison                                                                                                                     

        //P moves to empty space                                                                                                                                         
        //ASK: n moves to empty space with promotion character, promotion character is placed in destination                                                             

        //n moves to empty space                                                                                                                                         
        //ASK: n moves to empty space with promotion character, promotion character is placed in destination                                                             
        //correct?                                                                                                                                                       


        //ASK: about the wording of the pawn moves, character in front??? I think he just means diagonally forwards                                                       

        //White piece castling works on both sides                                                                                                                       
        //black piece castling works on both sides                                                                                                                       

        //ASK: tries castling, but there is a knight beside the rook, the king "captures" the knight (IS THIS ALLOWED???)                                                
        //it says you may assume that this only happens when castling is valid, so do we not need to account for this?   
	////yes under assumption    


	 //black b takes Q and puts it in bprison                                                                                                                     
            //black b takes Q, with promotion character r                                                                                                                
            //black n takes b and puts it in wprison                                                                                                                     

        //P moves to empty space                                                                                                                                         
        //ASK: n moves to empty space with promotion character, promotion character is placed in destination                                                             

        //n moves to empty space                                                                                                                                         
        //ASK: n moves to empty space with promotion character, promotion character is placed in destination                                                             
        //correct?                                                                                                                                                       


        //ASK: about the wording of the pawn moves, character in front??? I think he just means diagonally fowards                                                       

        //White piece castling works on both sides                                                                                                                       
        //black piece castling works on both sides                                                                                                                       

        //ASK: tries castling, but there is a knight beside the rook, the king "captures" the knight (IS THIS ALLOWED???)                                                
        //it says you may assume that this only happens when castling is valid, so do we not need to account for this?                                                   
        //yes under assumption                                                                                                                                           

        //ASK: tries en passant on a friendly piece, moves that friendly piece to the jail of the same colour, (ie. moving piece and captured piece is black, but moved \
to the bprison)                                                                                                                                                          
        //does this fall under the assumption that en passant is only performed if there is a valid move??????                                                           
        //yes under assumption                                                                                                                                           

        //otherwise en passant works                                                                                                                                     

        //FIX: drops from airfield places the promotion piece at the end of prison string?                                                                               
        //should we account for that the promotion piece might be dropped onto a piece already occupied? do we add that to a prison string?                              

        //ASK: what if when doing prison drop or airdrop the to destination has a piece already:                                                                         
            ///NOT ALLOWED                                                                                                                                               


        //drops from prison works      


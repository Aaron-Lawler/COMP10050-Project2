//
// Created by aaron on 17/05/2021.
//

//function prototypes

//loops through board and prints piece if an array location is 1 or 2 (B or W)
void printBoardCurrent(int array[8][8]){
    int i,j = 0;
    printf("       --- --- --- --- --- --- --- --- ");
    for(i=0;i<8;i++){
        printf("\n" );
        printf("%d     ", i+1);
        for(j=0;j<8;j++){
            if(array[i][j] == 1){
                printf("| B " );

            }
            else if(array[i][j] == 2){
                printf("| W " );

            }
            else{
                printf("|   " );
            }
        }
        printf("|\n");
        printf("       --- --- --- --- --- --- --- --- ");
    }

    printf("\n        a   b   c   d   e   f   g   h   \n" );
}

//checks to see if board number is valid (between 1 and 8), if not asks for user input again
int validGrid(int grid){
    int num = grid;
    if(num < 1 || num > 8){
        while(num < 1 || num > 8){
            printf("Invalid number co-ordinate   .\n");
            printf("Input co-ordinate number to move to: " );
            scanf(" %d", &num);
        }
        return num;
    }
    else{
        return grid;
    }
}

//checks to see if board letter is valid (between a and h), if not asks for user input again
char validLetter(char let){
    char pos = let;
    if(pos < 'a' || pos > 'h'){
        while(pos < 'a' || pos > 'h'){
            printf("Invalid letter co-ordinate  .\n");
            printf("Input co-ordinate letter to move to: ");
            scanf(" %c", &pos);
        }
        return pos;
    }
    else{
        return let;
    }
}


//converts letter to corresponding number (with -1 to allow for array indexing later)
int convertLetter(char letter){

    if(letter == 'a'){
        return 1;
    }
    if(letter == 'b'){
        return 2;
    }
    if(letter == 'c'){
        return 3;
    }
    if(letter == 'd'){
        return 4;
    }
    if(letter == 'e'){
        return 5;
    }
    if(letter == 'f'){
        return 6;
    }
    if(letter == 'g'){
        return 7;
    }
    if(letter == 'h'){
        return 8;
    }
}

//loops through array and increments player1 and player2 score if sees a 1 or 2 (B or W), then prints score to screen
void playerScores(int array[8][8], char player1[20], char player2[20]){
    int i,j;
    int p1 = 0;
    int p2 = 0;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(array[i][j] == 1){
                p1++;
            }
            else if(array[i][j] == 2){
                p2++;
            }
        }
    }
    printf("%s's score: %d\n", player1, p1);
    printf("%s's score: %d\n", player2, p2);
}

//checks if the move the user entered is valid and follows the game rules
//i.e the new move will place a piece that brackets and opponents piece and ends in a piece of their own colours
//checks lines along all 8 directions from proposed move
int Stage2MoveCheckerP1(int array[8][8], int gridRow, int gridCol, int lines[8]){
    int goodMove = 0;

    //-1 to allow for array indexing
    int gridRoww = gridRow - 1;
    int gridColl = gridCol - 1;

    while(goodMove == 0){

        //firstly, checks the horizontal and vertical squares surrounding the new user move
        //if that square is not white, we will not be able to have a valid move, so that square is Invalid
        //if the square is white, follow that line and check if the piece after the last white square is Black
        //if so, keep track of the length of white tiles using variables a,b,c....(one for each direction checked)
        //this will then be used to flip pieces later using lines array
        //if the last square is not a black square, reset a,b,c.... to 1 so those pieces will not be flipped later


        //checks if space isn't a white square
        if(array[gridRoww][gridColl-1] != 2){

        }
            //if it is, do This
        else{
            //go along that line for all white pieces, incrementing associated variable (e.g a) each time
            int a = 1;
            while(array[gridRoww][gridColl-a] == 2){
                a++;
            }
            if(array[gridRoww][gridColl-a] == 1){
                //if last square is black, this is a valid move

            }
                //if last square after white is not black, reset a to 1
            else{
                a = 1;
            }
            //assign a to lines array
            lines[0] = a;
        }

        //continue this method for all 7 surrounding squares

        if(array[gridRoww][gridColl+1] != 2){
        }
        else{
            int b = 1;
            while(array[gridRoww][gridColl+b] == 2){
                b++;
            }
            if(array[gridRoww][gridColl+b] == 1){
            }
            else{
                b = 1;
            }
            lines[1] = b;
        }

        //checking another surrounding square

        if(array[gridRoww-1][gridColl] != 2){
        }
        else{
            int c = 1;
            while(array[gridRoww-c][gridColl] == 2){
                c++;
            }
            if(array[gridRoww-c][gridColl] == 1){
            }
            else{
                c = 1;
            }
            lines[2] = c;
        }

        //checking another surrounding square
        if(array[gridRoww+1][gridColl] != 2){
        }
        else{
            int d = 1;
            while(array[gridRoww+d][gridColl] == 2){
                d++;
            }
            if(array[gridRoww+d][gridColl] == 1){
            }
            else{
                d = 1;
            }
            lines[3] = d;
        }


        //next, checks the diagnol squares surrounding the new user move
        //if that square is not white, we will not be able to have a valid move, so that square is Invalid
        //if the square is white, follow that line and check if the piece after the last white square is Black
        //if so, keep track of the lenght of white tiles using variables a,b,c....(one for each direction checked)
        //this will then be used to flip pieces later using lines array
        //if the last square is not a black square, reset a,b,c.... to 1 so those pieces will not be flipped later

        if(array[gridRoww-1][gridColl-1] != 2){
        }
        else{
            int e = 1;
            while(array[gridRoww-e][gridColl-e] == 2){
                e++;
            }
            if(array[gridRoww-e][gridColl-e] == 1){
            }
            else{
                e = 1;
            }
            lines[4] = e;
        }

        //checking another surrounding square

        if(array[gridRoww-1][gridColl+1] != 2){
        }
        else{
            int f = 1;
            while(array[gridRoww-f][gridColl+f] == 2){
                f++;
            }
            if(array[gridRoww-f][gridColl+f] == 1){
            }
            else{
                f = 1;
            }
            lines[5] = f;
        }

        //checking another surrounding square

        if(array[gridRoww+1][gridColl-1] != 2){
        }
        else{
            int g = 1;
            while(array[gridRoww+g][gridColl-g] == 2){
                g++;
            }
            if(array[gridRoww+g][gridColl-g] == 1){
            }
            else{
                g = 1;
            }
            lines[6] = g;
        }

        //checking another surrounding square

        if(array[gridRoww+1][gridColl+1] != 2){
        }
        else{
            int h = 1;
            while(array[gridRoww+h][gridColl+h] == 2){
                h++;
            }
            if(array[gridRoww+h][gridColl+h] == 1){
            }
            else{
                h = 1;
            }
            lines[7] = h;

        }

        //if any array index is greater than 0, that means we have a valid move
        if(lines[0] > 1 || lines[1] > 1 || lines[2] > 1 || lines[3] > 1 || lines[4] > 1 || lines[5] > 1 || lines[6] > 1 || lines[7] > 1){
            goodMove = 1;
            return 1;
        }
        else{
            //return 0 if not a valid move
            goodMove = 1;
            return 0;
        }

    }
}

void PieceFlipperP1(int array[8][8], int gridRow, int gridCol, int lines[8]){
    //-1 to allow for array indexing
    int gridRoww = gridRow - 1;
    int gridColl = gridCol - 1;

    //checks lines array, each index from 0-7 has been assigned a value a - h from the previous function
    //if any array index is greater than 1, there is a sequence of tiles that must be flipped
    //for the number in that array index, flip that many squares

    if(lines[0] > 1){
        for(int i = 1;i<=lines[0];i++){
            array[gridRoww][gridColl-i] = 1;
        }
    }

    if(lines[1] > 1){
        for(int i = 1;i<=lines[1];i++){
            array[gridRoww][gridColl+i] = 1;

        }
    }

    if(lines[2] > 1){
        for(int i = 1;i<=lines[2];i++){
            array[gridRoww-i][gridColl] = 1;
        }
    }

    if(lines[3] > 1){
        for(int i = 1;i<=lines[3];i++){
            array[gridRoww+i][gridColl] = 1;
        }
    }

    if(lines[4] > 1){
        for(int i = 1;i<=lines[4];i++){
            array[gridRoww-i][gridColl-i] = 1;

        }
    }

    if(lines[5] > 1){
        for(int i = 1;i<=lines[5];i++){
            array[gridRoww-i][gridColl+i] = 1;

        }
    }

    if(lines[6] > 1){
        for(int i = 1;i<=lines[6];i++){
            array[gridRoww+i][gridColl-i] = 1;
        }
    }

    if(lines[7] > 1){
        for(int i = 1;i<=lines[7];i++){
            array[gridRoww+i][gridColl+i] = 1;
        }
    }
}




int Stage2MoveCheckerP2(int array[8][8], int gridRow, int gridCol, int lines[8]){
    int goodMove = 0;
    int gridRoww = gridRow - 1;
    int gridColl = gridCol - 1;

    //top left
    while(goodMove == 0){

        //firstly, checks the horizontal and vertical squares surrounding the new user move
        //if that square is not black, we will not be able to have a valid move, so that square is Invalid
        //if the square is white, follow that line and check if the piece after the last white square is white
        //if so, keep track of the lenght of black tiles using variables a,b,c....(one for each direction checked)
        //this will then be used to flip pieces later using lines array
        //if the last square is not a white square, reset a,b,c.... to 1 so those pieces will not be flipped later

        //if surrounding square is not black, invalid
        if(array[gridRoww][gridColl-1] != 1){
        }

            //if surrounding square is black, do this
        else{
            //go along that line for all black pieces, incrementing associated variable (e.g a) each time
            int a = 1;
            while(array[gridRoww][gridColl-a] == 1){
                a++;
            }
            if(array[gridRoww][gridColl-a] == 2){
                //if the last square after that black line is white, valid move
            }
            else{
                //if last square after white is not black, reset a to 1
                a = 1;
            }
            //assign a to lines array
            lines[0] = a;
        }

        //continue this method for all 7 surrounding squares

        //checking another square
        if(array[gridRoww][gridColl+1] != 1){
        }
        else{
            int b = 1;
            while(array[gridRoww][gridColl+b] == 1){
                b++;
            }
            if(array[gridRoww][gridColl+b] == 2){
            }
            else{
                b = 1;
            }
            lines[1] = b;
        }

        //checking another square
        if(array[gridRoww-1][gridColl] != 1){
        }
        else{
            int c = 1;
            while(array[gridRoww-c][gridColl] == 1){
                c++;
            }
            if(array[gridRoww-c][gridColl] == 2){
            }
            else{
                c = 1;
            }
            lines[2] = c;
        }

        //checking another square
        if(array[gridRoww+1][gridColl] != 1){
        }
        else{
            int d = 1;
            while(array[gridRoww+d][gridColl] == 1){
                d++;
            }
            if(array[gridRoww+d][gridColl] == 2){
            }
            else{
                d = 1;
            }
            lines[3] = d;
        }

        //next, checks the diagnol squares surrounding the new user move
        //if that square is not black, we will not be able to have a valid move, so that square is Invalid
        //if the square is white, follow that line and check if the piece after the last white square is white
        //if so, keep track of the lenght of black tiles using variables a,b,c....(one for each direction checked)
        //this will then be used to flip pieces later using lines array
        //if the last square is not a white square, reset a,b,c.... to 1 so those pieces will not be flipped later

        if(array[gridRoww-1][gridColl-1] != 1){
        }
        else{
            int e = 1;
            while(array[gridRoww-e][gridColl-e] == 1){
                e++;
            }
            if(array[gridRoww-e][gridColl-e] == 2){
            }
            else{
                e = 1;
            }
            lines[4] = e;
        }

        //checking another square
        if(array[gridRoww-1][gridColl+1] != 1){
        }
        else{
            int f = 1;
            while(array[gridRoww-f][gridColl+f] == 1){
                f++;
            }
            if(array[gridRoww-f][gridColl+f] == 2){
            }
            else{
                f = 1;
            }
            lines[5] = f;
        }

        //checking another square
        if(array[gridRoww+1][gridColl-1] != 1){
        }
        else{
            int g = 1;
            while(array[gridRoww+g][gridColl-g] == 1){
                g++;
            }
            if(array[gridRoww+g][gridColl-g] == 2){
            }
            else{
                g = 1;
            }
            lines[6] = g;
        }

        //checking another square
        if(array[gridRoww+1][gridColl+1] != 1){
        }
        else{
            int h = 1;
            while(array[gridRoww+h][gridColl+h] == 1){
                h++;
            }
            if(array[gridRoww+h][gridColl+h] == 2){
            }
            else{
                h = 1;
            }
            lines[7] = h;
        }

        //return 1 if an array index is greater than one (i.e valid move)
        if(lines[0] > 1 || lines[1] > 1 || lines[2] > 1 || lines[3] > 1 || lines[4] > 1 || lines[5] > 1 || lines[6] > 1 || lines[7] > 1){
            goodMove = 1;
            return 1;
        }
        else{
            //return 0 if not a valid move
            goodMove = 1;
            return 0;
        }
    }
}


void PieceFlipperP2(int array[8][8], int gridRow, int gridCol, int lines[8]){

    //-1 to allow for array indexing
    int gridRoww = gridRow - 1;
    int gridColl = gridCol - 1;

    //checks lines array, each index from 0-7 has been assigned a value a - h from the previous function
    //if any array index is greater than 1, there is a sequence of tiles that must be flipped
    //for the number in that array index, flip that many squares

    if(lines[0] > 1){
        for(int i = 1;i<=lines[0];i++){
            array[gridRoww][gridColl-i] = 2;
        }
    }

    if(lines[1] > 1){
        for(int i = 1;i<=lines[1];i++){
            array[gridRoww][gridColl+i] = 2;

        }
    }

    if(lines[2] > 1){
        for(int i = 1;i<=lines[2];i++){
            array[gridRoww-i][gridColl] = 2;
        }
    }

    if(lines[3] > 1){
        for(int i = 1;i<=lines[3];i++){
            array[gridRoww+i][gridColl] = 2;
        }
    }

    if(lines[4] > 1){
        for(int i = 1;i<=lines[4];i++){
            array[gridRoww-i][gridColl-i] = 2;

        }
    }

    if(lines[5] > 1){
        for(int i = 1;i<=lines[5];i++){
            array[gridRoww-i][gridColl+i] = 2;

        }
    }

    if(lines[6] > 1){
        for(int i = 1;i<=lines[6];i++){
            array[gridRoww+i][gridColl-i] = 2;
        }
    }

    if(lines[7] > 1){
        for(int i = 1;i<=lines[7];i++){
            array[gridRoww+i][gridColl+i] = 2;
        }
    }
}

//checls board array to see if there are any empty spaces left
//if there are not, return 1 and end game
int boardFull(int array[8][8]){
    int i,j;
    int num1 = 1;
    int num2 = 0;
    int emptyLeft = 0;
    bool fullBoard = false;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(array[i][j] == 0){
                emptyLeft++;
            }
        }
    }

    if(emptyLeft == 0){
        printf("\nNO EMPTY PIECES LEFT, GAME IS OVER\n");
        return num1;
    }
    else{
        return num2;
    }
}

//function to deal with first end game scenario (board is full)
void endGame1(int array[8][8]){
    int p1 = 0;
    int p2 = 0;
    int i,j;
    printf("\nGame is over because board is full.\n");

    //loops through board array to print scores and decide winner
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(array[i][j] == 1){
                p1++;
            }
            else if(array[i][j] == 2){
                p2++;
            }
        }
    }

    //based on scores decide winner
    if(p1 > p2){
        printf("P1 score is: %d\n", p1);
        printf("P2 score is: %d\n", p2);
        printf("\nP1 is the winner!!!\n");

    }
    else if(p2 > p1){
        printf("P1 score is: %d\n", p1);
        printf("P2 score is: %d\n", p2);
        printf("\nP2 is the winner!!!\n");
    }
    else{
        printf("P1 score is: %d\n", p1);
        printf("P2 score is: %d\n", p2);
        printf("Scores are equal, game ends in a draw!\n");
    }
}

//function that writes results of game to file
void endGame1filePrinting(int array[8][8]){

//if file cannot be opened, print error
    FILE *fp;
    if((fp = fopen("othello-results.txt", "w")) == NULL){
        printf("File could not be opened. Error.\n");
    }

//otherwise, write to file
    else{

        //printing time played at to file
        fprintf(fp,"Date is - %s\n",__DATE__ );
        fprintf(fp,"Game was played at - %s\n\n",__TIME__ );

        //printing board to file
        int i,j = 0;
        fprintf(fp,"       --- --- --- --- --- --- --- --- ");
        for(i=0;i<8;i++){
            fprintf(fp,"\n" );
            fprintf(fp,"%d     ", i+1);
            for(j=0;j<8;j++){
                if(array[i][j] == 1){
                    fprintf(fp,"| B " );

                }
                else if(array[i][j] == 2){
                    fprintf(fp,"| W " );

                }
                else{
                    fprintf(fp,"|   " );
                }
            }
            fprintf(fp,"|\n");
            fprintf(fp,"       --- --- --- --- --- --- --- --- ");
        }

        fprintf(fp,"\n        a   b   c   d   e   f   g   h   \n\n" );

        //printing results to file
        int p1 = 0;
        int p2 = 0;
        fprintf(fp,"\nGame is over because board is full.\n");
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(array[i][j] == 1){
                    p1++;
                }
                else if(array[i][j] == 2){
                    p2++;
                }
            }
        }

        //deciding winner based on scores
        if(p1 > p2){
            fprintf(fp,"P1 score is: %d\n", p1);
            fprintf(fp,"P2 score is: %d\n", p2);
            fprintf(fp,"\nP1 is the winner!!!\n");

        }
        else if(p2 > p1){
            fprintf(fp,"P1 score is: %d\n", p1);
            fprintf(fp,"P2 score is: %d\n", p2);
            fprintf(fp,"\nP2 is the winner!!!\n");
        }
        else{
            fprintf(fp,"P1 score is: %d\n", p1);
            fprintf(fp,"P2 score is: %d\n", p2);
            fprintf(fp,"Scores are equal, game ends in a draw!\n");
        }
    }

}

//function to deal with second end game scenario (neither player has a valid move)
void endGame2(int array[8][8]){
    int p1 = 0;
    int p2 = 0;
    int i,j;
    printf("\nGame is over as neither player has a playable move.\n");

    //loops through board array to print scores and decide winner

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(array[i][j] == 1){
                p1++;
            }
            else if(array[i][j] == 2){
                p2++;
            }
        }
    }

    //based on scores decide winner
    if(p1 > p2){
        printf("P1 score is: %d\n", p1);
        printf("P2 score is: %d\n", p2);
        printf("\nP1 is the winner!!!\n");

    }
    else if(p2 > p1){
        printf("P1 score is: %d\n", p1);
        printf("P2 score is: %d\n", p2);
        printf("\nP2 is the winner!!!\n");
    }
    else{
        printf("P1 score is: %d\n", p1);
        printf("P2 score is: %d\n", p2);
        printf("Scores are equal, game ends in a draw!\n");
    }
}

//function that writes results of game to file
void endGame2filePrinting(int array[8][8]){
//if file cannot be opened, print error
    FILE *fp;
    if((fp = fopen("othello-results.txt", "w")) == NULL){
        printf("File could not be opened. Error.\n");
    }
        //otherwise, write to file
    else{

        //printing time played at to file
        fprintf(fp,"Date is - %s\n",__DATE__ );
        fprintf(fp,"Game was played at - %s\n\n",__TIME__ );


        //printing board to file
        int i,j = 0;
        fprintf(fp,"       --- --- --- --- --- --- --- --- ");
        for(i=0;i<8;i++){
            fprintf(fp,"\n" );
            fprintf(fp,"%d     ", i+1);
            for(j=0;j<8;j++){
                if(array[i][j] == 1){
                    fprintf(fp,"| B " );

                }
                else if(array[i][j] == 2){
                    fprintf(fp,"| W " );

                }
                else{
                    fprintf(fp,"|   " );
                }
            }
            fprintf(fp,"|\n");
            fprintf(fp,"       --- --- --- --- --- --- --- --- ");
        }

        fprintf(fp,"\n        a   b   c   d   e   f   g   h   \n\n" );



        //printing results to file
        int p1 = 0;
        int p2 = 0;
        fprintf(fp,"\nGame is over as neither player has a playable move.\n");
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(array[i][j] == 1){
                    p1++;
                }
                else if(array[i][j] == 2){
                    p2++;
                }
            }
        }

        //deciding winner based on scores
        if(p1 > p2){
            fprintf(fp,"P1 score is: %d\n", p1);
            fprintf(fp,"P2 score is: %d\n", p2);
            fprintf(fp,"\nP1 is the winner!!!\n");

        }
        else if(p2 > p1){
            fprintf(fp,"P1 score is: %d\n", p1);
            fprintf(fp,"P2 score is: %d\n", p2);
            fprintf(fp,"\nP2 is the winner!!!\n");
        }
        else{
            fprintf(fp,"P1 score is: %d\n", p1);
            fprintf(fp,"P2 score is: %d\n", p2);
            fprintf(fp,"Scores are equal, game ends in a draw!\n");
        }
    }



}



//this function looks at every possible move player 1 could make, examining all 64 spaces on the board
//if no spaces are available, this will cause the user to pass their turn
int SkipMoveP1(int array[8][8]){
    int gridRoww, gridColl;
    int goodMove = 0;
    int lines[8] = {0};
    int i,j;
    while(goodMove == 0){
        //nested for loop to examine all 64 squares of board

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                gridRoww = i;
                gridColl = j;

                //if a board position is empty and the surrounding square is white continue
                //counts all squares along that line until you come across the end of the white squares
                //if the last square is black, this is a valid move
                //keep track of how many white squares should be flipped using a,b,c.... variables for each direction (this will be used to decide if a move is valid)
                //if a move is invalid, associated variable is reset to 1

                if(array[gridRoww][gridColl] == 0 && array[gridRoww][gridColl-1] == 2){
                    int a = 1;
                    while(array[gridRoww][gridColl-a] == 2){
                        a++;
                    }
                    //checks if any moves are outside board, if so reset associated variable to 1
                    if(array[gridRoww][gridColl-a] == 1){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            a = 1;
                        }
                        else if(gridRoww < 0 || gridColl - a <0 || gridRoww > 7 || gridColl - a > 7){
                            a = 1;
                        }
                        else if(gridRoww < 0 || gridColl - 1 < 0 || gridRoww > 7|| gridColl - 1 > 7){
                            a = 1;
                        }
                    }
                    else{
                        a = 1;
                    }
                    //assigns a to array lines
                    lines[0] = a;
                }

                //checking another surrounding square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww][gridColl+1] == 2){
                    int b = 1;
                    while(array[gridRoww][gridColl+b] == 2){
                        b++;
                    }
                    if(array[gridRoww][gridColl+b] == 1){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            b = 1;
                        }
                        else if(gridRoww < 0 || gridColl + b <0 || gridRoww > 7 || gridColl + b > 7){
                            b = 1;
                        }
                        else if(gridRoww < 0 || gridColl + 1 < 0 || gridRoww > 7|| gridColl + 1 > 7){
                            b = 1;
                        }

                    }
                    else{
                        b = 1;
                    }
                    lines[1] = b;
                }

                //checking another surrounding square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww-1][gridColl] == 2){
                    int c = 1;
                    while(array[gridRoww-c][gridColl] == 2){
                        c++;
                    }
                    if(array[gridRoww-c][gridColl] == 1){
                        if(gridRoww < 0 || gridColl < 0|| gridRoww > 7 || gridColl > 7){
                            c = 1;
                        }
                        else if(gridRoww - c < 0 || gridColl  <0 || gridRoww - c > 7 || gridColl > 7){
                            c = 1;
                        }
                        else if(gridRoww - 1 < 0 || gridColl < 0 || gridRoww - 1 > 7|| gridColl > 7){
                            c = 1;
                        }

                    }
                    else{
                        c = 1;
                    }
                    lines[2] = c;
                }

                //checking another surrounding square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww + 1][gridColl] == 2){
                    int d = 1;
                    while(array[gridRoww + d][gridColl] == 2){
                        d++;
                    }
                    if(array[gridRoww + d][gridColl] == 1){
                        if(gridRoww < 0 || gridColl < 0|| gridRoww > 7 || gridColl > 7){
                            d = 1;
                        }
                        else if(gridRoww + d < 0 || gridColl<0 || gridRoww + d > 7 || gridColl > 7){
                            d = 1;
                        }
                        else if(gridRoww + 1 < 0 || gridColl < 0 || gridRoww + 1 > 7|| gridColl > 7){
                            d = 1;
                        }

                    }
                    else{
                        d = 1;
                    }
                    lines[3] = d;
                }


                //checking diagnols
                if(array[gridRoww][gridColl] == 0 && array[gridRoww-1][gridColl-1] == 2){
                    int e = 1;
                    while(array[gridRoww-e][gridColl-e] == 2){
                        e++;
                    }
                    if(array[gridRoww-e][gridColl-e] == 1){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            e = 1;
                        }
                        else if(gridRoww - e < 0 || gridColl - e <0 || gridRoww - e > 7 || gridColl - e > 7){
                            e = 1;
                        }
                        else if(gridRoww - 1 < 0 || gridColl - 1 < 0 || gridRoww - 1 > 7|| gridColl - 1 > 7){
                            e = 1;
                        }

                    }
                    else{
                        e = 1;
                    }
                    lines[4] = e;
                }

                //checking another diagnol surrounding square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww-1][gridColl+1] == 2){
                    int f = 1;
                    while(array[gridRoww-f][gridColl+f] == 2){
                        f++;
                    }
                    if(array[gridRoww-f][gridColl+f] == 1){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            f = 1;
                        }
                        else if(gridRoww - f< 0 || gridColl + f <0 || gridRoww - f > 7 || gridColl + f > 7){
                            f = 1;
                        }
                        else if(gridRoww - 1 < 0 || gridColl + 1 < 0 || gridRoww - 1 > 7|| gridColl + 1 > 7){
                            f = 1;
                        }

                    }
                    else{
                        f = 1;
                    }
                    lines[5] = f;
                }

                //checking another diagnol surrounding square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww+1][gridColl-1] == 2){
                    int g = 1;
                    while(array[gridRoww+g][gridColl-g] == 2){
                        g++;
                    }
                    if(array[gridRoww+g][gridColl-g] == 1){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            g = 1;
                        }
                        else if(gridRoww + g < 0 || gridColl - g <0 || gridRoww + g > 7 || gridColl - g > 7){
                            g = 1;
                        }
                        else if(gridRoww + 1 < 0 || gridColl - 1 < 0 || gridRoww + 1 > 7|| gridColl - 1 > 7){
                            g = 1;
                        }

                    }
                    else{
                        g = 1;
                    }
                    lines[6] = g;
                }

                //checking another diagnol surrounding square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww+1][gridColl+1] == 2){
                    int h = 1;
                    while(array[gridRoww+h][gridColl+h] == 2){
                        h++;
                    }
                    if(array[gridRoww+h][gridColl+h] == 1){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            h = 1;
                        }
                        else if(gridRoww + h < 0 || gridColl + h <0 || gridRoww + h > 7 || gridColl + h > 7){
                            h = 1;
                        }
                        else if(gridRoww + 1 < 0 || gridColl + 1 < 0 || gridRoww + 1 > 7|| gridColl + 1 > 7){
                            h = 1;
                        }

                    }
                    else{
                        h = 1;
                    }
                    lines[7] = h;
                }

                //if an element in the line array is greater than 1, this means there is a valid move as there is a move that will cause a sequence of white squares to be sandwiched by two black squares
                //return 1 so this is a valid move

            }
            if(lines[0] > 1 || lines[1] > 1 || lines[2] > 1 || lines[3] > 1 || lines[4] > 1 || lines[5] > 1 || lines[6] > 1 || lines[7] > 1){
                goodMove = 1;
                return 1;
            }
            else{
                goodMove = 0;
            }

        }


        //if there is no valid move, return 0 and pass move
        if(goodMove == 0){
            return 0;
            break;
        }

    }
}

//this function looks at every possible move player 2 could make, examining all 64 spaces on the board
//if no spaces are available, this will cause the user to pass their turn
int SkipMoveP2(int array[8][8]){
    int gridRoww, gridColl;
    int goodMove = 0;
    int lines[8] = {0};
    int i,j;

    while(goodMove == 0){
        //nested for loop to examine all 64 squares of board

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                //account for array indexing
                //re-set to 0, just add 1 at end
                gridRoww = i;
                gridColl = j;

                //if a board position is empty and the surrounding square is black continue
                //counts all squares along that line until you come across the end of the black squares
                //if the last square is white, this is a valid move
                //keep track of how many black squares should be flipped using a,b,c.... variables for each direction (this will be used to decide if a move is valid)
                //if a move is invalid, associated variable is reset to 1

                //checking square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww][gridColl-1] == 1){
                    int a = 1;
                    while(array[gridRoww][gridColl-a] == 1){
                        a++;
                    }
                    //checks if any moves are outside board, if so reset associated variable to 1
                    if(array[gridRoww][gridColl-a] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            a = 1;
                        }
                        else if(gridRoww < 0 || gridColl - a <0 || gridRoww > 7 || gridColl - a > 7){
                            a = 1;
                        }
                        else if(gridRoww < 0 || gridColl - 1 < 0 || gridRoww > 7|| gridColl - 1 > 7){
                            a = 1;
                        }

                    }
                    else{
                        a = 1;
                    }
                    //assigns a to array lines
                    lines[0] = a;
                }


                //checking another square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww][gridColl+1] == 1){
                    int b = 1;
                    while(array[gridRoww][gridColl+b] == 1){
                        b++;
                    }
                    if(array[gridRoww][gridColl+b] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            b = 1;
                        }
                        else if(gridRoww < 0 || gridColl + b <0 || gridRoww > 7 || gridColl + b > 7){
                            b = 1;
                        }
                        else if(gridRoww < 0 || gridColl + 1 < 0 || gridRoww > 7|| gridColl + 1 > 7){
                            b = 1;
                        }

                    }
                    else{
                        b = 1;
                    }
                    lines[1] = b;
                }

                //checking another square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww-1][gridColl] == 1){
                    int c = 1;
                    while(array[gridRoww-c][gridColl] == 1){
                        c++;
                    }
                    if(array[gridRoww-c][gridColl] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            c = 1;
                        }
                        else if(gridRoww - c < 0 || gridColl<0 || gridRoww - c > 7 || gridColl > 7){
                            c = 1;
                        }
                        else if(gridRoww - 1 < 0 || gridColl < 0 || gridRoww - 1 > 7|| gridColl > 7){
                            c = 1;
                        }

                    }
                    else{
                        c = 1;
                    }
                    lines[2] = c;
                }

                //checking another square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww + 1][gridColl] == 1){
                    int d = 1;
                    while(array[gridRoww + d][gridColl] == 1){
                        d++;
                    }
                    if(array[gridRoww + d][gridColl] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            d = 1;
                        }
                        else if(gridRoww + d < 0 || gridColl <0 || gridRoww + d > 7 || gridColl > 7){
                            d = 1;
                        }
                        else if(gridRoww + 1 < 0 || gridColl < 0 || gridRoww + 1 > 7|| gridColl  > 7){
                            d = 1;
                        }

                    }
                    else{
                        d = 1;
                    }
                    lines[3] = d;
                }


                //checking diagnols
                if(array[gridRoww][gridColl] == 0 && array[gridRoww-1][gridColl-1] == 1){
                    int e = 1;
                    while(array[gridRoww-e][gridColl-e] == 1){
                        e++;
                    }
                    if(array[gridRoww-e][gridColl-e] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            e = 1;
                        }
                        else if(gridRoww - e < 0 || gridColl - e <0 || gridRoww - e > 7 || gridColl - e > 7){
                            e = 1;
                        }
                        else if(gridRoww - 1 < 0 || gridColl - 1 < 0 || gridRoww - 1> 7|| gridColl - 1 > 7){
                            e = 1;
                        }

                    }
                    else{
                        e = 1;
                    }
                    lines[4] = e;
                }

                //checking another diagnol square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww-1][gridColl+1] == 1){
                    int f = 1;
                    while(array[gridRoww-f][gridColl+f] == 1){
                        f++;
                    }
                    if(array[gridRoww-f][gridColl+f] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            f = 1;
                        }
                        else if(gridRoww - f < 0 || gridColl + f <0 || gridRoww - f > 7 || gridColl + f > 7){
                            f = 1;
                        }
                        else if(gridRoww - 1 < 0 || gridColl + 1 < 0 || gridRoww - 1 > 7|| gridColl + 1 > 7){
                            f = 1;
                        }

                    }
                    else{
                        f = 1;
                    }
                    lines[5] = f;
                }

                //checking another diagnol square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww+1][gridColl-1] == 1){
                    int g = 1;
                    while(array[gridRoww+g][gridColl-g] == 1){
                        g++;
                    }
                    if(array[gridRoww+g][gridColl-g] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            g = 1;
                        }
                        else if(gridRoww + g < 0 || gridColl - g <0 || gridRoww + g > 7 || gridColl - g > 7){
                            g = 1;
                        }
                        else if(gridRoww + 1 < 0 || gridColl - 1 < 0 || gridRoww + 1 > 7|| gridColl - 1 > 7){
                            g = 1;
                        }

                    }
                    else{
                        g = 1;
                    }
                    lines[6] = g;
                }

                //checking another diagnol square
                if(array[gridRoww][gridColl] == 0 && array[gridRoww+1][gridColl+1] == 1){
                    int h = 1;
                    while(array[gridRoww+h][gridColl+h] == 1){
                        h++;
                    }
                    if(array[gridRoww+h][gridColl+h] == 2){
                        if(gridRoww < 0 || gridColl < 0 || gridRoww > 7 || gridColl > 7){
                            h = 1;
                        }
                        else if(gridRoww + h < 0 || gridColl + h <0 || gridRoww + h > 7 || gridColl + h > 7){
                            h = 1;
                        }
                        else if(gridRoww + 1 < 0 || gridColl + 1 < 0 || gridRoww + 1 > 7|| gridColl + 1 > 7){
                            h = 1;
                        }

                    }
                    else{
                        h = 1;
                    }
                    lines[7] = h;
                }

                //if an element in the line array is greater than 1, this means there is a valid move as there is a move that will cause a sequence of white squares to be sandwiched by two black squares
                //return 1 so this is a valid move
            }
            if(lines[0] > 1 || lines[1] > 1 || lines[2] > 1 || lines[3] > 1 || lines[4] > 1 || lines[5] > 1 || lines[6] > 1 || lines[7] > 1){
                goodMove = 1;
                return 1;
            }
            else{
                goodMove = 0;
            }

        }


        //if there is no valid move, return 0 and pass move
        if(goodMove == 0){
            return 0;
            break;
        }

    }
}



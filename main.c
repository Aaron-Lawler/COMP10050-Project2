//Final othello project for Software Engineering (COMP10050) Project 2
//Student Number: 20757091

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "functions.h"
#include "functions.c"

int main(){
    //declaring variables
    const int empty = 0;
    const int black = 1;
    const int white = 2;


    //used with Stage2MoveChecker and loop so user doesn't enter bad move
    int greatMove = 0;
    int goodMoveP1 = 1;
    int goodMoveP2 = 1;

    //array for valid move function
    //also used to flip pieces with PieceFlipperP1 && PieceFlipperP2 functions
    int lines[8] = {0};

    //2D array for playing board
    int board[8][8] = {0};

    //setting initial board positions
    board[3][3] = 2;
    board[3][4] = 1;
    board[4][3] = 1;
    board[4][4] = 2;

    //char arrays to hold player names
    char p1[20];
    char p2[20];

    //player colours
    char p1colour = 'B';
    char p2colour = 'W';

    //number co-ordinate (y axis)
    int grid;

    //letter co-ordinate (x-axis)
    char position;

    //letter co-ordinate converted to number to work with array
    int numPosition;

    //if 0, game continues, gets changed from function if game should end
    int gameOver = 0;

    printf("\n\t\t\t*** Welcome to othello ***\n\n");

    //takes user input and assigns them a colour

    printf("(Names can be maximum 20 characters)\n");
    printf("Enter p1 name: ");
    scanf("%19s", p1);
    printf("\n");
    printf("Enter p2 name: ");
    scanf("%19s", p2);
    printf("\n");

    printf("Player one is: %s\n", p1 );
    printf("%s will be Black (B)\n\n", p1);
    printf("Player two is: %s\n", p2 );
    printf("%s will be White (W)\n\n", p2);

    //loops through array to count score
    playerScores(board, p1, p2);

    //prints current board
    printBoardCurrent(board);

    printf("\nWhen inputting move, specify number then following letter (in lowercase). \n" );

    //loop of full game
    while(gameOver == 0){
        int play1 = 1;
        int play2 = 2;
        int currentPlayer;

        //gameOver will be assigned 1 if the board is full, or will be 0 if board has empty spaces (so game will continue)
        gameOver = boardFull(board);
        if(gameOver!=0){
            break;
        }

        //current player is automatically player 1 to begin
        currentPlayer = play1;

        //goodMoveP1 variable checks if player 1 can make a valid move using SkipMoveP1 function
        goodMoveP1 = SkipMoveP1(board);

        //if neither player has a valid move, break and end game
        if(goodMoveP1 == 0 && goodMoveP2 == 0){
            gameOver = 2;
            break;
        }

        //if player 1 cannot make a move, they automatically pass their turn and it is player 2's go
        if(goodMoveP1 == 0){
            printf("Player 1 does not have a playable move. They must pass this turn.\n");
            currentPlayer = play2;
        }

        //or else it is player 1's turn
        if(currentPlayer == play1){

            printf("\n%s's turn. Input co-ordinate number to move to: ", p1);

            //scans user input for y axis number
            scanf(" %d", &grid);
            printf("\n");

            //checks if number entered is between 1 and 8
            grid = validGrid(grid);


            printf("Input co-ordinate letter to move to: ");

            //scans user input for x axis letter
            scanf(" %c", &position);

            //checks letter entered is between a and h
            position = validLetter(position);

            //converts that letter to a number to be used in array board and puts it in numPosition variable
            numPosition = convertLetter(position);

            //checks if desired board location already has a piece on it
            // -1 to allow for arrays indexing from  [0][0]
            //if space is not empty, collect user input for another move
            while(board[grid - 1][numPosition - 1] != 0){
                printf("Cannot move here, try again\n");
                printf("Input co-ordinate number to move to: ");
                scanf(" %d", &grid);
                printf("\n");

                //checks if number entered is between 1 and 8
                grid = validGrid(grid);

                printf("Input co-ordinate letter to move to: ");
                scanf(" %c", &position);
                printf("\n");

                //checks letter entered is between a and h
                position = validLetter(position);

                //converts that letter to a number to be used in array board and puts it in numPosition variable
                numPosition = convertLetter(position);
            }

            //greatMove variable is assigned it's value from the Stage2MoveCheckerP1 function
            //this function checks if the user's move follows all of the rules of the game
            //(i.e the new piece will end up bracketing an opponents piece and causing those pieces to be flipped)
            //if the user's move does not evaluate correctly, take a new move
            greatMove = Stage2MoveCheckerP1(board, grid, numPosition, lines);
            while(greatMove == 0){
                printf("Invalid Move\n");
                printf("Input co-ordinate number to move to: " );
                scanf(" %d", &grid);
                printf("\n");

                //checks if number entered is between 1 and 8
                grid = validGrid(grid);

                printf("Input co-ordinate letter to move to: ");
                scanf(" %c", &position);
                printf("\n");

                //checks letter entered is between a and h
                position = validLetter(position);

                //converts that letter to a number to be used in array board and puts it in numPosition variable
                numPosition = convertLetter(position);

                //checks if the move entered is now valid
                greatMove = Stage2MoveCheckerP1(board, grid, numPosition, lines);
            }
            //checks all diagnol, vertical and Horizontal lines around new piece and flips any that are valid
            PieceFlipperP1(board, grid, numPosition, lines);

            //resets lines array to 0
            for(int i = 0;i<8;i++){
                lines[i] = 0;
            }


            //prints location user inputted
            printf("Will now move to [%d][%c]\n", grid, position);
            numPosition = convertLetter(position);

            //places player colour on that square if it is a stage 1 valid square (within board and not taken up by a piece)
            // - 1 to account for array indexing
            board[grid - 1][numPosition - 1] = 1;
            printf("board at [%d][%c] is now: %c\n", grid, position, p1colour);
        }

        printf("Current Board: \n");

        //loops board array checking for black and white pieces and prints out scores
        playerScores(board, p1, p2);


        //loops through board array and prints out current board
        printBoardCurrent(board);

        //after player 1's turn, it is now player 2's turn
        currentPlayer = play2;

//goodMoveP1 variable checks if player 2 can make a valid move using SkipMoveP2 function
        goodMoveP2 = SkipMoveP2(board);

//if neither play can make a valid move, game is over
        if(goodMoveP1 == 0 && goodMoveP2 == 0){
            gameOver = 2;
            break;
        }

//if player 2 cannot make a move, they must pass their turn
        if(goodMoveP2 == 0){
            printf("Player 2 does not have a playable move. They must pass this turn.\n");
            currentPlayer = play1;
        }

        //or else it is player 2's turn
        if(currentPlayer == play2){

            //if board is full, end game
            gameOver = boardFull(board);
            if(gameOver!=0){
                break;
            }

            printf("\n\n%s's turn. Input co-ordinate number to move to: ", p2);

            //scans number co-ordinate (y axis)
            scanf(" %d", &grid);
            printf("\n");

            //checks if number entered is between 1 and 8
            grid = validGrid(grid);


            printf("Input co-ordinate letter to move to: ");

            //scans letter co-ordinate (x axis)
            scanf(" %c", &position);
            printf("\n");

            //checks letter entered is between a and h
            position = validLetter(position);

            //converts that letter to a number to be used in array board and puts it in numPosition variable
            numPosition = convertLetter(position);

            //checks if desired board location already has a piece on it
            // -1 to allow for arrays indexing from  [0][0]
            //if space is not empty, collect user input for another move
            while(board[grid - 1][numPosition - 1] != 0){
                printf("Cannot move here, try again\n");
                printf("Input co-ordinate number to move to: " );
                scanf(" %d", &grid);
                printf("\n");

                //checks if number entered is between 1 and 8
                grid = validGrid(grid);

                printf("Input co-ordinate letter to move to: ");
                scanf(" %c", &position);
                printf("\n");

                //checks letter entered is between a and h
                position = validLetter(position);

                //converts that letter to a number to be used in array board and puts it in numPosition variable
                numPosition = convertLetter(position);
            }

            //greatMove variable is assigned it's value from the Stage2MoveCheckerP2 function
            //this function checks if the user's move follows all of the rules of the game
            //(i.e the new piece will end up bracketing an opponents piece and causing those pieces to be flipped)
            //if the user's move does not evaluate correctly, take a new move
            greatMove = Stage2MoveCheckerP2(board, grid, numPosition, lines);
            while(greatMove == 0){
                printf("Invalid Move\n");
                printf("Input co-ordinate number to move to: " );
                scanf(" %d", &grid);
                printf("\n");

                //checks if number entered is between 1 and 8
                grid = validGrid(grid);

                printf("Input co-ordinate letter to move to: ");
                scanf(" %c", &position);
                printf("\n");

                //checks letter entered is between a and h
                position = validLetter(position);

                //converts that letter to a number to be used in array board and puts it in numPosition variable
                numPosition = convertLetter(position);
                greatMove = Stage2MoveCheckerP2(board, grid, numPosition, lines);
            }

            //checks all diagnol, vertical and Horizontal lines around new piece and flips any that are valid
            PieceFlipperP2(board, grid, numPosition, lines);

            //resets lines array to 0
            for(int i = 0;i<8;i++){
                lines[i] = 0;
            }


            //prints location user inputted
            printf("Will now move to [%d][%c]\n", grid, position);
            numPosition = convertLetter(position);

            //places player colour on that square if it is a stage 1 valid square (within board and not taken up by a piece)
            // - 1 to account for array indexing
            board[grid - 1][numPosition - 1] = 2;
            printf("board at [%d][%c] is now: %c\n", grid, position, p2colour);
        }

        printf("Current Board: \n");

        //prints user scores by looking for black and white squares in board array
        playerScores(board, p1, p2);

        //loops through board array and prints out current board
        printBoardCurrent(board);

        //if neither player has a valid move, game is over
        if(goodMoveP1 == 0 && goodMoveP2 == 0){
            gameOver = 2;
            break;
        }


    }


    //if gameOver == 1, we exited due to board being full
    if(gameOver == 1){
        //print appropriate end game sequence and print results to file
        endGame1(board);
        endGame1filePrinting(board);

    }
    //if gameOver == 2, we exited due to no playable moves for either player
    if(gameOver == 2){
        //print appropriate end game sequence and print results to file
        endGame2(board);
        endGame2filePrinting(board);
    }
}

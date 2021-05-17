//
// Created by aaron on 17/05/2021.
//

#ifndef COMP10050_PROJECT2_FUNCTIONS_H
#define COMP10050_PROJECT2_FUNCTIONS_H

//function definitions
void printBoardCurrent(int array[8][8]);
int validGrid(int grid);
char validLetter(char let);
int convertLetter(char letter);
void playerScores(int array[8][8], char player1[20], char player2[20]);
int Stage2MoveCheckerP1(int array[8][8], int gridRow, int gridCol, int lines[8]);
void PieceFlipperP1(int array[8][8], int gridRow, int gridCol, int lines[8]);
int Stage2MoveCheckerP2(int array[8][8], int gridRow, int gridCol, int lines[8]);
void PieceFlipperP2(int array[8][8],int gridRow, int gridCol, int lines[8]);
int boardFull(int array[8][8]);
void endGame1(int array[8][8]);
void endGame1filePrinting(int array[8][8]);
void endGame2(int array[8][8]);
void endGame2filePrinting(int array[8][8]);
int SkipMoveP1(int array[8][8]);
int SkipMoveP2(int array[8][8]);

#endif //COMP10050_PROJECT2_FUNCTIONS_H

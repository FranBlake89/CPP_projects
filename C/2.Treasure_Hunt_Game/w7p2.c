/*
*****************************************************************************
                          Workshop - #7 (P2)
Full Name  : Francisco Castillo Rojas
Student ID#: 148904212
Email      : fcastillo-rojas1@myseneca.ca
Section    : NJJ
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct PlayerInfo
{
    char cha;
    int lives;
    int treasure;
    int moves[20];
} player1;

typedef struct GameInfo
{
    int maxNumberMov;
    int pathLength;
    int bombs[35];
    int treasure[35];
    int moves[70];
} game;

void filterConfigPlayer(int lives, int *flag);
void filterMoves(int moves, int *flag, int maxMoves);
void foundBombs(int movements, int length, int *bombs[]);
void arrow (int position, int length);
void road (int position, int length, int *playerMoves[]);
//void foundTreasures(int movements, int length, int *treasure[]);

int main(void)
{
    struct PlayerInfo player1;
    struct GameInfo game;
    player1.treasure = 0;
    int flag = 1, index = 0;

    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n\n"
//-------------------------------------------------------------------------------------------------
           "PLAYER Configuration\n"
           "--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf("%c", &player1.cha);
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player1.lives);
    
        filterConfigPlayer(player1.lives, &flag);
    } while (flag == 1);
//-------------------------------------------------------------------------------------------------    
    printf("GAME Configuration\n"
           "------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if ((game.pathLength % 5) == 0 && game.pathLength >= 10 && game.pathLength <= 70 ) 
        {
            while (flag == 0)
            {
                printf("Set the limit for number of moves allowed: ");
                scanf("%d", &game.maxNumberMov);
                if (game.maxNumberMov >= 3 && game.maxNumberMov <=15)
                {
                    flag = 2;
                    printf("\n");
                }else
                {
                    printf("    Value must be between 3 and 15\n");
                    flag = 0;
                }
            }
        }
        else
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
            flag = 0;
        }
    } while (flag == 0);
//-------------------------------------------------------------------------------------------------   
    printf("BOMB Placement\n"
           "--------------\n");
    
    printf("Enter the bomb positions in sets of 5 where a value\n" 
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n" 
           "(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
    
    int i; 
    //game.bombs[game.pathLength];
    //printf("\n----------\nmac number mov: %d\n----------\n", game.pathLength);

    for (i = 0; i < game.pathLength; i= i + 5)
    {
        printf("   Positions [%2d-%2d]: ", i+1, i+5 );
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i+1], &game.bombs[i+2], &game.bombs[i+3], &game.bombs[i+4]);
    }
    printf("BOMB placement set\n\n");
//-------------------------------------------------------------------------------------------------
    printf("TREASURE Placement\n"
           "------------------\n");

    printf("Enter the treasure placements in sets of 5 where a value\n" 
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n" 
           "(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");

    for (i = 0; i < game.pathLength; i= i + 5)
    {
        printf("   Positions [%2d-%2d]: ", i+1, i+5 );
        scanf("%d %d %d %d %d", &game.treasure[i], &game.treasure[i+1], &game.treasure[i+2], &game.treasure[i+3], &game.treasure[i+4]);
    }  
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
//------------------------------------------------------------------------------------------------
    printf("------------------------------------\n"
           "TREASURE HUNT Configuration Settings\n"
           "------------------------------------\n");
    printf("Player:\n"
           "   Symbol     : %c\n"
           "   Lives      : %d\n"
           "   Treasure   : [ready for gameplay]\n"
           "   History    : [ready for gameplay]\n"
           "\n"
           "Game:\n"
           "   Path Length: %d\n", player1.cha, player1.lives, game.pathLength);
    int j, ii;
    printf("   Bombs      : ");
    for ( j = 0; j < game.pathLength; j++)
    {
        printf("%d", game.bombs[j]);
    }
    printf("\n");

    printf("   Treasure   : ");
        for ( j = 0; j < game.pathLength; j++)
        {
            printf("%d", game.treasure[j]);
        }
        printf("\n");

// Values for player1.moves        
        for ( ii = 0; ii < game.pathLength; ii++)
        {
            player1.moves[ii] = 4;
        }
    
    
    printf("\n====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n\n");
     printf(
            "  --------------------");
    do
    {
        printf(    
            "\n  |||||||||1|||||||||2"
            "\n  12345678901234567890\n"
            "+---------------------------------------------------+\n"
            "  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n"
            "+---------------------------------------------------+\n"
            , player1.lives, player1.treasure, game.maxNumberMov);
        
        int movements, playermove,check = 0; 

        // check index: printf("\n>>>>>>>>>>\n INDEX start : %d \n>>>>>>>>>>>>>>>\n", index);  
        // Input next move. ///////////////////
  
        do
        {      
            printf("Next Move [1-20]: ");
            scanf("%d", &game.moves[index]);
            movements = game.moves[index];
            
            filterMoves(movements, &flag, game.maxNumberMov);

        } while (flag == 3);
        ///////////////////end input//////////////
            if (player1.moves[movements-1] == 0 || player1.moves[movements-1] == 1 || player1.moves[movements-1] == 2 || player1.moves[movements-1] == 3 )
            {
                printf("\n===============> Dope! You've been here before!\n\n");
            }
            else{
                    check = 1;
            }
            while (check == 1)
            {
                if ((game.bombs[movements-1] == 1) && (game.treasure[movements-1] == 1))
                {   
                    printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    player1.lives--;
                    player1.treasure++;
                    playermove = 3;
                    player1.moves[movements-1]= playermove;
                    
                }
                else if((game.bombs[movements-1] == 0) && (game.treasure[movements-1] == 0))
                {
                    printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                    player1.moves[movements-1]= 0;
                    

                }
                else if ((game.bombs[movements-1] == 1) && (game.treasure[movements-1] == 0))
                {
                    printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                    player1.lives--;
                    playermove = 1;
                    player1.moves[movements-1]= playermove;
                    
                }
                else if ((game.bombs[movements-1] == 0) && (game.treasure[movements-1] == 1))
                {
                    printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    player1.treasure++;
                    playermove = 2;
                    player1.moves[movements-1]= playermove;
                }        
                if (player1.lives == 0)
                {
                    printf("No more LIVES remaining!\n\n");
                }        
                //*****************************End print movements*****************************************             
                index++ ;
                game.maxNumberMov--;
                check = 0;
                //check index: printf("\n//////////// index end : %d \n ----------------\n", index); 
            }
        int jj, position = movements-1;
        
        /*check array: 
                printf("\n*******\n ARRAY\n");
                for ( i = 0; i < game.pathLength; i++)
                {
                    printf("%d", player1.moves[i]); 
                }
                printf("\n********\n");
            */
        // Print movements
        arrow (position, game.pathLength);
        printf("  ");
        for (jj = 0; jj < game.pathLength; jj++)
            {
                if (player1.moves[jj] == 0)
                    { printf("%c",'.'); }
                else if (player1.moves[jj] == 1)
                    { printf("%c",'!'); }
                else if (player1.moves[jj] == 2)
                    { printf("%c",'$'); }
                else if (player1.moves[jj] == 3)
                    { printf("%c", '&'); }
                else if (player1.moves[jj] == 4)
                    { printf("%c", '-'); }
            }  
        flag = 4;
   } while ((player1.lives > 0) && (game.maxNumberMov > 0)); 

    printf( "\n  |||||||||1|||||||||2"
            "\n  12345678901234567890\n"
            "+---------------------------------------------------+\n"
            "  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n"
            "+---------------------------------------------------+\n\n"
            , player1.lives, player1.treasure, game.maxNumberMov);

    printf( "##################\n" 
            "#   Game over!   #\n" 
            "##################\n\n" 
            "You should play again and try to beat your score!\n");
    return 0;
}

void filterConfigPlayer(int lives, int *flag)
{    
    if (lives < 1 || lives > 10){ printf("     Must be between 1 and 10!\n");}
    else{printf("Player configuration set-up is complete\n\n"); *flag = 0;}
}

void filterMoves(int move, int *flag, int maxMoves)
{
    if (move < 1 || move > 20){ printf("  Out of Range!!!\n"); *flag = 3;}
    else{  *flag = 4;}
}
void arrow (int position, int length)
{
    int i;
    printf("  ");
    for (i = 0; i < length; i++)
        {
            if (i == position){printf("%c", 'V');}
            else if (i < position ){printf("%c", ' ');}
        }    
    printf("\n");   
}
void road (int position, int length, int *playerMoves[])
{
    printf("ROAD!!!");
}
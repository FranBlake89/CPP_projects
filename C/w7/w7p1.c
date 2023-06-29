/*
*****************************************************************************
                          Workshop - #7 (P1)
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

struct PlayerInfo
{
    char cha;
    int lives;
}player1;

struct GameInfo
{
    int maxNumberMov;
    int pathLength;
    int bombs[35];
    int treasure[35];
}game;

void filterConfigPlayer(int lives, int *flag);
void filterConfigGame(int path, int moves, int *flag);

int main(void)
{
    struct PlayerInfo player1;
    struct GameInfo game;

    int flag = 1;

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
                if (game.maxNumberMov >= 3 && game.maxNumberMov <=26)
                {
                    flag = 2;
                    printf("\n");
                }else
                {
                    printf("    Value must be between 3 and 26\n");
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
           "(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    
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
           "(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    for (i = 0; i < 35; i= i + 5)
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
    int j;
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

    
    
    printf("\n====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n");

    return 0;
}

void filterConfigPlayer(int lives, int *flag)
{    
    if (lives < 1 || lives > 10){ printf("     Must be between 1 and 10!\n");}
    else{printf("Player configuration set-up is complete\n\n"); *flag = 0;}
}
#pragma once
/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : Francisco Castillo
Student ID#:
Email      :fcastillo-rojas1@senecacollege.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define LENGTH_ARRAY

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// Return int and receives no arguments
int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int,int);

char inputCharOption(const char *arrayChar);

char inputCString(char *string, int MINchar, int MAXchar);

void displayFormattedPhone(char *number);
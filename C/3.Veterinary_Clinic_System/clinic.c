/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Francisco Castillo Rojas
Student ID#:
Email      :fcastillo-rojas1@myseneca.ca
Section    :NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;
    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;
    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            putchar('\n');
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            putchar('\n');
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            putchar('\n');
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;
    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        
        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    
    displayPatientTableHeader();
    //patient[i].patientNumber != '\0'
    for (i = 0; i<max; i++)
    {
        if (patient[i].patientNumber != 00){
            printf("0%d %-15s ",
                patient[i].patientNumber, patient[i].name);
       
            displayFormattedPhone(patient[i].phone.number);
      
            printf(" (%s)\n", patient[i].phone.description);
        }
    }
    printf("\n");
};


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber( patient, max);
            break;
        case 2:
            //printf("<<< telephone number >>>\n\n");
            searchPatientByPhoneNumber(patient, max);
            suspend();
            putchar('\n');
            break;
        }
    } while (selection);
};

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int index=-1;
    // printf("holaaaaaaaaaaaaaaaa\n");
    for (i = 0; i < max && index == -1; i++)
    {
        //printf("id: %d ", patient[i].patientNumber);
        if (patient[i].patientNumber == 0)
        {
            index = i;
        }
    }
    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
    }
};


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int numberPatient, indexPosition;
    
    printf("Enter the patient number: ");
    scanf(" %d", &numberPatient);
    putchar('\n');
    indexPosition = findPatientIndexByPatientNum(numberPatient, patient, max);
    
    if (indexPosition != -1) {
        int i, index;
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == numberPatient) {
                index = i;
            }
        }
        menuPatientEdit( &patient[index]);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
};

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int numberPatient, indexPosition;
    //get the patient number to remove
    printf("Enter the patient number: ");
    scanf(" %d", &numberPatient);
    
    printf("\n");
    // find the patient number, and returning a value
    indexPosition = findPatientIndexByPatientNum(numberPatient, patient, max);
    
    if (indexPosition != -1) 
    {
        
        int i, index;
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == numberPatient) {
                index = i;
            }
        }
        displayPatientData(&patient[index], FMT_FORM);
        
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        //scanf("%c", &response_User);
        int result = inputCharOption("yn");
        
          
        if (result == 'y') 
        {            
            //delete the value of patient Number
            patient[index].patientNumber = 00;
            //Copy next element value to current element
            /*for (i = index; i < max - 1; i++)
            {
                patient[i] = patient[i + 1];
            }*/ //DOESN'T WORK PROPERLY WITH THE COMPLETE ARRAY
            printf("Patient record has been removed!\n\n");
        }
        else if (result == 'n') {
            printf("Operation aborted.\n\n");
        }
    }
    else if (indexPosition == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
};


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int searchNumber = 0;    
    //input user
    printf("Search by patient number: ");
    scanf("%d", &searchNumber);
    putchar('\n');
        // I should have call the function findPatientIndexByPatientNum();
    //init new const struct 
    const struct Patient* personPtr;
    
    int i, number = 0;
    //traverse array 'patient[]' until find a skip line    
    for (i = 0; patient[i].patientNumber != '\0'; i++)
    {
    //storing the number of the 'patient[i]'        
        number = patient[i].patientNumber;
    // copy info struct patient[i] in personPtr
        personPtr = &patient[i];
    //compare search with number of the patient[i]
        if (searchNumber == number) 
        {
    //if matched, display data of struct personPtr
            displayPatientData(personPtr, FMT_FORM);
            printf("\n");
            suspend();
            printf("\n");
            break;
        }
    }
    if (searchNumber != number)
    {
        // printf("it doesnt match: % d   y %d\n", searchNumber, number);
        printf("*** No records found ***\n\n");
        suspend();
        printf("\n");
    }
};

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneNumber[PHONE_LEN+1]; 
    char stringGet[PHONE_LEN+1];
    //input user
    printf("Search by phone number: ");
    scanf("%s",phoneNumber);
    putchar('\n');
        
    //init new const struct 
    const struct Patient* personPtr;
    
    int i, result = 0, flag=0;
    //traverse array 'patient[]' until find a skip line    
    for (i = 0; patient[i].patientNumber != '\0'; i++)
    {
        //storing the number of the 'patient[i]'
        strncpy(stringGet, patient[i].phone.number, 11);
        
        //comparing and obtain a int value 
        result = strcmp(phoneNumber, stringGet);
        //if result == 0, strings are equal; > 0, phoneNumber > stringGet; < 0, phoneNumber < stringGet
        if (result == 0)
        {
            // copy info struct patient[i] in personPtr
            personPtr = &patient[i];
            while (flag == 0)
            {
                //printf("\n");
                displayPatientTableHeader();
                flag++;
            }
            //if matched, display data of struct personPtr
            displayPatientData(personPtr, FMT_TABLE);
            //putchar('\n');
        }
        else if (result == 0 && stringGet == '\0') {
            //flag == 0;
            displayPatientTableHeader();
        }
    }
    if (flag == 0)
    {
        displayPatientTableHeader();
        // printf("it doesnt match: % d   y %d\n", searchNumber, number);
        printf("\n*** No records found ***\n");
    }
    
    printf("\n");
    
};

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int index=max, i;
                    //printf("\nmax pat num: %d", max);
    int largest_idPatient = patient->patientNumber;
                    //printf("\nfor idPatient pat num: %d", patient->patientNumber);
    for (i = 0; i < max; i++)
    {
                    //printf("\nfor index pat num: %d", patient[i].patientNumber);
        if (largest_idPatient > patient[i].patientNumber) {
            index = i;
                    //printf("\nindex next pat: %d\n", index);
        }
    }
                    //printf("\nhere next pat: %d\n", index);
    return (index);
};

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i, indexPosition;
    for (i = 0; patient[i].patientNumber != '\0'; i++)
    {
        if (patientNumber == patient[i].patientNumber) {
          
            return indexPosition = i;
        }
       
    } 
    return indexPosition = -1;
    
};


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    
    printf("Number: ");
    scanf("%d", &patient->patientNumber);
    
    printf("Name  : ");
    scanf("  %[^\n]s", patient->name);
    putchar('\n');
    // scanf("%s", patient->name);
    inputPhoneData(&patient->phone);
    
};

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection, checkPhone = 1, flag = 0;
    char phone_descrip[PHONE_DESC_LEN + 1] = "";

    //printf("\ndescrip: %s\n", phone->description);
    char comp[5]= "";
    strcpy(comp, phone->description);
    char temp[5] = "TBA";
    
    int compare = strcmp( comp, temp);
    //printf("\ncomp descrip: %s\n", comp);
    
    if ( compare != 0) {
        flag++;

    }
    //printf("flag: %d\n", flag);
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"//"To be determined".
        "Selection: ");
    
    selection = inputIntRange(1, 4);
    switch (selection)
    {
        case 1:
            strcpy(phone_descrip, "CELL");
            printf("\nContact: %s\n", phone_descrip);
            strcpy(phone->description, phone_descrip);
            
            // printf("\n*** New patient record added ***\n");        
            break;
        case 2:
            strcpy(phone_descrip, "HOME");
            printf("\nContact: %s\n", phone_descrip);
            strcpy(phone->description, phone_descrip);
            
            // printf("\n*** New patient record added ***\n");
            break;
        case 3:
            strcpy(phone_descrip, "WORK");
            printf("\nContact: %s\n", phone_descrip);
            strcpy(phone->description, phone_descrip);
           
            break;
        case 4:
            //TBD
            checkPhone = 0;
            strcpy(phone_descrip, "TBD");
            strcpy(phone->description, phone_descrip);
            printf("\n");
            break;
        default:
            printf("\n enter correct number...\n");
            break;
    }
    char numberInput[PHONE_LEN];
    if (checkPhone == 1) {
        
        printf("Number : ");
        scanf("%s", numberInput);
        putchar('\n');        //printf("%s", numberInput);
        strcpy(phone->number, numberInput);
    }
    else {
        //numberInput[PHONE_LEN] = "";
        strcpy(phone->number, "");
    }
    ////printf("\nflag: %d", flag);
    if (flag != 0) {
        //printf("\n3flag: %d\n", flag);
        printf("*** New patient record added ***\n\n");
    }
   
};
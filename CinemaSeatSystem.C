#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pressToContinue()
{
    printf("=============================================\n");
    printf("            WELCOME TO CINEMAX              \n");
    printf("           IMMERSIVE EXEPRIENCE              \n");
    printf("=============================================\n");
    printf("       [ PRESS ENTER TO START ORDER ]       \n");
    printf("=============================================\n");

    while (getchar() != '\n');
    system("cls");
}

int getUserWatcherQuantity() {

    int quantity = 0;

    printf("\nNUMBER OF SEATS: ");
    scanf("%d", &quantity);

    while (quantity > 12 || quantity < 1)
    {
        printf("\nSORRY, THIS IS MORE THAN THE AVAILABLE SEATS!\n");
        printf("PLEASE TRY AGAIN\n");
        printf("\nNUMBER OF SEATS: ");
        scanf("%d", &quantity);
    }

    return quantity;
}

int displayAndSelectSeat(char seats[12][3], char seatChoice[12][3], int *index) {

    int isValid = 0;
    int selectedSeat = 0;

    printf("\n====================================");
    printf("\n\t    SEATING MAP");
    printf("\n====================================\n\n");

    for (int i = 0; i < 12; i++)
    {
        printf("    [%s]", seats[i]);
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
        
    }

    do
    {
        printf("\nSELECT YOUR SEAT: ");
        scanf("%s", seatChoice[*index]);

        for (int j = 0; j < 12; j++)
        {
            if (strcmp(seatChoice[*index], seats[j]) == 0)
            {
                isValid = 1;
                selectedSeat++;
                (*index)++;
                strcpy(seats[j], "XX");
            }
        
        }
        if (isValid == 0)
        {   
            printf("\nSEAT DOESN'T EXIST OR UNAVAILABLE\n");
        }
        
    } while (isValid != 1);
    
    return selectedSeat;
}


int main() {

    char seats[12][3] = {"A1", "A2", "A3", "A4"
                        , "B1", "B2", "B3", "B4"
                        , "C1", "C2", "C3", "C4"};
    
    char seatChoice[12][3];
    int seatQuantity = 0;
    int seatSelectionQuantity = 0;
    int selectSeat = 0;
    int index = 0;

    // START PROGRAM

    pressToContinue();

    seatQuantity = getUserWatcherQuantity();

    while (seatQuantity != seatSelectionQuantity)
    {
        selectSeat = displayAndSelectSeat(seats, seatChoice, &index);
        seatSelectionQuantity += selectSeat;
    }

    system("cls");
    printf("\n====================================");
    printf("\n\t  RESERVED SEATS");
    printf("\n====================================\n\n");
    for (int i = 0; i < seatQuantity; i++)
    {
        printf("%d. [%s]\n", i + 1, seatChoice[i]);
    }
    

    return 0;
}
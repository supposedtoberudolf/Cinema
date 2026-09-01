#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void header();

void buyTicket(int *choice, int *quantity, double *total);

void schedule(int *choice);

void orderSummary(double total
                , int movieChoice
                , char movie[5][30]
                , char scheduledTime[3][10]
                , int scheduleChoice);

void mode_payment(int *choice
                , double *amount
                , int *cardChoice
                , double total
                , int quantity
                , double *change
                , double *discountAmount);

void applyDiscount(double *total, double *discountAmount, int *discountChoice);

void transactionSummaryCASH(int quantity
                          , double total
                          , char scheduledTime[3][10]
                          , int scheduleChoice
                          , double amount
                          , int movieChoice
                          , char movie[5][30]
                          , double change
                          , int discountChoice
                          , char discountOption[4][20]
                          , double discountAmount);

void transactionSummaryCard(int quantity
                          , double total
                          , char scheduledTime[3][10]
                          , int scheduleChoice
                          , int movieChoice
                          , char movie[5][30]
                          , char card[2][10]
                          , int cardChoice
                          , int discountChoice
                          , char discountOption[4][20]
                          , double discountAmount);

void printLoadingDots(const char *message, int dotCount, int delayMs);

int main() {

    int movieChoice = 0;
    int ticketChoice = 0;
    int scheduleChoice = 0;
    int paymentChoice = 0;
    int quantity = 0;
    int cardChoice = 0;
    int discountChoice = 0;

    double total = 0.0;
    double amount = 0.0;
    double change = 0.0;
    double discountAmount = 0.0;


    char scheduledTime[3][10] = {"12:30 PM", "5:00 PM", "8:15 PM"};

    char movie[5][30] = {"Spider-Man: Brand New Day"
                        , "Moana"
                        , "Oppenheimer"
                        , "The Odyssey"
                        , "Toy Story 5"};

    char discountOption[4][20] = {"Student", "Senior", "PWD", "None"};

    char card[2][10] = {"BPI", "BDO"};

    // START PROGRAM
    header();
    printf("\n1.) Spider-Man: Brand New Day"
           "\n2.) Moana"
           "\n3.) Oppenheimer"
           "\n4.) The Odyssey"
           "\n5.) Toy Story 5\n");
    
    printf("\nCHOOSE MOVIE(1-5): ");
    scanf("%d", &movieChoice);

    printLoadingDots("Processing", 4, 500);
    
    while (movieChoice > 5 || movieChoice < 1)
    {
        printf("\nInvalid Input!\n");
        printf("Please Try Again\n");
        header();
        printf("\n1.) Spider-Man: Brand New Day"
                "\n2.) Moana"
                "\n3.) Oppenheimer"
                "\n4.) The Odyssey"
                "\n5.) Toy Story 5\n");
    
    printf("\nCHOOSE MOVIE(1-5): ");
    scanf("%d", &movieChoice);

    printLoadingDots("Processing", 4, 500);
    }

    buyTicket(&ticketChoice, &quantity, &total);
    
    applyDiscount(&total, &discountAmount, &discountChoice);

    header();

    schedule(&scheduleChoice);

    orderSummary(total, movieChoice, movie, scheduledTime, scheduleChoice);

    mode_payment(&paymentChoice, &amount, &cardChoice, total, quantity, &change, &discountAmount);
        
    if (paymentChoice == 1) {
        transactionSummaryCASH(quantity, total, scheduledTime, scheduleChoice, amount, movieChoice, movie, change, discountChoice, discountOption, discountAmount);
    } else if (paymentChoice == 2) {
        transactionSummaryCard(quantity, total, scheduledTime, scheduleChoice, movieChoice, movie, card, cardChoice, discountChoice, discountOption, discountAmount);
    }

    return 0;
}

void header() 
{
    printf("\n====================================");
    printf("\n\t   CINEMA TICKET");
    printf("\n====================================\n");
}

void buyTicket(int *ticketChoice, int *quantity, double *total) 
{
        printf("\n====================================");
        printf("\n\t   TICKET PRICES");
        printf("\n====================================\n");
        printf("\n1. Regular - PHP 620"
               "\n2. Duo(PROMO!) - PHP 1200\n");

        printf("\nNote: Duo Promo Can Only Be Bought For One Time.\n");
        printf("\nCHOOSE PACKAGE(1-2): ");
        scanf("%d", ticketChoice);

        printLoadingDots("Processing", 4, 500);
    
            while (*ticketChoice > 2 || *ticketChoice < 1)
            {   
            printf("\nInvalid Input!");
            printf("\nPlease Try Again\n");
            printf("\nTICKET PRICES: \n"
           "\n1. Regular - PHP 620"
           "\n2. Duo(PROMO!) - PHP 1200\n");
            printf("\nNote: Duo Promo Can Only Be Bought For One Time.\n");

            printf("\nCHOOSE PACKAGE(1-2): ");
            scanf("%d", ticketChoice);

            printLoadingDots("Processing", 4, 500);
            }
        
        if (*ticketChoice == 1)
        {
            printf("\nHOW MANY TICKET(S): ");
            scanf("%d", quantity);
        
            *total = *quantity * 620;

            printLoadingDots("Processing", 4, 500);
        }
        else if (*ticketChoice == 2)
        {
            printf("\nHOW MANY TICKET(S): ");
            scanf("%d", quantity);

            printLoadingDots("Processing", 4, 500);

            while (*quantity != 1)
            {
                printf("\nPackage Can Only Be Bought One Time!");
                printf("\nPlease Try Again\n");
                Sleep(2000);
                printf("\nHOW MANY TICKET(S): ");
                scanf("%d", quantity);

                printLoadingDots("Processing", 4, 500);
            }
            
            *total = *quantity * 1200;

            
        }
  
}

void applyDiscount(double *total, double *discountAmount, int *discountChoice) {

    int discountSelected = 0;
    double discount = 0.0;

    do
    {
        printf("\n====================================");
        printf("\n\tDISCOUNT ELGIBILTY");
        printf("\n====================================\n");
        printf("\n1. Student / 5 %%");
        printf("\n2. Senior / 10 %%");
        printf("\n3. PWD / 20 %%");
        printf("\n4. None / No Discount");

        printf("\n\nSelect Discount: ");
        scanf("%d", &discountSelected);

    if (discountSelected == 1)
    {
        printLoadingDots("Applying Discount", 4, 500);
        discount = *total * (5.0 / 100.0);
        *total -= discount;
        printf("\nDiscount Applied!\n");
    }
    else if (discountSelected == 2)
    {
        printLoadingDots("Applying Discount", 4, 500);
        discount = *total * (10.0 / 100.0);
        *total -= discount;
        printf("\nDiscount Applied!\n");
    }
    else if (discountSelected == 3)
    {
        printLoadingDots("Applying Discount", 4, 500);
        discount = *total * (20.0 / 100.0);
        *total -= discount;
        printf("\nDiscount Applied!\n");
    }
    else if (discountSelected == 4)
    {
        printLoadingDots("Processing", 4, 500);
        printf("\nNo Discount Applied\n");
    }
    else {
        printf("\nInvalid Discount Selected!\n");
        Sleep(3000);
    }

    *discountAmount = discount;
    *discountChoice = discountSelected;

    } while (discountSelected > 4 || discountSelected < 1);
    
    

}

void schedule(int *scheduleChoice) 
{
    
    printf("\n1.) 12:30 PM"
           "\n2.) 5:00 PM"
           "\n3.) 8:15 PM\n");
    printf("\nSELECT TIME(1-3): ");
    scanf("%d", scheduleChoice);

    printLoadingDots("Processing", 4, 500);

        while (*scheduleChoice > 3 || *scheduleChoice < 1)
        {
            printf("\nINVALID INPUT!"
                "\nPlease Try Again\n");
            printf("\n1.) 12:30 PM"
            "\n2.) 5:00 PM"
            "\n3.) 8:15 PM\n");
        
            printf("\nSELECT TIME(1-3): ");
            scanf("%d", scheduleChoice);

            printLoadingDots("Processing", 4, 500);
   
    }

    
}
void orderSummary(double total
                , int movieChoice
                , char movie[5][30]
                , char scheduledTime[3][10]
                , int scheduleChoice) 
{
    printf("\n====================================");
    printf("\n\t   ORDER DETAILS");
    printf("\n====================================\n");
    printf("\nMovie\t: %s", movie[movieChoice - 1]);
    printf("\nTime\t: %s", scheduledTime[scheduleChoice - 1]);
    printf("\nTotal\t: PHP %.2lf ", total);
    
}

void mode_payment(int *paymentChoice
                , double *amount
                , int *cardChoice
                , double total
                , int quantity
                , double *change
                , double *discountAmount) 

{
    int successfulPayment = 0;
    

    printf("\n\n1. CASH"
           "\n2. CARD"
           "\n\nHOW WOULD YOU LIKE TO PAY(1-2): ");
    scanf("%d", paymentChoice);

    printLoadingDots("Processing", 4, 500);
    
            while (*paymentChoice > 2 || *paymentChoice < 1)
            {
                printf("\n\nInvalid Input!"
                   "\nPlease Try Again");

                printf("\n\n1. CASH"
                   "\n2. CARD"
                   "\n\nHOW WOULD YOU LIKE TO PAY(1-2): ");
                scanf("%d", paymentChoice);

                printLoadingDots("Processing", 4, 500);
            }

        if (*paymentChoice == 1)
        {

            do
            {
                printf("\nENTER AMOUNT: ");
                scanf("%lf", amount);

                    if (*amount <= 0)
                    {
                        printLoadingDots("Processing Payment", 4, 500);
                        printf("\nYou Have to Enter The Correct Amount!");
                        printf("\nPlease Try Again\n");
                        successfulPayment = 0;
                        Sleep(2000);
                    }
                    else if (*amount < total)
                    {
                        printLoadingDots("Processing Payment", 4, 500);
                        printf("\nInsufficient Amount!");
                        printf("\nPlease Try Again\n");
                        successfulPayment = 0;
                        Sleep(2000);
                    }
                    else if (*amount > total)
                    {
                        printLoadingDots("Processing Payment", 4, 500);
                        *change = *amount - total;
                        printf("\nPayment Successful!\n");
                        successfulPayment = 1;
                        Sleep(2000);
                    }
                    
                    else  
                    {
                        printLoadingDots("Processing Payment", 4, 500);
                        printf("\nPayment Successful!\n");
                        successfulPayment = 1;
                        Sleep(2000);
                    }
                    
                    
                    
            } while (successfulPayment == 0);
            
            
        }

        else if (*paymentChoice == 2)
        {
            printf("\nACCEPTED CARDS: "
                    "\n\n1. BPI"
                    "\n2. BDO");

            printf("\n\nENTER CARD(1-2): ");
            scanf("%d", cardChoice);


                while (*cardChoice > 2 || *cardChoice < 1)
                {
                    printf("\nInvalid Input!"
                       "\nPlease Try Again\n");

                    printf("\nACCEPTED CARDS: "
                    "\n\n1. BPI"
                    "\n2. BDO");

                printf("\n\nENTER CARD(1-2): ");
                scanf("%d", cardChoice);

                
                }
            
        }
        
}

void transactionSummaryCASH(int quantity, double total, char scheduledTime[3][10], int scheduleChoice, double amount, int movieChoice, char movie[5][30], double change, int discountChoice, char discountOption[4][20], double discountAmount) {
    
    printLoadingDots("Working on it", 4, 500);

    system("cls");
    printf("\n===================================================");
    printf("\n\t\tTRANSACTION SUMMARY");
    printf("\n===================================================\n");
    printf("\nMovie\t\t\t: %s", movie[movieChoice - 1]);
    printf("\nTicket(s) Purchased\t: %d", quantity);
    printf("\nTime\t\t\t: %s", scheduledTime[scheduleChoice - 1]);
    printf("\nMode Of Payment\t\t: CASH");
    printf("\nTotal\t\t\t: PHP %.2lf", total);
    printf("\nDiscount Applied\t: %s", discountOption[discountChoice - 1]);
    printf("\nDiscount Amount\t\t: PHP %.2lf", discountAmount);
    printf("\nPayment Received\t: PHP %.2lf", amount);
    printf("\nChange\t\t\t: PHP %.2lf\n", change);
    printf("\n===================================================\n\n");
}

void transactionSummaryCard(int quantity, double total, char scheduledTime[3][10], int scheduleChoice, int movieChoice, char movie[5][30], char card[2][10], int cardChoice, int discountChoice, char discountOption[4][20], double discountAmount) {
   
    printLoadingDots("Processing Payment", 4, 500);

    printf("\nPayment Successful!\n");
    
    
    Sleep(2000);

    system("cls");
    printf("\n===================================================");
    printf("\n\t\tTRANSACTION SUMMARY");
    printf("\n===================================================\n");
    printf("\nMovie\t\t\t: %s", movie[movieChoice - 1]);
    printf("\nTicket(s) Purchased\t: %d", quantity);
    printf("\nTime\t\t\t: %s", scheduledTime[scheduleChoice - 1]);
    printf("\nTotal\t\t\t: PHP %.2lf", total);
    printf("\nDiscount Applied\t: %s", discountOption[discountChoice - 1]);
    printf("\nDiscount Amount\t\t: PHP %.2lf", discountAmount);
    printf("\nMode Of Payment\t\t: CARD");
    printf("\nBank Card\t\t: %s\n", card[cardChoice - 1]);
    printf("\n===================================================\n\n");
}

void printLoadingDots(const char *message, int dotCount, int delayMs) {
    
    printf("\n%s", message);
    fflush(stdout);

    for (int i = 0; i < dotCount; i++) {
        Sleep(delayMs);
        printf(" .");
        fflush(stdout);
    }
    printf("\n");
}
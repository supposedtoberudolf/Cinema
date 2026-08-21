// FEATURES TO ADD: 
    /*
        discount
        sukli 
        payment validation
    
    */

#include <stdio.h>

void header();

void buyTicket(int *choice, int *quantity, int *total);

void schedule(int *choice);

void orderSummary(int total
                , int movieChoice
                , char movie[5][30]
                , char scheduledTime[3][10]
                , int scheduleChoice);

void mode_payment(int *choice
                , int *amount
                , int *cardChoice
                , int total
                , int quantity);

void transactionSummaryCASH(int quantity
                          , int total
                          , char scheduledTime[3][10]
                          , int scheduleChoice
                          , int amount
                          , int movieChoice
                          , char movie[5][30]);

void transactionSummaryCard(int quantity
                          , int total
                          , char scheduledTime[3][10]
                          , int scheduleChoice
                          , int movieChoice
                          , char movie[5][30]
                          , char card[2][10]
                          , int cardChoice);

int main() {

    int movieChoice = 0;
    int ticketChoice = 0;
    int scheduleChoice = 0;
    int paymentChoice = 0;
    int quantity = 0;
    int total = 0;
    int amount = 0;
    int cardChoice = 0;

    char scheduledTime[3][10] = {"12:30 PM", "5:00 PM", "8:15 PM"};

    char movie[5][30] = {"Spider-Man: Brand New Day"
                        , "Moana"
                        , "Oppenheimer"
                        , "The Odyssey"
                        , "Toy Story 5"};


    char card[2][10] = {"BPI", "BDO"};

    // Pipili ng Movie to Watch
    header();
    printf("\n1.) Spider-Man: Brand New Day"
           "\n2.) Moana"
           "\n3.) Oppenheimer"
           "\n4.) The Odyssey"
           "\n5.) Toy Story 5\n");
    
    printf("\nCHOOSE MOVIE(1-5): ");
    scanf("%d", &movieChoice);

    // Checks if tama input
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
    }
    
    switch (movieChoice)
    {
    case 1:
        header();
        buyTicket(&ticketChoice, &quantity, &total);           
        header();
        schedule(&scheduleChoice);

        orderSummary(total, movieChoice, movie, scheduledTime, scheduleChoice);
        mode_payment(&paymentChoice, &amount, &cardChoice, total, quantity);
        
        if (paymentChoice == 1)
        {
            transactionSummaryCASH(quantity, total, scheduledTime, scheduleChoice, amount, movieChoice, movie);
        }

        else if (paymentChoice == 2)
        {
            transactionSummaryCard(quantity, total, scheduledTime, scheduleChoice, movieChoice, movie, card, cardChoice);
        }
        
        break;
    

    case 2:
        header();
        buyTicket(&ticketChoice, &quantity, &total);           
        header();
        schedule(&scheduleChoice);

        orderSummary(total, movieChoice, movie, scheduledTime, scheduleChoice);
        mode_payment(&paymentChoice, &amount, &cardChoice, total, quantity);
        
        if (paymentChoice == 1)
        {
            transactionSummaryCASH(quantity, total, scheduledTime, scheduleChoice, amount, movieChoice, movie);
        }

        else if (paymentChoice == 2)
        {
            transactionSummaryCard(quantity, total, scheduledTime, scheduleChoice, movieChoice, movie, card, cardChoice);
        }
        
        break;

    case 3:
        header();
        buyTicket(&ticketChoice, &quantity, &total);           
        header();
        schedule(&scheduleChoice);

        orderSummary(total, movieChoice, movie, scheduledTime, scheduleChoice);
        mode_payment(&paymentChoice, &amount, &cardChoice, total, quantity);
        
        if (paymentChoice == 1)
        {
            transactionSummaryCASH(quantity, total, scheduledTime, scheduleChoice, amount, movieChoice, movie);
        }

        else if (paymentChoice == 2)
        {
            transactionSummaryCard(quantity, total, scheduledTime, scheduleChoice, movieChoice, movie, card, cardChoice);
        }
        
        break;

    case 4:
        header();
        buyTicket(&ticketChoice, &quantity, &total);           
        header();
        schedule(&scheduleChoice);

        orderSummary(total, movieChoice, movie, scheduledTime, scheduleChoice);
        mode_payment(&paymentChoice, &amount, &cardChoice, total, quantity);
        
        if (paymentChoice == 1)
        {
            transactionSummaryCASH(quantity, total, scheduledTime, scheduleChoice, amount, movieChoice, movie);
        }

        else if (paymentChoice == 2)
        {
            transactionSummaryCard(quantity, total, scheduledTime, scheduleChoice, movieChoice, movie, card, cardChoice);
        }
        
        break;

    case 5:
        header();
        buyTicket(&ticketChoice, &quantity, &total);           
        header();
        schedule(&scheduleChoice);

        orderSummary(total, movieChoice, movie, scheduledTime, scheduleChoice);
        mode_payment(&paymentChoice, &amount, &cardChoice, total, quantity);
        
        if (paymentChoice == 1)
        {
            transactionSummaryCASH(quantity, total, scheduledTime, scheduleChoice, amount, movieChoice, movie);
        }

        else if (paymentChoice == 2)
        {
            transactionSummaryCard(quantity, total, scheduledTime, scheduleChoice, movieChoice, movie, card, cardChoice);
        }
        
        break;

        
    }


    return 0;
}



void header() 
{
    printf("\n========== CINEMA TICKET ==========\n");
}

void buyTicket(int *ticketChoice, int *quantity, int *total) 
{
        printf("\nTICKET PRICES: \n"
           "\n1. Regular - PHP 620"
           "\n2. Duo(PROMO!) - PHP 1200\n");
        printf("\nCHOOSE PACKAGE(1-2): ");
        scanf("%d", ticketChoice);
    
            while (*ticketChoice > 2 || *ticketChoice < 1)
            {   
            printf("\nInvalid Input!");
            printf("\nPlease Try Again\n");
            printf("\nTICKET PRICES: \n"
           "\n1. Regular - PHP 620"
           "\n2. Duo(PROMO!) - PHP 1200\n");

            printf("\nCHOOSE PACKAGE(1-2): ");
            scanf("%d", ticketChoice);
            }
        
        printf("\nHOW MANY TICKET(S): ");
        scanf("%d", quantity);
        
        if (*ticketChoice == 1)
        {
            *total = *quantity * 620;
        }
        else if (*ticketChoice == 2)
        {
            *total = *quantity * 1200;
        }  
  
}

void schedule(int *scheduleChoice) 
{
    printf("\n1.) 12:30 PM"
           "\n2.) 5:00 PM"
           "\n3.) 8:15 PM\n");
    printf("\nSELECT TIME(1-3): ");
    scanf("%d", scheduleChoice);

        while (*scheduleChoice > 3 || *scheduleChoice < 1)
        {
            printf("\nINVALID INPUT!"
                "\nPlease Try Again\n");
            printf("\n1.) 12:30 PM"
            "\n2.) 5:00 PM"
            "\n3.) 8:15 PM\n");
        
            printf("\nSELECT TIME(1-3): ");
            scanf("%d", scheduleChoice);
   
    }

    
}
void orderSummary(int total, int movieChoice, char movie[5][30], char scheduledTime[3][10], int scheduleChoice) 
{
    movieChoice--;
    scheduleChoice--;
    printf("\n========== ORDER DETAILS ==========\n");
    printf("\nMovie\t: %s", movie[movieChoice]);
    printf("\nTime\t: %s", scheduledTime[scheduleChoice]);
    printf("\nTotal\t: PHP %d ", total);

}

void mode_payment(int *paymentChoice
                , int *amount
                , int *cardChoice
                , int total
                , int quantity) 

{
    printf("\n\n1. CASH"
           "\n2. CARD"
           "\n\nHOW WOULD YOU LIKE TO PAY(1-2): ");
    scanf("%d", paymentChoice);
    
            while (*paymentChoice > 2 || *paymentChoice < 0)
            {
                printf("\n\nInvalid Input!"
                   "\n Please Try Again");

                printf("\n\n1. CASH"
                   "\n2. CARD"
                   "\n\nHOW WOULD YOU LIKE TO PAY(1-2): ");
                scanf("%d", paymentChoice);
            }

        if (*paymentChoice == 1)
        {
            printf("\nENTER AMOUNT: ");
            scanf("%d", amount);


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

void transactionSummaryCASH(int quantity, int total, char scheduledTime[3][10], int scheduleChoice, int amount, int movieChoice, char movie[5][30]) {
    
    movieChoice--;
    scheduleChoice--;
    printf("\n\nPAYMENT SUCCESSFUL!\n");
    printf("\n========== TRANSACTION DETAILS ==========\n");
    printf("\nMovie: %s", movie[movieChoice]);
    printf("\nTicket(s) Purchased: %d", quantity);
    printf("\nTime: %s", scheduledTime[scheduleChoice]);
    printf("\nMode Of Payment: CASH");
    printf("\nTotal: PHP %d", total);
    printf("\nPayment Received: PHP %d\n\n", amount);
}

void transactionSummaryCard(int quantity, int total, char scheduledTime[3][10], int scheduleChoice, int movieChoice, char movie[5][30], char card[2][10], int cardChoice) {
    
    movieChoice--;
    scheduleChoice--;
    cardChoice--;
    printf("\n\nPAYMENT SUCCESSFUL!\n");
    printf("\n========== TRANSACTION DETAILS ==========\n");
    printf("\nMovie: %s", movie[movieChoice]);
    printf("\nTicket(s) Purchased: %d", quantity);
    printf("\nTime: %s", scheduledTime[scheduleChoice]);
    printf("\nTotal: PHP %d", total);
    printf("\nMode Of Payment: CARD");
    printf("\nBank Card: %s\n\n", card[cardChoice]);
}
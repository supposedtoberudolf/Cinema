#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

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

void pressToContinue()
{
    printf("=============================================\n");
    printf("            EXPRESS DINER KIOSK              \n");
    printf("     Freshly Cooked | Served To Your Seat    \n");
    printf("=============================================\n");
    printf("       [ PRESS ENTER TO START ORDER ]       \n");
    printf("=============================================\n");

    while (getchar() != '\n');
    system("cls");
}

void footer()
{
    printf("\n=============================================\n\n");
}

void invalidInput()
{
    printf("\nINVALID INPUT");
    printf("\nPLEASE TRY AGAIN\n");
}

int getUserMenuChoice()
{
    int choice;

    printf("\n=============================================");
    printf("\n   ------ WELCOME TO EXPRESS DINER! ------");
    printf("\n=============================================\n");
    printf("\n[1] MEALS - Enjoy Hot Rice Meals!");
    printf("\n[2] BITES - Crispy Fries & Popcorn!");
    printf("\n[3] DRINKS - Cold Sodas & Juices!");
    printf("\n[4] CONFIRM & PAY - Proceed to Checkout");
    printf("\n[5] EXIT\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

int getUserMealChoice()
{
    int choice;

    printf("\n=============================================");
    printf("\n\t    ------ MEALS ------");
    printf("\n=============================================\n");
    printf("\n[1] CHICKEN W/ GRAVY\t-> PHP 99");
    printf("\n[2] CHICKEN FILLET\t-> PHP 99");
    printf("\n[3] SPAGHETTI OVERLOAD\t-> PHP 129");
    printf("\n[4] PALABOK EXPRESS\t-> PHP 159");
    printf("\n[5] CRISPY PATA\t\t-> PHP 299");
    printf("\n[6] RETURN TO MAIN MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

int getUserBitesChoice()
{
    int choice;

    printf("\n=============================================");
    printf("\n\t    ------ BITES ------");
    printf("\n=============================================\n");
    printf("\n[1] BURGER EXPRESS\t-> PHP 79");
    printf("\n[2] FRENCH FRIES\t-> PHP 59");
    printf("\n[3] POPCORN\t\t-> PHP 109");
    printf("\n[4] HOTDOGS\t\t-> PHP 89");
    printf("\n[5] SPUD POTATO\t\t-> PHP 129");
    printf("\n[6] RETURN TO MAIN MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

int getUserDrinksChoice()
{
    int choice;

    printf("\n=============================================");
    printf("\n\t    ------ DRINKS ------");
    printf("\n=============================================\n");
    printf("\n[1] COKE\t-> PHP 59");
    printf("\n[2] SPRITE\t-> PHP 59");
    printf("\n[3] PEPSI\t-> PHP 59");
    printf("\n[4] ICE TEA\t-> PHP 49");
    printf("\n[5] RETURN TO MAIN MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

int askToOrderAgain(char selectedOrder[3][10], int i) {

    int choice = 0;

    do
    {
    footer();
    printf("DO YOU WISH TO ORDER %s AGAIN? ", selectedOrder[i]);
    printf("\n[1] YES");
    printf("\n[2] NO");

    printf("\n\nSELECT OPTION: ");
    scanf("%d", &choice);
    } while ((choice != 2) && (choice != 1));
    
    return choice;

}

int main() {

    char meals[5][20] = 
    {
        "CHICKEN W/ GRAVY",
        "CHICKEN FILLET",
        "SPAGHETTI OVERLOAD",
        "PALABOK EXPRESS",
        "CRISPY PATA"
    };

    double mealPrices[5] = 
    {
        99.00,
        99.00,
        129.00,
        159.00,
        299.00
    };

    int mealQuantity[5] = {0};

    char bites[5][20] = 
    {
        "BURGER EXPRESS",
        "FRENCH FRIES",
        "POPCORN",
        "HOTDOGS",
        "SPUD POTATO"
    };

    double bitesPrices[5] =
    {
        79.00,
        59.00,
        109.00,
        89.00,
        129.00
    };
    
    int bitesQuantity[5] = {0};

    char drinks[4][10] =
    {
        "COKE",
        "SPRITE",
        "PEPSI",
        "ICE TEA"
    };

    double drinksPrices[4] =
    {
        59.00,
        59.00,
        59.00,
        49.00  
    };

    int drinksQuantity[5] = {0};

    char selectedOrder[3][10] = 
    {
        "MEAL",
        "BITES",
        "DRINKS"
    };
    
    int getUserChoice = 0;
    int userMealChoice = 0;
    int userBitesChoice = 0;
    int userDrinksChoice = 0;

    // SUBTOTAL INDEX 

    int Index = 0;

    // TOTAL

    double itemCost = 0.0;
    double finalTotal = 0.0;

    // MEAL, BITES, DRINKS SUBTOTAL

    double menuSubTotalHandler[3] = {0};

    // MEAL QUANTITY & TOTAL
    int mealTotalQuantityHandler[5] = {0};
    double mealTotalHandler[5] = {0};

    // BITES QUANTITY
    int bitesTotalQuantityHandler[5] = {0};
    double bitesTotalHandler[5] = {0};

    // DRINKS QUANTITY & TOTAL
    int drinksTotalQuantityHandler[5] = {0};
    double drinksTotalHandler[5] = {0};

    // FLAG VARIABLES

    int MealOrderDone = 0;
    int BitesOrderDone = 0;
    int drinksOrderDone = 0;
    int orderDone = 0;

    int orderAgain = 0;
    int continueOrder = 0;
    char cancelOrder = '\0';
    char confirmOrder = '\0';

    // RANDOM NUMBER

    srand(time(NULL));
    int randomNum = (rand() % (100 - 50 + 1)) + 50;

    // START PROGRAM

    pressToContinue();

    do
    {
        getUserChoice = getUserMenuChoice();

        Index = getUserChoice - 1;

            if (getUserChoice == 1)
            {

                do
                {
                    userMealChoice = getUserMealChoice();

                        if ((userMealChoice <= 5) && (userMealChoice >= 1))
                        {
                            int index = userMealChoice - 1;

                            footer();
                            printf("HOW MANY ORDER(S): ");
                            scanf("%d", &mealQuantity[index]);

                            itemCost = mealPrices[index] * mealQuantity[index];
                            mealTotalQuantityHandler[index] += mealQuantity[index];
                            mealTotalHandler[index] += itemCost;
                            menuSubTotalHandler[0] += itemCost;

                            printLoadingDots("PROCESSING ORDER", 4, 500);
                            printf("\nADDED TO ORDER!\n");

                            Sleep(2000);

                            orderAgain = askToOrderAgain(selectedOrder, Index);
                            
                                if (orderAgain == 1)
                                {
                                    MealOrderDone = 0;
                                    printLoadingDots("RETURNING TO MEAL MENU", 4, 500);
                                    continue;
                                }
                                else if (orderAgain == 2)
                                {
                                    MealOrderDone = 1;
                                    printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                                    break;
                                }
                                
                                
                            
                        }
                        else if (userMealChoice == 6)
                        {
                            MealOrderDone = 1;
                            printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                            break;
                        }
                                               
                        else 
                        {
                            invalidInput();
                        }

                        
                } while (MealOrderDone != 1);
                
            }

            else if (getUserChoice == 2)
            {

                do
                {
                    userBitesChoice = getUserBitesChoice();          

                        if ((userBitesChoice <= 5) && (userBitesChoice >= 1))
                        {
                            int index = userBitesChoice - 1;

                            footer();
                            printf("HOW MANY ORDER(S): ");
                            scanf("%d", &bitesQuantity[index]);

                            itemCost = bitesPrices[index] * bitesQuantity[index];
                            bitesTotalQuantityHandler[index] += bitesQuantity[index];
                            bitesTotalHandler[index] += itemCost;
                            menuSubTotalHandler[1] += itemCost;
                            
                            printLoadingDots("PROCESSING ORDER", 4, 500);
                            printf("\nADDED TO ORDER!\n");

                            Sleep(2000);

                            orderAgain = askToOrderAgain(selectedOrder, Index);
                            
                                if (orderAgain == 1)
                                {
                                    BitesOrderDone = 0;
                                    printLoadingDots("RETURNING TO BITES MENU", 4, 500);
                                    continue;
                                }
                                else if (orderAgain == 2)
                                {
                                    BitesOrderDone = 1;
                                    printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                                    break;
                                }
                        }
                        else if (userBitesChoice == 6)
                        {
                            BitesOrderDone = 1;
                            printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                            break;
                        }
                        else 
                        {
                            invalidInput();
                        }

                } while (BitesOrderDone != 1);
                
                
                    
            }

            else if (getUserChoice == 3)
            {

                do
                {
                    userDrinksChoice = getUserDrinksChoice();          

                        if ((userDrinksChoice <= 4) && (userDrinksChoice >= 1))
                        {
                            int index = userDrinksChoice - 1;

                            footer();
                            printf("HOW MANY ORDER(S): ");
                            scanf("%d", &drinksQuantity[index]);

                            itemCost = drinksPrices[index] * drinksQuantity[index];
                            drinksTotalQuantityHandler[index] += drinksQuantity[index];
                            drinksTotalHandler[index] += itemCost;
                            menuSubTotalHandler[2] += itemCost;
                            
                            printLoadingDots("PROCESSING ORDER", 4, 500);
                            printf("\nADDED TO ORDER!\n");

                            Sleep(2000);

                            orderAgain = askToOrderAgain(selectedOrder, Index);
                            
                                if (orderAgain == 1)
                                {
                                    drinksOrderDone = 0;
                                    printLoadingDots("RETURNING TO DRINKS MENU", 4, 500);
                                    continue;
                                }
                                else if (orderAgain == 2)
                                {
                                    drinksOrderDone = 1;
                                    printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                                    break;
                                }
                        }
                        else if (userDrinksChoice == 5)
                        {
                            drinksOrderDone = 1;
                            printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                            break;
                        }
                        else 
                        {
                            invalidInput();
                        }
                } while (drinksOrderDone != 1);
                
                
                    
            }
            
            else if (getUserChoice == 4)
            {
                finalTotal = 0.0;
                for (int i = 0; i < 3; i++)
                {
                    finalTotal += menuSubTotalHandler[i];
                }
                
                if (finalTotal > 0)
                {
                    printf("\n=============================================");
                    printf("\n\t      PURCHASE OVERVIEW");
                    printf("\n=============================================\n");

                    for (int i = 0; i < 5; i++)
                    {
                        if (mealTotalQuantityHandler[i] > 0)
                        {
                            printf("| %-20s - x%-5d PHP %7.2lf\n", meals[i], mealTotalQuantityHandler[i], mealTotalHandler[i]);
                            
                        }
                        if (bitesTotalQuantityHandler[i] > 0)
                        {
                            printf("| %-20s - x%-5d PHP %7.2lf\n", bites[i], bitesTotalQuantityHandler[i], bitesTotalHandler[i]);
                        }
                        
                    }

                    for (int i = 0; i < 4; i++)
                    {
                        if (drinksTotalQuantityHandler[i] > 0)
                        {
                            printf("| %-20s - x%-5d PHP %7.2lf\n", drinks[i], drinksTotalQuantityHandler[i], drinksTotalHandler[i]);
                        }
                    }

                    for (int i = 0; i < 3; i++)
                    {
                        if (menuSubTotalHandler[i] > 0)
                        {
                            printf("\n| %-7s SUBTOTAL:               PHP %7.2lf", selectedOrder[i], menuSubTotalHandler[i]);
                        }
                        
                        
                    }
                    printf("\n| GRAND TOTAL:                  PHP %7.2lf", finalTotal);
                    footer();
                    Sleep(3000);

                    do
                    {
                        printf("\nDO YOU WISH TO PROCEED TO PAYMENT?");
                        printf("\n\nCONFIRM ORDER(Y/N): ");
                        scanf(" %c", &confirmOrder);

                            if (confirmOrder == 'Y' || confirmOrder == 'y')
                            {
                                printLoadingDots("WORKING ON YOUR ORDER", 4, 500);

                                printf("\nYOU MAY NOW PROCEED TO PAYMENT");
                                printf("\n\nYOUR ORDER NUMBER IS 00%d", randomNum);
                                return 0;
                            }
                            else if (confirmOrder == 'N' || confirmOrder == 'n')
                            {
                                printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                                orderDone = 1;
                            }
                            else 
                            {
                                orderDone = 0;
                                invalidInput();
                            }
                    } while (orderDone != 1);
                    
                    
                    
                }
                else
                {
                    printf("\nYOU HAVE TO BUY SOMETHING FIRST.\n");
                    Sleep(2000);
                    printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                }
                
            }
            else if (getUserChoice == 5)
            {
                finalTotal = 0.0;
                for (int i = 0; i < 3; i++)
                {
                    finalTotal += menuSubTotalHandler[i];
                }

                    if (finalTotal > 0)
                    {
                       do
                       {    
                            footer();
                            printf("\nPLEASE NOTE THAT YOUR PENDING ORDERS WILL BE DISCARDED");
                            printf("\nARE YOU SURE YOU WANT TO EXIT?");

                            printf("\n\n(Y/N): ");
                            scanf(" %c", &cancelOrder);

                                if (cancelOrder == 'Y' || cancelOrder == 'y')
                                {
                                    system("cls");
                                    printf("THANK YOU FOR USING EXPRESS DINER KIOSK!");
                                    return 0;
                                }
                                else if (cancelOrder == 'N' || cancelOrder == 'n')
                                {
                                    printLoadingDots("RETURNING TO MAIN MENU", 4, 500);
                                    continueOrder = 1;
                                }
                                else 
                                {
                                    continueOrder = 0;
                                    invalidInput();
                                }
                                

                       } while (continueOrder != 1);

                            
                    }
                    else
                    {
                        system("cls");
                        printf("THANK YOU FOR USING EXPRESS DINER KIOSK!");
                        break;
                    }
                    
                
                
            }
            else
            {
                invalidInput();
            }
            
            
            
    } while (1);
    

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
    printf("\n=============================================\n");
}

void invalidInput()
{
    printf("\nInvalid Input");
    printf("\nPlease Try Again\n");
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
    printf("\n[1] COKE");
    printf("\n[2] SPRITE");
    printf("\n[3] PEPSI");
    printf("\n[4] ICE TEA");
    printf("\n[5] RETURN TO MAIN MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

int getUserDrinksSize()
{
    int choice;

    printf("\n=============================================");
    printf("\n\t  ------ DRINKS SIZES ------");
    printf("\n=============================================\n");
    printf("\n[1] REGULAR\t-> PHP 39");
    printf("\n[2] MEDIUM\t-> PHP 59");
    printf("\n[3] LARGE\t-> PHP 79");
    printf("\n[4] RETURN TO DRINKS MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    return choice;
}

int askToOrderAgain(char message[])
{
    int choice;

    do
    {
        footer();
        printf("\n%s", message);
        printf("\n[1] YES");
        printf("\n[2] NO\n");

        printf("\nCHOOSE ONE: ");
        scanf("%d", &choice);

        if (choice != 1 && choice != 2)
        {
            invalidInput();
        }

    } while (choice != 1 && choice != 2);

    return choice;
}

void showOrder(
    char meals[5][20],
    int mealQuantity[5],
    float mealTotal[5],
    char bites[5][20],
    int biteQuantity[5],
    float biteTotal[5],
    char drinks[4][20],
    char sizes[3][10],
    int drinkQuantity[4][3],
    float drinkTotal[4][3],
    float total)
{
    int i;
    int j;

    printf("\n=============================================");
    printf("\n        ------ PURCHASE OVERVIEW ------");
    printf("\n=============================================\n");

    for (i = 0; i < 5; i++)
    {
        if (mealQuantity[i] > 0)
        {
            printf("\n%s - x%d\t\tPHP %.2f",
                   meals[i], mealQuantity[i], mealTotal[i]);
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (biteQuantity[i] > 0)
        {
            printf("\n%s - x%d\t\tPHP %.2f",
                   bites[i], biteQuantity[i], biteTotal[i]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (drinkQuantity[i][j] > 0)
            {
                printf("\n%s %s - x%d\tPHP %.2f",
                       drinks[i], sizes[j],
                       drinkQuantity[i][j],
                       drinkTotal[i][j]);
            }
        }
    }

    printf("\n\n---------------------------------------------");
    printf("\nTOTAL: \t\t\tPHP %.2f", total);
    printf("\n=============================================\n");
}

int main()
{
    int userMenuChoice;
    int userMealChoice;
    int userBitesChoice;
    int userDrinksChoice;
    int userDrinksSizeChoice;

    int wishToOrder;

    float mealSubtotal = 0.0;
    float biteSubtotal = 0.0;
    float drinkSubtotal = 0.0;
    float total = 0.0;

    char selectedMeals[5][20] =
    {
        "CHICKEN W/ GRAVY",
        "CHICKEN FILLET",
        "SPAGHETTI OVERLOAD",
        "PALABOK EXPRESS",
        "CRISPY PATA"
    };

    char selectedBites[5][20] =
    {
        "BURGER EXPRESS",
        "FRENCH FRIES",
        "POPCORN",
        "HOTDOGS",
        "SPUD POTATO"
    };

    char selectedDrinks[4][20] =
    {
        "COKE",
        "SPRITE",
        "PEPSI",
        "ICE TEA"
    };

    char drinkSizes[3][10] =
    {
        "REGULAR",
        "MEDIUM",
        "LARGE"
    };

    float mealPrices[5] =
    {
        99.00, 99.00, 129.00, 159.00, 299.00
    };

    float bitePrices[5] =
    {
        79.00, 59.00, 109.00, 89.00, 129.00
    };

    float drinkPrices[3] =
    {
        39.00, 59.00, 79.00
    };

    int mealQuantity[5] = {0};
    float mealTotal[5] = {0};

    int biteQuantity[5] = {0};
    float biteTotal[5] = {0};

    int drinkQuantity[4][3] = {0};
    float drinkTotal[4][3] = {0};

    pressToContinue();

    do
    {
        userMenuChoice = getUserMenuChoice();

        if (userMenuChoice == 1)
        {
            do
            {
                userMealChoice = getUserMealChoice();

                if (userMealChoice >= 1 && userMealChoice <= 5)
                {
                    int index = userMealChoice - 1;

                    footer();
                    printf("\nHOW MANY ORDER(S): ");
                    scanf("%d", &wishToOrder);

                    if (wishToOrder > 0)
                    {
                        mealQuantity[index] += wishToOrder;
                        mealTotal[index] = mealQuantity[index] * mealPrices[index];
                        mealSubtotal += wishToOrder * mealPrices[index];

                        if (askToOrderAgain("DO YOU WISH TO ORDER ANOTHER MEAL?") == 2)
                        {
                            break;
                        }
                    }
                    else
                    {
                        invalidInput();
                    }
                }
                else if (userMealChoice == 6)
                {
                    footer();
                    printf("\nRETURNING TO MAIN MENU . . . .\n");
                    Sleep(1500);
                    break;
                }
                else
                {
                    invalidInput();
                }

            } while (1);
        }

        else if (userMenuChoice == 2)
        {
            do
            {
                userBitesChoice = getUserBitesChoice();

                if (userBitesChoice >= 1 && userBitesChoice <= 5)
                {
                    int index = userBitesChoice - 1;

                    footer();
                    printf("\nHOW MANY ORDER(S): ");
                    scanf("%d", &wishToOrder);

                    if (wishToOrder > 0)
                    {
                        biteQuantity[index] += wishToOrder;
                        biteTotal[index] = biteQuantity[index] * bitePrices[index];
                        biteSubtotal += wishToOrder * bitePrices[index];

                        if (askToOrderAgain("DO YOU WISH TO ORDER MORE BITES?") == 2)
                        {
                            break;
                        }
                    }
                    else
                    {
                        invalidInput();
                    }
                }
                else if (userBitesChoice == 6)
                {
                    footer();
                    printf("\nRETURNING TO MAIN MENU . . . .\n");
                    Sleep(1500);
                    break;
                }
                else
                {
                    invalidInput();
                }

            } while (1);
        }

        else if (userMenuChoice == 3)
        {
            do
            {
                userDrinksChoice = getUserDrinksChoice();

                if (userDrinksChoice >= 1 && userDrinksChoice <= 4)
                {
                    int drinkIndex = userDrinksChoice - 1;

                    do
                    {
                        userDrinksSizeChoice = getUserDrinksSize();

                        if (userDrinksSizeChoice >= 1 &&
                            userDrinksSizeChoice <= 3)
                        {
                            int sizeIndex = userDrinksSizeChoice - 1;

                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &wishToOrder);

                            if (wishToOrder > 0)
                            {
                                drinkQuantity[drinkIndex][sizeIndex] += wishToOrder;

                                drinkTotal[drinkIndex][sizeIndex] =
                                    drinkQuantity[drinkIndex][sizeIndex] *
                                    drinkPrices[sizeIndex];

                                drinkSubtotal +=
                                    wishToOrder * drinkPrices[sizeIndex];

                                if (askToOrderAgain("DO YOU WISH TO ORDER MORE DRINKS?") == 2)
                                {
                                    userDrinksSizeChoice = 5;
                                }
                            }
                            else
                            {
                                invalidInput();
                            }
                        }
                        else if (userDrinksSizeChoice == 4)
                        {
                            break;
                        }
                        else
                        {
                            invalidInput();
                        }

                    } while (userDrinksSizeChoice != 5);
                }
                else if (userDrinksChoice == 5)
                {
                    footer();
                    printf("\nRETURNING TO MAIN MENU . . . .\n");
                    Sleep(1500);
                    break;
                }
                else
                {
                    invalidInput();
                }

            } while (1);
        }

        else if (userMenuChoice == 4)
        {
            total = mealSubtotal + biteSubtotal + drinkSubtotal;

            if (total > 0)
            {
                showOrder(
                    selectedMeals,
                    mealQuantity,
                    mealTotal,
                    selectedBites,
                    biteQuantity,
                    biteTotal,
                    selectedDrinks,
                    drinkSizes,
                    drinkQuantity,
                    drinkTotal,
                    total
                );

                printf("\nPress ENTER to return to the main menu...");
                while (getchar() != '\n');
                getchar();
                system("cls");
            }
            else
            {
                printf("\nYOU HAVE TO BUY SOMETHING FIRST\n");
                Sleep(1500);
            }
        }

        else if (userMenuChoice == 5)
        {
            printf("\nThank you for using EXPRESS DINER KIOSK!\n");
            break;
        }

        else
        {
            system("cls");
            invalidInput();
        }

    } while (1);

    return 0;
}

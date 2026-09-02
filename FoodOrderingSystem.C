/*
    Food Menu: Burger, Fries, Popcorn, Hotdogs, Spud
    Drinks: Coke, Sprite, Pepsi, Water

    Features: 
    - add orders
    - discount
    - promo

    for Optimization:
    - preview order quantity to confirm
    - refactoring 

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void pressToContinue() {
    printf("=============================================\n");
    printf("            EXPRESS DINER KIOSK              \n");
    printf("     Freshly Cooked | Served To Your Seat    \n");
    printf("=============================================\n");
    printf("       [ PRESS ENTER TO START ORDER ]       \n");
    printf("=============================================\n");
    while(getchar() != '\n');
    system("cls"); 
}

void footer() {

    printf("\n=============================================\n");
}

int getUserMenuChoice() {

    int userMenuChoice = 0;

    printf("\n=============================================");
    printf("\n   ------ WELCOME TO EXPRESS DINER! ------");
    printf("\n=============================================\n");
    printf("\n[1] MEALS - Enjoy Hot Rice Meals!");
    printf("\n[2] BITES - Crispy Fries & Popcorn!");
    printf("\n[3] DRINKS - Cold Sodas & Juices!");
    printf("\n[4] CONFIRM & PAY - Proceed to Checkout");
    printf("\n[5] EXIT\n");
    
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &userMenuChoice);
    return userMenuChoice;
}

void invalidInput() {

    printf("\nInvalid Input");
    printf("\nPlease Try Again\n");
}

int getUserFoodChoice() {

    int userFoodChoice = 0;

    printf("\n=============================================");
    printf("\n\t    ------ MEALS ------");
    printf("\n=============================================\n");
    printf("\n[1] CHICKEN W/ GRAVY\t- PHP 99");
    printf("\n[2] CHICKEN FILLET\t- PHP 99");
    printf("\n[3] SPAGHETTI OVERLOAD\t- PHP 129");
    printf("\n[4] PALABOK EXPRESS\t- PHP 159");
    printf("\n[5] CRISPY PATA\t\t- PHP 299");
    printf("\n[6] RETURN TO MAIN MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &userFoodChoice);
    return userFoodChoice;
}


int main() {

    // Cinema Food Ordering System
    int userMenuChoice = 0;
    int userFoodChoice = 0;
    int successfulOrder = 0;
    int successfulFoodOrder = 0;

    // Subtotals
    float mealSubtotal = 0.0;
    float biteSubtotal = 0.0;
    float drinkSubtotal = 0.0;

    // WISH TO CONTINUE
    int wishToOrder = 0;

    // Meals
    int chickenOrderQuantity = 0;
    int filletOrderQuantity = 0;
    int spaghettiOrderQuantity = 0;
    int palabokOrderQuantity = 0;
    int crispypataOrderQuantity = 0;
    // Additionals
    int addGravy = 0;

    pressToContinue();

    do
    {
        userMenuChoice = getUserMenuChoice();

            if (userMenuChoice == 1)
            {
                do
                {
                    userFoodChoice = getUserFoodChoice();

                        if (userFoodChoice == 1)
                        {   footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &chickenOrderQuantity);
                            mealSubtotal += (chickenOrderQuantity * 99.00);
                            
                            while (successfulFoodOrder != 1 || wishToOrder > 2 || wishToOrder < 1)
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulFoodOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulFoodOrder = 1;
                                        break;
                                    }
                            }
                            
                            
                        }
                        else if (userFoodChoice == 2)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &filletOrderQuantity);
                            mealSubtotal += (filletOrderQuantity * 99.00);
                            
                            while (successfulFoodOrder != 1 || wishToOrder > 2 || wishToOrder < 1)
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulFoodOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulFoodOrder = 1;
                                        break;
                                    }
                            }
                        }
                        else if (userFoodChoice == 3)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &spaghettiOrderQuantity);
                            mealSubtotal += (spaghettiOrderQuantity * 129.00);
                            
                            while (successfulFoodOrder != 1 || wishToOrder > 2 || wishToOrder < 1)
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulFoodOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulFoodOrder = 1;
                                        break;
                                    }
                            }
                        }
                        else if (userFoodChoice == 4)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &palabokOrderQuantity);
                            mealSubtotal += (palabokOrderQuantity * 159.00);
                            
                            while (successfulFoodOrder != 1 || wishToOrder > 2 || wishToOrder < 1)
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulFoodOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulFoodOrder = 1;
                                        break;
                                    }
                            }
                        }
                        else if (userFoodChoice == 5)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &crispypataOrderQuantity);
                            mealSubtotal += (crispypataOrderQuantity * 299.00);
                            
                            while (successfulFoodOrder != 1 || wishToOrder > 2 || wishToOrder < 1)
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulFoodOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulFoodOrder = 1;
                                        break;
                                    }
                            }
                        }
                        else if (userFoodChoice == 6)
                        {
                            footer();
                            printf("\nRETURNING TO MAIN MENU . . . .\n");
                            successfulFoodOrder = 1;
                            Sleep(3000);
                        }
                        else 
                        {
                            invalidInput();
                            successfulFoodOrder = 0;
                        }
                        
                        
                        
                        
                        
                        
                } while (userFoodChoice > 6 || userFoodChoice < 1 || successfulFoodOrder != 1);

                successfulOrder = 0;
            }

            else if (userMenuChoice == 2)
            {
                successfulOrder = 0;
            }

            else if (userMenuChoice == 3)
            {
                successfulOrder = 0;
            }

            else if (userMenuChoice == 4)
            {
                successfulOrder = 0;
            }

            else if (userMenuChoice == 5)
            {
                successfulOrder = 1;
            }

            else {
                system("cls");
                invalidInput();
                successfulOrder = 0;
            }
            
            

    } while (successfulOrder != 1);
    
    

    return 0;
}

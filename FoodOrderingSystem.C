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
    - DI KAILANGAN ULIT ULITIN YUNG DO YOU WISH TO CONTINUE TO ORDER
    - SA MAY DRINKS SECTION MAGULO BECAUSE OF DIFFERENT SIZES

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

int getUserMealChoice() {

    int userMealChoice = 0;

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
    scanf("%d", &userMealChoice);
    return userMealChoice;
}

int getUserBitesChoice() {

    int userBitesChoice = 0;

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
    scanf("%d", &userBitesChoice);
    return userBitesChoice;
}

int getUserDrinksChoice() {

    int userDrinksChoice = 0;

    printf("\n=============================================");
    printf("\n\t    ------ DRINKS ------");
    printf("\n=============================================\n");
    printf("\n[1] COKE");
    printf("\n[2] SPRITE");
    printf("\n[3] PEPSI");
    printf("\n[4] ICE TEA");
    printf("\n[5] RETURN TO MAIN MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &userDrinksChoice);
    return userDrinksChoice;
}

int getUserDrinksSize() {

    int userDrinksSizeChoice = 0;

    printf("\n=============================================");
    printf("\n\t  ------ DRINKS SIZES ------");
    printf("\n=============================================\n");
    printf("\n[1] REGULAR\t-> PHP 39");
    printf("\n[2] MEDIUM\t-> PHP 59");
    printf("\n[3] LARGE\t-> PHP 79");
    printf("\n[4] RETURN TO DRINKS MENU\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &userDrinksSizeChoice);
    return userDrinksSizeChoice;
}


int main() {

    // Cinema Food Ordering System
    int userMenuChoice = 0;

    int userMealChoice = 0;
    int userBitesChoice = 0;
    int userDrinksChoice = 0;
    int userDrinksSizeChoice = 0;

    int successfulMealOrder = 0;
    int successfulBitesOrder = 0;
    int successfulDrinksOrder = 0;

    int successfulOrder = 0;

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

    // Bites
    int burgerOrderQuantity = 0;
    int friesOrderQuantity = 0;
    int popcornOrderQuantity = 0;
    int hotdogOrderQuantity = 0;
    int spudOrderQuantity = 0;

    // Drinks
    int cokeOrderQuantity = 0;
    int spriteOrderQuantity = 0;
    int pepsiOrderQuantity = 0; 
    int iceteaOrderQuantity = 0;

    // Drinks Sizes

    


    // START PROGRAM
    pressToContinue();

    do
    {
        userMenuChoice = getUserMenuChoice();

            if (userMenuChoice == 1)
            {
                do
                {
                    userMealChoice = getUserMealChoice();

                        if (userMealChoice == 1)
                        {   footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &chickenOrderQuantity);
                            mealSubtotal += (chickenOrderQuantity * 99.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulMealOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulMealOrder = 1;
                                        break;
                                    }
                            } while (successfulMealOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                            
                            
                        }
                        else if (userMealChoice == 2)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &filletOrderQuantity);
                            mealSubtotal += (filletOrderQuantity * 99.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulMealOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulMealOrder = 1;
                                        break;
                                    }
                            } while (successfulMealOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userMealChoice == 3)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &spaghettiOrderQuantity);
                            mealSubtotal += (spaghettiOrderQuantity * 129.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulMealOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulMealOrder = 1;
                                        break;
                                    }
                            } while (successfulMealOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userMealChoice == 4)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &palabokOrderQuantity);
                            mealSubtotal += (palabokOrderQuantity * 159.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulMealOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulMealOrder = 1;
                                        break;
                                    }
                            } while (successfulMealOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userMealChoice == 5)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &crispypataOrderQuantity);
                            mealSubtotal += (crispypataOrderQuantity * 299.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulMealOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulMealOrder = 1;
                                        break;
                                    }
                            } while (successfulMealOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userMealChoice == 6)
                        {
                            footer();
                            printf("\nRETURNING TO MAIN MENU . . . .\n");
                            successfulMealOrder = 1;
                            Sleep(3000);
                        }
                        else 
                        {
                            invalidInput();
                            successfulMealOrder = 0;
                        }
                        
                        
                        
                        
                        
                        
                } while (userMealChoice > 6 || userMealChoice < 1 || successfulMealOrder != 1);

                successfulOrder = 0;
            }

            else if (userMenuChoice == 2)
            {

                do
                {
                    userBitesChoice = getUserBitesChoice();

                        if (userBitesChoice == 1)
                        {   footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &burgerOrderQuantity);
                            biteSubtotal += (burgerOrderQuantity * 79.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER BITES?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulBitesOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulBitesOrder = 1;
                                        break;
                                    }
                            } while (successfulBitesOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                            
                            
                        }
                        else if (userBitesChoice == 2)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &friesOrderQuantity);
                            biteSubtotal += (friesOrderQuantity * 59.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER BITES?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulBitesOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulBitesOrder = 1;
                                        break;
                                    }
                            } while (successfulBitesOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userBitesChoice == 3)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &popcornOrderQuantity);
                            biteSubtotal += (popcornOrderQuantity * 109.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER BITES?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulBitesOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulBitesOrder = 1;
                                        break;
                                    }
                            } while (successfulBitesOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userBitesChoice == 4)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &hotdogOrderQuantity);
                            biteSubtotal += (hotdogOrderQuantity * 89.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER BITES?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulBitesOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulBitesOrder = 1;
                                        break;
                                    }
                            } while (successfulBitesOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userBitesChoice == 5)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &spudOrderQuantity);
                            biteSubtotal += (spudOrderQuantity * 129.00);
                            
                            do
                            {
                                footer();
                                printf("\nDO YOU WISH TO ORDER ANOTHER BITES?");
                                printf("\n[1] YES");
                                printf("\n[2] NO\n");

                                printf("\nCHOOSE ONE: ");
                                scanf("%d", &wishToOrder);

                                    if (wishToOrder == 1)
                                    {
                                        successfulBitesOrder = 0;
                                        break;
                                    }
                                    else if (wishToOrder == 2)
                                    {
                                        successfulBitesOrder = 1;
                                        break;
                                    }
                            } while (successfulBitesOrder != 1 || wishToOrder > 2 || wishToOrder < 1);
                        }
                        else if (userBitesChoice == 6)
                        {
                            footer();
                            printf("\nRETURNING TO MAIN MENU . . . .\n");
                            successfulBitesOrder = 1;
                            Sleep(3000);
                        }
                        else 
                        {
                            invalidInput();
                            successfulBitesOrder = 0;
                        }
                        
                } while (successfulBitesOrder != 1 || userBitesChoice > 6 || userBitesChoice < 1);
                
                successfulOrder = 0;
            }

            else if (userMenuChoice == 3)
            {

                do
                {   
                    userDrinksChoice = getUserDrinksChoice();

                        if (userDrinksChoice == 1)
                        {   
                            userDrinksSizeChoice = getUserDrinksSize();
                            
                                if (userDrinksSizeChoice == 1)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &cokeOrderQuantity);
                                    drinkSubtotal += (cokeOrderQuantity * 39.00);
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &cokeOrderQuantity);
                                    drinkSubtotal += (cokeOrderQuantity * 59.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &cokeOrderQuantity);
                                    drinkSubtotal += (cokeOrderQuantity * 79.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 4)
                                {
                                    successfulDrinksOrder = 0;
                                    continue;
                                }                      
                        }
                        else if (userDrinksChoice == 2)
                        {
                            userDrinksSizeChoice = getUserDrinksSize();
                            
                                if (userDrinksSizeChoice == 1)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &spriteOrderQuantity);
                                    drinkSubtotal += (spriteOrderQuantity * 39.00);
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &spriteOrderQuantity);
                                    drinkSubtotal += (spriteOrderQuantity * 59.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &spriteOrderQuantity);
                                    drinkSubtotal += (spriteOrderQuantity * 79.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 4)
                                {
                                    successfulDrinksOrder = 0;
                                    continue;
                                }
                        }
                        else if (userDrinksChoice == 3)
                        {
                            userDrinksSizeChoice = getUserDrinksSize();
                            
                                if (userDrinksSizeChoice == 1)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &pepsiOrderQuantity);
                                    drinkSubtotal += (pepsiOrderQuantity * 39.00);
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &pepsiOrderQuantity);
                                    drinkSubtotal += (pepsiOrderQuantity * 59.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &pepsiOrderQuantity);
                                    drinkSubtotal += (pepsiOrderQuantity * 79.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 4)
                                {
                                    successfulDrinksOrder = 0;
                                    continue;
                                }
                        }
                        else if (userDrinksChoice == 4)
                        {
                            userDrinksSizeChoice = getUserDrinksSize();
                            
                                if (userDrinksSizeChoice == 1)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &iceteaOrderQuantity);
                                    drinkSubtotal += (iceteaOrderQuantity * 39.00);
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &iceteaOrderQuantity);
                                    drinkSubtotal += (iceteaOrderQuantity * 59.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &iceteaOrderQuantity);
                                    drinkSubtotal += (iceteaOrderQuantity * 79.00);
                                    
                                }
                                else if (userDrinksSizeChoice == 4)
                                {
                                    successfulDrinksOrder = 0;
                                    continue;
                                }
                        }
                        else if (userDrinksChoice == 5)
                        {
                            successfulDrinksOrder = 1;
                        }
                        else 
                        {
                            successfulDrinksOrder = 0;
                            invalidInput(); 
                        }
                        
                                    if (userDrinksSizeChoice <= 3 && userDrinksSizeChoice >= 1)
                                    {
                                        do  
                                        {
                                        footer();
                                        printf("\nDO YOU WISH TO ORDER MORE DRINKS?");
                                        printf("\n[1] YES");
                                        printf("\n[2] NO\n");

                                        printf("\nCHOOSE ONE: ");
                                        scanf("%d", &wishToOrder);

                                            if (wishToOrder == 1)
                                            {
                                                successfulDrinksOrder = 0;
                                            }
                                            else if (wishToOrder == 2)
                                            {
                                                successfulDrinksOrder = 1;
                                            }
                                        } while (wishToOrder > 2 || wishToOrder < 1);
                                    }

                } while (successfulDrinksOrder != 1);
                
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

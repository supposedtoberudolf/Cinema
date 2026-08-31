/*
    Food Menu: Burger, Fries, Popcorn, Hotdogs, Spud
    Drinks: Coke, Sprite, Pepsi, Water

    Features: 
    - add orders
    - discount
    - promo

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

int getUserFoodChoice() {

    int foodChoice = 0;

    printf("\n=============================================");
    printf("\n   ------ WELCOME TO EXPRESS DINER! ------");
    printf("\n=============================================\n");
    printf("\n[1] MEALS - Enjoy Hot Rice Meals!");
    printf("\n[2] BITES - Crispy Fries & Popcorn!");
    printf("\n[3] DRINKS - Cold Sodas & Juices!");
    printf("\n[4] CONFIRM & PAY - Proceed to Checkout");
    printf("\n[5] EXIT\n");
    
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", &foodChoice);
    return foodChoice;
}

void invalidInput() {

    printf("\nInvalid Input");
    printf("\nPlease Try Again\n");
}

int main() {

    // Cinema Food Ordering System
    int foodChoice = 0;
    int successfulOrder = 0;

    pressToContinue();

    do
    {
        foodChoice = getUserFoodChoice();

            if (foodChoice == 1)
            {
                successfulOrder = 0;
            }

            else if (foodChoice == 2)
            {
                successfulOrder = 0;
            }

            else if (foodChoice == 3)
            {
                successfulOrder = 0;
            }

            else if (foodChoice == 4)
            {
                successfulOrder = 0;
            }

            else if (foodChoice == 5)
            {
                successfulOrder = 1;
            }

            else {
                system("cls");
                invalidInput();
                successfulOrder = 0;
            }
            
            

    } while (successfulOrder != 1);
    
    system("cls");
    

    return 0;
}

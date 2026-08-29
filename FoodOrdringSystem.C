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

    printf("=============================================");
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

int main() {

    // Cinema Food Ordering System
    int foodChoice = 0;

    pressToContinue();

    foodChoice = getUserFoodChoice();

    return 0;
}

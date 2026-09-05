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
    - 
    - 

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

void mealWishToOrder(int *wishToOrder, int *successfulMealOrder) {

    do
    {
        footer();
        printf("\nDO YOU WISH TO ORDER ANOTHER MEAL?");
        printf("\n[1] YES");
        printf("\n[2] NO\n");

        printf("\nCHOOSE ONE: ");
        scanf("%d", wishToOrder);

            if (*wishToOrder == 1)
            {
            *successfulMealOrder = 0;
            break;
            }
            else if (*wishToOrder == 2)
            {
            *successfulMealOrder = 1;
            break;
            }
    } while (*successfulMealOrder != 1 || *wishToOrder > 2 || *wishToOrder < 1);
}

void bitesWishToOrder(int *wishToOrder, int *successfulBitesOrder) {

    do
    {
        footer();
        printf("\nDO YOU WISH TO ORDER MORE BITES?");
        printf("\n[1] YES");
        printf("\n[2] NO\n");

        printf("\nCHOOSE ONE: ");
        scanf("%d", wishToOrder);

            if (*wishToOrder == 1)
            {
            *successfulBitesOrder = 0;
            break;
            }
            else if (*wishToOrder == 2)
            {
            *successfulBitesOrder = 1;
            break;
            }
    } while (*successfulBitesOrder != 1 || *wishToOrder > 2 || *wishToOrder < 1);
}

void drinksWishToOrder(int *wishToOrder, int *successfulDrinksOrder) {

    do  
    {
        footer();
        printf("\nDO YOU WISH TO ORDER MORE DRINKS?");
        printf("\n[1] YES");
        printf("\n[2] NO\n");

        printf("\nCHOOSE ONE: ");
        scanf("%d", wishToOrder);

            if (*wishToOrder == 1)
            {
                *successfulDrinksOrder = 0;
            }
            else if (*wishToOrder == 2)
            {
                *successfulDrinksOrder = 1;
            }
    } while (*wishToOrder > 2 || *wishToOrder < 1);
}

void confirmOrder(char selectedMeals[5][20]
                , int isMealChoice1
                , int chickenOrderFinalQuantity
                , float chickenOrderFinalTotal
                , int isMealChoice2
                , int filletOrderFinalQuantity
                , float filletOrderFinalTotal
                , int isMealChoice3
                , int spaghettiOrderFinalQuantity
                , float spaghettiOrderFinalTotal
                , int isMealChoice4
                , int palabokOrderFinalQuantity
                , float palabokOrderFinalTotal
                , int isMealChoice5
                , int crispypataOrderFinalQuantity
                , float crispypataOrderFinalTotal) {

    printf("\n=============================================");
    printf("\n        ------ PURCHASE OVERVIEW ------");
    printf("\n=============================================\n");

    if (isMealChoice1)
    {
        printf("\n%s - x%d\t\tPHP %.2f", selectedMeals[isMealChoice1 - 1], chickenOrderFinalQuantity, chickenOrderFinalTotal);
    }
    if (isMealChoice2)
    {
        printf("\n%s - x%d\t\tPHP %.2f", selectedMeals[isMealChoice2 - 1], filletOrderFinalQuantity, filletOrderFinalTotal);
    }
    if (isMealChoice3)
    {
        printf("\n%s - x%d\t\tPHP %.2f", selectedMeals[isMealChoice3 - 1], spaghettiOrderFinalQuantity, spaghettiOrderFinalTotal);
    }
    if (isMealChoice4)
    {
        printf("\n%s - x%d\t\tPHP %.2f", selectedMeals[isMealChoice4 - 1], palabokOrderFinalQuantity, palabokOrderFinalTotal);
    }
    if (isMealChoice5)
    {
        printf("\n%s - x%d\t\tPHP %.2f", selectedMeals[isMealChoice5 - 1], crispypataOrderFinalQuantity, crispypataOrderFinalTotal);
    }
    
    
    
    
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

    // Total 
    float total = 0.0;
    float grandTotal = 0.0;

    // WISH TO CONTINUE
    int wishToOrder = 0;

    // Meals
    int chickenOrderQuantity = 0;
    int filletOrderQuantity = 0;
    int spaghettiOrderQuantity = 0;
    int palabokOrderQuantity = 0;
    int crispypataOrderQuantity = 0;

    int chickenOrderFinalQuantity = 0;
    int filletOrderFinalQuantity = 0;
    int spaghettiOrderFinalQuantity = 0;
    int palabokOrderFinalQuantity = 0;
    int crispypataOrderFinalQuantity = 0;

    float chickenOrderTotal = 0.0;
    float filletOrderTotal = 0.0;
    float spaghettiOrderTotal = 0.0;
    float palabokOrderTotal = 0.0;
    float crispypataOrderTotal = 0.0;

    float chickenOrderFinalTotal = 0.0;
    float filletOrderFinalTotal = 0.0;
    float spaghettiOrderFinalTotal = 0.0;
    float palabokOrderFinalTotal = 0.0;
    float crispypataOrderFinalTotal = 0.0;

    // Bites
    int burgerOrderQuantity = 0;
    int friesOrderQuantity = 0;
    int popcornOrderQuantity = 0;
    int hotdogOrderQuantity = 0;
    int spudOrderQuantity = 0;

    int burgerOrderFinalQuantity = 0;
    int friesOrderFinalQuantity = 0;
    int popcornOrderFinalQuantity = 0;
    int hotdogOrderFinalQuantity = 0;
    int spudOrderFinalQuantity = 0;

    float burgerOrderTotal = 0.0;
    float friesOrderTotal = 0.0;
    float popcornOrderTotal = 0.0;
    float hotdogOrderTotal = 0.0;
    float spudOrderTotal = 0.0;

    float burgerOrderFinalTotal = 0.0;
    float friesOrderFinalTotal = 0.0;
    float popcornOrderFinalTotal = 0.0;
    float hotdogOrderFinalTotal = 0.0;
    float spudOrderFinalTotal = 0.0;

    // Drinks Regular
    int cokeRegularOrderQuantity = 0;
    int spriteRegularOrderQuantity = 0;
    int pepsiRegularOrderQuantity = 0; 
    int iceteaRegularOrderQuantity = 0;

    int cokeRegularOrderFinalQuantity = 0;
    int spriteRegularOrderFinalQuantity = 0;
    int pepsiRegularOrderFinalQuantity = 0; 
    int iceteaRegularOrderFinalQuantity = 0;

    float cokeRegularOrderTotal = 0.0;
    float spriteRegularOrderTotal = 0.0;
    float pepsiRegularOrderTotal = 0.0; 
    float iceteaRegularOrderTotal = 0.0;

    float cokeRegularOrderFinalTotal = 0.0;
    float spriteRegularOrderFinalTotal = 0.0;
    float pepsiRegularOrderFinalTotal = 0.0; 
    float iceteaRegularOrderFinalTotal = 0.0;

    // Drinks Medium
    int cokeMediumOrderQuantity = 0;
    int spriteMediumOrderQuantity = 0;
    int pepsiMediumOrderQuantity = 0; 
    int iceteaMediumOrderQuantity = 0;

    int cokeMediumOrderFinaluantity = 0;
    int spriteMediumOrderFinaluantity = 0;
    int pepsiMediumOrderFinalQuantity = 0; 
    int iceteaMediumOrderFinalQuantity = 0;

    float cokeMediumOrderTotal = 0.0;
    float spriteMediumOrderTotal = 0.0;
    float pepsiMediumOrderTotal = 0.0; 
    float iceteaMediumOrderTotal = 0.0;

    float cokeMediumOrderFinalTotal = 0.0;
    float spriteMediumOrderFinalTotal = 0.0;
    float pepsiMediumOrderFinalTotal = 0.0; 
    float iceteaMediumOrderFinalTotal = 0.0;

    // Drinks Large
    int cokeLargeOrderQuantity = 0;
    int spriteLargeOrderQuantity = 0;
    int pepsiLargeOrderQuantity = 0; 
    int iceteaLargeOrderQuantity = 0;

    int cokeLargeOrderFinalQuantity = 0;
    int spriteLargeOrderFinalQuantity = 0;
    int pepsiLargeOrderFinalQuantity = 0; 
    int iceteaLargeOrderFinalQuantity = 0;

    float cokeLargeOrderTotal = 0.0;
    float spriteLargeOrderTotal = 0.0;
    float pepsiLargeOrderTotal = 0.0; 
    float iceteaLargeOrderTotal = 0.0;

    float cokeLargeOrderFinalTotal = 0.0;
    float spriteLargeOrderFinalTotal = 0.0;
    float pepsiLargeOrderFinalTotal = 0.0; 
    float iceteaLargeOrderFinalTotal = 0.0;

    char selectedMeals[5][20] = {"CHICKEN W/ GRAVY", "CHICKEN FILLET", "SPAGHETTI OVERLOAD", "PALABOK EXPRESS", "CRISPY PATA"};
    char selectedBites[5][20] = {"BURGER EXPRESS", "FRENCH FRIES", "POPCORN", "HOTDOGS", "SPUD POTATO"};
    char selectedDrinks[4][20] = {"COKE", "SPRITE", "PEPSI", "ICE TEA"};
    char drinks_Size[3][10] = {"REGULAR", "MEDIUM", "LARGE"};

    int isMealChoice1 = 0;
    int isMealChoice2 = 0;
    int isMealChoice3 = 0;
    int isMealChoice4 = 0;
    int isMealChoice5 = 0;

    int isBitesChoice1 = 0;
    int isBitesChoice2 = 0;
    int isBitesChoice3 = 0;
    int isBitesChoice4 = 0;
    int isBitesChoice5 = 0;

    int isDrinksChoice1 = 0;
    int isDrinksChoice2 = 0;
    int isDrinksChoice3 = 0;
    int isDrinksChoice4 = 0;

    int isDrinksSize1 = 0;
    int isDrinksSize2 = 0;
    int isDrinksSize3 = 0;
    
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
                        {   
                            isMealChoice1 = userMealChoice;
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &chickenOrderQuantity);
                            chickenOrderTotal = 0;
                            chickenOrderTotal += (chickenOrderQuantity * 99.00);
                            chickenOrderFinalQuantity += chickenOrderQuantity;
                            chickenOrderFinalTotal += chickenOrderTotal;
                            mealSubtotal += chickenOrderTotal;
                        }
                        else if (userMealChoice == 2)
                        {
                            isMealChoice2 = userMealChoice;
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &filletOrderQuantity);
                            filletOrderTotal = 0;
                            filletOrderTotal += (filletOrderQuantity * 99.00);
                            filletOrderFinalQuantity += filletOrderQuantity;
                            filletOrderFinalTotal += filletOrderTotal;
                            mealSubtotal += filletOrderTotal;
                                                        
                        }
                        else if (userMealChoice == 3)
                        {
                            isMealChoice3 = userMealChoice;
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &spaghettiOrderQuantity);
                            spaghettiOrderTotal = 0;
                            spaghettiOrderTotal += (spaghettiOrderQuantity * 129.00);
                            spaghettiOrderFinalQuantity += spaghettiOrderQuantity;
                            spaghettiOrderFinalTotal += spaghettiOrderTotal;
                            mealSubtotal += spaghettiOrderTotal;
                                                        
                        }
                        else if (userMealChoice == 4)
                        {
                            isMealChoice4 = userMealChoice;
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &palabokOrderQuantity);
                            palabokOrderTotal = 0;
                            palabokOrderTotal += (palabokOrderQuantity * 159.00);
                            palabokOrderFinalQuantity += palabokOrderQuantity;
                            palabokOrderFinalTotal += palabokOrderTotal;
                            mealSubtotal += palabokOrderTotal;
                                                        
                        }
                        else if (userMealChoice == 5)
                        {
                            isMealChoice5 = userMealChoice;
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &crispypataOrderQuantity);
                            crispypataOrderTotal = 0;
                            crispypataOrderTotal += (crispypataOrderQuantity * 299.00);
                            crispypataOrderFinalQuantity += crispypataOrderQuantity;
                            crispypataOrderFinalTotal += crispypataOrderTotal;
                            mealSubtotal += crispypataOrderTotal;
                                                        
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
                        
                                if (userMealChoice <= 5 && userMealChoice >= 1)
                                {
                                    mealWishToOrder(&wishToOrder, &successfulMealOrder);
                                }
                                   
                } while (successfulMealOrder != 1);

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
                            burgerOrderTotal = 0;
                            burgerOrderTotal += (burgerOrderQuantity * 79.00);
                            burgerOrderFinalQuantity += burgerOrderQuantity;
                            burgerOrderFinalTotal += burgerOrderTotal;
                            biteSubtotal += burgerOrderQuantity;
                            
                        }
                        else if (userBitesChoice == 2)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &friesOrderQuantity);
                            friesOrderTotal = 0;
                            friesOrderTotal += (friesOrderQuantity * 59.00);
                            friesOrderFinalQuantity += friesOrderQuantity;
                            friesOrderFinalTotal += friesOrderTotal;
                            biteSubtotal += friesOrderTotal;
                            
                        }
                        else if (userBitesChoice == 3)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &popcornOrderQuantity);
                            popcornOrderTotal = 0;
                            popcornOrderTotal += (popcornOrderQuantity * 109.00);
                            popcornOrderFinalQuantity += popcornOrderQuantity;
                            popcornOrderFinalTotal += popcornOrderTotal;
                            biteSubtotal += popcornOrderTotal;
                            
                        }
                        else if (userBitesChoice == 4)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &hotdogOrderQuantity);
                            hotdogOrderTotal = 0;
                            hotdogOrderTotal += (hotdogOrderQuantity * 89.00);
                            hotdogOrderFinalQuantity += hotdogOrderQuantity;
                            hotdogOrderFinalTotal += hotdogOrderTotal;
                            biteSubtotal += hotdogOrderTotal;
                            
                        }
                        else if (userBitesChoice == 5)
                        {
                            footer();
                            printf("\nHOW MANY ORDER(S): ");
                            scanf("%d", &spudOrderQuantity);
                            spudOrderTotal = 0;
                            spudOrderTotal += (spudOrderQuantity * 129.00);
                            spudOrderFinalQuantity += spudOrderQuantity;
                            spudOrderFinalTotal += spudOrderTotal;
                            biteSubtotal += spudOrderTotal;
                            
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
                        
                                if (userBitesChoice <= 5 && userBitesChoice >= 1)
                                {
                                    bitesWishToOrder(&wishToOrder, &successfulBitesOrder);
                                }
                                
                } while (successfulBitesOrder != 1);
                
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
                                    scanf("%d", &cokeRegularOrderQuantity);
                                    cokeRegularOrderTotal = 0;
                                    cokeRegularOrderTotal += (cokeRegularOrderQuantity * 39.00);
                                    cokeRegularOrderFinalQuantity += cokeRegularOrderQuantity;
                                    cokeRegularOrderFinalTotal += cokeRegularOrderTotal;
                                    drinkSubtotal += cokeRegularOrderTotal;
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &cokeMediumOrderQuantity);
                                    cokeMediumOrderTotal = 0;
                                    cokeMediumOrderQuantity += (cokeMediumOrderQuantity * 59.00);
                                    cokeMediumOrderFinalTotal += cokeMediumOrderQuantity;
                                    cokeMediumOrderFinalTotal += cokeMediumOrderTotal;
                                    drinkSubtotal += cokeMediumOrderTotal;
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &cokeLargeOrderQuantity);
                                    cokeLargeOrderTotal = 0;
                                    cokeLargeOrderTotal += (cokeLargeOrderQuantity * 79.00);
                                    cokeLargeOrderFinalQuantity += cokeLargeOrderQuantity;
                                    cokeLargeOrderFinalTotal += cokeLargeOrderTotal;
                                    drinkSubtotal += cokeLargeOrderTotal;
                                    
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
                                    scanf("%d", &spriteRegularOrderQuantity);
                                    spriteRegularOrderTotal = 0;
                                    spriteRegularOrderTotal += (spriteRegularOrderQuantity * 39.00);
                                    spriteRegularOrderFinalQuantity += spriteRegularOrderFinalQuantity;
                                    drinkSubtotal += spriteRegularOrderTotal;
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &spriteMediumOrderQuantity);
                                    spriteMediumOrderTotal = 0;
                                    spriteMediumOrderTotal += (spriteMediumOrderQuantity * 59.00);
                                    spriteMediumOrderFinaluantity += spriteMediumOrderQuantity;
                                    drinkSubtotal += spriteMediumOrderTotal;
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &spriteLargeOrderQuantity);
                                    spriteLargeOrderTotal = 0;
                                    spriteLargeOrderTotal += (spriteLargeOrderQuantity * 79.00);
                                    spriteLargeOrderFinalQuantity += spriteLargeOrderQuantity;
                                    drinkSubtotal += spriteLargeOrderTotal;
                                    
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
                                    scanf("%d", &pepsiRegularOrderQuantity);
                                    pepsiRegularOrderTotal = 0;
                                    pepsiRegularOrderTotal += (pepsiRegularOrderQuantity * 39.00);
                                    pepsiRegularOrderFinalTotal += pepsiRegularOrderQuantity;
                                    pepsiRegularOrderFinalTotal += pepsiLargeOrderTotal;
                                    drinkSubtotal += pepsiRegularOrderTotal;
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &pepsiMediumOrderQuantity);
                                    pepsiMediumOrderTotal = 0;
                                    pepsiMediumOrderTotal += (pepsiMediumOrderQuantity * 59.00);
                                    pepsiMediumOrderFinalQuantity += pepsiMediumOrderQuantity;
                                    pepsiMediumOrderFinalTotal += pepsiMediumOrderTotal;
                                    drinkSubtotal += pepsiMediumOrderTotal;
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &pepsiLargeOrderQuantity);
                                    pepsiLargeOrderTotal = 0;
                                    pepsiLargeOrderTotal += (pepsiLargeOrderQuantity * 79.00);
                                    pepsiLargeOrderFinalQuantity += pepsiLargeOrderQuantity;
                                    pepsiLargeOrderFinalTotal += pepsiLargeOrderTotal;
                                    drinkSubtotal += pepsiLargeOrderTotal;
                                    
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
                                    scanf("%d", &iceteaRegularOrderQuantity);
                                    iceteaRegularOrderTotal = 0;
                                    iceteaRegularOrderTotal += (iceteaRegularOrderQuantity * 39.00);
                                    iceteaRegularOrderFinalQuantity += iceteaRegularOrderQuantity;
                                    iceteaRegularOrderFinalTotal += iceteaRegularOrderTotal;
                                    drinkSubtotal += iceteaRegularOrderTotal;
                                    
                            
                                }
                                else if (userDrinksSizeChoice == 2)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &iceteaMediumOrderQuantity);
                                    iceteaMediumOrderTotal = 0;
                                    iceteaMediumOrderTotal += (iceteaMediumOrderQuantity * 59.00);
                                    iceteaMediumOrderFinalQuantity += iceteaMediumOrderQuantity;
                                    iceteaMediumOrderFinalTotal += iceteaMediumOrderTotal;
                                    drinkSubtotal += iceteaMediumOrderTotal;
                                    
                                }
                                else if (userDrinksSizeChoice == 3)
                                {
                                    footer();
                                    printf("\nHOW MANY ORDER(S): ");
                                    scanf("%d", &iceteaLargeOrderQuantity);
                                    iceteaLargeOrderTotal = 0;
                                    iceteaLargeOrderTotal += (iceteaLargeOrderQuantity * 79.00);
                                    iceteaLargeOrderFinalQuantity += iceteaLargeOrderQuantity;
                                    iceteaLargeOrderFinalTotal += iceteaLargeOrderTotal;
                                    drinkSubtotal += iceteaLargeOrderTotal;
                                    
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
                        
                                if (userDrinksSizeChoice <= 4 && userDrinksSizeChoice >= 1)
                                {
                                    drinksWishToOrder(&wishToOrder, &successfulDrinksOrder);
                                }

                } while (successfulDrinksOrder != 1);
                
                successfulOrder = 0;
            } 

            else if (userMenuChoice == 4)
            {
                total = mealSubtotal + biteSubtotal + drinkSubtotal;

                if (total > 0)
                {
                    confirmOrder(selectedMeals, isMealChoice1, chickenOrderFinalQuantity, chickenOrderFinalTotal
                                , isMealChoice2, filletOrderFinalQuantity, filletOrderFinalTotal
                                , isMealChoice3, spaghettiOrderFinalQuantity, spaghettiOrderFinalTotal
                                , isMealChoice4, palabokOrderFinalQuantity, palabokOrderFinalTotal
                                , isMealChoice5, crispypataOrderFinalQuantity, crispypataOrderFinalTotal);
                }
                else
                {
                    printf("\nYOU HAVE TO BUY SOMETHING FIRST\n");
                    successfulOrder = 0;
                }
                
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

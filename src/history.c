#include <stdio.h>
#include "history.h"
#define MAX_HISTORY 100

//static array to store history
static Calculation history[MAX_HISTORY];
static int history_count = 0;

//save calculation to history
void save_to_history(char operation, double operand1, double operand2, double result)
{
    //check if history is full
    if (history_count == MAX_HISTORY)
    {
        printf("Error: Calculation history is full. Please clear or reset the history.\n");
        return;
    }

    //save calculation to history
    history[history_count].operation = operation;
    history[history_count].operand1 = operand1;
    history[history_count].operand2 = operand2;
    history[history_count].result = result;

    //increment history count
    history_count++;
}

//display history
void display_history(){
        if (history_count == 0){
        printf("No calculations in history.\n");
        return;
        }

        printf("========== Calculation History ==========\n");
for (int i = 0; i < history_count; i++) {
    printf("%d. %.2lf %c %.2lf = %.2lf\n", 
           i + 1, 
           history[i].operand1, 
           history[i].operation, 
           history[i].operand2, 
           history[i].result);
}
printf("=========================================\n");
}
void clear_history(){
    history_count = 0;
    printf("History cleared.\n");
}

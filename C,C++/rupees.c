#include <stdio.h>

int main(void)
{
    printf("enter the amount: ");
    float amount;
    scanf("%f", &amount);
    int paisa = amount * 100;
    printf("paisa: %i", paisa);
}

// when the input is 4.2 it converts the rupees to 419 instead of 420
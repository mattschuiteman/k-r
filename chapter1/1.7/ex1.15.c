#include <stdio.h>

float celsiusFrom(float fahr);

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("----- Fahrenheit & Celsius Table -----\n");
    while (fahr <= upper) {
	celsius = celsiusFrom(fahr);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr = fahr + step;
    }
}

float celsiusFrom(float fahr)
{
    float celsius;
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}


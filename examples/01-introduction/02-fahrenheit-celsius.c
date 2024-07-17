#include<stdio.h>

/* print fahrenheit-celsius table for fahr = 0, 20, .....300 */

int main () {
	float fahr, celsius;
	int start, stop, step;

	start = 0;
	stop = 300;
	step = 20;
	printf("fah  celsius\n");
	fahr = start;
	while (fahr <= stop) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f  %7.2f\n", fahr, celsius);
		fahr = fahr + step;
	}
}


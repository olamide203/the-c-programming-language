#include <stdio.h>

int main(){
    float celsius, fahr;
    int start, stop, step;

    start = 0;
    stop = 300;
    step = 20;

    celsius = start;
    printf(" °C   °F\n");
    while(celsius <= stop){
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f  %3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}


#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
int main()
{
    double x, y, z, result;
    printf("Input in meters and degrees.\n\n");
    printf("Define alpha: ");
    scanf("%lf", &x);
    printf("Define beta: ");
    scanf("%lf", &y);
    printf("Defina distance: ");
    scanf("%lf", &z);
    
    result = z * ((cos(((y * M_PI)/180))*(((pow(cos(((x * M_PI)/180)),2))/(sin(((x * M_PI)/180)))) + ((pow((cos(((x * M_PI)/180))),3)) * (sin(((y * M_PI)/180)))/(sin(((x * M_PI)/180)))))) - (pow(((cos(((x * M_PI)/180)))*(cos(((y * M_PI)/180)))),2)));
    
    printf("\n\n\n the distance is: %lf", result);
    return 0;
}


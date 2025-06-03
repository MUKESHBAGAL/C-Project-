#include <stdio.h>
#include <math.h>

void showMenu() {
    printf("\nEngineering Calculator\n");
    printf("1.  Addition\n");
    printf("2.  Subtraction\n");
    printf("3.  Multiplication\n");
    printf("4.  Division\n");
    printf("5.  Sine (sin)\n");
    printf("6.  Cosine (cos)\n");
    printf("7.  Tangent (tan)\n");
    printf("8.  Exponential (e^x)\n");
    printf("9.  Logarithm (ln)\n");
    printf("10. Power (x^y)\n");
    printf("11. Square Root\n");
    printf("12. Differentiation (ax^n)\n");
    printf("13. Integration (ax^n)\n");
    printf("14. Exit\n");
    printf("Enter your choice: ");
}

void differentiation() {
    double a, n, x, result;
    printf("Enter coefficient (a): ");
    scanf("%lf", &a);
    printf("Enter exponent (n): ");
    scanf("%lf", &n);
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    result = a * n * pow(x, n - 1);
    printf("The derivative of %.2lfx^%.2lf at x = %.2lf is %.2lf\n", a, n, x, result);
}

void integration() {
    double a, n, x1, x2, integralAtX2, integralAtX1, result;
    printf("Enter coefficient (a): ");
    scanf("%lf", &a);
    printf("Enter exponent (n): ");
    scanf("%lf", &n);
    printf("Enter lower limit of integration (x1): ");
    scanf("%lf", &x1);
    printf("Enter upper limit of integration (x2): ");
    scanf("%lf", &x2);

    if (n == -1) {
        printf("Integration undefined for exponent n = -1 (logarithmic case).\n");
        return;
    }

    integralAtX2 = a * pow(x2, n + 1) / (n + 1);
    integralAtX1 = a * pow(x1, n + 1) / (n + 1);
    result = integralAtX2 - integralAtX1;

    printf("The definite integral of %.2lfx^%.2lf from x = %.2lf to x = %.2lf is %.2lf\n", a, n, x1, x2, result);
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 5:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = sin(num1 * M_PI / 180.0);
                printf("Result: %.2lf\n", result);
                break;
            case 6:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = cos(num1 * M_PI / 180.0);
                printf("Result: %.2lf\n", result);
                break;
            case 7:
                printf("Enter an angle in degrees: ");
                scanf("%lf", &num1);
                result = tan(num1 * M_PI / 180.0);
                printf("Result: %.2lf\n", result);
                break;
            case 8:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = exp(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 9:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Error: Logarithm undefined for non-positive numbers.\n");
                } else {
                    result = log(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 10:
                printf("Enter the base (x) and exponent (y): ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 11:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Square root undefined for negative numbers.\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 12:
                differentiation();
                break;
            case 13:
                integration();
                break;
            case 14:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 14);

    return 0;
}


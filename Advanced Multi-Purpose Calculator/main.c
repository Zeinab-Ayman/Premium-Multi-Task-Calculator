#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void showMainMenu();

void arithmeticInterface();
void conversionInterface();
void scientificInterface();

void operation();
void multiOperation();
void secondOrder();

void decimalToBinary();
void decimalToOctal();
void decimalToHex();

void binaryToDecimal();
void octalToDecimal();
void hexToDecimal();

int main()
{
    int choice;

    do
    {
        showMainMenu();
        printf("\n    >> Enter Choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch (choice)
        {
        case 1:
            arithmeticInterface();
            break;
        case 2:
            conversionInterface();
            break;
        case 3:
            scientificInterface();
            break;
        case 0:
            printf("\n   Exiting...\n\n\tGoodbye! Hope to see you soon.\n");
            break;
        default:
            printf("\n   Invalid option! Try again.\n");
        }
    }
    while (choice != 0);

    return 0;
}


void showMainMenu()
{
    printf("\n");
    printf("\n\t\t\t=========================================");
    printf("\n\t\t\t         PREMIUM MULTI-TASK CALC         ");
    printf("\n\t\t\t=========================================");
    printf("\n\n   ---");
    printf("\n   [1] Standard Arithmetic");
    printf("\n   [2] Number Systems (Bin, Oct, Hex, Dec)");
    printf("\n   [3] Scientific & Engineering Math");
    printf("\n   [0] Exit");
    printf("\n   ---------------------------------------");
}

void arithmeticInterface()
{
    int choice;

    while(1)
    {
        printf("\n\n");
        printf("\n  --- STANDARD ARITHMETIC ---\n");
        printf("\n   [1] Simple operation (+, -, *, /)");
        printf("\n   [2] Multi-operation Expression");
        printf("\n   [3] Find roots of an Equation (Second Order)");
        printf("\n   [0] To return to Main Menu");
        printf("\n  -----------------------------------------------------------");
        printf("\n    >> Select Mode: ");
        scanf("%d",&choice);
        while(getchar() != '\n');

        if(choice==1) operation();

        else if (choice == 2) multiOperation();

        else if (choice==3) secondOrder();

        else
            return;

    }
}

void operation()
{
    double num1, num2, result;
    char op;
    printf("Enter operation in format (Number Operator Number) ");
    scanf("%lf %c %lf", &num1, &op, &num2);
    while(getchar() != '\n');

    switch(op)
    {
    case'+':
        result = num1+num2;
        break;
    case'-':
        result = num1-num2;
        break;
    case'*':
        result = num1*num2;
        break;
    case'/':
        if(num2!=0)
            result = num1/num2;
        else
        {
            printf("\n\tError: Division by zero!\n");
            return;
        }
        break;
    default:
    {
        printf("\n\tInvalid operator");
        return;
    }

    }
    printf("\n\tResult: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
}

void secondOrder()
{
    double A,B,C;
    printf("\n   Format: Ax^2+Bx+C Enter A B C \n    >> ");
    scanf("%lf %lf %lf", &A, &B, &C);
    while(getchar() != '\n');

    if(A==0)
        printf("\n\tx= %g",-C/B);
    else if(B==0)
    {
        if(C<0)
        {
            printf("\n\tx= ±%g",sqrt(C/A));
        }
        else if (C==0)
            printf("\n\tx=0");
        else
        {
            printf("\n\tx= ±%gj",sqrt(C/A));
        }

    }
    else if (C==0)
        printf("\n\tx= 0, %g",-B/A);
    else
    {
        double D, d= B*B - 4*A*C;
        if (d>=0)
        {
            D=sqrt(d);
            printf("\n\tx= %g, %g",(-B+D)/(2*A),(-B-D)/(2*A));
        }
        else
        {
            D=sqrt(-d);
            printf("\n\tx= %g ± %gj",(-B)/(2*A),D/(2*A));
        }
    }
}

void conversionInterface()
{
    int subChoice;
    while(1)
    {
        printf("\n\n");
        printf("\n  --- NUMBER SYSTEM CONVERTER ---\n");
        printf("\n   [1] Decimal to Binary");
        printf("\n   [2] Decimal to Octal");
        printf("\n   [3] Decimal to Hex");
        printf("\n   [4] Binary to Decimal");
        printf("\n   [5] Octal to Decimal");
        printf("\n   [6] Hexadecimal to Decimal");
        printf("\n   [0] Back to Main Menu");
        printf("\n  ---------------------------------------");
        printf("\n    >> Select Mode: ");
        scanf("%d", &subChoice);
        while(getchar() != '\n');

        switch(subChoice)
        {
        case 1:
            decimalToBinary();
            break;
        case 2:
            decimalToOctal();
            break;
        case 3:
            decimalToHex();
            break;
        case 4:
            binaryToDecimal();
            break;
        case 5:
            octalToDecimal();
            break;
        case 6:
            hexToDecimal();
            break;
        case 0:
            return;
        default:
            printf("\n\tInvalid choice, try again!\n");
        }
    }
}

void decimalToBinary()
{
    int decimalNum,i=1;
    long long binaryNum = 0;
    printf("\tDec >> ");
    scanf("%d",&decimalNum);
    while(getchar() != '\n');

    if (decimalNum == 0)
    {
        printf("\tBin >> 0\n");
        return;
    }
    while(decimalNum!=0)
    {
        int digit = decimalNum%2;
        binaryNum = binaryNum + digit*i;
        decimalNum /= 2;
        i*=10;
    }
    printf("\tBin >> %lld\n",binaryNum);
}

void decimalToOctal()
{
    int decimalNum,i=1;
    long long octalNum = 0;
    printf("\tDec >> ");
    scanf("%d",&decimalNum);
    while(getchar() != '\n');

    if (decimalNum == 0)
    {
        printf("\tOctal >> 0\n");
        return;
    }
    while(decimalNum!=0)
    {
        int digit = decimalNum%8;
        octalNum = octalNum + digit*i;
        decimalNum /= 8;
        i*=10;
    }
    printf("\tOctal >> %lld\n",octalNum);
}

/*void decimalToOctal() {
    int num;
    printf("\tDec >> ");
    scanf("%d", &num);
    printf("\tOctal >> %o\n", num);
}*/

void decimalToHex()
{
    int decimalNum,i=0;
    char hexNum[100];
    printf("\tDec >> ");
    scanf("%d",&decimalNum);
    while(getchar() != '\n');

    if (decimalNum == 0)
    {
        printf("\tHex >> 0\n");
        return;
    }

    for(i; decimalNum!=0; i++)
    {
        int digit = decimalNum % 16;
        if(digit<10)
            hexNum[i]=digit+'0';
        else
            hexNum[i]=digit +55;
        decimalNum /= 16;
    }
    printf("\tHex >> ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexNum[j]);
    }
    printf("\n");
}

/*void decimalToHex() {
    int num;
    printf("\tDec >> ");
    scanf("%d", &num);
    printf("\tHex >> %x\n", num);
}
*/

void binaryToDecimal()
{
    long long int binaryNum;
    int decimalNum=0;
    printf("\tBin >> ");
    scanf("%lld", &binaryNum);
    while(getchar() != '\n');

    if (binaryNum == 0)
    {
        printf("\tDec >> 0\n");
        return;
    }
    for(int i=0; binaryNum!=0; i++)
    {
        int digit = binaryNum % 10;
        if (digit > 1)
        {
            printf("\tError: Not a binary number!\n");
            return;
        }
        decimalNum += digit * pow(2,i);
        binaryNum /= 10;
    }
    printf("\tDec >> %d\n", decimalNum);
}

void octalToDecimal()
{
    long long int octNum;
    int decimalNum=0;
    printf("\tOct >> ");
    scanf("%lld", &octNum);
    while(getchar() != '\n');

    if (octNum == 0)
    {
        printf("\tDec >> 0\n");
        return;
    }
    for(int i=0; octNum!=0; i++)
    {
        int digit = octNum % 10;
        if (digit > 7)
        {
            printf("\tError: Invalid Octal digit (%d)! Only 0-7 allowed.\n", digit);
            return;
        }
        decimalNum += digit * pow(8,i);
        octNum /= 10;
    }
    printf("\tDec >> %d\n", decimalNum);
}

void hexToDecimal()
{
    char hexNum[100];
    int decimalNum=0;
    printf("\tHex >> ");
    scanf("%s", &hexNum);
    while(getchar() != '\n');

    if (hexNum == 0)
    {
        printf("\tDec >> 0\n");
        return;
    }
    int len = strlen(hexNum);
    int j=0;
    for(int i = len - 1; i >= 0; i--)
    {
        if (hexNum[i] >= '0' && hexNum[i] <= '9')
        {
            decimalNum += (hexNum[i]-'0') * pow(16,j);
        }
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F')
        {
            decimalNum += (hexNum[i] - 'A' + 10) * pow(16,j);
        }
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f')
        {
            decimalNum += (hexNum[i] - 'a' + 10) * pow(16,j);
        }
        else
        {
            printf("\tError: Invalid Hex character!\n");
            return;
        }
        j++;
    }
    printf("\tDec >> %d\n", decimalNum);
}

void scientificInterface()
{

    int op;
    double x, y, result;

    while(1)
    {
        printf("\n\n");
        printf("\n  --- SCIENTIFIC MATH MODULE ---\n");
        printf("\n   [1] Power (x^y)");
        printf("\n   [2] Square Root (sqrt)");
        printf("\n   [3] Factorial (n!)");
        printf("\n   [4] Trigonometry (Sin/Cos/Tan)");
        printf("\n   [5] Natural Log (Ln)");
        printf("\n   [6] Base-10 Log (Log10)");
        printf("\n   [7] Absolute Value (abs)");
        printf("\n   [0] Back to Main Menu");
        printf("\n  ---------------------------------------");
        printf("\n   >> Select Function: ");
        scanf("%d", &op);

        if (op == 0) return;

        switch(op)
        {
        case 1: // Power
            printf("\n  Enter base (x) and exponent (y): ");
            scanf("%lf %lf", &x, &y);
            while(getchar() != '\n');
            printf("\tResult: %g ^ %g = %g\n", x, y, pow(x, y));
            break;

        case 2: // Square Root
            printf("\n  Enter number: ");
            scanf("%lf", &x);
            while(getchar() != '\n');
            if (x >= 0)
                printf("\tResult: sqrt(%g) = %g\n", x, sqrt(x));
            else
                printf("\tError: Cannot take sqrt of negative number!\n");
            break;

        case 3: // Factorial
            printf("\n  Enter integer (n): ");
            int n;
            scanf("%d", &n);
            while(getchar() != '\n');
            if (n < 0)
                printf("\tError: No factorial for negatives!\n");
            else
            {
                long long fact = 1;
                for(int i = 1; i <= n; i++) fact *= i;
                printf("\tResult: %d! = %lld\n", n, fact);
            }
            break;

        case 4: // Trigonometry
            printf("\n  Enter angle in Degrees: ");
            scanf("%lf", &x);
            while(getchar() != '\n');
            double rad = x * (M_PI / 180.0);
            printf("\t>>Sin(%g) = %.4f\n", x, sin(rad));
            printf("\t>>Cos(%g) = %.4f\n", x, cos(rad));
            printf("\t>>Tan(%g) = %.4f\n", x, tan(rad));
            break;
        case 5: // Natural Log (Ln)
            printf("  Enter number: ");
            scanf("%lf", &x);
            while(getchar() != '\n');
            if(x > 0)
                printf("  Ln(%g) = %.4f\n", x, log(x));
            else
                printf("  Error: Log defined for positive numbers only!\n");
            break;

        case 6: // Base-10 Log (Log10)
            printf("  Enter number: ");
            scanf("%lf", &x);
            while(getchar() != '\n');
            if(x > 0)
                printf("  Log10(%g) = %.4f\n", x, log10(x));
            else
                printf("  Error: Log defined for positive numbers only!\n");
            break;

        case 7: // Absolute Value (abs)
            printf("  Enter number: ");
            scanf("%lf", &x);
            while(getchar() != '\n');
            printf("  |%g| = %g\n", x, fabs(x));
            break;
        default:
            printf("\tInvalid choice!\n");
        }
    }
}



void multiOperation()
{
    char str[256];
    double numbers[50];
    char ops[50];
    int numCount = 0, opCount = 0;

    printf("\n  Enter expression : ");
    if (fgets(str, sizeof(str), stdin) == NULL) return;

    char *ptr = str;
    while (*ptr != '\0' && *ptr != '\n')
    {
        while (*ptr == ' ') ptr++;

        if (*ptr >= '0' && *ptr <= '9')
        {
            char *end;
            numbers[numCount++] = strtod(ptr, &end);
            ptr = end;
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/')
        {
            ops[opCount++] = *ptr;
            ptr++;
        }
        else
        {
            ptr++;
        }
    }

    if (numCount == 0) return;

    for (int i = 0; i < opCount; )
    {
        if (ops[i] == '*' || ops[i] == '/')
        {
            if (ops[i] == '*')
                numbers[i] = numbers[i] * numbers[i + 1];
            else
            {
                if (numbers[i + 1] == 0)
                {
                    printf("\n\tError: Division by zero!\n");
                    return;
                }
                numbers[i] = numbers[i] / numbers[i + 1];
            }

            for (int j = i + 1; j < numCount - 1; j++)
                numbers[j] = numbers[j + 1];
            numCount--;

            for (int j = i; j < opCount - 1; j++)
                ops[j] = ops[j + 1];
            opCount--;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < opCount; )
    {
        if (ops[i] == '+')
            numbers[i] = numbers[i] + numbers[i + 1];
        else if (ops[i] == '-')
            numbers[i] = numbers[i] - numbers[i + 1];

        for (int j = i + 1; j < numCount - 1; j++)
            numbers[j] = numbers[j + 1];
        numCount--;

        for (int j = i; j < opCount - 1; j++)
            ops[j] = ops[j + 1];
        opCount--;
    }

    printf("\n\tResult = %g\n", numbers[0]);
}




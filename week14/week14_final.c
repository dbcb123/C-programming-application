#include <stdio.h>
#include <string.h>
#include <math.h>
#define WORD 16
void getBinary(char bin[], char str[], int n) {
    int count = 0;
    for (count = 0; count < n; count++) {
        if (str[count] != '1' && str[count] != '0') {
            break;
        }
    }

    for (int i = 0, strIndex = 0; i < n; i++) {
        if (i < 16 - count) {
            bin[i] = '0';
        }
        else {
            bin[i] = str[strIndex];
            strIndex++;
        }
    }
}
void complement2(char bin[], int n) {
    int check = 0;
    for (int i = n - 1; i > 0; i--) {
        if (bin[i] == '0') {
            bin[i] = '1';
        } else if (bin[i] == '1') {
            bin[i] = '0';
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (bin[i] == '1' && i == n-1) {
            check = 1;
        }

        if (check == 1 && bin[i] == '1') {
            bin[i] = '0';
        }
        else {
            bin[i] = '1';
            check = 0;
            break;
        }
    }

}
int bin2dec(char bin[], int n) {
    int check = 1;
    if (bin[0] == '1') {
        bin[0] = '0';
        complement2(bin, n);
        check = -1;
    }

    int dec = 0;

    for (int i = 1; i < n; i++) {
        if (bin[i] == '1') {
            dec += (int)(pow(2, n - 1 - i));
        }
    }

    return dec * check;
}
int main() {

    char input1[100];
    char input2[100];
    char op[10];

    char binary1[WORD + 1] = { 0 };
    char binary2[WORD + 1] = { 0 };

    int result;
    int num1, num2;

    printf("<<<<input>>>>>\n");
    gets(input1);
    gets(op);
    gets(input2);
    getBinary(binary1, input1, WORD);
    getBinary(binary2, input2, WORD);

    num1 = bin2dec(binary1, WORD);
    num2 = bin2dec(binary2, WORD);

    switch(op[0]) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        case '%': result = num1 % num2; break;
        default: printf("bad operator...\n"); break;
    }

    printf("%s(%d) %c %s(%d) = %d\n", binary1, num1, op[0], binary2, num2, result);

    return 0;
}
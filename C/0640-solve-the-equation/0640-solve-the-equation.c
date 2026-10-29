
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* solveEquation(char* equation) {
    int xCoeff = 0;
    int constant = 0;
    int sign = 1;
    int i = 0;
    int n = strlen(equation);

    while (i < n) {
        if (equation[i] == '=') {
            sign = -1;
            i++;
            continue;
        }

        int termSign = sign;

        if (equation[i] == '+') {
            i++;
        } else if (equation[i] == '-') {
            termSign = -sign;
            i++;
        }

        int num = 0;
        int hasNum = 0;

        while (i < n && equation[i] >= '0' && equation[i] <= '9') {
            num = num * 10 + equation[i] - '0';
            hasNum = 1;
            i++;
        }

        if (i < n && equation[i] == 'x') {
            xCoeff += termSign * (hasNum ? num : 1);
            i++;
        } else {
            constant += termSign * num;
        }
    }

    char* result = (char*)malloc(50 * sizeof(char));

    if (xCoeff == 0) {
        if (constant == 0) {
            strcpy(result, "Infinite solutions");
        } else {
            strcpy(result, "No solution");
        }
    } else {
        int answer = -constant / xCoeff;
        sprintf(result, "x=%d", answer);
    }

    return result;
}


// int romanToInt(char* s) {
//     int integer = 0;
    
//     while (*s) {
//         if (*s == 'M'){
//             integer += 1000;
//         }
//         else if (*s == 'D') {
//             integer += 500;
//         }
//         else if (*s == 'C') {
//             if (*(s + 1) == 'M') {
//                 integer += 900;
//                 s++;     
//             }
//             else if (*(s + 1) == 'D') {
//                 integer += 400;
//                 s++;
//             }
//             else
//                 integer += 100;
//         }
//         else if (*s == 'L') {
//             integer += 50;
//         }
//         else if (*s == 'X') {
//             if (*(s + 1) == 'L') {
//                 integer += 40;
//                 s++;     
//             }
//             else if (*(s + 1) == 'C') {
//                 integer += 90;
//                 s++;
//             }
//             else
//                 integer += 10;
//         }
//         else if (*s == 'V') {
//             integer += 5;
//         }
//         else {
//             if (*(s + 1) == 'V') {
//                 integer += 4;
//                 s++;     
//             }
//             else if (*(s + 1) == 'X') {
//                 integer += 9;
//                 s++;
//             }
//             else
//                 integer++;
//         }
//         s++;
//     }

//     return (integer);
// }

// Symbol       Value      Substitue
// I             1         1
// V             5         2
// X             10        3
// L             50        4
// C             100       5
// D             500       6
// M             1000      7

#include <stdio.h>

int romanToInt(char* s) {

// substitute the value to have an order in the string
    short int i = 0;
    while (s[i]) {
        if (s[i] == 'C')
            s[i] = 100;
        else if (s[i] == 'L')
            s[i] = 50;
        else if (s[i] == 'X')
            s[i] = 10;
        else if (s[i] == 'V')
            s[i] = 5;
        else if (s[i] == 'I')
            s[i] = 1;
        i++;
    }

    i = 0;
    while (*s) {
        if (*s == 'M')
            i += 1000;
        else if (*s == 'D')
            i += 500;
        else if (*s == 100) {
            if (*(s + 1) == 'M') {
                i += 900;
                s++;
            }
            else if (*(s + 1) == 'D') {
                i += 400;
                s++;
            }
            else
                i += 100;
        }
        else if (*s < *(s + 1)) {
            i += *(s + 1) - *(s);
            s++;
        }
        else
            i += *s;
        s++;
    }
    return (i);
}


























// int numJewelsInStones3(char* jewels, char* stones) {
//     int abc = 0, ABC = 0;

//     while (*jewels) {
//         if (*jewels >= 'a')
//             abc |= 1 << (*jewels - 'a');
//         else
//             ABC |= 1 << (*jewels - 'A');
//         jewels++;
//     }
//     int nb = 0;
//     while (*stones) {
//         if (*stones >= 'a' && (abc & (1 << (*stones - 'a'))))
//             nb++;
//         else if (*stones <= 'Z' && (ABC & (1 << (*stones - 'A'))))
//             nb++;
//         stones++;
//     }
//     return (nb);
// }

#define PAD 26

int numJewelsInStones(char* jewels, char* stones) {
    char flags[7] = "";

    while (*jewels) {
        if (*jewels >= 'a')
            flags[(*jewels - 'a') >> 3] |= 1 << (*jewels - 'a') % 8;
        else
            flags[((*jewels - 'A' + PAD) >> 3)] |= 1 << (*jewels - 'A' + PAD) % 8;
        jewels++;
    }
    unsigned char nb = 0;
    while (*stones) {
        if (*stones >= 'a' && (flags[(*stones - 'a') >> 3] >> ((*stones - 'a') % 8) & 1))
            nb++;
        else if (*stones <= 'Z' && (flags[(*stones - 'A' + PAD) >> 3] >> ((*stones - 'A' + PAD) % 8) & 1))
            nb++;
        stones++;
    }
    return (nb);
}
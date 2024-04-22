#include <stdio.h>

int main(void) {
	short	code;
	scanf("%hd", &code);
	printf("%d\n", (((((code % 100) / 10) - 1) % 10)) * 10);
	short	temp = (code - ((code % 100) / 10) * 10) + (((((code % 100) / 10) - 1) % 10)) * 10;
	printf("%d\n", temp);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int number = atoi(argv[1]);
	int base = atoi(argv[2]);
	char number_of_base_str[1000] = {0};
	char number_of_base_str_rev[1000] = {0};
	int i, j;
	printf("%d (base 10) = ", number);

	if (number < base) {
		if (number >= 10) {
			number += 55;
			printf("%c (base %d)\n", (char)number, base);
		} else
			printf("%d (base %d)\n", number, base);
		return 0;
	}

	for (i = 0; number >= base; i++) {
		int div = number / base;
		int rem = number - (div * base);
		if (rem >= 10)
			rem += 55;
		else
			rem += 48;
		number_of_base_str[i] = (char)rem;
		number = div;
	}
	if (number >= 10)
		number += 55;
	else
		number += 48;
	number_of_base_str[i] = (char)number;
	for (i = 0; number_of_base_str[i]; i++);
	--i;
	for (j = 0; i >= 0; i--, j++)
		number_of_base_str_rev[j] = number_of_base_str[i];
	--j;
	printf("%s (base %d)\n", number_of_base_str_rev, base);
	printf("%s (base %d) = ", number_of_base_str_rev, base);
	for (i = 0;; i++) {
		int cifra;
		if (number_of_base_str_rev[i] >= 65) {
			cifra = number_of_base_str_rev[i] - 55;
			printf("%d * %d^%d", (char)cifra, base, j);
		} else {
			cifra = number_of_base_str_rev[i] - 48;
			printf("%d * %d^%d", (char)cifra, base, j);
		}
		if (number_of_base_str_rev[i + 1])
			printf(" + ");
		else
			break;
		--j;
	}
	printf(" (base 10)\n");
	return 0;
}

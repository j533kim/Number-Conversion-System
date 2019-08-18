#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Version 3.0 no more has to be in base 2, 10, 16.
// The base of the number can be any.

int my_power(int base, int exponent) {
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return base;
	} else {
		return base * my_power(base, exponent - 1);
	}
}

int main(void) {
	while (1) {
		printf("Type the base of the input number: ");
		int initial_base = 0;
		while (initial_base <= 1) {
			scanf("%d", &initial_base);
			if ((initial_base <= 1) || (initial_base > 36)) {
				printf("Make sure the base is bigger or equal to 2 and smaller than 37\n");
			}
		}

		printf("Type the base of the output number: ");
		int final_base = 0;
		while (final_base <= 1) {
			scanf("%d", &final_base);
			if ((final_base <= 1) || (final_base > 36)) {
				printf("Make sure the base is bigger or equal to 2 and smaller than 37\n");
				printf("Type the base of the output number:\n");
			}
		}

		printf("Type your number: ");
		char num[100];
		int len = 0;
		int this_one = 0;

		while (1) {
			scanf(" %s", num);
			len = strlen(num);
			int pass = 0;
			for (int i = 0; i < len; ++i) {
				if ((num[i] >= '0') && (num[i] <= '9') && (num[i] - '0' >= initial_base)) {
					printf("The input is not in your base system\n");
					printf("Type again: ");
					pass = 0;
					break;
				} else if ((num[i] >= 'a') && (num[i] <= 'z') && (num[i] - 'a' + 10 >= initial_base)) {
					printf("The input is not in your base system\n");
					printf("Type again: ");
					pass = 0;
					break;
				} else if ((num[i] >= 'A') && (num[i] <= 'Z') && (num[i] - 'A' + 10 >= initial_base)) {
					printf("The input is not in your base system\n");
					printf("Type again: ");
					pass = 0;
					break;
				} else if (!(((num[i] >= '0') && (num[i] <= '9')) ||
				((num[i] >= 'a') && (num[i] <= 'z')) || ((num[i] >= 'A') && (num[i] <= 'Z')))) {
					printf("The input is not in your base system\n");
					printf("Type again: ");
					pass = 0;
					break;
				}
				pass = 1;
			}
			if (pass == 1) break;
		}

			for (int i = 0; i < len; ++i) {
				if ((num[i] >= '0') && (num[i] <= '9')) {
					this_one += my_power(initial_base, len - i - 1) * (num[i] - '0');
				} else if ((num[i] >= 'a') && (num[i] <= 'z')) {
					this_one += my_power(initial_base, len - i - 1) * (num[i] - 'a' + 10);
				} else {
					this_one += my_power(initial_base, len - i - 1) * (num[i] - 'A' + 10);
				}
			}

		///////////////////////////////////////////////////////////////
		int copy = this_one;

		int first_power = 0;
		while (copy >= final_base) {
			copy /= final_base;
			++first_power;
		}
		int newlen = first_power + 1;
		int new_num[newlen];

		for (int i = first_power, index = 0; index < newlen; ++index, --i) {
			for (int j = 0; j * my_power(final_base, i) <= this_one; ++j) {
				new_num[index] = j;
			}
			this_one -= (new_num[index] * my_power(final_base, i));
		}

		printf("Your number in %d base system is: ", final_base);
	for (int i = 0; i < newlen; ++i) {
			if (new_num[i] >= 10) {
				printf("%c", 'A' + new_num[i] - 10);
			} else {
				printf("%d", new_num[i]);
			}
		}
		printf("\n");
///////////////////////////////////////////////////////
		printf("Again?\n");
		printf("y/Y: Yes   |   Any key: No\n");

		char a;
		scanf(" %c", &a);

		if (a != 'y' && a != 'Y') {
			printf("Bye\n");
			return 0;
		}
		///////////////////////////////////////////////
	}
}

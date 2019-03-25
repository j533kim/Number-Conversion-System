#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

int my_power(int base, int exponent) {
	assert(exponent >= 0);
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return base;
	} else {
		return base * my_power(base, exponent - 1);
	}
}

int binary_to_deci2(char num[]) {
	const int len = strlen(num);
	int this_one = 0;
	int index = 1;
	while(index <= len) {
		this_one += my_power(2, len - index) * (num[index - 1] - '0');
		++index;
	}
	return this_one;
}

void deci_to_hexa(char num[]) {
	int this_one = 0;
	for (int i = 0; num[i] != '\0'; ++i) {
		this_one *= 10;
		this_one += num[i] - '0';
	}

	int copy = this_one;
	int first_power = 0;
	while (copy >= 16) {
		copy /= 16;
		++first_power;
	}
	const int len_hex = first_power + 1;
	int list[len_hex];

		for (int i = 0; i < len_hex; ++i) {
			list[i] = 0;
		}


		for (int i = first_power, index = 0; index < len_hex; ++index, --i) {
			for (int j = 0; j * my_power(16, i) <= this_one; ++j) {
				list[index] = j;
			}
			this_one = this_one - (list[index] * my_power(16, i));
			if (this_one== 0) {
				break;
			}
		}

	for (int i = 0; i < len_hex; ++i) {
			if (list[i] >= 10) {
				printf("%c", 'A' + list[i] - 10);
			} else {
				printf("%d", list[i]);
			}
		}
		printf("\n");
}


void binary_to_hexa(char num[]) {
	int len = strlen(num);
	char this_one[50];
	int actual[15];

	for (int i = 0; i < len; ++i) {
		this_one[i] = num[i];
	}
	this_one[len] = '\0';

	if (len % 4 != 0) {
		const int additional = 4 - (len % 4);
		for (int i = len; i >= 0; --i) {
			this_one[i + additional] = num[i];
		}
		for (int i = 0; i < additional; ++i) {
			this_one[i] = '0';
		}
		len += additional;
	}
	int index = 0;

	for (int i = 0; i < len; i += 4) {
		char cha[5];
		for (int j = 0; j < 4; ++j) {
			cha[j] = this_one[i + j];
		}
		cha[4] = '\0';
		actual[index] = binary_to_deci2(cha);
		++index;
	}

	len = len / 4;

	for (int i = 0; i < len; ++i) {
		if (actual[i] <= 9) {
			printf("%d", actual[i]);
		} else {
			printf("%c", actual[i] + 'A' - 10);
		}
	}
	printf("\n");
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int my_power2(int base, int exponent) {
	assert(exponent >= 0);
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return base;
	} else {
		return base * my_power2(base, exponent - 1);
	}
}

int hexa_to_deci(char num[]) {
	const int len = strlen(num);
	int this_one = 0;
	int index = 1;
	while (index <= len) {
		if (num[index - 1] < '9') {
			this_one += my_power2(16, len - index) * (num[index - 1] - '0');
		} else {
			this_one += my_power2(16, len - index) * (num[index - 1] - 'A' + 10);
		}
		++index;
	}
	return this_one;
}

int binary_to_deci(char num[]) {
	const int len = strlen(num);
	int this_one = 0;
	int index = 1;
	while(index <= len) {
		this_one += my_power2(2, len - index) * (num[index - 1] - '0');
		++index;
	}
	return this_one;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int my_power3(int base, int exponent) {
	assert(exponent >= 0);
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return base;
	} else {
		return base * my_power3(base, exponent - 1);
	}
}

void deci_to_binary(char num[]) {
	int this_one = 0;
	for (int i = 0; num[i] != '\0'; ++i) {
		this_one *= 10;
		this_one += num[i] - '0';
	}

	int q,r = 100;
	int list[100];
	int len = 0;

	q = this_one;
	if (this_one == 0) {
		printf("0\n");
		return;
	}
	while (q != 0) {
		r = q % 2;
		q = q / 2;
		list[len] = r;
		++len;
	}

	for (int i = len - 1; i >= 0; --i) {
		printf("%d", list[i]);
	}
	printf("\n");
}

void hexa_to_binary(char num[]) {
	int len = strlen(num);
	int n[len * 4];

	for (int i = 0, j = 0; i < len * 4; i += 4, ++j) {
		if (num[j] == '0') {
			n[i] = n[i+1] = n[i+2] = n[i+3] = 0;
		} else if (num[j] == '1') {
			n[i] = n[i+1] = n[i+2] = 0;
			n[i+3] = 1;
		} else if (num[j] == '2') {
			n[i] = n[i+1] = n[i+3] = 0;
			n[i+2] = 1;
		} else if (num[j] == '3') {
			n[i] = n[i+1] = 0;
			n[i+3] = n[i+2] = 1;
		} else if (num[j] == '4') {
			n[i] = n[i+3] = n[i+2] = 0;
			n[i+1] = 1;
		} else if (num[j] == '5') {
			n[i] = n[i+2] = 0;
			n[i+3] = n[i+1] = 1;
		} else if (num[j] == '6') {
			n[i] = n[i+3] = 0;
			n[i+1] = n[i+2] = 1;
		} else if (num[j] == '7') {
			n[i+2] = n[i+1] = n[i+3] = 1;
			n[i] = 0;
		} else if (num[j] == '8') {
			n[i+2] = n[i+1] = n[i+3] = 0;
			n[i] = 1;
		} else if (num[j] == '9') {
			n[i] = n[i+3] = 1;
			n[i+1] = n[i+2] = 0;
		} else if ((num[j] == 'A') || (num[j] == 'a')) {
			n[i] = n[i+2] = 1;
			n[i+1] = n[i+3] = 0;
		} else if ((num[j] == 'B') || (num[j] == 'b')) {
			n[i+2] = n[i] = n[i+3] = 1;
			n[i+1] = 0;
		} else if ((num[j] == 'c') || (num[j] == 'C')) {
			n[i] = n[i+1] = 1;
			n[i+2] = n[i+3] = 0;
		} else if ((num[j] == 'D') || (num[j] == 'd')) {
			n[i+1] = n[i] = n[i+3] = 1;
			n[i+2] = 0;
		} else if ((num[j] == 'E') || (num[j] == 'e')) {
			n[i+1] = n[i] = n[i+2] = 1;
			n[i+3] = 0;
		} else {
			n[i] = n[i+1] = n[i+2] = n[i+3] = 1;
		}
	}
	for (int i = 0; i < len * 4; ++i) {
		printf("%d", n[i]);
	}
	printf("\n");
}





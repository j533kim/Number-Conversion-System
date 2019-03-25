#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main_to_hexa.c"
#include "main_to_deci.c"
#include "main_to_binary.c"
#include <string.h>

int main(void) {
	while (1) {
		printf("Type the initial of the mode you want\n");
		printf("d/D: decimal to something\n");
		printf("b/B: binary to something\n");
		printf("h/H: hexadecimal to something\n");

		int deci = 0;
		int binary = 0;
		int hexa = 0;
		int to_deci = 0;
		int to_binary = 0;
		int to_hexa = 0;

		while (1) {
			char c;
			scanf(" %c", &c);
			if (c == 'd' || c == 'D') {
				++deci;
				break;
			} else if (c == 'b' || c == 'B') {
				++binary;
				break;
			} else if (c == 'h' || c == 'H') {
				++hexa;
				break;
			} else {
				printf("Type again\n");
				/*read =*/ 
				scanf(" %c", &c);
			}
		}

		printf("convert to?\n");
		printf("d/D: to decimal\n");
		printf("b/B: to binary\n");
		printf("h/H: to hexadecimal\n");

		while (1) {
			char c;
			scanf(" %c", &c);

			if (c == 'd' || c == 'D') {
				++to_deci;
				break;
			} else if (c == 'b' || c == 'B') {
				++to_binary;
				break;
			} else if (c == 'h' || c == 'H') {
				++to_hexa;
				break;
			} else {
				printf("Type again\n");
				scanf("%c", &c);
			}
		}



		if ((deci && to_deci) || (binary && to_binary) || (hexa && to_hexa)) {
			printf("Just same...\n");
		} else {
			char num[100];

			while (1) {
				int pass = 0;
				printf("Type the number:\n");
				scanf(" %s", num);
				const int len = strlen(num);
				for (int i = 0; i < len; ++i) {
					if (binary && !(num[i] == '0' || num[i] == '1')) {
						printf("Please only type 1 or 0\n");
						printf("Gotta be binary number\n");
						pass = 0;
						break;
					} else if (deci && ((num[i] > '9') || (num[i] < '0'))) {
						printf("Please only type numbers\n");
						printf("Gotta be decimal number\n");
						pass = 0;
						break;
					} else if (hexa && !(((num[i] <= 'F') && (num[i] >= 'A')) || ((num[i] >= '0') && (num[i] <= '9'))
						|| ((num[i] <= 'f') && (num[i] >= 'a')))) {
						printf("Please only type numbers or letters from 'A' to 'F'\n");
						printf("Gotta be hexadecimal number\n");
						pass = 0;
						break;
					}
					pass = 1;
				}
				if (pass == 1) break;
			}

			if (deci && to_binary) {
				deci_to_binary(num);
			} else if (deci && to_hexa) {
				deci_to_hexa(num);
			} else if (binary && to_deci) {
				printf("%d\n", binary_to_deci(num));
			} else if (binary && to_hexa) {
				binary_to_hexa(num);
			} else if (hexa && to_binary) {
				hexa_to_binary(num);
			} else {
				printf("%d\n", hexa_to_deci(num));
			}
		}

		printf("Again?\n");
		printf("y/Y: Yes   |   Any key: No\n");

		char a;
		scanf(" %c", &a);

		if (a != 'y' && a != 'Y') {
			printf("Bye\n");
			return 0;
		}
	}
}

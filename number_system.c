#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * Converts a decimal number to binary by repeatedly dividing
 * the number by 2 and pushing the remainders into a stack.
 */
void decimal_to_binary_by_division(int decimal)
{
	int binary[32] = {0,};
	int top = -1;

	printf("%d = ", decimal);

	while (decimal > 0)
		// push into the stack
		binary[++top] = decimal % 2, decimal /= 2;

	while (top > -1)
		// pop from the stack
		printf("%d", binary[top--]);
	printf("\n");
}

/*
 * Converts a decimal number to its binary (base-2) representation
 * using the bitwise right shift operator.
 */
void decimal_to_binary_by_shift(int decimal)
{
	int binary[32] = {0,};
	int top = -1;

	printf("%d = ", decimal);

	while (decimal > 0) {
		binary[++top] = decimal & 1;
		decimal >>= 1;
	}

	while (top > -1)
		printf("%d", binary[top--]);
	printf("\n");
}

void binary_to_decimal(char *binary)
{
	int decimal = 0;
	int len = strlen(binary);
	int i;

	for (i = 0 ; i < len ; i++)
		decimal = decimal * 2 + (binary[i] - '0');

	printf("%s = %d\n", binary, decimal);
}

void octal_to_decimal(char *octal)
{
	int decimal = 0;
	int len = strlen(octal);

	for (int i = 0 ; i < len ; i++)
		decimal = decimal * 8 + (octal[i] - '0');

	printf("%s = %d\n", octal, decimal);
}

void binary_to_hexadecimal(char *binary)
{
	int decimal = 0;
	int len = strlen(binary);

	for (int i = 0 ; i < len ; i++)
		decimal = decimal * 2 + (binary[i] - '0');

	printf("%s = %#x\n", binary, decimal);
}

// TODO: convert from any base to decimal and vice versa
int any_base_to_decimal(char *num, int base);
char* decimal_to_any_base(int decimal, int base);

#define MAX_N	1000
void prime_numbers_with_saved_array(int max_n)
{
	int n, i;
	int prime[MAX_N] = {0,};
	int idx = 0;

	printf("%s: <= %d\n", __func__, max_n);

	if (max_n <= 1)
		return;

	prime[0] = 2;
	idx = 1;
	printf("%d ", prime[0]);

	for (n = 3 ; n <= max_n ; n += 2) {
		for (i = 0 ; i < idx ; i++)
			if (n % prime[i] == 0)
				break;

		if (i == idx) {
			prime[idx++] = n;
			printf("%d ", n);
		}
	}

	printf("\n");
}

void prime_numbers_without_array(int max_n)
{
	int n, i;

	printf("%s: <= %d\n", __func__, max_n);

	if (max_n <= 1)
		return;

	printf("2 ");
	for (n = 3 ; n <= max_n ; n += 2) {
		for (i = 3 ; i*i < n ; i += 2)
			if (n % i == 0)
				break;

		if (i*i > n)
			printf("%d ", n);
	}

	printf("\n");
}

void prime_numbers_using_Sieve_of_Eratosthenes(int max_n)
{
	bool is_prime[MAX_N + 1] = {0,};
	int n, i;

	printf("%s: <= %d\n", __func__, max_n);

	memset(is_prime, true, sizeof(is_prime));

	for (n = 2 ; n*n <= max_n ; n++)
		if (is_prime[n])
			// for (i = n*n ; i <= max_n ; i += n)
			// 	is_prime[i] = false;
			for (i = n ; i <= max_n/n ; i++)	// alternative
				is_prime[n*i] = false;

	for (n = 2 ; n <= max_n ; n++)
		if (is_prime[n])
			printf("%d ", n);
}

int gcd_brute_force(int a, int b)
{
	int min = a < b ? a : b;
	int gcd = min;

	printf("%s(%d, %d)", __func__, a, b);

	while (gcd > 0) {
		if (a % gcd == 0 && b % gcd == 0)
			break;
		gcd--;
	}

	printf(" = %d\n", gcd);
	return gcd;
}

int gcd_Euclidean_recur(int a, int b)
{
	printf("%s(%d, %d)\n", __func__, a, b);

	if (b == 0)		// b is smaller than a
		return a;

	return gcd_Euclidean_recur(b, a % b);
}

int gcd_Euclidean_iter(int a, int b)
{
	int r;

	while (b != 0) {	// b is smaller than a
		printf("%s(%d, %d)\n", __func__, a, b);

		r = a % b;
		a = b;
		b = r;
	}

	printf("= %d\n", a);
	return a;
}

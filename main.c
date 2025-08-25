#include <stdio.h>

void decimal_to_binary_by_division(int decimal);
void decimal_to_binary_by_shift(int decimal);
void binary_to_decimal(char *binary);
void octal_to_decimal(char *octal);
void binary_to_hexadecimal(char *binary);

int main(void)
{
	/* Number system conversion */
	// decimal_to_binary_by_division(30);
	decimal_to_binary_by_shift(34);
	// binary_to_decimal("1010");
	// octal_to_decimal("42");
	// binary_to_hexadecimal("1010111010000011");
	
	return 0;
}
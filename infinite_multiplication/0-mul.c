#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Main
 * @argc: N of arguments
 * @argv: array of passed args
 *
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	char *num1, *num2;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!str_checker(num1) || !str_checker(num2))
	{
		printf("Error\n");
		return (98);
	}

	mult_str(num1, num2);

	return (0);
}

/**
 * str_checker - Check if a string only contains digits
 * @str: The string to check
 *
 * Return: 1 if the string only contains digits, if not 0
 */
int str_checker(char *str)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

/**
 * len_str - Get string length
 * @str: str
 *
 * Return: Length
 */
int len_str(char *str)
{
	int length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * mult_str - * 2 n
 * @num1: Arg
 * @num2: Arg
 */
void mult_str(char *num1, char *num2)
{
	int len1 = len_str(num1);
	int len2 = len_str(num2);
	int len_result = len1 + len2;
	int *result;
	int i, j, carry, digit, prod;

	result = malloc(sizeof(int) * len_result);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < len_result; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			digit = prod % 10;
			carry = prod / 10;
			result[i + j + 1] = digit;
		}
		result[i] += carry;
	}

	if (result[0] == 0)
		i = 1;
	else
		i = 0;

	for (; i < len_result; i++)
		_putchar(result[i] + '0');

	_putchar('\n');

	free(result);
}

#include "_string.h"

/**
 * _strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * itoa - converts integer to string
 *
 * @num: integer to be converted to string
 * @str: buffer to hold the string
 * @base: base to be converted to
 * Return: returns the integer to be converted
 */
char *itoa(int num, char *str, int base)
{
	int i = 0, isNegative = 0;

	/* Explicitly handle 0 */
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	/* Handling negative numbers in base 10 as other bases are unsigned */
	if (num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}

	/* Loop through the digits */
	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	/* Append '-' if negative */
	if (isNegative)
		str[i++] = '-';

	str[i] = '\0'; /* Add Null terminator */

	/* Reverse the string */
	rev_string(str, i);

	return (str);
}

/**
 * rev_string - reverses a string
 *
 * @s: string to be reversed
 * @len: string length
 */

void rev_string(char *s, int len)
{
	int max, half;
	char first, last;

	max = len - 1;
	half = max / 2;
	while (half >= 0)
	{
		first = s[max - half];
		last = s[half];
		s[half] = first;
		s[max - half] = last;
		half--;
	}
}

/**
 * _isdigit - checks if a char is a digit
 *
 * @str: string to check
 * Return: returns 1 if digit and 0 if not a digit
 */

int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

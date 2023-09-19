#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Helper function to print a character
 *
 * @c: Character to print
 * @char_count: Pointer to the character count
 */
void print_char(char c, int *char_count)
{
	putchar(c);
	(*char_count)++;
}

/**
 * print_str - Helper function to print a string
 *
 * @str: String to print
 * @char_count: Pointer to the character count
 */
void print_str(const char *str, int *char_count)
{
	int j = 0;

	while (str[j] != '\0')
	{
		putchar(str[j]);
		(*char_count)++;
		j++;
	}
}

/**
 * _printf - Custom printf function that handles c, s, and %
 *
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int character_count = 0;
	int x = 0;

	while (format[x] != '\0')
	{
		if (format[x] != '%')
		{
			print_char(format[x], &character_count);
		}
		else
		{
			x++;
			if (format[x] == 'c')
			{
				char c = va_arg(args, int);

				print_char(c, &character_count);
			}
			else if (format[x] == 's')
			{
				char *str = va_arg(args, char *);

				print_str(str, &character_count);
			}
			else if (format[x] == '%')
			{
				print_char('%', &character_count);
			}
			else
			{
				print_char('%', &character_count);
				print_char(format[x], &character_count);
			}
		} x++;
	}
	va_end(args);
	return (character_count);
}
/**
 * main - Test for _printf function
 *
 * Return: 0 Success
 */
int main(void)
{
	int text;

	text = _printf("Hello, %c World! %s %%\n", 'C', "Printf team project");
	printf("Character count: %d\n", text);

	return (0);
}

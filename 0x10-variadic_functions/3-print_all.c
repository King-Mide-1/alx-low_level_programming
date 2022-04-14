#include "variadic_functions.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * print_int - prints int
 * @list: arguments from print_all
 */
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}
/**
 * print_float - prints float
 * @list: arguments from print_all
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}
/**
 * print_char - prints int
 * @list: arguments from print_all
 */
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}
/**
 * print_str - prints string
 * @list: arguments from print_all
 */
void print_str(va_list list)
{
	char *s = va_arg(list, char *);

	s == NULL ? printf("(nil)") : printf("%s", s)
}
/**
 * print_all - prints any type
 * @format: arguments to print
 */
void print_all(const char * const format, ...)
{
	in_format arr_st_fm[] = {
		{"c", print_ch},
		{"i", print_int},
		{"s", print_st},
		{"f", print_flt},
		{NULL, NULL}
	};
	int a, b;
	va_list ls_args;
	char *empty = "";
	char *separator = ", ";

	va_start(ls_args, format);
	a = 0;
	while (format != NULL)
	{
		b = 0;
		while (arr_st_fm[b].n != NULL)
		{
			if (format[a] == arr_st_fm[b].n[0])
			{
				printf("%s", empty);
				arr_st_fm[b].func(ls_args);
				empty = separator;
			}
			b++;
		}
		a++;
	}
	va_end(ls_args);
	printf("\n");
}

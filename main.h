#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: the format
 * @fn: function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt - struct op
 * @fmt: the format
 * @fm_t: function asscociated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_printf(const char *fmt, int *i, va_list list, char buffer[],
	int flags, int width, int precision, int size);

/*************FUNCTONS*****************/

/* Functions to print characters and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* function to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function to print string reverse */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print string in rot 13 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[],
int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int lenth,
int width, int flags, char padd,
	char extra_c, int padd_strt);
int write_unsgned(int is_negative, int ind,
	char buffer[],
int flags, int width, int precision, int size);

/*********UTILS*********/

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsngd(unsigned long int num, int size);

#endif /* MAIN_H */

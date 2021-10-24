#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <string>;
#include <cstring>;

//Функция strcpy.
//Формат char* strcpy(char* dest, const char* src).
//Функция копирует строку src в строку dest.


char* my_strcpy(char* dst, const char* src) 
{
	char* d = dst;
	while (*d++ = *src++);

	return dst;
}

int main()

{
	char dest[] = "It's my life ";
	const char  src[] = "Now or never";
	char* standard_result = strcpy(dest, src);
	char* my_result = my_strcpy(dest, src );

	printf("Standard: %s\nMy version: %s\n", standard_result, my_result);

	return 0;

}
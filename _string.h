#ifndef __STRING_H
#define __STRING_H

#include <unistd.h>
#include <stdlib.h>

char *_strdup(const char *s);
size_t _strlen(const char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *itoa(int num, char *str, int base);
void rev_string(char *s, int len);
int _isdigit(char *str);

#endif

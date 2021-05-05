#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Vector.h"

#define DEFAULT_STRING_CAPACITY 16;

typedef struct String{
    size_t capacity;
    size_t size;
    char *data;
}String;

static void double_capacity(String *s);
static void reduce_capacity(String *s);

String *newString();
String *newStringFromLitteral(char *stringLitteral);
void freeString(String *s);

int String_len(String *s);
char String_pop(String *s);
String_append(String *s, char c);

static int containsAtIndex(String *s, int index, String *separator);
Vector *String_split(String *s, String *separator); // return Vector containing strings
String *String_slice(String *sSource, size_t begin, size_t end); // create new String

static void String_insertSpace(String *s, size_t index, size_t nb);
void String_insert(String *sSource, size_t index, String *sDest);
void String_replace(String *s, size_t index, char source); // replace char at index 'index' by source
void String_substitute(String *s, char target, char substitute); // replace all occurence of target by substitute

int String_equal(String *s, String *s2);
int String_contains(String *s, String *s2);
int String_isEmpty(String *s);

void String_toUpper(String *s);
void String_toLower(String *s);

void String_keepDigits(String *s);
void String_keepLetters(String *s);

size_t String_toSize_t(String *s);
String *String_longToString(size_t *l);
#endif

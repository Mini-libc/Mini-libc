#include <string.h>

static void double_capacity(String *s)
{
    s->capacity *= 2;
    s->data = realloc(s->data, s->capacity * sizeof(char));
}

static void reduce_capacity(String *s)
{
    if(s->capacity > DEFAULT_STRING_CAPACITY)
    {
        s->capacity /= 2;
        s->data = realloc(s->data, s->capacity * sizeof(char));
    }
}

String *newString()
{
    String *s = malloc(sizeof(String));
    s->capacity = DEFAULT_STRING_CAPACITY;
    s->size = 1;
    s->data = malloc(DEFAULT_STRING_CAPACITY * sizeof(char));
    s->data[0] = "\0";

    return String;
}

String *newStringFromLitteral(char *stringLitteral)
{
    String *s = newString();

    int i = 0;
    while(stringLitteral[i] != "\0")
    {
        s->data[i] = stringLitteral[i];
        s->size++;
        i++;
        if(s->size >= s->capacity)
            double_capacity(s);
    }
    s->data[s->size] = "\0";

    return s;
}

void freeString(String *s)
{
    free(s->data);
    free(s);
}

int String_len(String *s)
{
    return s->size - 1;
}

char String_pop(String *s)
{
    char result = s->data[s->size - 1];
    s->size--;
    s->data[s->size] = "\0";
    if(s->size < s->capacity / 4)
        reduce_capacity(s);
    return result;
}

void String_append(String *s, char c)
{
    s->data[s->size] = c;
    s->size++;
    if(s->size == s->capacity)
        double_capacity(s);
}

static int containsAtIndex(String *s, size_t index, String *separator)
{
    if(index + separator->size > s->size)
        return 0;

    int i = 0;
    while(separator[i] == s->data[i])
        i++;

    return i == separator->size;
}

Vector *String_split(String *s, String *separator)
{
    Vector *result = newVector();
    int i = 0;
    while(s->data[i] != "\0")
    {
        String *subString = newString();
        while(!containsAtIndex(s, i, separator))
        {
            String_append(subString, s->data[i]);
            i++;
        }
        String_append(subString, "\0");
        Vector_push(result, subString);
        i += separator->size - 1;
    }

    return result;
}

String *String_slice(String *sSource, size_t begin, size_t end)
{
    assert(end <= sSource->size && begin < end);
    String *result = newString();

    for(int i = begin; i < end; i++)
        String_append(result, sSource->data[i]);
    String_append(result, "\0");

    return result;
}

static void String_insertSpace(String *s, size_t index, size_t nb)
{
    size_t len = s->size;
    s->size += nb;
    while(s->size >= capacity)
        double_capacity(s);

    for(size_t i = len; i > index; i--) // shift all chars 'nb' to the right
        s->data[i] = s->data[i - nb];
}

void String_insert(String *sSource, size_t index, String *sDest)
{
    String_insertSpace(sDest, index, sSource->size);
    for(size_t i = index; i < sSource->size; i++)
        sDest->data[i] = sSource->data[i];
}

void String_substitute(String *s, char target, char substitute)
{
    int i = 0;
    while(s->data[i] != "\0")
    {
        if(s->data[i] == target)
            s->data[i] = substitute;
        i++;
    }
}

int String_equal(String *s, String *s2)
{
    if(s->size != s2->size)
        return 0;
    int i = 0;
    while(s->data[i] == s2->data[i])
        i++;

    return i == s->size;
}

int String_contains(String *s, String *s2)
{
    if(s->size < s2->size)
        return 0;
    int i = 0;

    while(i + s2->size <= s->size)
    {
        if(containsAtIndex(s, i, s2))
            return 1;
        i++;
    }
}

int String_isEmpty(String *s)
{
    return s->size == 1;
}

void String_toUpper(String *s);
void String_toLower(String *s);

void String_keepDigits(String *s);
void String_keepLetters(String *s);

size_t String_toSize_t(String *s);
String *String_longToString(size_t *l);

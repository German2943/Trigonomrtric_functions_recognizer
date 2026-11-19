#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int lenght = 1;
    char *buffer;
    int acc = 0;
    if ((buffer = malloc(sizeof(char) * lenght)) == NULL)
    {
        return 1;
    }

    while ((buffer[acc] = getchar()) != '\n')
    {

        if (acc >= lenght)
        {
            lenght *= 2;
            if ((buffer = realloc(buffer, lenght)) == NULL)
            {
                return 1;
            }
        }
        acc++;
    }
    printf("your input was: %s", buffer);

    free(buffer);
    return 0;
}
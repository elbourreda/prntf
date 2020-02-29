#include <stdio.h>

// char pors(char *s)
// {
    


// }

int main()
{
    
    char *s;

    s = "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
    // s = pors(s);
    // printf("%s", s);

    int i = 0;
    if (s[i] == '%')
    {
        while (s[i] == '%')
        {
            i++;
        }
        if (i % 2 == 0)
            i = i / 2;
        else 
        {
            i = i - 1;
            i = i / 2;
        }
        while (i > 0)
            {
                putchar(s[i]);
                i--;
            }
    }

    printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
}
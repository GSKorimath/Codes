#include <stdio.h>
#include <string.h>

#define MAXLINES 10
#define MAXLEN 75

void find_p(char str[][MAXLEN], int n, char* p)  // code to find a certain pattern
{
    int i, j, p_len = strlen(p);
    for (i = 0; i < n; i++)
        {
        int l_len = strlen(str[i]);  // to find linelength
        for (j = 0; j <= l_len - p_len; j++)
        {
            if (strncmp(str[i]+j, p, p_len) == 0)
            {
                printf("%s\n", str[i]);
                break;
            }
        }
    }

}

int main()
{
    char str[MAXLINES][MAXLEN];
    char p[]="ire"; // pattern to be found
    int n=0;
    while (n < MAXLINES && gets(str[n]))
    {
        n++;
    }
    find_p(str, n, p);
    return 0;
}

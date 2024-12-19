//lab2.3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void explode(char str1[], char splitter, char str2[][100], int *count);

int main()
{
    char out[20][100];
    char in[50] ;
    int num;
    strcpy(in , "I Love You");
    explode(in, '/', out, &num);

    for (int i = 0; i < num; i++) {
        printf("str2[%d] = %s\n",i ,out[i]);
    }
    printf("count = %d", num);
    return 0;
} // end function
void explode(char str1[], char splitter, char str2[][100], int *count)
{
    int i = 0, j = 0, k = 0, s = 0, l = 0;
    *count = 0;

    // i= user input
    // j= row
    // k= column

    // Handle empty string case
    if (str1 == NULL || str1[0] == '\0')
    {
        return;
    }

    while (str1[i] != '\0')
    {
            // Skip consecutive delimiters
            if (str1[i] == splitter)
            {
                // If we have a non-empty substring, terminate and move to next
                if (j > 0)
                {
                    str2[k][j] = '\0';
                    k++;
                    j = 0;
                }
                i++;
                continue;
            }

            if (str1[i] == ' ')
            {
                if (j > 0)
                {
                    str2[k][j] = '\0';
                    k++;
                    j = 0;
                }
                i++;
                continue;
            }

            if (str1[i] == '-' )
            {
                if (j > 0)
                {
                    str2[k][j] = '\0';
                    k++;
                    j = 0;
                }
                i++;
                continue;
            }

            if (str1[i] == ',')
            {
                if (j > 0)
                {
                    str2[k][j] = '\0';
                    k++;
                    j = 0;
                }
                i++;
                continue;
            }

            if (str1[i] == ':')
            {
                if (j > 0)
                {
                    str2[k][j] = '\0';
                    k++;
                    j = 0;
                }
                i++;
                continue;
            }

        // Add character to current substring
        str2[k][j] = str1[i];
        j++;
        i++;

        // If next char is delimiter or end of string, terminate substring
        if (str1[i] == splitter || str1[i] == '\0')
        {
            str2[k][j] = '\0';

            // Only increment count if substring is non-empty
            if (j > 0)
            {
                k++;
                j = 0;
            }
        }
    }

    *count = k;
}//end function

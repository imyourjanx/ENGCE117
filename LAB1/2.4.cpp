//lab2.4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void explode(char str1[], const char splitters[], char str2[][100], int *count);

int main()
{
    char out[20][100] ;
    char in[50] ;
    int count;
    printf("Enter a text: ") ;
    fgets(in, 50, stdin);
    explode(in, " /-,:!*", out, &count) ;
    printf("count = %d\n", count) ;
    for (int i = 0; i < count; i++)
    {
        printf("str2[%d] = %s\n", i, out[i]) ;
    }//end for
    printf("count = %d", count) ;
    return 0;
}//end main

void explode(char str1[], const char splitters[], char str2[][100], int *count)
{
    int i = 0, j = 0, k = 0 ;
    *count = 0 ;

    if (str1 == NULL || str1[0] == '\0')
    {
        return;
    }//end if

    while (str1[i] != '\0')
    {
        int isSplitter = 0;
        for (int s = 0; splitters[s] != '\0'; s++)
        {
            if (str1[i] == splitters[s])
            {
                isSplitter = 1;
                break;
            }//end if
        }//end for

        if (isSplitter)
        {
            if (j > 0)
            {
                str2[k][j] = '\0';
                k++;
                j = 0;
            }//end if
            i++;
            continue;
        }//end if

        str2[k][j] = str1[i];
        j++;
        i++;

        if (str1[i] == '\0')
        {
            if (j > 0)
            {
                str2[k][j] = '\0' ;
                k++;
            }//end if
        }//end if
    }//end while
    k -= 1 ;
    *count = k ;
}//end function

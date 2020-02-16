/*****
@author: Nilay Chandra Barman (https://github.com/Nilaycb)
Copyright (c) 2020, All rights reserved.
Copyrights licensed under the GNU GPLv3 License.
******/

#include<stdio.h>
#include<conio.h>

int main()
{
    char st[100];
    int i=0, p, res=1, j=0, max=0;

    printf("## A program to find the biggest word size of a sentence ##\n\n");

    printf("Enter a sentence: ");
    while(1)
    {
        scanf("%c", &st[i]);
        if(st[i] == '\n')
        {
            break;
        }

        i++;
    }

    printf("\nThe input sentence: ");
    for(p=0; p<i; p++)
    {
        printf("%c", st[p]);
    }
    printf("\n\nThe input sentence length: %d\n", i);

    res=1; //whether a new word starts or not
    for(p=0; p<i; p++)
    {
        if(res == 1)
        {
            j=0;

            if(st[p] != ' ')
            {
                j++; //j=1 also applicable
                res=0;

                //[important] need to set the max when the loop ends by default at the start
                if(j>max)
                {
                    max = j;
                }
            }
        }
        else
        {
            if(st[p] == ' ')
            {
                res = 1;

                if(j>max)
                {
                    max = j;
                }
            }
            else
            {
                j++;

                //[important] need to set the max when the loop ends by default at the end
                if(j>max)
                {
                    max = j;
                }
            }
        }
    }
    printf("\nThe biggest word size is: %d\n", max);

    return 0;
}

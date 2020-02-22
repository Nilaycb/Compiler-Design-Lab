/*****
@author: Nilay Chandra Barman (https://github.com/Nilaycb)
Copyright (c) 2020, All rights reserved.
Copyrights licensed under the GNU GPLv3 License.
******/

#include<stdio.h>
#include<conio.h>

int main()
{
    char st[100], tmp_st[100], big_st[100];
    int i=0, p, res=1, j=0, max=0, m=0, v=0;

    printf("## A program to find the biggest word with size of a sentence ##\n\n");

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
    m=0; //index and length for new tmp_st[] array
    v=0; //index for new big_st[] array
    for(p=0; p<i; p++)
    {
        if(res == 1)
        {
            j=0;

            if(st[p] != ' ')
            {
                j++; //j=1 also applicable
                res=0;

                tmp_st[m] = st[p];
                m++;

                //[important] need to set the max when the loop ends by default at the start
                if(j>max)
                {
                    max = j;

                    for(v=0; v<m; v++)
                    {
                        big_st[v] = tmp_st[v];
                    }
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

                    for(v=0; v<m; v++)
                    {
                        big_st[v] = tmp_st[v];
                    }
                }
                else
                {
                    //new word is not bigger
                    //need to drop the letters from tmp_st[] array
                    while(m--)
                    {
                        tmp_st[m] = '\0';
                    }
                    m=0;
                }
            }
            else
            {
                j++;

                tmp_st[m] = st[p];
                m++;

                //[important] need to set the max when the loop ends by default at the end
                if(j>max)
                {
                    max = j;

                    for(v=0; v<m; v++)
                    {
                        big_st[v] = tmp_st[v];
                    }
                }
            }
        }
    }
    printf("\nThe biggest word size is: %d\n", max);

    printf("\nThe biggest word is: ");
    for(p=0; p<max; p++)
    {
        printf("%c", big_st[p]);
    }
    printf("\n");

    return 0;
}

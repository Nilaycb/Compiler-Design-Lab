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
    int i=0, p, flag=1, res=1, j=0, min=0, sp_flag=0;

    printf("## A program to find the smallest word size of a sentence ##\n\n");

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
    printf("\n");

    j=0;
    flag=1; //flag to capture the initial min length
    res=1; //whether a new word starts or not
    sp_flag=0; //flag to identify whether a space/split was previously found or not
    for(p=0; p<i; p++)
    {
        if(flag == 1)
        {
            if((p == 0) && (st[p] == ' '))
            {
                sp_flag = 1;
            }
            else if((st[p] == ' '))
            {
                if(sp_flag == 0)
                {
                    min = j;
                    flag = 0; //initial min length captured
                    res = 1;
                    sp_flag = 0; //[no use afterwards] space found but have been reset since loop is going to go out of flag=1
                }
            }
            else
            {
                j++;
                sp_flag = 0; //char found and space flag reset

                //char found and loop ends
                if(p == i-1)
                {
                    min = j;
                }
            }
        }
        else
        {
            if(res == 1)
            {
                j = 0;

                if(st[p] != ' ')
                {
                    j++; //j=1 also applicable
                    res=0;

                    //[important] need to set the min when the loop ends by default at the start
                    if(j<min)
                    {
                        min = j;
                    }
                }
            }
            else
            {
                if(st[p] == ' ')
                {
                    res = 1;

                    if(j<min)
                    {
                        min = j;
                    }
                }
                else
                {
                    j++;

                    //[important] need to set the min when the loop ends by default at the end
                    if(j<min)
                    {
                        min = j;
                    }
                }
            }
        }
    }
    printf("\nThe smallest word size is: %d\n", min);

    return 0;
}

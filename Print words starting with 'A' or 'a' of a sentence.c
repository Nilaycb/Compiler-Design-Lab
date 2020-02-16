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
    int i=0, cnt=1, p, flag=1, res=1;

    printf("## A program that reads a sentence and prints every word which started with 'A' or 'a' ##\n\n");

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


        if(st[p] == ' ')
        {
            cnt++;
        }
    }
    printf("\n\n");


    flag=0; //whether to print or not
    res=1; //signifies starting of a word
    for(p=0; p<i; p++)
    {
        if(res == 1)
        {
            if((st[p] == 'A') || (st[p] == 'a'))
            {
                res = 0;
                flag = 1;
            }
            else
            {
                res = 0;
                flag = 0;
            }
        }
        else
        {
            if(st[p] == ' ')
            {
                if((res == 0) && (flag == 1))
                {
                    printf("\n");
                }

                res = 1;
                flag = 0;
            }
        }

        if((res == 0) && (flag == 1))
        {
            printf("%c", st[p]);
        }
    }
    printf("\n");

    return 0;
}

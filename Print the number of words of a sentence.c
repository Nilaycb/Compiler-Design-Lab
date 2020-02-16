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
    int i=0, cnt=0, p;
    int sp_flag=0; //flag to identify whether a space/split was previously found or not

    printf("## A program to print the number of words of a sentence ##\n\n");

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

        if((p == 0) && (st[p] == ' '))
        {
            sp_flag = 1;
        }
        else if((st[p] == ' '))
        {
            if(sp_flag == 0)
            {
                cnt++;
                sp_flag = 1; //space found
            }
        }
        else
        {
            sp_flag = 0; //char found and space flag reset

            //char found and loop ends
            if(p == i-1)
            {
                cnt++;
            }
        }
    }
    printf("\n\nTotal words found: %d\n", cnt);

    return 0;
}

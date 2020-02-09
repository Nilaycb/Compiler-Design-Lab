/*****
@author: Nilay Chandra Barman (https://github.com/Nilaycb)
Copyright (c) 2020, All rights reserved.
Copyrights licensed under the GNU GPLv3 License.
******/

#include<stdio.h>
#include<conio.h>

int main() {
    char st[100], st2[100];
    int i=0, flag=0, com_c=0, flag2=0, flag3=0, clr=0;
    int j=0, p;

    while(1)
    {
        scanf("%c", &st[i]);
        
        if(st[i] == '\n')
        {
            break;
        }
        else if(st[i] == '/')
        {
            if(flag2 == 0)
            {
                if(flag == 1)
                {
                    com_c++;
                    flag2=1;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            else
            {
                if(flag3 == 1)
                {
                    clr = 1;
                    flag = 0;
                    flag2=0;
                    flag3=0;
                }
            }
        }
        else if(st[i] == '*')
        {
            if(flag2 == 0)
            {
                if(flag == 1)
                {
                    com_c++;
                    flag2=1;
                }
            }
            else
            {
                flag3=1;
            }
        }
        else if(flag2 == 0)
        {
            st2[j] = st[i];
            j++;
        }

        i++;
    }


    printf("\n\nThe string without comment: ");
    for(p=0; p<j; p++)
    {
        printf("%c", st2[p]);
    }
    printf("\n\nThe Number of Comment: %d\n", com_c);


    return 0;
}

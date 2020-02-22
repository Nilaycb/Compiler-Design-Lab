/*****
@author: Nilay Chandra Barman (https://github.com/Nilaycb)
Copyright (c) 2020, All rights reserved.
Copyrights licensed under the GNU GPLv3 License.
******/

#include<stdio.h>
#include<conio.h>

int main() {
    char st[100], st2[100];
    int i=0, j=0, p, com_c=0;
    int flag=0; //detecting the first occurrence of '/' 
    int flag2=0; //detecting the completion of first pair of '//' or '/*' 
    int flag3=0; 

    // Definition with example: "//{this is the starting pair of a comment} ........... some demo text here.......... //{this is the ending pair of a comment}" 
    //......................... the first '/' of starting pair is detected by {flag} .............................................................
    //.......................... '//' or '/*' starting pair is detected by {flag2} ............................................................
    //.......................... the first '
    
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
                    flag2=1; //first pair of '//' is found
                    break; //rest of the inputs will be a comment, no need to run loop
                }
                else
                {
                    flag = 1; // the first element of the comment sign pair is found
                }
            }
            else
            {
                //checks ending pair's first '/' occurrence was already found or not
                if(flag3 == 1)
                {
                    //comment's ending is found, reset all the flags
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
                    //starting pair is found which is '/*'
                    com_c++;
                    flag2=1;
                }
            }
            else
            {
                //ending pair's first element is found
                flag3=1;
            }
        }
        else if(flag2 == 0)
        {
            //starting pair is not activated yet, hence no comment is found
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

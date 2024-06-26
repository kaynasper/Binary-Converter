
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//Simple program to return the binary of a given number

int count = 0;

int get_binary(int figure, char *data) {
        char digit[1];

        while (figure != 0) {
                char digit[2];
                int keep;
                keep = figure % 2;
                
                if (keep == 1) {
                        figure -= 1;
                }

                figure = figure / 2;
                
                sprintf(digit, "%d", keep);
                strcat(data, digit);
                count++;
        }
        
        return 0;
}



//<Cmain>
int main()
{       
        char data[15];
        char answer[15];
        char entry[8];

        printf("Enter a number to get its Binary digit:  ");
        fgets(entry, 7, stdin);

        for (int x=0 ; x <((strlen(entry)) - 1) ; x++) {
                if (isdigit(entry[x]) < 1) {
                        puts("\nWrong entry");
                        return 0;
                }
        }

        get_binary(atoi(entry), data);
        data[count + 1] = '\0';

        for (int y=count, z = 0 ; y>0 ; y--, z++) {
                answer[z] = data[y-1];
        }

        answer[count] = '\0';
        printf("\n%s\n", answer);
        free(data);

        return 0;
}

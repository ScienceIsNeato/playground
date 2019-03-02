/* This program's generates random numbers and write them out to a file
   Then get the md5sum of the file.
*/

#include "/usr/include/stdio.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void get_random_number(void *random){

    int r = rand();
    random = r;

}

char *getStringFromInt(long i)
{

        char str[8];
        sprintf(str, "%-d", i);
        return str;
}

void write_string_to_file(char *random_number)
{

        int fd = open("output.txt", O_WRONLY | O_APPEND, 0777);
        write(fd, random_number, strlen(random_number));
        return;

}

void printRandomNumber(char *file)
{

        char *command = malloc(32);
        sprintf(command, "md5sum %s", file);
        system(command);
        free(command);

}


int main(int argc, char** argv)
{

        /* See Note 1 */
        if(argc > 1)
        {
                printf("About to generate ");
                printf(argv[1]);
                printf(" random numbers...\n");
        }
        else
        {
                printf("Usage 'playgound <num_rands>'\n");
                return 0;
        }

        printf("Press 'y' to continue..  ");

        /* See Note 3 
        char answer[2];
        gets(answer);
        */
        int ans_len = 2;
        char answer[ans_len];
        fgets(answer, ans_len, stdin); // use this instead

        /* See Note 4 */
        printf("answer: %s %p\n", answer, answer);

        /* See Note 2 */
        if(answer[0] != 'y'){ // See Note 5
                printf("You answered %s, aborting\n",answer);
                
                return 0;
        }

        /* See Note 6 */
        short count = atoi(argv[1]); // This (argv[1]) is only ok because of the code change we made in Note 1


        printf("About to generate %u \n",count);


        while(--count){

                int *a = malloc(4);
                get_random_number(a);

                char *str = getStringFromInt(a);
                write_string_to_file(str);
                printRandomNumber("output.txt");


        }

        return 0;

}

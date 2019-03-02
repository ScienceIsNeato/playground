/* See Note 20 */
/* See Note 26 */

/* This program's generates random numbers and write them out to a file
   Then get the md5sum of the file.
*/

#include "/usr/include/stdio.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h> /* Needed for Note 18 */
#include <time.h> /* Needed for Note 19 */

/* See note 8 */
int get_random_number(){
        /* See note 9 */
        // int r = rand();
        // random = r;
        return rand(); /* See Note 19 */
}

char* getStringFromInt(int i) /* see Note 11 */
{
        int length = snprintf( NULL, 0, "%d", i ); /* See note 12 */
        char *str = malloc( length + 1 ); /* See note 12 */
        snprintf( str, length + 1, "%d", i ); /* See note 12 */

        sprintf(str, "%d", i); /* dash indicates left justify - not needed here */
        return str;
}

void write_string_to_file(char *random_number) /* See Note 16 */
{
        int fd = open("output.txt", O_WRONLY | O_APPEND | O_CREAT, 0666); /* See Note 14 */

        if(fd < 0) /* See Note 15 */
        {
                printf("ERROR - CANNOT OPEN FILE output.txt!\n");
                close(fd);
                return;
        }
        int success = write(fd, random_number, strlen(random_number));

        if(success < 0) /* See Note 15 */
        {
                printf("ERROR - CANNOT WRITE TO FILE output.txt!\n");
                close(fd);
                return;
        }
        close(fd);
        return;
}

void printMd5sum(char *file)
{
        char *command = malloc(PATH_MAX); /* See Note 18 */

        if(__APPLE__) /* See Note 22 */
        {
                /* See Note 23 */
                sprintf(command, "md5 -q %s | sed 's/^[ \t]*//;s/[ \t]*$//' >> %s", file, file);
        }
        else
        {
                /* See Note 23 */
                sprintf(command, "md5sum %s", file);
        }
        int res = system(command); /* See Note 24 */

        free(command);
}


int main(int argc, char* argv[])
{
        /* See Note 25 */

        /* See Note 1 */
        if(argc > 1)
        {
                printf("About to generate ");
                printf("%s", argv[1]); /* See note 10 */
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

        int a = 0; /* See Note 7 */
        srand(time(0)); /* See Note 19 */

        while(count--){ /* See Note 17 */
                //int *a = malloc(4); /* See note 7 */
                a = get_random_number(); /* See note 9 */
                char *str = getStringFromInt(a); /* See note 12 */
                write_string_to_file(str);
                free(str); /* See Note 13 */
        }

        /* See Note 20 */
        printMd5sum("output.txt"); /* See Note 21 */

        return 0; /* See Note 27 */

}

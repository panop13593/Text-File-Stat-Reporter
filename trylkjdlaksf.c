#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS   1000

int main()
{
    FILE * file;
    char path[100];
    int i, len, index, isUnique;
    char ch;
    int characters, words, lines;
    char worst[MAX_WORDS][50];
    char distinct[50];


    int  count[MAX_WORDS];

    printf("Enter source file path: ");
    scanf("%s", path);


    file = fopen(path, "r");



    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }
    for (i=0; i<MAX_WORDS; i++)
        count[i] = 0;
    index = 0;

    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;


        if (ch == '\n' || ch == '\0')
            lines++;


        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;

        {

        strlwr(distinct);


        len = strlen(distinct);
        if (ispunct(distinct[len - 1]))
            distinct[len - 1] = '\0';



        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(worst[i], distinct) == 0)
                isUnique = 0;
        }


        if (isUnique)
        {
            strcpy(worst[index], distinct);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }
    }


    if (characters > 0)
    {
        words++;
        lines++;
    }


    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);
    printf("\nOccurrences of all distinct words in file: \n");
    for (i=0; i<index; i++)
    {

        printf("%-15s => %d\n", worst[i], distinct[i]);
    }

    fclose(file);

    return 0;
}



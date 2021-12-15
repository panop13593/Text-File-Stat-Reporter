#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to count frequency of occurance word and print it out//
void Count_frequency(const char *word, const char *array, int i, int occur[], char words[], int* szo, int* szw) {
  int count = 0;
  const char *found;
  for (int j = 0; j < i; j++) {
    if (isalpha(array[j])) {
      
      if (strcmp(&array[j], word) == 0) {
        found = &array[j];
        count++;
      }

      do {
        j++;
      } while (isalpha(array[j]));
    }
  }
  // check for occurance word and then print it out //
  if (found == word) {
    //create 2 new arrays for keeping unique words and the number of occurences
    printf(" [%s]  occur [%d] times\n", word, count); 
    for(int j=0;word[j]!='\0';j++,(*szw)++){
        words[*szw] = word[j];
    }
    words[*szw] = '\0';
    (*szw)++;
    occur[(*szo)++] = count;

  }

}

int main()
{   
    //Declare variable//
    FILE * file;
    char path[1000] , allw[1000] = {};
    char array[1000] ;
    int i = 0, occur[1000] = {}, szw = 0, szo = 0, alpo[30] = {};
    int j;
    char ch;
    int characters, words, lines ,space, paragraph;
    int countchar;

    

    //input the name of file//
    printf("Enter source file path: ");
    scanf("%s", path);

    // Open source files//
    file = fopen(path, "r");


   // Check if open sucessfully //
    if (file == NULL)
    {
        printf("---------ERROR--------\n");
        printf("Please check your file\n");

        exit(EXIT_FAILURE);
    }

    // While loop to count number of characters, words, lines and space occur in the program //
    characters = words = lines = space = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        // isalpha from <ctype.h> //
        // count character //
        if(isalpha(ch)){
            characters++;
            // convert character into lowercase //
            if(ch >= 'A' && ch <= 'Z'){
                ch = ch-'A'+'a';
            }

            alpo[ch-'a']++;
        }

        // Check new line //
        if (ch == '\n' || ch == '\0')
            lines++;

        // Check words //
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;

        // Check space //
        if (ch == ' ')
            space++;



        array[i] = ch;
        if (i + 1 >= sizeof array)
              break;
        i++;

    }
    array[i] = '\0';

     /* Increment words and lines for last word */
    if (characters > 0)
    {
        words++;
        lines++;
    }

    for (j = 0; j < i; j++)
    {
    if (!isalpha(array[j]))
        {
          array[j] = '\0';
        }
    }
    for (j = 0; j < i; j++)
    {
    // Use the beginning of each word ...
    if (isalpha(array[j]))
     {
      Count_frequency(&array[j], array, i, occur, allw, &szo, &szw);
      
      // skip test of word
      do {
        j++;
      } while (isalpha(array[j]));
     }

    }

    //Function to print bar chart for words//
    int lim=0;

    if(words > 0){
      printf("\nBar Chart For Words\n^\n");

      for(int cnt=0,j=0;cnt<szo;cnt++){
        printf("|");

        for(int k=0; k<occur[cnt]; k++){
          printf("*");
        }
        printf(" ");
        for(;allw[j]!='\0';j++){
          printf("%c",allw[j]);
        }
        printf("(%d)\n",occur[cnt]);

        if(occur[cnt]>lim){
          lim = occur[cnt];
        }
        j++;
      }

      printf("|");
      for(int j=0;j<lim+10;j++){
        printf("-");
      }
      printf(">\n");
    }


    // Function to print bar chart for character //
    if(characters > 0){
      lim = 0;
      printf("\nBar Chart For Characters\n^\n");
      for(int j=0;j<26;j++){
          if(alpo[j] == 0) continue;
          printf("|");
          for(int k=0;k<alpo[j];k++){
            printf("*");
          }
          printf(" %c(%d)",j+'a',alpo[j]);
          if(alpo[j]>lim){
            lim=alpo[j];
          }
          printf("\n");
      }

      for(int j=0;j<lim+10;j++){
        printf("-");
      }
      printf(">\n");
    }



    // print count //
    printf("\n");
    printf("Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);
    printf("Total spaces     = %d\n", space);
    // close file //
    fclose(file);

    return 0;
}

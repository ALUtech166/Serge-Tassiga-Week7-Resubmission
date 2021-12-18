
/** 
 * File 
 * handling
 * program
 * C
 * 
 *  **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX_WORDS   500

// the main function
void main() {

    char words[MAX_WORDS][25];
    char word[25];

    int i, len, index, unique_word;
    int count[MAX_WORDS];

    FILE *file;
   
    pid_t wait();

  // Open with if statement to check whether the file exist or not

    if ((file = fopen("File.txt", "r")) == NULL) {
        printf("Ouff Error, This file doesn't exist.\n");
        printf("Please try again Later and make sure the file exist.\n");

        exit(1);
    } else {
        // printing out if is opened
        printf("File Opened Successfully. Reading Content now \n\n");
        
    }

// While Method 
     while (fscanf(file, "%s", word) != EOF)
    {
        // We then convert word to lowercase
        strlen(word);

        // This code removes the last punctuation character
        len = strlen(word);
        if (ispunct(word[len - 1])) {
            word[len - 1] = '\0';
        }
      

        // THis code check if word exits in list of all distinct words
        unique_word = 1;
        for (i=0; i<index && unique_word; i++)
        {
            if (strcmp(words[i], word) == 0)
                unique_word = 0;
        }

        // We add(first check if unique word) unique word to distinct words
    
        if (unique_word) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    // Close file
    fclose(file);

    //
    
    // Using Fork to print the output
    int pid = fork();
    int x = getpid();
    printf("Before Fork: Parent process is PID is %d\n", x);

    if (pid == 0) {
        printf("I'm a child with pid : %d and parent pid : \n", getpid());
        printf("\nOccurrences of all distinct words in file: \n");
        // It is waiting for parent process to be executed.
        wait();

    
    } else if (pid > 0) {
        printf("I'm parent process with pid: %d\n", getpid());
        // print theoccur rences of the all distinct words in that particular file
        printf("\nOccurrences of all distinct words in file: \n");
          
    
    } else {
        printf("Error");
    }
    
    i = 0;
    // While method to increment the occurences of all Distinct words
    while (i<index)
    {
        //
        printf("'%s ': %d\n", words[i], count[i]);
        i++;
    }
    
}
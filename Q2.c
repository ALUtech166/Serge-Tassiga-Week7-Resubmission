#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// If_number function is checking if the input entered by user is a valid number 
int if_number(char *str)
{
     int i = 0;
    while (str[i] != '\0')
    {
        if((str[i]>='0'&&str[i]<='5')||(str[i]=='.')) {
			printf(".");
			i++;
		}
    }
     return 0;
}



// main function
void main()
{
    // necessary variables
    int i, j;
    char sheet[10][10][20] = {0};
    
    for (i = 0; i <= 5; i++)
        for (j = 0; j <= 5; j++)
        {
            if (i == 0 && j != 0)
                sheet[i][j][0] = 'A' + j - 1;
            else if (i != 0 && j == 0)
                sheet[i][j][0] = '0' + i;
            else if (i == 0 && j == 0)
                sheet[i][j][0] = ' ';
            else
                sheet[i][j][0] = '_';
        }
     // print the initialized sheet
     for (i = 0; i <= 5; i++)
     {
          for (j = 0; j <= 5; j++)
          {
               printf("%11s", sheet[i][j]);
          }
          printf(" \n");
     }
    // calling the Program function to enter input into the spreadsheet and 
    //print the result of the sheet
    program(sheet);
    
    
}


// Program Function is focusing on how the program should excute
void program(char sheet[10][10][20]) {

    // All variables needed
    double excelbook[10][10] = {0};
    // flag variables
    int flag[10][10] = {0};
    //cell value
    char cellValue[20];
    // cell input 
    char cellInput[4];
    char *sub;

    while (1)
    {
        
        int i, j;
        int col, row;  // cell coordinates
        


        printf("==== Welcome to a simple spreadsheet program ===== \n");
        printf("\nEnter the cell number :  \n");
        scanf("%s", cellInput);

        if (cellInput[0] >= 'A' && cellInput[0] <= 'Z')
            col = cellInput[0] - 'A' + 1;
        else
            col = cellInput[0] - 'a' + 1;
        row = cellInput[1] - '1' + 1;
        // if for invalid input
        if (row > 5 || row < 0 || col > 5 || col < 0)
        {
            printf("\n No cell found. Please try a new one \n");
            continue;
        }
        // New input that user should enter again the correct one
        printf("\nEnter a new cell value to be inserted:  ");
        scanf("%s", cellValue);

        // User input should be checked if the right one or invalid input
        if (if_number(cellValue))
        {
            excelbook[row][col] = atoi(cellValue);
            flag[row][col] = 1;
            strcpy(sheet[row][col], cellValue);
            if (strlen(sheet[row][col]) > 6)
            {
                sheet[row][col][6] = '.';
                sheet[row][col][7] = '.';
                sheet[row][col][8] = '\0';
            }
        }
        else
        {
            strcpy(sheet[row][col], cellValue);
            if (strlen(sheet[row][col]) > 6)
            {
                sheet[row][col][6] = '.';
                sheet[row][col][7] = '.';
                sheet[row][col][8] = '\0';
            }
        }

        for (i = 0; i <= 5; i++)
        {
            for (j = 0; j <= 5; j++)
                printf("%8s   ", sheet[i][j]);
            printf("\n");
        }

        printf("\n\n The Previous Input\nCell Value : %s\nValue : %s\n\n", cellInput, cellValue);
    }
    
  
 
}



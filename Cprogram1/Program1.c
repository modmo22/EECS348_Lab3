//
// Created by modco on 2/11/2023.
//

#include <stdio.h>


int main () {
    // create an array of months
    char months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    // input a .txt file that has a floating point number on each line and put it into an array
    FILE *file = fopen("input.txt", "r");
//    if (file == NULL)
//    {
//        perror("Error opening file");
//        return 1;
//    }

    float sales[12];
    char line[256];
    int i = 0;

//    file = fopen("input.txt", "r");
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%f", &sales[i]);
        i++;
    }
    fclose(file);
    for (i = 0; i < 12; i++)
    {
        printf("%s: %.2f", months[i], sales[i]);
    }
}

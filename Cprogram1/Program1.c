//
// Created by modco on 2/11/2023.
//

#include <stdio.h>

// the bubble sort algorithm that will sort the sales array in descending order and keep the months array in sync
void bubbleSort(float* sales, char* months, int size)
{
    int i, j;
    float temp;
    char temp2;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = 0; j < (size - i - 1); j++)
        {
            if (sales[j] < sales[j+1])
            {
                temp = sales[j];
                sales[j] = sales[j+1];
                sales[j+1] = temp;
                temp2 = months[j];
                months[j] = months[j+1];
                months[j+1] = temp2;
            }
        }
    }
}

int main () {
    // create an array of months
    char* months[12];
    months[0] = "January";
    months[1] = "February";
    months[2] = "March";
    months[3] = "April";
    months[4] = "May";
    months[5] ="June";
    months[6] = "July";
    months[7] = "August";
    months[8] = "September";
    months[9] = "October";
    months[10] = "November";
    months[11] = "December";


    // input a .txt file that has a floating point number on each line and put it into an array
    FILE* file;
    file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

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
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (i = 0; i < 12; i++)
    {
        printf("%s\t$%.2f", months[i], sales[i]);
    }
    int min = 0, max = 0;
    float sum = 0;
    // iterate through the sales array to find the min and max values
    for (i = 0; i < 12; i++)
    {
        if (sales[i] < sales[min])
        {
            min = i;
        }
        if (sales[i] > sales[max])
        {
            max = i;
        }
        sum += sales[i];
    }
    float average = sum / 12;
    printf("Sales summary:\n");
    printf("Minimum sales:\t$%.2f\t(%s)\n", sales[min], months[min]);
    printf("Maximum sales:\t$%.2f\t(%s)\n", sales[max], months[max]);
    printf("Average sales:\t$%.2f\n", average);

    printf("Six-Month Moving Average Report:\n");
    for (i = 0; i <= 6; i++)
    {
        float movingAverage = ((sales[i] + sales[i+1] + sales[i+2] + sales[i+3] + sales[i+4] + sales[i+5]) / 6);
        printf("%s\t -\t%s\t$%.2f", months[i], months[i+5], movingAverage);
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    bubbleSort(sales, months, 12);
    for (i = 0; i < 12; i++)
    {
        printf("%s\t$%.2f", months[i], sales[i]);
    }
}

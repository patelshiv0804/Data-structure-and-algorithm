#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int createRecords(char cityNames[][100], int numOfCities, double coordinates[][2])
{

    for (int i = 0; i < numOfCities; i++)
    {
        printf("Enter the city name: ");
        scanf("%s", cityNames[i]);
        for (int j = 0; j < 2; j++)
        {
            printf("Enter the coordinates (x, y) for city %s: ", cityNames[i]);
            scanf("%lf", &coordinates[i][j]);
        }
    }
    return numOfCities;
}

void displayRecords(char cityNames[][100], double coordinates[][2], int numOfCities)
{
    printf("\nDisplaying records:\n");
    for (int i = 0; i < numOfCities; i++)
    {
        printf("City %d - Name: %s, Coordinates: (%lf, %lf)\n", i + 1, cityNames[i], coordinates[i][0], coordinates[i][1]);
    }
}

int insertRecord(char cityNames[][100], double coordinates[][2], int numOfCities)
{
    printf("\nEnter the city name: ");
    scanf("%s", cityNames[numOfCities]);
    for (int j = 0; j < 2; j++)
    {
        printf("Enter the coordinates (x, y) for city %s: ", cityNames[numOfCities]);
        scanf("%lf", &coordinates[numOfCities][j]);
    }
    return numOfCities + 1;
}

int deleteRecord(char cityNames[][100], double coordinates[][2], int numOfCities)
{
    printf("\nEnter the city name: ");
    char cityName[100];
    scanf("%s", cityName);
    for (int i = 0; i < numOfCities; i++)
    {
        int value = strcmp(cityName, cityNames[i]);
        if (value == 0)
        {
            while (i < numOfCities)
            {
                strcpy(cityNames[i], cityNames[i + 1]);
                coordinates[i][0] = coordinates[i + 1][0];
                coordinates[i][1] = coordinates[i + 1][1];
                i++;
            }
        }
    }
    return numOfCities - 1;
}

void searchRecord(char cityNames[][100], double coordinates[][2], int numOfCities)
{
    int found = 0;
    printf("\nEnter the city name: ");
    char cityName[100];
    scanf("%s", cityName);
    for (int i = 0; i < numOfCities; i++)
    {
        int value = strcmp(cityName, cityNames[i]);
        if (value == 0)
        {
            printf("City found\n");
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("City not found\n");
    }
}

void printCloseRecords(char cityNames[][100], double coordinates[][2], int numOfCities)
{
    double xCoord, yCoord, specifiedDistance;
    printf("Enter the specified distance point: ");
    scanf("%lf", &specifiedDistance);
    printf("Enter x coordinate of location: ");
    scanf("%lf", &xCoord);
    printf("Enter y coordinate of location: ");
    scanf("%lf", &yCoord);

    for (int i = 0; i < numOfCities; i++)
    {
        double xDiff = (xCoord - coordinates[i][0]) * (xCoord - coordinates[i][0]);
        double yDiff = (yCoord - coordinates[i][1]) * (yCoord - coordinates[i][1]);
        double distance = sqrt(xDiff + yDiff);
        if (distance <= specifiedDistance)
        {
            printf("%s\n", cityNames[i]);
        }
    }
}

int main()
{
    char cityNames[100][100];
    double coordinates[100][2];
    int numOfCities = 3;
    int choice;

    numOfCities = createRecords(cityNames, numOfCities, coordinates);

    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");

    printf("1. Insert a record\n");
    printf("2. Delete a record\n");
    printf("3. Search for a record\n");
    printf("4. Display all records\n");
    printf("5. Print records close to a point\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        numOfCities = insertRecord(cityNames, coordinates, numOfCities);
        break;
    case 2:
        numOfCities = deleteRecord(cityNames, coordinates, numOfCities);
        break;
    case 3:
        searchRecord(cityNames, coordinates, numOfCities);
        break;
    case 4:
        displayRecords(cityNames, coordinates, numOfCities);
        break;
    case 5:
        printCloseRecords(cityNames, coordinates, numOfCities);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}
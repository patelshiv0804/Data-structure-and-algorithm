#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct city
{
    char name[100];
    int x;
    int y;
};

struct city_database
{
    struct city cities[100];
    int num_cities;
};

void insert_record(struct city_database *db, const char *name, int x, int y)
{
    if (db->num_cities < 100)
    {
        strcpy(db->cities[db->num_cities].name, name);
        db->cities[db->num_cities].x = x;
        db->cities[db->num_cities].y = y;
        db->num_cities++;
        printf("city record added successfully.\n");
    }
    else
    {
        printf("city database is full. Cannot add record.\n");
    }
}

void delete_record_by_name(struct city_database *db, const char *name)
{
    int found = 0;
    for (int i = 0; i < db->num_cities; i++)
    {
        if (strcmp(db->cities[i].name, name) == 0)
        {
            for (int j = i; j < db->num_cities - 1; j++)
            {
                db->cities[j] = db->cities[j + 1];
            }
            db->num_cities--;
            found = 1;
            printf("city record deleted successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("city record with name '%s' not found.\n", name);
    }
}

void delete_record_by_coordinates(struct city_database *db, int x, int y)
{
    int found = 0;
    for (int i = 0; i < db->num_cities; i++)
    {
        if (db->cities[i].x == x && db->cities[i].y == y)
        {
            for (int j = i; j < db->num_cities - 1; j++)
            {
                db->cities[j] = db->cities[j + 1];
            }
            db->num_cities--;
            found = 1;
            printf("city record deleted successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("city record with coordinates (%d, %d) not found.\n", x, y);
    }
}

void search_record_by_name(const struct city_database *db, const char *name)
{
    int found = 0;
    for (int i = 0; i < db->num_cities; i++)
    {
        if (strcmp(db->cities[i].name, name) == 0)
        {
            printf("city record found: Name: %s, Coordinates: (%d, %d)\n", db->cities[i].name, db->cities[i].x, db->cities[i].y);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("city record with name '%s' not found.\n", name);
    }
}

void search_record_by_coordinates(const struct city_database *db, int x, int y)
{
    int found = 0;
    for (int i = 0; i < db->num_cities; i++)
    {
        if (db->cities[i].x == x && db->cities[i].y == y)
        {
            printf("city record found: Name: %s, Coordinates: (%d, %d)\n", db->cities[i].name, db->cities[i].x, db->cities[i].y);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("city record with coordinates (%d, %d) not found.\n", x, y);
    }
}

int main()
{

    printf("Name:Shiv Patel\n");
    printf("Roll No:22BCP317\n");

    struct city_database db;
    db.num_cities = 0;

    insert_record(&db, "Gandhinagar", 40, -74);
    insert_record(&db, "Ahemdabad", 51, 0);
    insert_record(&db, "Mehsana", 35, 139);

    delete_record_by_name(&db, "Mehsana");
    delete_record_by_coordinates(&db, 35, 139);

    search_record_by_name(&db, "Gandhinagar");
    search_record_by_coordinates(&db, 51, 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



struct City {
    char name[100];
    int x;
    int y;
};

struct CityDatabase {
    struct City cities[100];
    int numCities;
};

void insertRecord(struct CityDatabase *db, const char *name, int x, int y) {
    if (db->numCities < 100) {
        strcpy(db->cities[db->numCities].name, name);
        db->cities[db->numCities].x = x;
        db->cities[db->numCities].y = y;
        db->numCities++;
        printf("City record added successfully.\n");
    } else {
        printf("City database is full. Cannot add record.\n");
    }
}

void deleteRecordByName(struct CityDatabase *db, const char *name) {
    int found = 0;
    for (int i = 0; i < db->numCities; i++) {
        if (strcmp(db->cities[i].name, name) == 0) {
            for (int j = i; j < db->numCities - 1; j++) {
                db->cities[j] = db->cities[j + 1];
            }
            db->numCities--;
            found = 1;
            printf("City record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("City record with name '%s' not found.\n", name);
    }
}

void deleteRecordByCoordinates(struct CityDatabase *db, int x, int y) {
    int found = 0;
    for (int i = 0; i < db->numCities; i++) {
        if (db->cities[i].x == x && db->cities[i].y == y) {
            for (int j = i; j < db->numCities - 1; j++) {
                db->cities[j] = db->cities[j + 1];
            }
            db->numCities--;
            found = 1;
            printf("City record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("City record with coordinates (%d, %d) not found.\n", x, y);
    }
}


void searchRecordByName(const struct CityDatabase *db, const char *name) {
    int found = 0;
    for (int i = 0; i < db->numCities; i++) {
        if (strcmp(db->cities[i].name, name) == 0) {
            printf("City record found: Name: %s, Coordinates: (%d, %d)\n", db->cities[i].name, db->cities[i].x, db->cities[i].y);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("City record with name '%s' not found.\n", name);
    }
}

void searchRecordByCoordinates(const struct CityDatabase *db, int x, int y) {
    int found = 0;
    for (int i = 0; i < db->numCities; i++) {
        if (db->cities[i].x == x && db->cities[i].y == y) {
            printf("City record found: Name: %s, Coordinates: (%d, %d)\n", db->cities[i].name, db->cities[i].x, db->cities[i].y);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("City record with coordinates (%d, %d) not found.\n", x, y);
    }
}

int main() {

    printf("Name:Shiv Patel\n");
    printf("Roll No:22BCP317\n");

    struct CityDatabase db;
    db.numCities = 0;


    insertRecord(&db, "Gandhinagar", 40, -74);
    insertRecord(&db, "Ahemdabad", 51, 0);
    insertRecord(&db, "Mehsana", 35, 139);

    deleteRecordByName(&db, "Mehsana");
    deleteRecordByCoordinates(&db, 35, 139);

    searchRecordByName(&db, "Gandhinagar");
    searchRecordByCoordinates(&db, 51, 0);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000 // 

// Function to search for a number in the hash table
bool searchNumber(int hashTable[], int num) {
    
    if (hashTable[num + MAX] == 1) {
        return true;
    } else {
        return false;
    }
}

void insertNumber(int hashTable[], int num) {
 
    hashTable[num + MAX] = 1;
}

int main() {
    int hashTable[2 * MAX + 1] = {0}; 


    insertNumber(hashTable, -2);
    insertNumber(hashTable, 5);
    insertNumber(hashTable, 8);

 
    printf("%d\n", searchNumber(hashTable, -2)); // Should print 1 (true)
    printf("%d\n", searchNumber(hashTable, 0));  // Should print 0 (false)

    return 0;
}

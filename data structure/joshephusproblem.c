#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[20];
    int chosen_integer;
    struct Person* next;
} Person;

struct Person* create_person(char name[], int chosen_integer) {
    struct Person* new_person = (struct Person*)malloc(sizeof(struct Person));
    strcpy(new_person->name, name);
    new_person->chosen_integer = chosen_integer;
    new_person->next = NULL;
    return new_person;
}

struct Person* insert_person(struct Person* head, char name[], int chosen_integer) {
   struct Person* new_person = create_person(name, chosen_integer);
    if (head == NULL) {
        new_person->next = new_person; // Point to itself for circular linked list
        return new_person;
    }
    struct Person* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = new_person;
    new_person->next = head;
    return head;
}

void eliminate_person(struct Person** head, int count) {
    if (*head == NULL) {
        return;
    }

    struct Person* current = *head;
    struct Person* prev = NULL;

   do {
        for (int i = 1; i < count; i++) {
            prev = current;
            current = current->next;
        }

        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *head = current->next;
        }

        printf("%s\n", current->name);
        count = current->chosen_integer;
        free(current);
        current = prev->next;
    } while (current->next != current);
    printf("%s\n", current->name);
    *head = NULL;
}

int main() {
    int num_people, initial_count;
    printf("enter the no of people:");
    scanf("%d", &num_people);

    struct Person* circle = NULL;

    for (int i = 0; i < num_people; i++) {
        char name[20];
        int chosen_integer;
        printf("enter name and number:");
        scanf("%s %d", name, &chosen_integer);
        circle = insert_person(circle, name, chosen_integer);
    }
    printf("enter the value of initial count:");
    scanf("%d", &initial_count);

    eliminate_person(&circle, initial_count);

    return 0;
}

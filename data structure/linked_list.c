// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Person {
//     char name[20];
//     int integer;
//     struct Person* next;
// };

// struct Person* create(char name[], int integer) {
//     struct Person* new_person = (struct Person*)malloc(sizeof(struct Person));
//     strcpy(new_person->name, name);
//     new_person->integer = integer;
//     new_person->next = NULL;
//     return new_person;
// }

// struct Person* insert(struct Person* head, char name[], int integer) {
//    struct Person* new_person = create(name, integer);
//     if (head == NULL) {
//         new_person->next = new_person; 
//         return new_person;
//     }
//     struct Person* current = head;
//     while (current->next != head) {
//         current = current->next;
//     }
//     current->next = new_person;
//     new_person->next = head;
//     return head;
// }

// void eliminate(struct Person* head, int count) {
//     if (head == NULL) {
//         return;
//     }

//     struct Person* current = head;
//     struct Person* prev = NULL;

//    while (current->next != current) {
//         for (int i = 1; i < count; i++) {
//             prev = current;
//             current = current->next;
//         }

//         if (prev != NULL) {
//             prev->next = current->next;
//         } else {
//             head = current->next;
//         }

//         printf("%s\n", current->name);
//         count = current->integer;
//         free(current);
//         current = prev->next;
//     } 
//     printf("the last one in the circle :%s\n", current->name);

// }

// int main() {
//     int people, initial_count;
//     printf("enter the no of people:");
//     scanf("%d", &people);

//     struct Person* ptr = NULL;

//     for (int i = 0; i < people; i++) {
//         char name[20];
//         int integer;
//         printf("enter name and number:");
//         scanf("%s %d", name, &integer);
//         ptr = insert(ptr, name, integer);
//     }
//     printf("enter the value of initial count:");
//     scanf("%d", &initial_count);

//     eliminate(ptr, initial_count);

//   return 0;
// }




#include <stdio.h>

struct student
{
    int id;
    char full_name[50];
};

int main()
{
    printf("Student Information System\n");
    printf("Enter your student ID: ");
    
    struct student stud;
    scanf("%d", &stud.id);
    
    printf("Enter your full name: ");
    scanf("%s", stud.full_name);
    
    struct student *stud_ptr = &stud;
    
    printf("Name: %s\t Memory Address: %p\n", stud.full_name, &stud.full_name);
    printf("ID: %d\t Memory Address: %p\n", stud.id, &stud.id);
    
    return 0;
}

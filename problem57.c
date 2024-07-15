/*
    Create a sample link list with about 5 entries using the following

    structure. Insert a new entry before or after a given id.
    Menu Items
    1. Insert Entry
    2. Display List
    3. Exit
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Student {
    int mathMark;
    int scienceMark;
    struct Student *nextStudent;
} Student;

void append(Student **root, int mathGrade, int scienceGrade);
void print_menu();
void display_list(Student *root);
int get_input(char *text);
void deallocate(Student **root);
void push(Student **root, int mathGrade, int scienceGrade);
void insert(Student *root, int index, int mathGrade, int scienceGrade);

int main() {

    Student *root = NULL;
   
    //append(&root, 10, 9);

    int option = 0;
    int mathGrade;
    int scienceGrade;

    while (option != 3) {
        option = 0;
        print_menu();
        //option = get_option();
        printf("Selection an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: // Insert Entry
            mathGrade = get_input("\nEnter math grade: ");
            scienceGrade = get_input("\nEnter science grade: ");
            append(&root, mathGrade, scienceGrade);
            break;
        case 2:
            display_list(root);
            break;
        
        default:
            break;
        }
    }

    deallocate(&root);
    return 0;
}

void append(Student **root, int mathGrade, int scienceGrade) {
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Something went wrong...\n");
        exit(2);
    }
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    newStudent->nextStudent = NULL;
    if (*root == NULL) {
        *root = newStudent;
    } else {

        Student *current = *root;
        while (current->nextStudent != NULL) {
            current = current->nextStudent;
        }
        current->nextStudent = newStudent;
    }
}

void push(Student **root, int mathGrade, int scienceGrade) {
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        exit(3);
    }
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    newStudent->nextStudent = *root;
    *root = newStudent;
}

void insert(Student *root, int index, int mathGrade, int scienceGrade) {
    Student *newStudent = malloc(sizeof(Student));
    int i = 0;
    if (newStudent == NULL) {
        exit(3);
    }

    Student *current = root;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    for (i = 0; i < index; i++) {
        current = current->nextStudent;
    }
    newStudent->nextStudent = current->nextStudent;
    current->nextStudent = newStudent;

}

void print_menu() {
    printf("============ Menu Items ============\n");
    printf("1 -> Insert Entry\n");
    printf("2 -> Display List\n");
    printf("3 -> Exit\n");
}

void display_list(Student *root) {
    Student *current = root;
    while (current != NULL) {
        printf("Math grade: %d\n", current->mathMark);
        printf("Science grade: %d\n", current->scienceMark);
        current = current->nextStudent;
    }
    
}

int get_input(char *text) {
    int mark = 0;
    printf("%s: ", text);
    scanf("%d", &mark);
    return mark;
}

void deallocate(Student **root) {
    Student *current = *root;
    while(current != NULL) {
        Student *temp = current;
        current = current->nextStudent;
        free(temp);
    }
    *root = NULL;
}
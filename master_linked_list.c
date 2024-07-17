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
    int id;
    int mathMark;
    int scienceMark;
    struct Student *nextStudent;
} Student;

void append(Student **root, int id, int mathGrade, int scienceGrade);
void print_menu();
void display_list(Student *root);
int get_input(char *text);
void deallocate(Student **root);
void push(Student **root, int id, int mathGrade, int scienceGrade);
void insert(Student **root, int index, int id, int mathGrade, int scienceGrade);
void delete_by_id(Student **root, int id);

int main() {

    Student *root = NULL;
   
    //append(&root, 10, 9);

    int option = 0;
    int id;
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
            id = get_input("Student's ID: ");
            mathGrade = get_input("Enter math grade: ");
            scienceGrade = get_input("Enter science grade: ");
            append(&root, id, mathGrade, scienceGrade);
            break;
        case 2: // display Student's info
            display_list(root);
            break;
        
        default:
            break;
        }
    }

    deallocate(&root); // deallocated heap memory
    return 0;
}

void append(Student **root, int id, int mathGrade, int scienceGrade) { 
    /*
    *    Appends student at the end of linked list
    *    If linked list is empty it it will make it as root node
    */ 
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Something went wrong...\n");
        exit(2);
    }
    newStudent->id = id;
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

void push(Student **root, int id, int mathGrade, int scienceGrade) {
    /*
    *    Adds an element at the beginning of the linked list
    */
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        exit(3);
    }
    newStudent->id = id;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    newStudent->nextStudent = *root;
    *root = newStudent;
}

void insert(Student **root, int index, int id, int mathGrade, int scienceGrade) {
    // Inserts a student after the index given
    Student *newStudent = malloc(sizeof(Student));
    int i = 0;
    if (newStudent == NULL) {
        exit(3);
    }

    Student *current = *root;
    newStudent->id = id;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    for (i = 0; i < index; i++) {
        current = current->nextStudent;
    }
    newStudent->nextStudent = current->nextStudent;
    current->nextStudent = newStudent;
}

void delete_by_id(Student **root, int id) {
    // deletes a student by ID
    if (*root == NULL) {
        return;
    }
    Student *current = *root;
    while (current != NULL) {

        if ((*root)->id == id) {
            Student *studentToRemove = *root;
            *root = (*root)->nextStudent;
            free(studentToRemove);
            return;
        }

        if (current->nextStudent->id == id) {
            Student *studentToRemove = current->nextStudent;
            if (current->nextStudent->nextStudent == NULL){
                current->nextStudent = NULL;
            } else {
                current->nextStudent = current->nextStudent->nextStudent;
            }
            free(studentToRemove);
            return;
            
        }

        current = current->nextStudent;
    }
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
        printf("============ Student's ID: %d ============\n", current->id);
        printf("Math grade: %d\n", current->mathMark);
        printf("Science grade: %d\n", current->scienceMark);
        printf("==========================================\n");
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
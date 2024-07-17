/*
    Create a sample linked list with about 5 entries using the following
    structure. Insert a new entry before or after a given id. Delete an
    entry of a given id.
    Menu Items
    1. Insert Entry
    2. Delete Entry
    3. Display List
    4. Exit
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
void insert_after_id(Student **root, int index, int id, int mathGrade, int scienceGrade);
void delete_by_id(Student **root, int id);

int main() {

    Student *root = NULL;
   
    //append(&root, 10, 9);

    int option = 0;
    int id;
    int mathGrade;
    int scienceGrade;
    int getId;

    append(&root, 1, 10, 10);
    append(&root, 2, 9, 9);
    append(&root, 3, 8, 8);
    append(&root, 4, 7, 7);
    append(&root, 5, 6, 6);

    while (option != 4) {
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
            getId = get_input("Enter the ID to place student after it: ");

            insert_after_id(&root, getId, id, mathGrade, scienceGrade);
            printf("Inserted new student with ID: %d\n", id);
            break;
        case 2: // display Student's info
            display_list(root);
            break;
        case 3:
            id = get_input("Student's ID to delete: ");
            delete_by_id(&root, id);
            printf("Student with ID: %d deleted.\n", id);
            break;
        
        default:
            break;
        }
    }
    printf("Exiting program...");

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

void insert_after_id(Student **root, int findID, int id, int mathGrade, int scienceGrade) {
    // Inserts a student after the index given
    Student *newStudent = malloc(sizeof(Student));

    if (newStudent == NULL) {
        exit(3);
    }

    Student *current = *root;
    newStudent->id = id;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    while (current != NULL) {
        if (current->id == findID) {
            newStudent->nextStudent = current->nextStudent;
            current->nextStudent = newStudent;
            return;
        }
        current = current->nextStudent;
    }
    printf("Unable to find ID: %d\n", findID);
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
    printf("3 -> Delete Entry by ID\n");
    printf("4 -> Exit\n");
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
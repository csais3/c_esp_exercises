/*
    Create a doubly linked list with about 5 entries using the following
    structure. Insert a new entry before or after a given id. Delete an
    entry of a given id.
    Menu Items
    1. Insert Entry
    2. Delete Entry
    3. Display List
    4. Exit
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Student {
    int id;
    int mathMark;
    int scienceMark;
    struct Student *nextStudent;
    struct Student *prevStudent;
} Student;

void inser_student_after_id(Student **tail, int afterID, int id, int mathGrade, int scienceGrade);
void deallocate(Student **tail, Student **head);
void push_student(Student **tail, int id, int mathGrade, int scienceGrade);
void display_students_list(Student *tail);
void delete_student_by_id(Student **tail, int id);
void print_menu();
int get_input(char *text);

int main() {
    Student *tail = NULL;
    Student *head = NULL;
    int option = 0;
    int id;
    int mathGrade;
    int scienceGrade;
    int getId;

    push_student(&tail, 1, 10, 10);
    push_student(&tail, 2, 9, 9);
    push_student(&tail, 3, 8, 8);
    push_student(&tail, 4, 7, 7);
    push_student(&tail, 5, 6, 6);

    //inser_student_after_id(&tail, 2, 6, 10, 10);
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

            inser_student_after_id(&tail, getId, id, mathGrade, scienceGrade);
            printf("Inserted new student with ID: %d\n", id);
            break;
        case 2: // display Student's info
            display_students_list(tail);
            break;
        case 3:
            id = get_input("Student's ID to delete: ");
            delete_student_by_id(&tail, id);
            printf("Student with ID: %d deleted.\n", id);
            break;
        
        default:
            break;
        }
    }
    printf("Exiting program...");

    deallocate(&tail, &head);

    return 0;
}

void inser_student_after_id(Student **tail, int afterID, int id, int mathGrade, int scienceGrade) {
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        exit(1);
    }
    newStudent->id = id;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;

    Student *current = *tail;
    while (current != NULL) {
        if (current->id == afterID) {
            Student *temp = current->nextStudent;
            current->nextStudent = newStudent;
            newStudent->prevStudent = current;
            newStudent->nextStudent = temp;
            temp->prevStudent = newStudent;
            printf("Inserted Student with ID %d after student with ID %d\n", id, afterID);
            return;
        }
        current = current->nextStudent;
    }
    printf("Unable to find student with ID %d\n", afterID);
}

void push_student(Student **tail, int id, int mathGrade, int scienceGrade) {
    /*
        Enter a student to the beginning of the list
    */
   Student *newStudent = malloc(sizeof(Student));
   if (newStudent == NULL) {
    exit(1);
   }
   
   newStudent->prevStudent = NULL;
   newStudent->id = id;
   newStudent->mathMark = mathGrade;
   newStudent->scienceMark = scienceGrade;
   newStudent->nextStudent = *tail;
   if (*tail != NULL) {
    (*tail)->prevStudent = newStudent;
   }
   *tail = newStudent;
}

void delete_student_by_id(Student **tail, int id) {
    if (*tail == NULL) {
        return;
    }

    Student *current = *tail;

    // If the head needs to be deleted
    if (current->id == id) {
        *tail = current->nextStudent;
        if (*tail != NULL) {
            (*tail)->prevStudent = NULL;
        }
        free(current);
        return;
    }

    // Traverse the list to find the student to delete
    while (current != NULL) {
        if (current->nextStudent != NULL && current->nextStudent->id == id) {
            Student *studentToDelete = current->nextStudent;
            current->nextStudent = studentToDelete->nextStudent;

            if (studentToDelete->nextStudent != NULL) {
                studentToDelete->nextStudent->prevStudent = current;
            }

            free(studentToDelete);
            return;
        }
        current = current->nextStudent;
    }
}

void deallocate(Student **tail, Student **head) {
    if (*tail == NULL) {
        return;
    }
    Student *current = *tail;
    while(current->nextStudent != NULL) {
        current = current->nextStudent;
        free(current->prevStudent);
    }
    free(current);
    *tail = NULL;
    *head = NULL;
}

void display_students_list(Student *tail) {
    Student *current = tail;
    while (current != NULL) {
        printf("============ Student's ID: %d ============\n", current->id);
        printf("Math grade: %d\n", current->mathMark);
        printf("Science grade: %d\n", current->scienceMark);
        printf("==========================================\n");
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

int get_input(char *text) {
    int mark = 0;
    printf("%s: ", text);
    scanf("%d", &mark);
    return mark;
}
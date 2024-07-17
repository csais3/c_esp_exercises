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

void init_list(Student **tail, Student **head, int studentID, 
                    int mathGrade, int scienceGrade);
void inser_student_after_id(Student **tail, int afterID, int id, int mathGrade, int scienceGrade);
void deallocate(Student **tail, Student **head);
void push_student(Student **tail, int id, int mathGrade, int scienceGrade);
void append_student(Student**root, int id, int mathGrade, int scienceGrade);
void insert_after(Student *insertAfter, int id, int mathGrade, int scienceGrade);
void display_students_list(Student *tail);
void delete_student_by_id(Student **tail, int id);
void print_menu();
int get_input(char *text);

int main() {
    Student *tail = NULL;
    Student *head = NULL;

    init_list(&tail, &head, 1, 10, 10);
    push_student(&tail, 2, 9, 9);
    push_student(&tail, 3, 8, 8);
    push_student(&tail, 5, 7, 7);

    insert_after(tail, 7, 4, 4);

    display_students_list(tail);

    printf("head id: %d\n", head->id);
    
    deallocate(&tail, &head);

    return 0;
}

void init_list(Student **tail, Student **head, int studentID, 
                    int mathGrade, int scienceGrade) {

    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        exit(1);
    }

    newStudent->id = studentID;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    newStudent->nextStudent = NULL;
    newStudent->prevStudent = NULL;

    *tail = newStudent;
    *head = newStudent;
    printf("**Added student with ID %d**\n", studentID);
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

void append_student(Student**head, int id, int mathGrade, int scienceGrade) {
    /*
        Appends student at the end of the list
    */
    Student *newStudent = malloc(sizeof(Student));
    if (newStudent == NULL) {
        exit(1);
    }

    newStudent->id = id;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    newStudent->nextStudent = NULL;
    if (*head == NULL) {
        newStudent->prevStudent = NULL;
        *head = newStudent;
        
    } else {
        newStudent->prevStudent = *head;
        (*head)->nextStudent = newStudent;
        *head = newStudent;
    }

}

void insert_after(Student *insertAfter, int id, int mathGrade, int scienceGrade) {
    Student *newStudent = malloc(sizeof(Student));
    newStudent->id = id;
    newStudent->mathMark = mathGrade;
    newStudent->scienceMark = scienceGrade;
    newStudent->prevStudent = insertAfter;
    newStudent->nextStudent = insertAfter->nextStudent;

    if (insertAfter->nextStudent != NULL) {
        insertAfter->nextStudent->prevStudent = newStudent;
    }
    
    insertAfter->nextStudent = newStudent;
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

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    int mathMark;
    int scienceMark;
    struct Student *nextStudent;
    struct Student *prevStudent;
} Student;

void deallocate(Student **tail, Student **head);

int main() {
    Student *tail = malloc(sizeof(Student));
    if (tail == NULL){
        exit(1);
    }
    tail->id = 1;
    tail->mathMark = 10;
    tail->scienceMark = 10;
    tail->prevStudent = NULL;
    tail->nextStudent = malloc(sizeof(Student));
    if (tail->nextStudent == NULL) {
        exit(1);
    }
    tail->nextStudent->id = 2;
    tail->nextStudent->mathMark = 9;
    tail->nextStudent->scienceMark = 9;
    tail->nextStudent->prevStudent = tail;
    tail->nextStudent->nextStudent = malloc(sizeof(Student));
    if (tail->nextStudent->nextStudent == NULL) {
        exit(1);
    }
    tail->nextStudent->nextStudent->id = 3;
    tail->nextStudent->nextStudent->mathMark = 8;
    tail->nextStudent->nextStudent->scienceMark = 8;
    tail->nextStudent->nextStudent->prevStudent = tail->nextStudent;
    tail->nextStudent->nextStudent->nextStudent = NULL;
    Student *head = tail->nextStudent->nextStudent;

    Student *current = head;
    while (current != NULL) {
        printf("Student's ID: %d\n", current->id);
        printf("Student's Math Grade: %d\n", current->mathMark);
        printf("Student's Science Grade: %d\n", current->scienceMark);
        current = current->prevStudent;
    }

    deallocate(&tail, &head);
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
        printf("Student's ID: %d\n", current->id);
        printf("Student's Math Grade: %d\n", current->mathMark);
        printf("Student's Science Grade: %d\n", current->scienceMark);
    }
}
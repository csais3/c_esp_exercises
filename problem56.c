#include <stdio.h>
#include <stdlib.h>

/*
    Create a linked list for the following structure and get user inputs of
    id, Maths mark, Science Mark. Once the user inputs id as -1 exit the
    input mode and display all the entries.
*/

typedef struct Student {
    int id;
    int maths;
    int science;
    struct Student *nextPtr;
} Student;

void print_linked_list(Student *root);
int get_input(char *text);

int main() {
    int studentId = 0, mathMark = 0, scienceMark = 0;
    Student *root = NULL, *current = NULL, *newStudent;

    while (1) {
        // Allocate memory for a new Student
        newStudent = (Student *)malloc(sizeof(Student));
        if (newStudent == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter student's information.\n");
        printf("To end program, add Student's ID as -1\n");

        // get user input
        studentId = get_input("Student's ID");
        if (studentId == -1) {
            free(newStudent); // free the last allocated memory as it's not needed
            break;
        }

        mathMark = get_input("Math mark");
        scienceMark = get_input("Science mark");

        // Initialize new student data
        newStudent->id = studentId;
        newStudent->maths = mathMark;
        newStudent->science = scienceMark;
        newStudent->nextPtr = NULL;

        // Add new student to the list
        if (root == NULL) {
            root = newStudent;
        } else {
            current->nextPtr = newStudent;
        }
        current = newStudent;
    }
    printf("=============================\n");
    print_linked_list(root);

    // Free allocated memory
    current = root;
    while (current != NULL) {
        Student *temp = current;
        current = current->nextPtr;
        free(temp);
    }

    return 0;
}

void print_linked_list(Student *root) {
    Student *current = root;
    while (current != NULL) {
        printf("Student's ID: %d\n", current->id);
        printf("Math Mark: %d\n", current->maths);
        printf("Science Mark: %d\n", current->science);
        printf("=============================\n");
        current = current->nextPtr;
    }
}

int get_input(char *text) {
    int mark = 0;
    printf("%s: ", text);
    scanf("%d", &mark);
    return mark;
}

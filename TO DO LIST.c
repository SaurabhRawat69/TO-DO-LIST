#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

// Structure to hold a task
typedef struct {
    char task[TASK_LENGTH];
} Task;

// Function prototypes
void addTask(Task tasks[], int *taskCount);
void viewTasks(Task tasks[], int taskCount);
void deleteTask(Task tasks[], int *taskCount);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount < MAX_TASKS) {
        printf("Enter the task: ");
        fgets(tasks[*taskCount].task, TASK_LENGTH, stdin);
        tasks[*taskCount].task[strcspn(tasks[*taskCount].task, "\n")] = 0; // Remove newline character
        (*taskCount)++;
        printf("Task added successfully!\n");
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
}

void viewTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks in the list.\n");
    } else {
        printf("\nTo-Do List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i].task);
        }
    }
}

void deleteTask(Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int taskNum;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNum);
    getchar(); // Clear the newline character from input buffer

    if (taskNum < 1 || taskNum > *taskCount) {
        printf("Invalid task number.\n");
    } else {
        for (int i = taskNum - 1; i < *taskCount - 1; i++) {
            tasks[i] = tasks[i + 1]; // Shift tasks to the left
        }
        (*taskCount)--;
        printf("Task deleted successfully!\n");
    }
}

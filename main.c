#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    while (1) {
        printf("\n--- LOGISTICS MANAGEMENT SYSTEM ---\n");
        printf(" 1. Add City\n 2. Set Distance\n 3. Display Distance Matrix\n 4. Add Delivery\n 5. Generate Report\n 0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 0: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

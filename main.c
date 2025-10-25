#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_CITIES 30
#define MAX_NAME_LEN 50


typedef struct {
    char name[MAX_NAME_LEN];
} City;

City cities[MAX_CITIES];
int cityCount = 0;


void addCity();
void listCities();



int main()
{
    int choice;
    while (1) {
        printf("\n--- LOGISTICS MANAGEMENT SYSTEM ---\n");
        printf(" 1. Add City\n 2. Set Distance\n 3. Display Distance Matrix\n 4. Add Delivery\n 5. Generate Report\n 0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addCity();
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

void addCity() {
    if (cityCount >= MAX_CITIES) {
        printf("City limit reached.\n");
        return;
    }
    printf("Enter city name: ");
    scanf("%s", cities[cityCount].name);
    cityCount++;
}

void listCities() {
    printf("Cities:\n");
    for (int i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i, cities[i].name);
    }
}




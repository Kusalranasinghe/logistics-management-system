#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_CITIES 30
#define MAX_NAME_LEN 50
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0




typedef struct {
    char name[MAX_NAME_LEN];
} City;

typedef struct {
    char type[10];
    int capacity;
    float ratePerKm;
    float speed;
    float efficiency;
} Vehicle;

typedef struct {
    int source;
    int destination;
    int weight;
    int vehicleType;
    float distance;
    float deliveryCost;
    float fuelUsed;
    float fuelCost;
    float totalCost;
    float profit;
    float customerCharge;
    float time;
} Delivery;


City cities[MAX_CITIES];
int cityCount = 0;
int distanceMatrix[MAX_CITIES][MAX_CITIES];

Vehicle vehicles[3] = {
    {"Van", 1000, 30, 60, 12},
    {"Truck", 5000, 40, 50, 6},
    {"Lorry", 10000, 80, 45, 4}
};

Delivery deliveries[MAX_DELIVERIES];
int deliveryCount = 0;

void addCity();
void listCities();
void setDistance();
void displayDistanceMatrix();
void addDelivery();


int main()
{
    int choice;
    while (1) {
        printf("\n--- LOGISTICS MANAGEMENT SYSTEM ---\n");
        printf(" 1. Add City\n 2. Set Distance\n 3. Display Distance Matrix\n 4. Add Delivery\n 5. Generate Report\n 0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addCity(); break;
            case 2: setDistance(); break;
            case 3: displayDistanceMatrix(); break;
            case 4: addDelivery(); break;
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

void setDistance() {
    int i, j, d;
    listCities();
    printf("Enter source city index: ");
    scanf("%d", &i);
    printf("Enter destination city index: ");
    scanf("%d", &j);
    if (i == j) {
        printf("Distance to same city is 0.\n");
        distanceMatrix[i][j] = 0;
        return;
    }
    printf("Enter distance between %s and %s: ", cities[i].name, cities[j].name);
    scanf("%d", &d);
    distanceMatrix[i][j] = d;
    distanceMatrix[j][i] = d;
}

void displayDistanceMatrix() {
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < cityCount; i++) {
        for (int j = 0; j < cityCount; j++) {
            printf("%4d ", distanceMatrix[i][j]);
        }
        printf("\n");
    }
}

void addDelivery() {
    if (deliveryCount >= MAX_DELIVERIES) {
        printf("Delivery limit reached.\n");
        return;
    }

    int src, dest, weight, vType;
    listCities();
    printf("Enter source city index: ");
    scanf("%d", &src);
    printf("Enter destination city index: ");
    scanf("%d", &dest);
    if (src == dest) {
        printf("Source and destination cannot be the same.\n");
        return;
    }

    printf("Enter weight (kg): ");
    scanf("%d", &weight);
    printf("Select vehicle (0=Van, 1=Truck, 2=Lorry): ");
    scanf("%d", &vType);

    if (weight > vehicles[vType].capacity) {
        printf("Weight exceeds vehicle capacity.\n");
        return;
    }




}




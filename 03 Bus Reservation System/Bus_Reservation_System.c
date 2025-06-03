#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 100
#define MAX_SEATS 40

typedef struct {
    char name[50];
    char contact[15];
} Passenger;

typedef struct {
    char busNumber[10];
    char origin[30];
    char destination[30];
    char departureTime[10];
    char arrivalTime[10];
    Passenger seats[MAX_SEATS];
    int reserved[MAX_SEATS];
} Bus;

Bus buses[MAX_BUSES];
int busCount = 0;

// Preload Maharashtra buses
void preloadMaharashtraBuses() {
    strcpy(buses[0].busNumber, "MH101");
    strcpy(buses[0].origin, "Mumbai");
    strcpy(buses[0].destination, "Pune");
    strcpy(buses[0].departureTime, "07:00");
    strcpy(buses[0].arrivalTime, "10:00");
    for (int i = 0; i < MAX_SEATS; i++) buses[0].reserved[i] = 0;

    strcpy(buses[1].busNumber, "MH102");
    strcpy(buses[1].origin, "Pune");
    strcpy(buses[1].destination, "Nagpur");
    strcpy(buses[1].departureTime, "20:00");
    strcpy(buses[1].arrivalTime, "08:00");
    for (int i = 0; i < MAX_SEATS; i++) buses[1].reserved[i] = 0;

    strcpy(buses[2].busNumber, "MH103");
    strcpy(buses[2].origin, "Mumbai");
    strcpy(buses[2].destination, "Aurangabad");
    strcpy(buses[2].departureTime, "18:30");
    strcpy(buses[2].arrivalTime, "23:30");
    for (int i = 0; i < MAX_SEATS; i++) buses[2].reserved[i] = 0;

    busCount = 3;
}

void addBus() {
    if (busCount >= MAX_BUSES) {
        printf("Cannot add more buses. Database is full.\n");
        return;
    }

    Bus newBus;
    printf("Enter bus number: ");
    scanf("%s", newBus.busNumber);
    printf("Enter origin location: ");
    scanf("%s", newBus.origin);
    printf("Enter destination location: ");
    scanf("%s", newBus.destination);
    printf("Enter departure time (HH:MM): ");
    scanf("%s", newBus.departureTime);
    printf("Enter arrival time (HH:MM): ");
    scanf("%s", newBus.arrivalTime);

    for (int i = 0; i < MAX_SEATS; i++) {
        newBus.reserved[i] = 0; // All seats initially unreserved
    }

    buses[busCount++] = newBus;
    printf("Bus added successfully!\n");
}

void displayBuses() {
    if (busCount == 0) {
        printf("No buses available.\n");
        return;
    }

    printf("\nAvailable Buses:\n");
    printf("-------------------------------------------------------------\n");
    printf("| Bus Number | Origin      | Destination  | Dep Time | Arr Time |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < busCount; i++) {
        printf("| %-11s | %-11s | %-12s | %-8s | %-8s |\n",
               buses[i].busNumber,
               buses[i].origin,
               buses[i].destination,
               buses[i].departureTime,
               buses[i].arrivalTime);
    }
    printf("-------------------------------------------------------------\n");
}

void reserveSeat() {
    char busNumber[10];
    int seatNumber;

    if (busCount == 0) {
        printf("No buses available for reservation.\n");
        return;
    }

    printf("Enter bus number: ");
    scanf("%s", busNumber);

    Bus *selectedBus = NULL;
    for (int i = 0; i < busCount; i++) {
        if (strcmp(buses[i].busNumber, busNumber) == 0) {
            selectedBus = &buses[i];
            break;
        }
    }

    if (selectedBus == NULL) {
        printf("Bus not found.\n");
        return;
    }

    printf("Enter seat number to reserve (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number. Please select between 1 and %d.\n", MAX_SEATS);
        return;
    }

    if (selectedBus->reserved[seatNumber - 1] == 1) {
        printf("Seat %d is already reserved. Please choose another seat.\n", seatNumber);
    } else {
        printf("Enter passenger name: ");
        scanf(" %[^\n]", selectedBus->seats[seatNumber - 1].name);
        printf("Enter passenger contact number: ");
        scanf("%s", selectedBus->seats[seatNumber - 1].contact);

        selectedBus->reserved[seatNumber - 1] = 1; // Reserve the seat
        printf("Seat %d reserved successfully on bus %s.\n", seatNumber, selectedBus->busNumber);
    }
}

void displayReservations() {
    char busNumber[10];

    if (busCount == 0) {
        printf("No buses available.\n");
        return;
    }

    printf("Enter bus number to display reservations: ");
    scanf("%s", busNumber);

    Bus *selectedBus = NULL;
    for (int i = 0; i < busCount; i++) {
        if (strcmp(buses[i].busNumber, busNumber) == 0) {
            selectedBus = &buses[i];
            break;
        }
    }

    if (selectedBus == NULL) {
        printf("Bus not found.\n");
        return;
    }

    printf("\nReservations for Bus %s:\n", selectedBus->busNumber);
    printf("------------------------------------------------\n");
    printf("| Seat Number | Passenger Name      | Contact   |\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (selectedBus->reserved[i] == 1) {
            printf("| %-11d | %-19s | %-9s |\n",
                   i + 1,
                   selectedBus->seats[i].name,
                   selectedBus->seats[i].contact);
        }
    }
    printf("------------------------------------------------\n");
}

int main() {
    preloadMaharashtraBuses();

    int choice;
    do {
        printf("\nBus Reservation System\n");
        printf("1. Add Bus\n");
        printf("2. Display Buses\n");
        printf("3. Reserve a Seat\n");
        printf("4. Display Reservations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBus(); break;
            case 2: displayBuses(); break;
            case 3: reserveSeat(); break;
            case 4: displayReservations(); break;
            case 5: printf("Thank you for Visiting !\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


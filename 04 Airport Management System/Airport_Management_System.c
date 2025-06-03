#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char flightNumber[10];
    char departure[30];
    char destination[30];
    char departureTime[10];
    char arrivalTime[10];
} Flight;

Flight flights[100];
int flightCount = 0;

// Pre-load flights into the system
void preloadFlights() {
    strcpy(flights[0].flightNumber, "AI101");
    strcpy(flights[0].departure, "NewYork");
    strcpy(flights[0].destination, "London");
    strcpy(flights[0].departureTime, "08:30");
    strcpy(flights[0].arrivalTime, "15:45");

    strcpy(flights[1].flightNumber, "BA202");
    strcpy(flights[1].departure, "London");
    strcpy(flights[1].destination, "Paris");
    strcpy(flights[1].departureTime, "10:00");
    strcpy(flights[1].arrivalTime, "11:30");

    strcpy(flights[2].flightNumber, "UA303");
    strcpy(flights[2].departure, "Paris");
    strcpy(flights[2].destination, "Berlin");
    strcpy(flights[2].departureTime, "12:45");
    strcpy(flights[2].arrivalTime, "14:00");

    strcpy(flights[3].flightNumber, "LH404");
    strcpy(flights[3].departure, "Berlin");
    strcpy(flights[3].destination, "Rome");
    strcpy(flights[3].departureTime, "15:15");
    strcpy(flights[3].arrivalTime, "17:00");

    strcpy(flights[4].flightNumber, "AF505");
    strcpy(flights[4].departure, "Rome");
    strcpy(flights[4].destination, "Madrid");
    strcpy(flights[4].departureTime, "18:20");
    strcpy(flights[4].arrivalTime, "20:00");

    flightCount = 5;
}

void addFlight() {
    if (flightCount >= 100) {
        printf("Cannot add more flights. Database is full.\n");
        return;
    }
    Flight newFlight;
    printf("Enter flight number: ");
    scanf("%s", newFlight.flightNumber);
    printf("Enter departure location: ");
    scanf("%s", newFlight.departure);
    printf("Enter destination location: ");
    scanf("%s", newFlight.destination);
    printf("Enter departure time (HH:MM): ");
    scanf("%s", newFlight.departureTime);
    printf("Enter arrival time (HH:MM): ");
    scanf("%s", newFlight.arrivalTime);

    flights[flightCount++] = newFlight;
    printf("Flight added successfully!\n");
}

void displayFlights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }
    printf("\nFlight List:\n");
    printf("-------------------------------------------------------------\n");
    printf("| Flight Number | Departure | Destination | Dep Time | Arr Time |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < flightCount; i++) {
        printf("| %-13s | %-9s | %-11s | %-8s | %-8s |\n",
               flights[i].flightNumber,
               flights[i].departure,
               flights[i].destination,
               flights[i].departureTime,
               flights[i].arrivalTime);
    }
    printf("-------------------------------------------------------------\n");
}

void searchFlight() {
    char flightNumber[10];
    printf("Enter flight number to search: ");
    scanf("%s", flightNumber);
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            printf("\nFlight Found:\n");
            printf("Flight Number: %s\n", flights[i].flightNumber);
            printf("Departure: %s\n", flights[i].departure);
            printf("Destination: %s\n", flights[i].destination);
            printf("Departure Time: %s\n", flights[i].departureTime);
            printf("Arrival Time: %s\n", flights[i].arrivalTime);
            return;
        }
    }
    printf("Flight not found.\n");
}

int main() {
    preloadFlights();
    do {
        int choice;
        printf("\nAirport Management System\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Search Flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addFlight(); break;
            case 2: displayFlights(); break;
            case 3: searchFlight(); break;
            case 4:
                printf("Thank you For Visiting !\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                continue; // skip back prompt and show menu again
        }


    } while (1);

    return 0;
}


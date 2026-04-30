#include <stdio.h>
#include <string.h>

struct Room {
    int roomNumber;
    char guestName[50];
    int isBooked;
};

struct Room rooms[5];

// Initialize rooms
void initRooms() {
    for(int i = 0; i < 5; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = 0;
        strcpy(rooms[i].guestName, "");
    }
}

// Book a room
void bookRoom() {
    int room;
    printf("Enter room number (1-5): ");
    scanf("%d", &room);

    if(room < 1 || room > 5) {
        printf("Invalid room number!\n");
        return;
    }

    if(rooms[room - 1].isBooked) {
        printf("Room already booked!\n");
    } else {
        printf("Enter guest name: ");
        scanf("%s", rooms[room - 1].guestName);
        rooms[room - 1].isBooked = 1;
        printf("Room booked successfully!\n");
    }
}

// View all rooms
void viewRooms() {
    printf("\nRoom Status:\n");
    for(int i = 0; i < 5; i++) {
        printf("Room %d - %s",
            rooms[i].roomNumber,
            rooms[i].isBooked ? "Booked" : "Available");

        if(rooms[i].isBooked) {
            printf(" (Guest: %s)", rooms[i].guestName);
        }
        printf("\n");
    }
}

// Search guest
void searchGuest() {
    char name[50];
    printf("Enter guest name to search: ");
    scanf("%s", name);

    for(int i = 0; i < 5; i++) {
        if(strcmp(rooms[i].guestName, name) == 0) {
            printf("Guest found in Room %d\n", rooms[i].roomNumber);
            return;
        }
    }
    printf("Guest not found!\n");
}

int main() {
    int choice;
    initRooms();

    while(1) {
        printf("\n--- Hotel Management System ---\n");
        printf("1. Book Room\n");
        printf("2. View Rooms\n");
        printf("3. Search Guest\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: bookRoom(); break;
            case 2: viewRooms(); break;
            case 3: searchGuest(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

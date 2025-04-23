#include <stdio.h>
#include <string.h>

// Define a structure for Date of Birth (Nested Structure)
struct Date {
    int day;
    int month;
    int year;
};

// Define the main structure for Player details
struct Player {
    char name[1];
    int id;
    struct Date dob; // Nested structure for Date of Birth
    int age;
    float salary;
};

int main() {
    int numPlayers, i;

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    // Declare an array of Player structures to store multiple player details
    struct Player players[numPlayers];

    // Input details for each player
    printf("\nEnter player details:\n");
    for (i = 0; i < numPlayers; i++) {
        printf("\n--- Player %d ---\n", i + 1);

        printf("Enter Name: ");
        // Clear the input buffer before reading a string
        while (getchar() != '\n');
        fgets(players[i].name, sizeof(players[i].name), stdin);
        // Remove trailing newline character if present
        players[i].name[strcspn(players[i].name, "\n")] = 0;

        printf("Enter ID: ");
        scanf("%d", &players[i].id);

        printf("Enter Date of Birth (day month year): ");
        scanf("%d %d %d", &players[i].dob.day, &players[i].dob.month, &players[i].dob.year);

        printf("Enter Age: ");
        scanf("%d", &players[i].age);

        printf("Enter Salary: ");
        scanf("%f", &players[i].salary);
    }

    // Display the entered player details
    printf("\n--- Player Details ---\n");
    for (i = 0; i < numPlayers; i++) {
        printf("\n--- Player %d ---\n", i + 1);
        printf("Name: %s\n", players[i].name);
        printf("ID: %d\n", players[i].id);
        printf("Date of Birth: %d/%d/%d\n", players[i].dob.day, players[i].dob.month, players[i].dob.year);
        printf("Age: %d\n", players[i].age);
        printf("Salary: %.2f\n", players[i].salary);
    }

    return 0;
}

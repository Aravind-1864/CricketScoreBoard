#include <stdio.h>
#include <string.h>

struct Team {
    char name[50];
    int runs;
    int wickets;
    float oversPlayed;
};

void enterScore(struct Team *team, int totalOvers) {
    printf("\n--- Enter Score for %s ---\n", team->name);
    printf("Enter runs scored: ");
    scanf("%d", &team->runs);
    printf("Enter wickets fallen: ");
    scanf("%d", &team->wickets);
    printf("Enter overs played (max %d): ", totalOvers);
    scanf("%f", &team->oversPlayed);

    if(team->oversPlayed > totalOvers) {
        printf("⚠ Overs cannot exceed total match overs! Setting to %d.\n", totalOvers);
        team->oversPlayed = totalOvers;
    }
    if(team->wickets > 10) {
        printf("⚠ Wickets cannot be more than 10! Setting to 10.\n");
        team->wickets = 10;
    }
}

void displayScore(struct Team team, int totalOvers) {
    printf("\n📊 Scorecard for %s:\n", team.name);
    printf("Runs: %d\n", team.runs);
    printf("Wickets: %d/10\n", team.wickets);
    printf("Overs Played: %.1f / %d\n", team.oversPlayed, totalOvers);
    printf("Run Rate: %.2f\n", (team.oversPlayed > 0) ? team.runs / team.oversPlayed : 0.0);
}

void matchResult(struct Team team1, struct Team team2) {
    printf("\n🏆 Final Match Result:\n");

    if(team1.runs > team2.runs) {
        printf("%s won the match by %d runs!\n", team1.name, team1.runs - team2.runs);
    } 
    else if(team2.runs > team1.runs) {
        printf("%s won the match by %d runs!\n", team2.name, team2.runs - team1.runs);
    } 
    else {
        printf("The match is a Tie/Draw!\n");
    }
}

int main() {
    struct Team team1, team2;
    int totalOvers, choice;

    printf("🏏 Welcome to Cricket Score Board 🏏\n");

    printf("Enter Team 1 name: ");
    scanf("%s", team1.name);
    printf("Enter Team 2 name: ");
    scanf("%s", team2.name);
    printf("Enter total overs for the match: ");
    scanf("%d", &totalOvers);

    team1.runs = team1.wickets = 0;
    team1.oversPlayed = 0.0;
    team2.runs = team2.wickets = 0;
    team2.oversPlayed = 0.0;

    do {
        printf("\n===== Cricket Score Board Menu =====\n");
        printf("1. Enter/Update %s Score\n", team1.name);
        printf("2. Enter/Update %s Score\n", team2.name);
        printf("3. Display Scorecard\n");
        printf("4. Show Match Result (Winner)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enterScore(&team1, totalOvers);
                break;
            case 2:
                enterScore(&team2, totalOvers);
                break;
            case 3:
                displayScore(team1, totalOvers);
                displayScore(team2, totalOvers);
                break;
            case 4:
                displayScore(team1, totalOvers);
                displayScore(team2, totalOvers);
                matchResult(team1, team2);
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}

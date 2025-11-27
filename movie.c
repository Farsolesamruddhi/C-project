
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"

Movie GetMovieDetails() {
    Movie m;
    printf("Enter movie name: ");
    fgets(m.movieName, sizeof(m.movieName), stdin);

    // Remove newline character if present
    size_t len = strlen(m.movieName);
    if (len > 0 && m.movieName[len - 1] == '\n')
        m.movieName[len - 1] = '\0';

    printf("Enter duration (in minutes): ");
    scanf_s("%d", &m.duration);
    (void)getchar(); // consume newline

    printf("Enter category (2D/3D): ");
    fgets(m.category, sizeof(m.category), stdin);

    // Remove newline if present
    len = strlen(m.category);
    if (len > 0 && m.category[len - 1] == '\n')
        m.category[len - 1] = '\0';

    m.ticketCost = 0; // initialize
    return m;
}

char* GetCircleDetails() {
    static char circle[10];
    printf("Enter circle type (gold/silver): ");
    fgets(circle, sizeof(circle), stdin);

    size_t len = strlen(circle);
    if (len > 0 && circle[len - 1] == '\n')
        circle[len - 1] = '\0';

    return circle;
}

int CalculateTicketCost(Movie* m, char circle[]) {
    int validCategory = (strcmp(m->category, "2D") == 0 || strcmp(m->category, "3D") == 0);
    int validCircle = (strcmp(circle, "gold") == 0 || strcmp(circle, "silver") == 0);

    if (!validCategory && !validCircle)
        return -3; // both invalid
    if (!validCategory)
        return -1; // category invalid
    if (!validCircle)
        return -2; // circle invalid

    if (strcmp(circle, "gold") == 0 && strcmp(m->category, "2D") == 0)
        m->ticketCost = 300;
    else if (strcmp(circle, "gold") == 0 && strcmp(m->category, "3D") == 0)
        m->ticketCost = 500;
    else if (strcmp(circle, "silver") == 0 && strcmp(m->category, "2D") == 0)
        m->ticketCost = 250;
    else if (strcmp(circle, "silver") == 0 && strcmp(m->category, "3D") == 0)
        m->ticketCost = 450;

    return 0; 
}

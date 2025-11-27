
#ifndef MOVIE_H
#define MOVIE_H

typedef struct {
    char movieName[50];
    int duration;      // in minutes
    char category[5];  // "2D" or "3D"
    int ticketCost;
} Movie;

Movie GetMovieDetails();
char* GetCircleDetails();
int CalculateTicketCost(Movie* m, char circle[]);

#endif


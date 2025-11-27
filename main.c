
#include <stdio.h>
#include "movie.h"

int main() {
    Movie m = GetMovieDetails();
    char* circle = GetCircleDetails();

    int result = CalculateTicketCost(&m, circle);

    if (result == 0) {
        printf("The ticket cost is %d\n", m.ticketCost);
    }
    else if (result == -1) {
        printf("Sorry there is no %s type of category in the theatre\n", m.category);
    }
    else if (result == -2) {
        printf("Sorry the circle is invalid\n");
    }
    else if (result == -3) {
        printf("Sorry both circle and category are invalid\n");
    }

    return 0;
}

#include "Events.h"

int main(){
    std::srand(time(NULL));
    Events event;
    Player home_team;
    Player away_team;

    home_team.setPlayerOnTeam();
    away_team.setPlayerOnTeam();
    int inning = 6;
    int out = 3;

    
    event.play(home_team, away_team, inning, out);

    return 0;
}

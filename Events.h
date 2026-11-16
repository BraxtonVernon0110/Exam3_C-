#include <iostream>
#include "Player.h"

class Events{
    private:
        std::string choice;
        bool swing;
        bool strike;
        int ball_count = 0;
        int strike_count = 0;
        int out = 0;
        int inning = 1;
        int home_batter = 0;
        int away_batter = 0;

        bool first_base = false;
        bool second_base = false;
        bool third_base = false;


        int chance = rand() % 100;

    public:
        void batterChoice(Player& team);
        bool batting();
        void pitchingChoice(Player& team);
        bool pitching();
        void count();
        void play(Player& home_team, Player& away_team, int inn, int m_out);
        void single(Player& team);
        void doub(Player& team);
        void triple(Player& team);
        void homerun(Player& team);
        void randomOut();
        void scoreRun(Player& team);

        double player_ab_perc(Player& team, int index);

};
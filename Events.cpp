#include "Events.h"

void Events::batterChoice(Player& team){
    std::cout << "  Your move [swing / watch / count / batter%]: ";
    std::cin >> choice;
    if (choice == "count" || choice == "Count"){
        count();
    }

    else if (choice == "Batter%" || choice == "batter%"){
        std::cout << team.getPlayerOnTeam(home_batter) << ": " << player_ab_perc(team, home_batter) << std::endl;
    }

    else if (batting()){
        if (chance < 30){
            strike_count = 0;
            ball_count = 0;
            team.set_at_bats(home_batter);
            team.set_hits(home_batter);
            std::cout << "  Result: Hit! ";
            int hit_chance = rand() % 100;
            if (hit_chance < 50){
                single(team);
                std::cout << "Single." << std::endl;
            }
            else if(hit_chance < 80){
                doub(team);
                std::cout << "Double." << std::endl;
            }
            else if(hit_chance < 95){
                homerun(team);
                std::cout << "Home run!" << std::endl;
            }
            else{
                triple(team);
                std::cout << "Triple." << std::endl;
            }
            home_batter = (home_batter + 1) % 9;
        }
        else if (chance <= 71){
            team.set_at_bats(home_batter);
            strike_count = 0;
            ball_count = 0;
            out++;
            randomOut();
            home_batter = (home_batter + 1) % 9; 
        }
        else{
            strike_count++;
            std::cout << "  Result: Swing and a miss. Strike!" << std::endl;
        }
    }
    else{
        if (chance <=50){
            ball_count++;
            std::cout << "  Result: Ball." << std::endl;
        }
        else{
            team.at_bats_percantage(home_batter);
            strike_count++;
            std::cout << "  Result: Strike." << std::endl;
        }
    }
    if (strike_count == 3){
        strike_count = 0;
        ball_count = 0;
        team.set_at_bats(home_batter);
        out++;
        std::cout << "StrikeOut!" << std::endl;
        home_batter = (home_batter + 1) % 9;
    }
    if (ball_count == 4){
        strike_count = 0; 
        ball_count = 0;
        single(team);
        home_batter = (home_batter + 1) % 9;
        std::cout << "Walked!" << std::endl;
    }
}


bool Events::batting(){
    if (choice == "swing" || choice == "Swing"){
        swing = true;
    }
    else{
        swing = false;
    }
    return swing;
}

void Events::pitchingChoice(Player& team){
    std::cout << "  Your pitch [ball / strike / count / player%]: ";
    std::cin >> choice;

    if (choice == "count" || choice == "Count"){
        count();
    }

    else if (choice == "Player%" || choice == "player%"){
        std::cout << team.getPlayerOnTeam(away_batter) << ": " << team.at_bats_percantage(away_batter) << std::endl;
    }

    else if (pitching()){
        if (chance < 53){
            strike_count++;
            std::cout << "  Result: Strike." << std::endl;
        }
        else if(chance < 77){
            std::cout << "  Result: Hit! ";
            strike_count = 0;
            ball_count = 0;
            team.set_at_bats(away_batter);
            team.set_hits(away_batter);
            int hit_chance = rand() % 100;
            if (hit_chance < 50){
                single(team);
                std::cout << "Single." << std::endl;
            }
            else if (hit_chance < 80){
                doub(team);
                std::cout << "Double." << std::endl;
            }
            else if (hit_chance < 95){
                homerun(team);
                std::cout << "Home run!" << std::endl;
            }
            else{
                triple(team);
                std::cout << "Triple." << std::endl;
            }
            away_batter = (away_batter + 1) % 9;
        }
        else{
            out++;
            team.set_at_bats(away_batter);
            strike_count = 0;
            ball_count = 0;
            randomOut();
            away_batter = (away_batter + 1) % 9;
        }
    }
    else{
        if (chance <= 47){
            ball_count++;
            std::cout << "  Result: Ball." << std::endl;
        }
        else{
            strike_count++;
            std::cout << "  Result: Strike." << std::endl;
        }
    }
    if (strike_count == 3){
        out++;
        strike_count = 0;
        ball_count = 0;
        team.set_at_bats(away_batter);
        std::cout << "  Strikeout! Batter is out." << std::endl;
        away_batter = (away_batter + 1) % 9;
        
    }
    if (ball_count == 4){
        strike_count = 0;
        ball_count = 0;
        std::cout << "  Walk! Batter takes first base." << std::endl;
        single(team);
        away_batter = (away_batter + 1) % 9;
    }
}

bool Events::pitching(){
    if (choice == "strike" || choice == "Strike"){
        strike = true;
    }
    else{
        strike = false;
    }
    return strike;
}


void Events::count(){
    std::cout << "  Inning: " << inning << "  |  Outs: " << out << '\n';
    std::cout << "  Balls:  " << ball_count << "  |  Strikes: " << strike_count << '\n';
    if (first_base){
        std::cout << "  First base:  " <<  "Occupied" << '\n';
    }
    else{
        std::cout << "  First base: " << "Empty" << '\n';
    }
    if (second_base){
        std::cout << "  Second base: " << "Occupied" << '\n';
    }
    else{
        std::cout << "  Second base: " <<  "Empty"<< '\n';
    }
    if (third_base){
        std::cout << "  Third base:  " <<  "Occupied"  << '\n';
    }
    else{
        std::cout << "  Third base:  " <<  "Empty" << '\n';
    }
    
    
}




void Events::single(Player& team){
    if (third_base){
        team.addRun();
    }
    third_base = second_base;
    second_base = first_base;
    first_base = true;
}



void Events::doub(Player& team){
    if (third_base){
        team.addRun();
    }
    if (second_base){
        team.addRun();
    }
    third_base = first_base;
    first_base = false;
    second_base = true;
}



void Events::triple(Player& team){
    if (third_base){
        team.addRun();
    }
    if (second_base){
        team.addRun();
    }
    if (first_base){
        team.addRun();
    }
    first_base = false;
    second_base = false;
    third_base = true;
}



void Events::homerun(Player& team){
    if (third_base){
        team.addRun();
    }
    if (second_base){
        team.addRun();
    }
    if (first_base){
        team.addRun();
    }
    team.addRun();
    first_base = false;
    second_base = false;
    third_base = false;
}



void Events::randomOut(){
    std::vector<std::string> outs = {
        "Ground ball to shortstop. Throw to first is in time!",
        "Ground ball to second base. Throw to first gets the batter!",
        "Ground ball to third base. A strong throw to first gets the out!",
        "Ground ball to first base. The first baseman steps on the bag!",
        "Ground ball back to the pitcher. Throw to first gets the out!",
        "Bunt fielded by the catcher. Throw to first beats the batter!",
        "Fly ball to right field. Caught for the out!",
        "Fly ball to center field. Caught for the out!",
        "Fly ball to left field. Caught for the out!",
        "Line drive to shortstop. Caught for the out!",
        "Line drive to second base. Caught for the out!",
        "Line drive to third base. Caught for the out!",
        "Line drive to first base. Caught for the out!",
        "Line drive to right field. Caught for the out!",
        "Line drive to center field. Caught for the out!",
        "Line drive to left field. Caught for the out!",
        "Pop-up to the catcher. Caught for the out!",
        "Pop-up to first base. Caught for the out!",
        "Pop-up to second base. Caught for the out!",
        "Pop-up to shortstop. Caught for the out!",
        "Pop-up to third base. Caught for the out!",
        "Deep fly ball to right field. Caught at the warning track!",
        "Shallow fly ball to center field. A diving catch gets the out!",
        "Foul pop-up near third base. Caught before it reaches the stands!"
    };

    int index = rand() % outs.size();
    std::cout << "  Result: " << outs[index] << std::endl;
}



void Events::scoreRun(Player& team){
    team.addRun();
}



double Events::player_ab_perc(Player& team, int index){
    return team.at_bats_percantage(index);
}


void Events::play(Player& home_team, Player& away_team, int inn, int m_out){
    while (inning <= inn){

            std::cout << "  INNING " << inning << " - TOP | YOU ARE PITCHING\n"
                  << "  Score: Home " << home_team.getScore()
                  << "  |  Away " << away_team.getScore() << '\n' << std::endl;

        while (out < m_out){
            std::cout << "\n  At bat: " << away_team.getPlayerOnTeam(away_batter) << std::endl;
            chance = rand() % 100;
            pitchingChoice(away_team);
        }
        first_base = false;
        second_base = false;
        third_base = false;
        out = 0;
        std::cout << "  INNING " << inning << " - BOTTOM | YOU ARE BATTING\n"
                  << "  Score: Home " << home_team.getScore() << "  |  Away " << away_team.getScore() << '\n'<< std::endl;
        while (out < m_out){
            std::cout << "\n  At bat: " << home_team.getPlayerOnTeam(home_batter) << std::endl;
            chance = rand() % 100;
            batterChoice(home_team);
        }
        first_base = false;
        second_base = false;
        third_base = false;
        out = 0;
        inning++;
    }


    std::cout << "  Home (you): " << home_team.getScore() << '\n';
    std::cout << "  Away:       " << away_team.getScore() << '\n';
    std::cout << "  Ball game! Thanks for playing.\n" << std::endl;

}






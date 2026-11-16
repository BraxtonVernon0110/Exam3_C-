#include "Player.h"
#include <cstdlib>
#include <ctime>

std::string random_player(){
    std::vector<std::string> name = {"Herb Reeves","Tessa Levy","Lenora Macias","Elvia Rollins","Ramon Shepherd",
"Tommie Ayala","Ferdinand Rojas","Maribel Rosario","Selena Wyatt","Kurtis Steele","Charlotte Kent","Bradley McClain","Marguerite Espinoza","Rudy Chambers","Darron Herring","Arnoldo Ochoa","Werner Castillo","Giovanni Grimes","Korey Cruz",
"Lamont Everett","Corinne Graham","Candy Mendez","Laurence Barrett","Wilton Cowan","Letitia Barnett","Milford Murray","Lucia Riggs","Jerri Garcia","Modesto Christian","Gilbert Simpson","Erik Doyle","Roger Rosales","Marcelo McKay","Fabian Stewart",
"Estella Russell","Joanne Young","Jewell Andrade","Kathryn Fields","Janna Mann","Nettie Burns","Walter Short","Hayden Summers","Elbert Maxwell","Lula Garrett", "Dana Solis","Douglass Morrow", "Basil Adkins","Jonathan Carter","Patrick Burch","Becky Snow",};

    int index = rand() % name.size();
    return name[index];
}

Player::Player(): player(random_player()), m_hits(1, 0), m_at_bats(1, 0){
    team.push_back(player);
}

Player::Player(std::string name){
    player = name;
    team.push_back(player);
}

std::string Player::getPlayer() const{
    return player;
}

void Player::setPlayerOnTeam(){
    while (team.size() < 9){
        std::string new_player = random_player();
        bool duplicates = false;
        for (int i = 0; i < 10; i++){
            if (team[i] == new_player){
            duplicates = true;
            break;
            }
        }
        if (!duplicates){
            team.push_back(new_player);
            m_hits.push_back(0);
            m_at_bats.push_back(0);
        }
    }
}


void Player::set_at_bats(int index){
    m_at_bats[index] += 1;
}

void Player::set_hits(int index){
    m_hits[index] += 1;
}


double Player::at_bats_percantage(int index) const{
    if (m_at_bats[index] == 0){
        return 0;
    }
    double percent = static_cast<double>(m_hits[index]) / m_at_bats[index];
    return percent;
}

std::string Player::getPlayerOnTeam(const int& index) const{
    return team[index];
}   


void Player::setPlayerPos(){
    std::vector<std::string> position = {"P", "C", "1B", "2B", "SS", "3B", "RF", "CF", "LF"};
    for (int i = 0; i < team.size(); i++){
            int random = rand() % position.size();
            field_pos[team[i]] = position[random];
            position.erase(position.begin() + random);
    }
}

std::string Player::getPosition(const int& index) const{
    return field_pos.at(team[index]);
}

int Player::getScore(){
    return team_score;
}

void Player::addRun(){
    team_score++;
}







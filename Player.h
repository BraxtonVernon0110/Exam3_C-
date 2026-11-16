#include <vector>
#include <map>
#include <string>
#include <iostream>

class Player{
    private:
    std::string player;
    std::vector<std::string> team;
    std::vector<int> m_hits;
    std::vector<int> m_at_bats;
    std::map<std::string, std::string> field_pos;
    
    int team_score = 0;

    public:
    Player();
    Player(std::string player);
    std::string getPlayer() const;
    void setPlayerOnTeam();
    double at_bats_percantage(int index) const;
    std::string getPlayerOnTeam(const int& index) const;
    void setPlayerPos();
    std::string getPosition(const int& index) const;
    int getScore();
    void addRun();
    void set_at_bats(int index);
    void set_hits(int index);
};

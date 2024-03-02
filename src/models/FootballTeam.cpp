//
// Created by m1martin on 06-01-2024.
//

#include "FootballTeam.h"

namespace mar {
// Selection internal class
void FootballTeam::Selection::Write(std::ostream &output) const {
    for (Selection::const_iterator i = begin(); i != end(); i++) {
        (*i)->WriteLine(output);
    }
}

void FootballTeam::Selection::AddPlayers(
    const std::vector<FootballPlayer> &players,
    FootballPlayer::PositionType position, int n) {
    int count = 0;
    for (std::vector<FootballPlayer>::const_iterator i = players.begin();
         i != players.end(); i++) {
        if (!i->Injured() && i->Position() == position) {
            push_back(i);
            count++;
        }
    }
    if (count < n) {
        throw StringBasic("Not enough players.");
    }
}

// Selection end
FootballTeam::FootballTeam(int capacity) : players() {
    players.reserve(capacity);
}

FootballTeam::~FootballTeam() {}

void FootballTeam::Put(const FootballPlayer &p) {
    players.push_back(p);
}

FootballPlayer &FootballTeam::PlayerOf(int number) {
    for (std::vector<FootballPlayer>::iterator i = players.begin();
         i != players.end(); i++) {
        if (i->Number() == number) {
            return *i;
        }
        // throw StringBasic("No player with shirt number " +
        //                   StringBasic::Numeral(number) + ".");
        throw StringBasic("No player with shirt number ");
    }
}

const FootballPlayer &FootballTeam::PlayerOf(int number) const {
    return const_cast<FootballTeam *>(this)->PlayerOf(number);
}

FootballPlayer &FootballTeam::PlayerOf(const StringBasic &name) {
    for (std::vector<FootballPlayer>::iterator i = players.begin();
         i != players.end(); i++) {
        if (i->Name() == name) {
            return *i;
        }
    }
    // throw StringBasic("No player called " + name + ".");
    throw StringBasic("No player called.");
}

const FootballPlayer &FootballTeam::PlayerOf(const StringBasic &name) const {
    return const_cast<FootballTeam *>(this)->PlayerOf(name);
}

void FootballTeam::Write(std::ostream &output) const {
    output << static_cast<unsigned>(players.size()) << std::endl;
    for (std::vector<FootballPlayer>::const_iterator i = players.begin();
         i != players.end(); i++) {
        i->WriteLine(output);
    }
}

void FootballTeam::Read(std::istream &input) {
    int n;
    input >> n;
    SkipLine(input);
    std::cout << n << std::endl;
    players.reserve(n);
    for (int i = 0; i < n; i++) {
        std::cout << i << std::endl;
        FootballPlayer f;
        f.Read(input);
        players.push_back(f);
    }
}

int FootballTeam::CountPlayersOK(FootballPlayer::PositionType position) const {
    int result = 0;
    for (std::vector<FootballPlayer>::const_iterator i = players.begin();
         i != players.end(); i++) {
        if (i->Position() == position && !i->Injured()) {
            result++;
        }
    }
    return result;
}

void FootballTeam::Sort() {
    std::sort(players.begin(), players.end());
    // Sorting criteria: from highest to lowest
    // std::sort(players.begin(), players.end(), [](int a, int b) { return a >
    // b;
    // });
}

FootballTeam::Selection FootballTeam::MakeTeam(int defenders, int midfields,
                                               int forwards) const {
    FootballTeam::Selection result;
    result.reserve(1 + defenders + midfields + forwards);
    result.AddPlayers(players, FootballPlayer::GOALKEEPER, 1);
    result.AddPlayers(players, FootballPlayer::DEFENDER, defenders);
    result.AddPlayers(players, FootballPlayer::MIDFIELD, midfields);
    result.AddPlayers(players, FootballPlayer::FORWARD, forwards);
    return result;
}

} // namespace mar
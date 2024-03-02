//
// Created by m1martin on 06-01-2024.
//

#ifndef PROGRAMACAOCOMCLASSES_FOOTBALLTEAM_H
#define PROGRAMACAOCOMCLASSES_FOOTBALLTEAM_H

#include "FootballPlayer.h"
#include "StringBasic.h"
#include "UtilityFunctions.h"
#include <algorithm>

namespace mar {

class FootballTeam {
public:
    class Selection
        : public std::vector<std::vector<FootballPlayer>::const_iterator> {
    public:
        void Write(std::ostream &output = std::cout) const;
        void AddPlayers(const std::vector<FootballPlayer> &players,
                        FootballPlayer::PositionType position, int n);
    };

private:
    std::vector<FootballPlayer> players;

public:
    FootballTeam(int capacity = 0);
    virtual ~FootballTeam();

    virtual void                  Put(const FootballPlayer &p);
    virtual const FootballPlayer &PlayerOf(const StringBasic &name) const;
    virtual FootballPlayer       &PlayerOf(const StringBasic &name);
    virtual const FootballPlayer &PlayerOf(int x) const;
    virtual FootballPlayer       &PlayerOf(int x);

    virtual void Write(std::ostream &output = std::cout) const;
    virtual void Read(std::istream &input = std::cin);

    virtual void Sort();
    virtual int  CountPlayersOK(FootballPlayer::PositionType position) const;

    virtual Selection MakeTeam(int defenders, int midfields,
                               int forwards) const;
};
} // namespace mar
#endif // PROGRAMACAOCOMCLASSES_FOOTBALLTEAM_H

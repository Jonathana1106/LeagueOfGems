//
// Created by jonathan on 08/11/18.
//

#ifndef LOG_WAR_H
#define LOG_WAR_H


#include<bits/stdc++.h>

struct soldier{

    int life = 125;
    int attack = 1;
    int fastAtack;
    int ID ;
    int location;

};

struct enemy{
    int life = 1000;
    int attack = 15;
    int timeLife;
    int killedSoldier;
    int ID;
    int location;

};

class War {

private:
    static War* instance;
    int numsoldiers;
    int numenemies;
    int level;
    int reg = 0;

    enemy* tempEnemies;
    enemy easyEnemies[20];
    soldier Soldiers[15];

    enemy mediumEnemies[26];
    enemy hardEnemies[36];

public:

    static War* getInstance(int numberEnemies, int numberSoldiers, int difficult);
    static War* getInstance();

    typedef std::pair<int, int> Pair;

    War();

    War(int numberEnemies, int numberSoldiers, int difficult);
    bool attackEnemy(int soldier, int enemy);
    bool attackSoldier(int soldier, int enemy);

    void selection();
    void mergeGene(std::stack<enemy> weakEnemies, std::stack<enemy> strongEnemies);

    int mergeBinary(int strong, int weak);

};


#endif //LOG_WAR_H

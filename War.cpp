//
// Created by jonathan on 08/11/18.
//

#include <stack>
#include "War.h"

War::War(int numberEnemies, int numberSoldiers, int difficult) {

    numsoldiers = numberSoldiers;
    numenemies = numberEnemies;
    level = difficult;
    tempEnemies = new enemy[numberEnemies];

    if(level == 1){
        tempEnemies = easyEnemies;
        for(int i = 0; i < numberEnemies; i++){
            easyEnemies[i].ID = i + 1;
        }
    }
    if(level == 2){
        tempEnemies = easyEnemies;
        for(int i = 0; i < numberEnemies; i++){
            mediumEnemies[i].ID = i + 1;
        }
    }
    if(level == 3){
        tempEnemies = easyEnemies;
        for(int i = 0; i < numberEnemies; i++){
            hardEnemies[i].ID = i + 1;
        }
    }
    for(int i = 0; i < numberSoldiers; i++){
        Soldiers[i].ID = i + 1;
    }
}

bool War::attackEnemy(int soldier, int enemy) {


    if(tempEnemies[enemy - 1].life <= 0){
        std::cout << "Enemy is not alive" << std::endl;
        return true;
    } else{
        tempEnemies[enemy - 1].life -= Soldiers[soldier - 1].attack;
        return tempEnemies[enemy - 1].life <= 0;
    }

}

bool War::attackSoldier(int soldier, int enemy) {

    int life = 0;

    if(tempEnemies[enemy - 1].life <= 0){
        std::cout << "Soldier is not alive" << std::endl;
        return true;
    } else{
        Soldiers[soldier - 1].life -= tempEnemies[enemy - 1].attack;
        if(Soldiers[soldier - 1].life <= 0){
            tempEnemies[enemy - 1].killedSoldier += 1;
            std::cout << "Soldier killed" << std::endl;
        }
        return Soldiers[soldier - 1].life <= 0;
    }
}

void War::selection() {

    int totalEnemies = 0;
    bool usedEnemies[numenemies];
    std::stack<enemy> weakEnemies;
    std::stack<enemy> strongEnemies;

    for(int tempLive = 0; tempLive <= 50; tempLive++){
        if(totalEnemies == numenemies){
            break;
        }
        for(int j = 0; j< numenemies; j++){
            if(tempEnemies[j].life <= tempLive && !usedEnemies[j]){
                if(totalEnemies < numenemies/2){
                    weakEnemies.push(tempEnemies[j]);
                } else{
                    strongEnemies.push(tempEnemies[j]);
                }
                usedEnemies[j] = true;
                totalEnemies++;
            }
        }
    }
    mergeGene(weakEnemies, strongEnemies);

}

void War::mergeGene(std::stack<enemy> weakEnemies, std::stack<enemy> strongEnemies) {
    //auto* weakEnemies = new std::stack<enemy>;
    //auto* strongEnemies = new std::stack<enemy>;

    //std::stack<enemy>* weakEnemies = _weakEnemies;
    //std::stack<enemy>* strongEnemies = _strongEnemies;
    while(!weakEnemies.empty() || !strongEnemies.empty()){
        enemy enemyweak = weakEnemies.top();
        enemy enemystrong= strongEnemies.top();

        std::cout << "Flag " << std::endl;
        tempEnemies[enemyweak.ID - 1].life = mergeBinary(enemystrong.life, enemyweak.life);
        tempEnemies[enemyweak.ID - 1].attack = mergeBinary(enemystrong.attack, enemyweak.attack);


        std::cout << "Weak: " << enemyweak.ID << " live:" << enemyweak.life << " attack:" << enemyweak.attack << std::endl;
        std::cout << "Stronger: " << enemystrong.ID << " live:" << enemystrong.life << " attack:" << enemystrong.attack << std::endl;

        std::cout << "New Weak: " << tempEnemies[enemyweak.ID - 1].ID << " live:" << tempEnemies[enemyweak.ID - 1].life << " attack:" << tempEnemies[enemyweak.ID - 1].attack << std::endl;
        std::cout << "Stronger: " << tempEnemies[enemystrong.ID - 1].ID << " live:" << tempEnemies[enemystrong.ID - 1].life << " attack:" << tempEnemies[enemystrong.ID - 1].attack << std::endl;

        weakEnemies.pop();
        strongEnemies.pop();
    }

}

int War::mergeBinary(int strong, int weak) {
    std::string str2, str3;
    std::string finalBinary;

    std::string binaryStrong = std::bitset<8>(static_cast<unsigned long long int>(strong)).to_string(); //to binary
    std::cout << binaryStrong << std::endl;

    std::string binaryWeak = std::bitset<8>(static_cast<unsigned long long int>(weak)).to_string(); //to binary
    std::cout << binaryWeak << std::endl;

    str2 = binaryStrong.substr(0, 4);
    str3 = binaryWeak.substr(4, 7);

    unsigned long decimal = std::bitset<8>(str2 + str3).to_ulong();
    std::cout<<str2 + str3<< std::endl;
    std::cout<<decimal<< std::endl;

    return static_cast<int>(decimal);
}

War* War::instance = 0;

War *War::getInstance(int numberEnemies, int numberSoldiers, int difficult) {
    std::cout << "Flag " << std::endl;
    if (instance == 0)
    {
        instance = new War(numberEnemies, numberSoldiers, difficult);
    }

    return instance;
}

War *War::getInstance() {
    if (instance == 0)
    {
        instance = new War();
    }

    return instance;
}

War::War() {

}

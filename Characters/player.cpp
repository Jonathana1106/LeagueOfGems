#include "player.h"
#include "../SetUp/TextureManager.h"
#include "../SetUp/Game.h"
#include "../SetUp/Levels.h"

using namespace std;

void player::init(int posX, int posY, int ID) {

    id = ID;
    position.h = position.w = 35;
    position.x = x = posX;
    position.y = y = posY;
    p.second = posX / 35;
    p.first = posY / 35;
    contX = contY = attackLeft = attackRight = 0;
    attackR = attackL = false;
    stat = TextureManager::LoadTexture("../Assets/static.bmp");
    right1 = TextureManager::LoadTexture("../Assets/right1.bmp");
    right2 = TextureManager::LoadTexture("../Assets/right2.bmp");
    right3 = TextureManager::LoadTexture("../Assets/right3.bmp");
    left1 = TextureManager::LoadTexture("../Assets/left1.bmp");
    left2 = TextureManager::LoadTexture("../Assets/left2.bmp");
    left3 = TextureManager::LoadTexture("../Assets/left3.bmp");
    up1 = TextureManager::LoadTexture("../Assets/up1.bmp");
    up2 = TextureManager::LoadTexture("../Assets/up2.bmp");
    up3 = TextureManager::LoadTexture("../Assets/up3.bmp");
    up4 = TextureManager::LoadTexture("../Assets/up4.bmp");
    down1 = TextureManager::LoadTexture("../Assets/Down1.bmp");
    down2 = TextureManager::LoadTexture("../Assets/Down2.bmp");
    down3 = TextureManager::LoadTexture("../Assets/Down3.bmp");
    attackL1 = TextureManager::LoadTexture("../Assets/AttackL1.bmp");
    attackL2 = TextureManager::LoadTexture("../Assets/AttackL2.bmp");
    attackL3 = TextureManager::LoadTexture("../Assets/AttackL3.bmp");
    attackR1 = TextureManager::LoadTexture("../Assets/AttackR1.bmp");
    attackR2 = TextureManager::LoadTexture("../Assets/AttackR2.bmp");
    attackR3 = TextureManager::LoadTexture("../Assets/AttackR3.bmp");
    map = new Map();
    pathfinding = new Pathfinding();
}

void player::move() {
    if(!isattacking) {
        if (position.x < p.second * 35) {
            contX++;
            left = up = down = 0;
            right++;
            leftB = upB = downB = false;
            rightB = true;
            if (contX % 10 == 0) {
                position.x++;
            }
        }

        if (position.x > p.second * 35) {
            contX++;
            right = up = down = 0;
            left++;
            rightB = upB = downB = false;
            leftB = true;
            if (contX % 10 == 0) {
                position.x--;
            }
        }

        if (position.y < p.first * 35) {
            contY++;
            left = right = up = 0;
            down++;
            leftB = rightB = upB = false;
            downB = true;
            if (contY % 10 == 0) {
                position.y++;
            }
        }

        if (position.y > p.first * 35) {
            contY++;
            left = right = down = 0;
            up++;
            leftB = rightB = downB = false;
            upB = true;
            if (contY % 10 == 0) {
                position.y--;
            }
        }

        if (position.y == (y / 35) * 35 && position.x == (x / 35) * 35) {
            rightB = leftB = upB = downB = false;
            right = left = up = down = 0;
        }
    }
}

void player::render() {

    map->DrawMap();
    if (!rightB && !leftB && !upB && !downB && !attackL && !attackR) {
        SDL_RenderCopy(Game::renderer, stat, NULL, &position);
    } else {
        animation();
    }
    attack();
}

void player::animation() {
    if (rightB) {
        if (right <= 150) {
            SDL_RenderCopy(Game::renderer, right1, NULL, &position);
        }
        if (right > 150 && right <= 300) {
            SDL_RenderCopy(Game::renderer, right2, NULL, &position);
        }
        if (right > 300 && right <= 450) {
            SDL_RenderCopy(Game::renderer, right3, NULL, &position);
        }
        if (right > 450 && right <= 600) {
            SDL_RenderCopy(Game::renderer, right2, NULL, &position);
        }
        if (right == 600) {
            right = 0;
        }
    }
    if (leftB) {
        if (left <= 150) {
            SDL_RenderCopy(Game::renderer, left1, NULL, &position);
        }
        if (left > 150 && left <= 300) {
            SDL_RenderCopy(Game::renderer, left2, NULL, &position);
        }
        if (left > 300 && left <= 450) {
            SDL_RenderCopy(Game::renderer, left3, NULL, &position);
        }
        if (left > 450 && left <= 600) {
            SDL_RenderCopy(Game::renderer, left2, NULL, &position);
        }
        if (left == 600) {
            left = 0;
        }
    }
    if (upB) {
        if (up <= 150) {
            SDL_RenderCopy(Game::renderer, up1, NULL, &position);
        }
        if (up > 150 && up <= 300) {
            SDL_RenderCopy(Game::renderer, up2, NULL, &position);
        }
        if (up > 300 && up <= 450) {
            SDL_RenderCopy(Game::renderer, up3, NULL, &position);
        }
        if (up > 450 && up <= 600) {
            SDL_RenderCopy(Game::renderer, up4, NULL, &position);
        }
        if (up > 600 && up <= 750) {
            SDL_RenderCopy(Game::renderer, up3, NULL, &position);
        }
        if (up > 750 && up <= 900) {
            SDL_RenderCopy(Game::renderer, up2, NULL, &position);
        }
        if (up == 900) {
            up = 0;
        }
    }
    if (downB) {
        if (down <= 150) {
            SDL_RenderCopy(Game::renderer, down1, NULL, &position);
        }
        if (down > 150 && down <= 300) {
            SDL_RenderCopy(Game::renderer, down2, NULL, &position);
        }
        if (down > 300 && down <= 450) {
            SDL_RenderCopy(Game::renderer, down3, NULL, &position);
        }
        if (down > 450 && down <= 600) {
            SDL_RenderCopy(Game::renderer, down2, NULL, &position);
        }
        if (down == 600) {
            down = 0;
        }
    }
}

void player::getGem() {
    if (Levels::Level == 1 &&
        ((position.x == 1190 && position.y == 490) || (position.x == 1225 && position.y == 455))) {
        Levels::Level++;
        Levels::next = true;
    }
    if (Levels::Level == 2 && ((position.x == 1190 && position.y == 0) || (position.x == 1225 && position.y == 35))) {
        Levels::Level++;
        Levels::next = true;
    }
    if (Levels::Level == 3 && ((position.x == 1190 && position.y == 210) || (position.x == 1225 && position.y == 245) || (position.x == 1225 && position.y == 175))) {
        Levels::Level++;
        Levels::next = true;
    }
    if (Levels::Level == 4 && ((position.x == 1190 && position.y == 245) || (position.x == 1225 && position.y == 280) || (position.x == 1225 && position.y == 210))) {
        Levels::Level++;
        Levels::next = true;
    }
    if (Levels::Level == 5 && (position.x == 700 && position.y == 210)){
        Levels::Level++;
        Levels::next = true;
    }
    if (Levels::Level == 6 && (position.x == 1155 && position.y == 385)){
        Levels::Level = true;
    }
}

void player::update() {

    if (contX > 1000000) {
        contX = 0;
    }

    if (contY > 1000000) {
        contY = 0;
    }

    SDL_PumpEvents();
    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        SDL_GetMouseState(&x, &y);
        if (y < 525) {
            if (Levels::Level == 1) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 2) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 3) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 4) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else if (Levels::Level == 5) {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            } else {
                path_destiny = pathfinding->start(position.y / 35, position.x / 35, y / 35, x / 35);
            }
        }
    }

    if (!path_destiny.empty()) {
        p = path_destiny.top();
        if (position.x == p.second * 35 && position.y == p.first * 35) {
            path_destiny.pop();
        }
    }

    getGem();
    detectEnemy();
}

void player::detectEnemy() {
    if (Map::map[position.y / 35][(position.x + 35) / 35] > 25 &&
        Map::map[position.y / 35][(position.x + 35) / 35] < 73) {
        enemy = Map::map[position.y / 35][(position.x + 35) / 35];
        isattacking = true;
        attackL = false;
        attackR = true;
        attackRight++;


    } else if (Map::map[position.y / 35][(position.x - 35) / 35] > 25 &&
               Map::map[position.y / 35][(position.x - 35) / 35] < 73) {
        enemy = Map::map[position.y / 35][(position.x - 35) / 35];
        isattacking = true;
        attackL = true;
        attackR = false;
        attackLeft++;

    } else if (Map::map[(position.y - 35) / 35][position.x / 35] > 25 &&
               Map::map[(position.y - 35) / 35][position.x / 35] < 73) {
        enemy = Map::map[(position.y - 35) / 35][position.x / 35];
        isattacking = true;
        attackL = false;
        attackR = true;
        attackRight++;

    } else if (Map::map[(position.y + 35) / 35][position.x / 35] > 25 &&
               Map::map[(position.y + 35) / 35][position.x / 35] < 73) {
        enemy = Map::map[(position.y + 35) / 35][position.x / 35];
        isattacking = true;
        attackL = true;
        attackR = false;
        attackLeft++;
    }
}

void player::attack() {
    War* war = War::getInstance();

    if (attackL) {
        if (attackLeft <= 100) {
            SDL_RenderCopy(Game::renderer, attackL1, NULL, &position);
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
        }
        if (attackLeft > 100 && attackLeft <= 200) {
            SDL_RenderCopy(Game::renderer, attackL2, NULL, &position);
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
        }
        if (attackLeft > 200 && attackLeft <= 300) {
            SDL_RenderCopy(Game::renderer, attackL3, NULL, &position);
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
        }
        if (attackLeft > 300 && attackLeft <= 400) {
            SDL_RenderCopy(Game::renderer, attackL2, NULL, &position);
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
        }
        if (attackLeft == 400) {
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
            attackLeft = 0;
        }
    }
    if (attackR) {
        if (attackRight <= 100) {
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
            SDL_RenderCopy(Game::renderer, attackR1, NULL, &position);
        }
        if (attackRight > 100 && attackRight <= 200) {
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
            SDL_RenderCopy(Game::renderer, attackR2, NULL, &position);
        }
        if (attackRight > 200 && attackRight <= 300) {
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
            SDL_RenderCopy(Game::renderer, attackR3, NULL, &position);
        }
        if (attackRight > 300 && attackRight <= 400) {
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
            SDL_RenderCopy(Game::renderer, attackR2, NULL, &position);
        }
        if (attackRight == 400) {
            std::cout << enemy << std::endl;
            if(war->attackEnemy(id,enemy - 25)){
                killEnemy();
            }
            attackRight = 0;
        }
    }
}

void player::killEnemy() {
    for(int i=0; i<15; i++){
        for(int j=0; j<36; j++){
            if(Map::map[i][j] == enemy){
                Map::map[i][j] = 0;
                isattacking = false;
            }
        }

    }
    if(attackL){
        attackL = false;
    }
    if(attackR){
        attackR = false;
    }
}

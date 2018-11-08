#include <iostream>
#include "Levels.h"
#include "thread"

void threadfn(){
    Levels *welcome = new Levels;
    welcome->welcome();
}

int main() {

    thread thread1 {threadfn};
    thread1.join();

    return 0;
}
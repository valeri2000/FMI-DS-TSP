#include "App.h"

int main() {
    App* TSP = App::getInstance();

    TSP->run();

    delete TSP;
    return 0;
}

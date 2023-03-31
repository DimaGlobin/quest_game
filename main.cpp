#include <iostream>

#include "game.h"

int main(int argc, char** argv) {
    
    build_game game;
    room* kitchen = new room("Kitchen", "You came to kitchen. What wiil you do?");

    game.add_room(kitchen);

    go_back* quit_kitchen = new go_back("Quit kitchen");
    empty_action* sit = new empty_action("Sit down");

    empty_action* eat_sandwich = new empty_action("Sandwich fell down");

    item* sandwich = new item(eat_sandwich);

    kitchen -> add_action(quit_kitchen);
    kitchen -> add_action(sit);

    interaction* sandw = new interaction("Take sandwich", sandwich);

    kitchen -> add_action(sandw);

    room* bedroom = new room("bedroom", "You are in bedroom. You decided to sleep?");

    game.add_room(bedroom);

    movement* next_room = new movement("Move to bedroom", bedroom);

    kitchen -> add_action(next_room);

    empty_action* smoke_cigarette = new empty_action("If you continue smokig, you will DIE struggling.");

    item* cigarette = new item(smoke_cigarette);

    go_back* quit_bedroom = new go_back("Quit bedroom");
    interaction* smoke = new interaction("There are a cigarette. Do you want to smoke?", cigarette);

    bedroom -> add_action(quit_bedroom);
    bedroom -> add_action(smoke);

    // int size = kitchen -> actions.size();

    // std::cout << "size: " << size << std::endl;
    
    // for (int i = 0; i < size; i++){

    //     std::cout << kitchen -> actions[i]->_description << std::endl;
    // } 

    game.start();

    return 0;
}

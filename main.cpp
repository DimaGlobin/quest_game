#include <iostream>

#include "game.h"

int main(int argc, char** argv) {
    
    build_game game;
    room* kitchen = new room("Kitchen", "You came to kitchen. What wiil you do?");

    game.add_room(kitchen);

    go_back* quit_kitchen = new go_back("Quit kitchen.");
    empty_action* sit = new empty_action("Sit down.");

    empty_action* eat_sandwich = new empty_action("Sandwich fell down.");

    item* sandwich = new item(eat_sandwich);

    kitchen -> add_action(quit_kitchen);
    kitchen -> add_action(sit);

    interaction* sandw = new interaction("Take sandwich.", sandwich);

    kitchen -> add_action(sandw);

    room* bedroom = new room("bedroom", "You are in bedroom. You decided to sleep?");

    game.add_room(bedroom);

    movement* move_to_bedroom = new movement("Move to bedroom", bedroom);

    kitchen -> add_action(move_to_bedroom);

    empty_action* smoke_cigarette = new empty_action("If you continue smokig, you will DIE struggling.");
    item* cigarette = new item(smoke_cigarette);
    go_back* quit_bedroom = new go_back("Quit bedroom.");
    interaction* smoke = new interaction("There is a cigarette. Do you want to smoke?", cigarette);

    winning_action* lay_down = new winning_action("Lay down on the bed.");

    bedroom -> add_action(lay_down);
    bedroom -> add_action(quit_bedroom);
    bedroom -> add_action(smoke);

    room* bathroom = new room("bathroom", "You are in bathroom. It's wet here.");

    go_back* quit_bathroom = new go_back("Quit bathroom");
    
    empty_action* paste_act = new empty_action("There was poison on the brush!!!");

    item* toothpaste = new item(paste_act);        

    killing_action* wash_teeth = new killing_action("There is a toothpaste and a brush. Dow you want to wash your teeth?", toothpaste);

    bathroom -> add_action(quit_bathroom);
    bathroom -> add_action(wash_teeth);

    movement* move_to_bathroom = new movement("Move to bathroom", bathroom);

    kitchen -> add_action(move_to_bathroom);

    game.start();

    return 0;
}

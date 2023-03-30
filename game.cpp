#include "game.h"

using std::cout;
using std::cin;
using std::endl;

room* build_game::add_room(std::string name, std::string description) {

    room room_created(name, description);
    this -> rooms.push_back(&room_created);

    return &room_created;
}

room::room(std::string name, std::string decription) {
    this -> room_name  = name;
    this -> description = description;
};

void room::add_action(action _action) {

    this -> actions.push_back(&_action);
}

item::item(empty_action empty){

    this -> action_desc = empty._description;
}

action::action(std::string type_of_action, std::string description, room* target_room, item* target_item):
_type_of_action(type_of_action), _description(description), _target_room(target_room),
_target_item(target_item) {}

void build_game::start() {

    int room_counter = 0;

    while(room_counter < rooms.size()) {

        cout << rooms[room_counter] -> description << endl;
        cout << "Chose the variant and enter its number:\n";
        for (int i = 0; i < rooms[room_counter] -> actions.size(); i++) {

            cout << i + 1 << ") " <<  rooms[room_counter] -> actions[i]->_description << endl;
        }

        int var_number;
        cin >> var_number;

        string type_of_action = rooms[room_counter] -> actions[var_number - 1]->_type_of_action;
        action* cur_action = rooms[room_counter] -> actions[var_number - 1];

        if (type_of_action == "move") {

            room_counter++;
        }

        else if (type_of_action == "interaction") {

            cout << cur_action -> _target_item -> action_desc << endl;
        }

        else if (type_of_action == "deactivation") {

            if (room_counter == 0) cout << "No way\n";
            else room_counter--;
        }
        


    }
}

#include "game.h"

using std::cout;
using std::cin;
using std::endl;

build_game::build_game() : rooms() {}

void build_game::add_room(room* room_to_add) {

    this -> rooms.push_back(room_to_add);
}

room::room(std::string name, std::string _decription) : actions(), items(),
room_name(name), description(_decription) 
{};

void room::add_action(action* _action) {

    this -> actions.push_back(_action);
}

void room::add_item(item* _item) {

    this -> items.push_back(_item);
}

item::item(empty_action* empty){

    this -> action_desc = empty -> _description;
}

action::action(std::string type_of_action, std::string description, room* target_room, item* target_item):
_type_of_action(type_of_action), _description(description), _target_room(target_room),
_target_item(target_item) {}

void build_game::start() {

    int room_counter = 0;
    int flag = 0;

    while(room_counter < rooms.size()) {

        room* cur_room = rooms[room_counter];

        if (flag == 0) cout << cur_room -> description << endl;

        flag = 1;

        int size_of_actions = cur_room -> actions.size();

        // cout << "size_of_action: " << size_of_actions << endl;

        if (size_of_actions == 0) {

            cout << "No available actions. YOU LOST\n";
            break;
        }

        cout << "Chose the variant and enter its number:\n";

        for (int i = 0; i < size_of_actions; i++) {

            cout << i + 1 << ") " <<  cur_room -> actions[i] -> _description << endl;
        }

        int var_number;

        if (size_of_actions > 1)  cin >> var_number;
        else var_number = 1;

        string type_of_action = cur_room -> actions[var_number - 1]->_type_of_action;
        action* cur_action = cur_room -> actions[var_number - 1];

        if (type_of_action == "movement") {

            room_counter++;
            flag = 0;
        }

        else if (type_of_action == "interaction") {

            cout << endl << cur_action -> _target_item -> action_desc << "\n\n";
            cur_room -> actions.erase(cur_room -> actions.begin() + var_number - 1);

        }

        else if (type_of_action == "deactivation") {

            if (room_counter == 0) cout << "No way\n";
            else room_counter--;
        }

        else if (type_of_action == "empty") {

        }

        else if (type_of_action == "go_back") {

            if (room_counter <= 0) cout << "No way. You are in the begining\n\n";
            else {

                room_counter--;
                flag = 0;
            }
        }

    }
}

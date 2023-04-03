#include <stack>
#include <cassert>
#include <algorithm>

#include "game.h"

using std::cout;
using std::cin;
using std::endl;

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

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

    int flag = 0;
    std::stack<room*>rooms_order;
    room* cur_room = rooms[0];

    while(1) {

        if (flag == 0) cout << "\n" << cur_room -> description << "\n\n";

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

        std::string var_number;
        int int_var_number;

        if (size_of_actions > 1)  {
            
            cin >> var_number;

            if (!is_number(var_number)) {

                while(!is_number(var_number)) {

                    cout << "Wrong format for variant. Try again.\n";
                    cin >> var_number;
                }

            }

            int_var_number = std::atoi(var_number.c_str());
        }

        else int_var_number = 1;

        string type_of_action = cur_room -> actions[int_var_number - 1]->_type_of_action;
        action* cur_action = cur_room -> actions[int_var_number - 1];

        if (type_of_action == "movement") {

            rooms_order.push(cur_room);
            cur_room = cur_action -> _target_room;
            flag = 0;
        }

        else if (type_of_action == "interaction") {

            item* tar_item = cur_action -> _target_item;

            assert(tar_item != nullptr);

            cout << endl << tar_item -> action_desc << "\n\n";
            cur_room -> actions.erase(cur_room -> actions.begin() + int_var_number - 1);

        }

        else if (type_of_action == "empty") {

        }

        else if (type_of_action == "go_back") {

            if (rooms_order.size() == 0) cout << "No way. You are in the begining\n\n";
            
            else {

                cur_room = rooms_order.top();
                rooms_order.pop();

                flag = 0;
            }
        }

        else if (type_of_action == "winning_action") {

            cout << "---------------------------------\n\n\n" << "!!!YOU WON!!!\n THE END!\n\n\n" << "---------------------------------\n\n\n";
            break;
        }

        else if (type_of_action == "killing_action") {

            item* tar_item = cur_action -> _target_item;

            assert(tar_item != nullptr);

            cout << endl << tar_item -> action_desc << "\n\n";
            cout << "---------------------------------\n\n\n" << "WASTED\n\n\n" << "---------------------------------\n\n\n";
        
            break;
        }

    }

    cout << "THE END. If you want to play again, type \"./KR\" in console.\n";
}

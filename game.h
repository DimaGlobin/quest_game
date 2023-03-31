#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class room;
class item;
class build_game;
class action;
class empty_action;
class movement;
class interaction;
class deactivation;

class build_game {

    vector<room*>rooms;

    public:
    build_game();
    void start();

    void add_room(room* room_to_add);
};

/*
available types of actions:

    1) movement
    2) interaction
    3) empty
    4) deactivation
    5) go_back
*/

class room {

    public:

    string room_name;
    string description;

    vector <action*> actions;
    vector <item*> items;
    vector <room*> neighbours; 

    room(std::string name, std::string decription);
    void add_action(action* _action);
    void add_item(item* _item);

    friend class build_game;
};

class item {

    public:

    std::string action_desc;
    item(empty_action* empty);

    friend class build_game;
};

class action {

    public:

    string _type_of_action;
    string _description;
    room* _target_room;
    item* _target_item;

    // protected:
    action(std::string type_of_action, std::string description, room* target_room, item* target_item);
    
    friend class room;
};

class empty_action : public action {

    public:
    empty_action(std::string description) : action("empty", description, nullptr, nullptr){};
};

class interaction : public action {

    public:
    interaction(std::string description, item* target_item) : action("interaction", description, nullptr, target_item){};
};

class movement : public action {

    public:
    movement(std::string description, room* target_room) : action("movement", description, target_room, nullptr){};
};

class deactivation : public action {

    public:
    deactivation(std::string description, item* target_item) : action("deactivation", description, nullptr, target_item){};
};

class go_back : public action {

    public:

    go_back(std::string description) : action("go_back", description, nullptr, nullptr){};

};
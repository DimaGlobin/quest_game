#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class build_game {

    vector<room*>rooms;

    public:
    build_game();
    void start();

    room* add_room(std::string name, std::string description);
};

/*
available types of actions:

    1) movement
    2) interaction
    3) empty
    4) deactivation

*/

class room {

    string room_name;
    string description;

    vector <action*> actions;

    private:

    room(std::string name, std::string decription);
    void add_action(action _action);

    friend class build_game;
};

class item {

    std::string action_desc;

    private:
    item(empty_action empty);

    friend class build_game;
};

class action {

    public:

    string _type_of_action;
    string _description;
    room* _target_room;
    item* _target_item;

    protected:
    action(std::string type_of_action, std::string description, room* target_room, item* target_item);
    
    friend class room;
};

class empty_action : public action {

    protected:
    empty_action(std::string description) : action("empty", description, nullptr, nullptr){};
};

class interaction : public action {

    protected:
    interaction(std::string description, item* target_item) : action("interaction", description, nullptr, target_item){};
};

class movement : public action {

    protected:
    movement(std::string description, room* target_room) : action("movement", description, target_room, nullptr){};
};

class deactivation : public action {

    protected:
    deactivation(std::string description, item* target_item) : action("deactivation", description, nullptr, target_item){};
};
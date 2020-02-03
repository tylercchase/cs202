#define CATCH_CONFIG_MAIN
#include <iostream>
#include <list>
#include <sstream>
#include <memory>
#include "catch.hpp"

struct pokemon {
    std::string _type{""};
    std::string _name{""};
    std::string _heldItem{""};
    int _hp{0};
    int _level{0};
    int _attack{0};

    pokemon(){

    }
    pokemon(std::string name, std::string type, std::string heldItem,
    int hp, int level, int attack):_name(name),_type(type),_heldItem(heldItem)
    ,_hp(hp),_level(level),_attack(attack){

    }
};

TEST_CASE("Test pokemon","[pokemon]"){
    std::list<std::shared_ptr<pokemon>> pokemons = { 
    std::make_shared<pokemon>("Charmander","fire","Oran Berry",17,5,6),
    std::make_shared<pokemon>("Squirtle","water","Leftovers",15,5,5),
    std::make_shared<pokemon>("Bulbasaur","grass","XP share",16,5,4)};

    REQUIRE(pokemons.front()->_type == "fire");

    //Queue
    pokemons.push_back(std::make_shared<pokemon>("Rattata","normal","Metal coat",8,3,3));
    REQUIRE(pokemons.back()->_name == "Rattata");
    pokemons.pop_front();
    REQUIRE(pokemons.front()->_name == "Squirtle");

    // //Stack
    pokemons.push_back(std::make_shared<pokemon>("Pidgey","flying","Power Bracer",9,4,5));
    REQUIRE(pokemons.back()->_name == "Pidgey");
    pokemons.pop_back();
    REQUIRE(pokemons.back()->_name == "Rattata");

    // //Insert and Find
    std::shared_ptr<pokemon> found;

    for(auto i = pokemons.begin(); i != pokemons.end(); i++){
        if(i->get()->_name == "Bulbasaur"){
            found = *i;
            break;
        }
    }
    REQUIRE(found->_name == "Bulbasaur");
    
    // //Print list out
    for(auto poke : pokemons){
        std::cout << "Name: " << poke->_name << std::endl;
        std::cout << "Type: " << poke->_type << std::endl;
        std::cout << "Held Item: " << poke->_heldItem << std::endl;
        std::cout << "HP: " << poke->_hp << std::endl;
        std::cout << "Attack: " << poke->_attack << std::endl;
        std::cout << "Level: " << poke->_level << std::endl;
        std::cout << "------" << std::endl;
    }
}
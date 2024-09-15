/* Kashif Mohammed Week 11 Class UML
Creating a RPG game outline with 2-3 attributes  */
#ifndef RPG_HPP
#define RPG_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Character {
private:
    std::string name;
    int health;
    bool shield;
    bool specialAvailable;

public:
    Character(const std::string& name, int health);

    void Display() const;

    void Attack(Character& target, const std::string& attackType);
    void Dodge();
    void UseSpecialAbility(Character& target);
    void Heal();

    int GetHealth() const;
    bool IsSpecialAbilityAvailable() const;
};

#endif

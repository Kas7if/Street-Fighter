#include "RPG.hpp"

Character::Character(const std::string& name, int health)
    : name(name), health(health), shield(false), specialAvailable(true) {
    // Initialize random seed
    srand(time(nullptr));
}

void Character::Display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
}

void Character::Attack(Character& target, const std::string& attackType) {
    int damage = 0;
    if (attackType == "kick")
        damage = 20;
    else if (attackType == "punch")
        damage = 10;

    if (!target.shield) {
        target.health -= damage;
        std::cout << name << " attacks " << target.name << " with " << attackType << " dealing " << damage << " damage.\n";
    } else {
        std::cout << target.name << " blocked " << name << "'s attack with a shield!\n";
        target.shield = false;
    }
}

void Character::Dodge() {
    std::cout << name << " dodges the attack!\n";
}

void Character::UseSpecialAbility(Character& target) {
    if (specialAvailable) {
        target.health -= 30;
        std::cout << name << " uses a special ability against " << target.name << " dealing 30 damage.\n";
        specialAvailable = false;
    } else {
        std::cout << name << "'s special ability is not available!\n";
    }
}

void Character::Heal() {
    if (health < 100) {
        health += 10;
        std::cout << name << " heals for 10 health.\n";
    } else {
        std::cout << name << " is already at full health!\n";
    }
}

int Character::GetHealth() const {
    return health;
}

bool Character::IsSpecialAbilityAvailable() const {
    return specialAvailable;
}

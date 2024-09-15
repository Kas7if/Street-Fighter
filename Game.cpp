/* This is a street fighter style rpg game which was a project for my cs class. 
The game is a simple turn based game where the player and the enemy take turns attacking each other. 
The player can choose to attack, dodge, use a special ability, or heal. 
The enemy's actions are randomly chosen. The game continues until either the player or the enemy's health drops to 0. The player wins if the enemy's health drops to 0, and the player loses if the player's health drops to 0.
*/ 

#include <iostream>
#include "RPG.hpp"

int main() {
    // Create player character
    Character player("Player", 100);

    // Create NPC
    Character enemy("Enemy", 80);

std::cout << "Hello Gamer! Welcome to Street Fighter!\n";
    // Display initial character information
    std::cout << "Initial Character Information:\n";
    std::cout << "Player:\n";
    player.Display();
    std::cout << "\nEnemy:\n";
    enemy.Display();
    std::cout << std::endl;

    // Game loop
    char choice;
    bool gameover = false;
    do {
        // Player's turn
        std::cout << "Player's turn:\n";
        std::cout << "Choose action (k: Kick, p: Punch, d: Dodge, s: Special, h: Heal, q: Quit): ";
        std::cin >> choice;
        switch (choice) {
            case 'k':
            case 'p':
                player.Attack(enemy, (choice == 'k') ? "kick" : "punch");
                break;
            case 'd':
                player.Dodge();
                break;
            case 's':
                player.UseSpecialAbility(enemy);
                break;
            case 'h':
                player.Heal();
                break;
            case 'q':
                std::cout << "Exiting the game.\n";
                gameover = true;
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }

        // Check if enemy is defeated
        if (enemy.GetHealth() <= 0) {
            std::cout << "Enemy defeated! You win!\n";
            gameover = true;
        }

        if (!gameover) {
            // Enemy's turn
            std::cout << "Enemy's turn:\n";
            // Randomly choose enemy action
            int enemyAction = rand() % 4; // Random number between 0 and 3
            switch (enemyAction) {
                case 0:
                    enemy.Attack(player, "kick");
                    break;
                case 1:
                    enemy.Attack(player, "punch");
                    break;
                case 2:
                    enemy.UseSpecialAbility(player);
                    break;
                case 3:
                    enemy.Heal();
                    break;
            }
        }

        // Check if player is defeated
        if (player.GetHealth() <= 0) {
            std::cout << "Player defeated! You lose!\n";
            gameover = true;
        }

        // Display updated character information if game is still ongoing
        if (!gameover) {
            std::cout << "Updated Character Information:\n";
            std::cout << "Player:\n";
            player.Display();
            std::cout << "\nEnemy:\n";
            enemy.Display();
            std::cout << std::endl;
        }

    } while (!gameover);

    return 0;
}

#include <iostream>
#include <vector>
#include <memory>
#include "Monster.hpp"

using namespace otari;

int main() {
    std::cout << "=== Menace Under Otari: Part 3 Combat Test ==_\n\n";

    std::vector<std::unique_ptr<Monster>> active_encounter;
    
    active_encounter.push_back(std::make_unique<GiantRat>());
    active_encounter.push_back(std::make_unique<GiantSpider>());
    active_encounter.push_back(std::make_unique<SkeletonGuard>());
    active_encounter.push_back(std::make_unique<ZombieShambler>());
    active_encounter.push_back(std::make_unique<KoboldWarrior>());
    active_encounter.push_back(std::make_unique<KoboldTrapmaster>());

    std::cout << "Simulating Monster Turns via Polymorphic Dispatch:\n";
    std::cout << "--------------------------------------------------\n";
    
    for (const auto& monster : active_encounter) {
        std::cout << "[" << monster->get_name() << " (HP: " << monster->get_hp() << ", AC: " << monster->get_ac() << ")] -> ";
        monster->take_turn();
    }

    std::cout << "\nSimulating Damage and Status Checks:\n";
    std::cout << "------------------------------------\n";
    
    auto& rat = active_encounter[0];
    std::cout << rat->get_name() << " takes 5 slashing damage.\n";
    rat->take_damage(5, DamageType::Slashing);
    std::cout << "Remaining HP: " << rat->get_hp() << " | Is Alive? " << (rat->is_alive() ? "Yes" : "No") << "\n";

    std::cout << rat->get_name() << " takes 10 more damage.\n";
    rat->take_damage(10, DamageType::Slashing);
    std::cout << "Remaining HP: " << rat->get_hp() << " | Is Alive? " << (rat->is_alive() ? "Yes" : "No") << "\n";

    std::cout << "\nCombat test completed successfully!\n";
    return 0;
}

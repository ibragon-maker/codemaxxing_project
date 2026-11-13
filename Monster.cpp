#include "Monster.hpp"
#include <iostream>

namespace otari {

    Monster::Monster(std::string name, int hp, int ac, int speed)
        : name(std::move(name)), hit_points(hp), armor_class(ac), speed(speed) {}

    void Monster::take_damage(int amount, DamageType type) {
        hit_points -= amount;
        if (hit_points < 0) hit_points = 0;
    }

    std::string Monster::get_name() const { return name; }
    int Monster::get_hp() const { return hit_points; }
    int Monster::get_ac() const { return armor_class; }
    bool Monster::is_alive() const { return hit_points > 0; }


    GiantRat::GiantRat() : Monster("Giant Rat", 8, 12, 30) {}
    void GiantRat::take_turn() {
        std::cout << name << " gnaws viciously at the nearest hero!\n";
    }

    GiantSpider::GiantSpider() : Monster("Giant Spider", 16, 14, 25) {}
    void GiantSpider::take_turn() {
        std::cout << name << " spins a sticky web or strikes with venomous fangs!\n";
    }

    SkeletonGuard::SkeletonGuard() : Monster("Skeleton Guard", 10, 16, 20) {}
    void SkeletonGuard::take_turn() {
        std::cout << name << " swings a rusted scimitar with skeletal precision.\n";
    }

    ZombieShambler::ZombieShambler() : Monster("Zombie Shambler", 20, 10, 20) {}
    void ZombieShambler::take_turn() {
        std::cout << name << " lumbers forward, slamming with decaying fists.\n";
    }

    KoboldWarrior::KoboldWarrior() : Monster("Kobold Warrior", 6, 13, 30) {}
    void KoboldWarrior::take_turn() {
        std::cout << name << " jabs with a spear, shouting tactical threats.\n";
    }

    KoboldTrapmaster::KoboldTrapmaster() : Monster("Kobold Trapmaster", 8, 13, 30) {}
    void KoboldTrapmaster::take_turn() {
        std::cout << name << " sets a hasty spike trap on the battlefield floor!\n";
    }

    void execute_monster_turns(const std::vector<std::unique_ptr<Monster>>& active_monsters) {
        for (const auto& monster_ptr : active_monsters) {
            if (monster_ptr->is_alive()) {
                monster_ptr->take_turn(); 
            }
        }
    }

} 

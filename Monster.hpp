#pragma once

#include <string>
#include <vector>
#include <memory>

namespace otari {

    enum class DamageType { Bludgeoning, Piercing, Slashing, Fire, Cold, Acid, Electricity, Poison };

    class Monster {
    protected:
        std::string name;
        int hit_points;
        int armor_class;
        int speed;

    public:
        Monster(std::string name, int hp, int ac, int speed);
        virtual ~Monster() = default;

        virtual void take_turn() = 0;
        virtual void take_damage(int amount, DamageType type);

        std::string get_name() const;
        int get_hp() const;
        int get_ac() const;
        bool is_alive() const;
    };

    // Derived Monster Classes 
    class GiantRat : public Monster {
    public:
        GiantRat();
        void take_turn() override;
    };

    class GiantSpider : public Monster {
    public:
        GiantSpider();
        void take_turn() override;
    };

    class SkeletonGuard : public Monster {
    public:
        SkeletonGuard();
        void take_turn() override;
    };

    class ZombieShambler : public Monster {
    public:
        ZombieShambler();
        void take_turn() override;
    };

    class KoboldWarrior : public Monster {
    public:
        KoboldWarrior();
        void take_turn() override;
    };

    class KoboldTrapmaster : public Monster {
    public:
        KoboldTrapmaster();
        void take_turn() override;
    };

} 

#ifndef HERO_BASIC_H
#define HERO_BASIC_H

class OBJ_BASIC{
protected:
    // ATTACK PART ------------------------------ PHYSICS PART ------------------------                             
    int BASIC_ATTACK_VALUE;
    int EXTRA_ATTACK_VALUE;
    int TOTAL_ATTACK_VALUE;

    double BASIC_ATTACK_SPEED;

    // CRIT

    int BASIC_CRIT_VALUE;
    double BASIC_CRIT_PROBA;

    // LIFE STOLE

    double BASIC_LIFE_STOLE;
    
    // PIERCE

    double BASIC_ARMOUR_PIERCE;
    double EXTRA_ARMOUR_PIERCE;

    // ------------------------------------------ MAGIC PART --------------------------

    // MAGIC ATTACK

    int BASIC_MAGIC_VALUE;

    // COOLING DECREASE

    int BASIC_COOLING_DECRE;

    // MAGIC RESUME

    int BASIC_MAGIC_RESUME;

    // MAGIC QUANTITY

    int BASIC_MAGIC_QUANTITY;

    // MAGIC STOLE

    int BASIC_MAGIC_STOLE;

    // PIERCE

    double BASIC_MAGIC_PIERCE;

    // ------------------------------------------ DEFENCE PART ------------------------

    // ARMOUR

    int PHYSICS_ARMOUR_VALUE;

    // MAGIC ARMOUR

    int MAGIC_ARMOUR_VALUE;

    // LIFE

    int BASIC_LIFE_VALUE;
    int BASIC_LIFE_RESUME;


    // ------------------------------------------ NORMAL PART -------------------------

    // ANGRY VALUE
    int BASIC_ANGRY_VALUE;
    int BASIC_ANGRY_RESUME;
    
    // MOVE SPEED

    int BASIC_MOVE_SPEED;
    
    // ATTACK RANGE

    int BASIC_ATTACK_RANGE;

    // TENACITY

    double BASIC_TENACITY_VALUE;


    
};



#endif
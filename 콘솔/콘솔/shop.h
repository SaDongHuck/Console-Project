#ifndef SHOP_H
#define SHOP_H

class unit;

class shop
{
private:
    int gold;
    int white_potion_price;
    int red_potion_price;
    int orange_potion_price;
    int dart_price;
    int arrow_price;
    int bullet_price;
    int attack_correction_price;
    int grape_juice_price;

public:
    shop(int g)
        : gold(g),
        white_potion_price(50),
        red_potion_price(100),
        orange_potion_price(150),
        dart_price(20),
        arrow_price(30),
        bullet_price(10),
        attack_correction_price(200),
        grape_juice_price(100) {}

    // 골드 관련 메서드
    int Getgold() const { return gold; }
    void subgold(int amount) { gold -= amount; }
    void Setgold(int amount) { gold = amount; } // 골드를 설정하는 메서드
    void addGold(int amount) { gold += amount; } // 골드를 추가 하는 메서드

    // 아이템 구매 메서드
    void buy_item(unit& player);
};

#endif
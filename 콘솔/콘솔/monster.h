#pragma once
#include "unit.h" // unit 클래스 포함
#include <string>
#include <iostream>
using namespace std;

class monster : public unit { // unit 클래스를 상속받음
protected:
    string name;

public:
    monster(const string& n, const int health, const int attack, const int skill, shop& g, int d, int f)
        : unit(n, health, attack, skill ,d,g,f), name(n) {}

    void status() override {
        cout << "몬스터 이름 : " << name << '\n';
        cout << "채력 : " << Gethealth() << '\n';
        cout << "공격력 : " << Getattack() << '\n';
        cout << "방어력 : " << Getdefense() << '\n';
    }

    void Attack(unit& target) override {
        cout << name << "이(가) 공격합니다!" << '\n';
        target.Sethealth(target.Gethealth() - Getattack());
        cout << "데미지는 " << Getattack() << "만큼 받았습니다. "
            << "플레이어 체력은 " << target.Gethealth() << " 남았습니다." << '\n';
    }

    void Skill(unit& target) override {
 
        cout << name << "이(가) 강력한 스킬을 사용합니다!" << '\n';
        target.Sethealth(target.Gethealth() - Getskill());
        cout << "데미지는 " << Getskill() << "만큼 받았습니다. "
            << "플레이어 체력은 " << target.Gethealth() << " 남았습니다." << '\n';
    }

    void show_inventory() override {}
    void Setweapon(int f) override {}
    int Getweapon() const { return 0; }
    void Setwhite_position(int e) {}
    int Getwhite_position() const { return 0; }
    void Setred_position1(int z) {}
    int Getred_position1() const { return 0; }
    void Setorange_position1(int p) {}
    int Getorange_position1() const { return 0; }
    void Setblue_position(int bl) override {}
    int Getblue_position()const override { return 0; }
    void Setgrape_juice(int q) override {}
    int Getgrpae_juice() const override { return 0; }
    void buy_item() {}
    void HP(){}
    void MP() {}
    void Basic_attak(unit& target) {}
};

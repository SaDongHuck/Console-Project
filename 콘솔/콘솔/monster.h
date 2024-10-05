#pragma once
#include "unit.h" // unit Ŭ���� ����
#include <string>
#include <iostream>
using namespace std;

class monster : public unit { // unit Ŭ������ ��ӹ���
protected:
    string name;

public:
    monster(const string& n, const int health, const int attack, const int skill, shop& g, int d, int f)
        : unit(n, health, attack, skill ,d,g,f), name(n) {}

    void status() override {
        cout << "���� �̸� : " << name << '\n';
        cout << "ä�� : " << Gethealth() << '\n';
        cout << "���ݷ� : " << Getattack() << '\n';
        cout << "���� : " << Getdefense() << '\n';
    }

    void Attack(unit& target) override {
        cout << name << "��(��) �����մϴ�!" << '\n';
        target.Sethealth(target.Gethealth() - Getattack());
        cout << "�������� " << Getattack() << "��ŭ �޾ҽ��ϴ�. "
            << "�÷��̾� ü���� " << target.Gethealth() << " ���ҽ��ϴ�." << '\n';
    }

    void Skill(unit& target) override {
 
        cout << name << "��(��) ������ ��ų�� ����մϴ�!" << '\n';
        target.Sethealth(target.Gethealth() - Getskill());
        cout << "�������� " << Getskill() << "��ŭ �޾ҽ��ϴ�. "
            << "�÷��̾� ü���� " << target.Gethealth() << " ���ҽ��ϴ�." << '\n';
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

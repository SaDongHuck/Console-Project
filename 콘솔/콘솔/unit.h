#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "util.h"
#include "shop.h"
using namespace std;
class unit
{
protected:
	int health;
	int attack;
	int skill;
	int mp;
	int defense;
	string name;
	shop& player_shop;
public:
	void Sethealth(int a) { health = a; }
	void Setattack(int b) { attack = b; }
	void Setskill(int c) { skill = c; }
	void Setdefense(int d) { defense = d; }
	int Getdefense() const { return defense; }
	int Gethealth() const { return health; }
	int Getattack() const { return attack; }
	int Getskill() const { return skill; }
	void SetMP(int d) { mp = d; }
	int GetMP() const { return mp; }

	unit(const string& n, const int a, const int b, const int c, const int d, shop& g, int f)
		:name(n), health(a), attack(b), skill(c), mp(d), player_shop(g), defense(f){
	};
	virtual ~unit() {
	};

	int Getgold() const { return player_shop.Getgold(); }
	void subgold(int amount) { player_shop.subgold(amount); }
	// 골드 추가 메서드
	void addGold(int amount) {
		player_shop.addGold(amount);// shop의 addGold 메서드 호출
		Sleep(3000);
		setColoer(yellow, black);
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@@=,.  .,:!@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@-.     .,-,@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@-.      .,,,@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@        ...,,@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@ -         ...,,:@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@....         ..,,,,@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@:,;;~,.       .,,,,,@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@=:**;~~-,..   .,,--=@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@=,;!!:~;~::-,,--,-~-@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@-,;;.--~;:;**:-,,=@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@,   ,, .~*:::-~,-=@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@*         .~~~-,$@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@,           ~~-,@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@~           ,--,@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@.          .-,@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@;.         .,,@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@~.       ,,@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@;.=-..~-:@@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
		cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << '\n';
		Sleep(3000);
		cout << "현재 메소: " << player_shop.Getgold() << '\n';
	}

	virtual void Attack(unit& target) = 0;
	virtual void Skill(unit& target) = 0;
	virtual void status() = 0;
	virtual void show_inventory() = 0;
	virtual void Setweapon(int f) = 0;
	virtual int Getweapon() const = 0;
	virtual void Setwhite_position(int e) = 0;
	virtual int Getwhite_position() const = 0;
	virtual void Setred_position1(int z) = 0;
	virtual int Getred_position1() const = 0;
	virtual void Setorange_position1(int p) = 0;
	virtual int Getorange_position1() const = 0;
	virtual void Setblue_position(int bl) = 0;
	virtual int Getblue_position() const = 0;
	virtual void Setgrape_juice(int q) = 0;
	virtual int Getgrpae_juice() const = 0;
	virtual void buy_item() = 0;
	virtual void HP() = 0;
	virtual void MP() = 0;
	virtual void Basic_attak(unit& target) = 0;
};


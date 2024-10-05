#pragma once
#ifndef ARCHER_H
#define ARCHER_H

#include "unit.h"
#include "shop.h"
#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

class archer : public unit
{
private:
	int arrowcount;
	int white_position;
	int red_position1;
	int orange_position1;
	int blue_position;
	int grape_juice;
public:
	archer(const string& n, int a, int b, int c, int d ,shop& g, int arrow, int wh, int bl, int f)
		: unit(n,a,b,c,d,g,f), arrowcount(arrow), white_position(wh), blue_position(bl), red_position1(0), orange_position1(0),
	grape_juice(0){}
	~archer()
	{

	}
	void Setwhite_position(int k)override { white_position = k; }
	int Getwhite_position()const { return white_position; }
	void Setred_position1(int u)override { red_position1 = u; }
	int Getred_position1()const { return red_position1; }
	void Setorange_position1(int r)override { orange_position1 = r; }
	int Getorange_position1()const { return orange_position1; }
	void Setblue_position(int bl) override { blue_position = bl; }
	int Getblue_position()const override { return blue_position; }
	void Setgrape_juice(int q) override { grape_juice = q; }
	int Getgrpae_juice() const override { return grape_juice; }
	void Setweapon(int e)override { arrowcount = e; }
	int Getweapon()const { return arrowcount; }

	void status() override
	{
		cout << "�÷��̾� �̸� : " << name << '\n';
		cout << "ä�� : " << Gethealth() << '\n';
		cout << "MP : " << GetMP() << '\n';
		cout << "���ݷ� : " << attack << '\n';
		cout << "���� : " << Getdefense() << '\n';
		cout << "���� �ż� : " << player_shop.Getgold() << '\n';
		cout << "���� ȭ�� �� : " << Getweapon() << '\n';
	}

	void Attack(unit& target) override
	{
		if (Getweapon() <= 0) {
			cout << "ȭ���� ��� ������ �� �� �����ϴ�.\n";
			return;
		}


		int AttackDamage = 8;

		cout << name << "��(��) ȭ���� �߻��մϴ�.\n";
		Setweapon(Getweapon() - 1);
		cout << "���� ȭ�� ���� " << Getweapon() << "�� ���ҽ��ϴ�.\n";
		target.Sethealth(target.Gethealth() - AttackDamage);
		cout << "�������� " << AttackDamage << "��ŭ �޾ҽ��ϴ�. "
			<< "�� ä���� " << target.Gethealth() << " ���ҽ��ϴ�.\n";
	}

	void Basic_attak(unit& target) override
	{
		int BasicDamage = 3;
		cout << name << "��(��) �⺻ ������ �մϴ�.\n";
		target.Sethealth(target.Gethealth() - BasicDamage);
		cout << "�������� " << BasicDamage << "��ŭ �޾ҽ��ϴ�. "
			<< "�� ä���� " << target.Gethealth() << " ���ҽ��ϴ�.\n";

	}

	void Skill(unit& target) override
	{
		if (Getweapon() <= 0) {
			cout << "ȭ���� ��� ��ų�� ����� �� �����ϴ�.\n";
			return;
		}

		if (GetMP() <= 0) {
			cout << "MP �����ؼ� ��ų�� ����� �� �����ϴ�\n";
			return;
		}


	
		int choice;
		cout << "��ų�� ���� �Ͻÿ�" << '\n';
		cout << "1.�Ǿ��(30)" << '\n';
		cout << "2.��������(20)" << '\n';
		cout << "3.��Ʈ������(25)" << '\n';
		cout << "4.������(40)" << '\n';
		cin >> choice;
		int skillDamage = 0;
		switch (choice)
		{
		case 1: skillDamage = 30;
			SetMP(GetMP() - 8);
			break;
		case 2: skillDamage = 20;
			SetMP(GetMP() - 3);
			break;
		case 3: skillDamage = 25;
			SetMP(GetMP() - 5);
			break;
		case 4: skillDamage = 40;
			SetMP(GetMP() - 10);
			break;
		default:
			cout << "�߸� �Է� �ϼ̽��ϴ� " << '\n';
			break;
		}
		cout << name << "��(��) ��ų�� ����մϴ�.\n";
		Setweapon(Getweapon() - 1);
		cout << "���� ǥâ ���� " << Getweapon() << "�� ���ҽ��ϴ�.\n";
		target.Sethealth(target.Gethealth() - skillDamage);
		cout << "��ų �������� " << skillDamage << "��ŭ �޾ҽ��ϴ�. "
			<< "�� ä���� " << target.Gethealth()<< " ���ҽ��ϴ�.\n";
		cout << "���� MP�� " << GetMP() << "���ҽ��ϴ�" << '\n';
		
	}

	void show_inventory() override
	{
		cout << "�κ��丮 �Դϴ�!!" << '\n';
		cout << "ȭ�� : " << Getweapon() << '\n';
		cout << "�Ͼ� ���� : " << Getwhite_position() << '\n';
		cout << "���� ���� : " << Getred_position1() << '\n';
		cout << "��Ȳ ���� : " << Getorange_position1() << '\n';
		cout << "�Ķ� ���� : " << Getblue_position() << '\n';
		cout << "���� �ֽ� : " << Getgrpae_juice() << '\n';
	}

	void buy_item() override
	{
		player_shop.buy_item(*this);
	}

	void HP() override
	{
		int choice;
		const int white_position_heal = 100;
		const int red_position1_heal = 60;
		const int orange_position1_heal = 80;
		if (Getwhite_position() > 0 || Getred_position1() > 0 || Getorange_position1() > 0)
		{
			cout << "1.�Ͼ� ����" << Getwhite_position() << "(��) ����" << '\n';
			cout << "2.���� ����" << Getred_position1() << "(��) ����" << '\n';
			cout << "3.��Ȳ ����" << Getorange_position1() << "(��) ����" << '\n';
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (Getwhite_position() > 0) {
					cout << "�Ͼ� ������ �����߽��ϴ�" << '\n';
					Setwhite_position(Getwhite_position() - 1);
					Sethealth(Gethealth() + white_position_heal);
					cout << "���� ä���� " << Gethealth() << "�Դϴ�" << '\n';
				}
				else {
					cout << "�Ͼ� ������ �����ϴ�!" << '\n';
				}
				break;
			case 2:
				if (Getred_position1() > 0) {
					cout << "���� ������ �����߽��ϴ�" << '\n';
					Setred_position1(Getred_position1() - 1);
					Sethealth(Gethealth() + red_position1_heal);
					cout << "���� ä���� " << Gethealth() << "�Դϴ�" << '\n';
				}
				else {
					cout << "���� ������ �����ϴ� " << '\n';
				}
				break;
			case 3:
				if (Getorange_position1() > 0)
				{
					cout << "��Ȳ ������ �����߽��ϴ�" << '\n';
					Setorange_position1(Getorange_position1() - 1);
					Sethealth(Gethealth() + orange_position1_heal);
					cout << "���� ä���� " << Gethealth() << "�Դϴ�" << '\n';
				}
				else {
					cout << "��Ȳ ������ �����ϴ� " << '\n';
				}
				break;
			default:
				cout << "�߸� �Է� �ϼ̽��ϴ� " << '\n';
				break;
			}
		}
	}

	void MP() override
	{
		int choice;
		const int blue_position_heal = 70;
		const int grape_juice_heal = 100;
		if (Getblue_position() > 0 || Getgrpae_juice() > 0)
		{
			cout << "1.�Ķ� ����" << Getblue_position() << "(��) ����" << '\n';
			cout << "2.���� �ֽ�" << Getgrpae_juice() << "(��) ����" << '\n';
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (Getblue_position() > 0) {
					cout << "�Ķ� ������ �����߽��ϴ�" << '\n';
					Setblue_position(Getblue_position() - 1);
					SetMP(GetMP() + blue_position_heal);
					cout << "���� ������ " << GetMP() << "�Դϴ�" << '\n';
				}
				else {
					cout << "�Ķ� ������ �����ϴ�!" << '\n';
				}
				break;
			case 2:
				if (Getgrpae_juice() > 0) {
					cout << "���� �ֽ��� �����߽��ϴ�" << '\n';
					Setred_position1(Getred_position1() - 1);
					SetMP(GetMP() + grape_juice_heal);
					cout << "���� ä���� " << GetMP() << "�Դϴ�" << '\n';
				}
				else {
					cout << "���� �ֽ��� �����ϴ� " << '\n';
				}
				break;
			default:
				cout << "�߸� �Է� �ϼ̽��ϴ� " << '\n';
				break;
			}
		}
	}

};


#endif
#include "unit.h"

class thief : public unit
{
private:
	int dart1;
	int white_position;
	int red_position1;
	int orange_position1;
public:
	thief(const string& n, const int a, const int b, const int c, shop& g, int dart, int wh)
	: unit(n,a,b,c,g), dart1(dart), white_position(wh), red_position1(0), orange_position1(0) {}
	void Setwhite_position(int e) override { white_position = e; }
	int Getwhite_position() const override { return white_position; }
	void Setred_position1(int z) override { red_position1 = z; }
	int Getred_position1() const override { return red_position1; }
	void Setorange_position1(int p) override { orange_position1 = p; }
	int Getorange_position1() const override { return orange_position1; }
	void Setdart1(int d) override { dart1 = d; }
	int Getdart1() const override { return dart1; }
	~thief()
	{

	}
	void status() override
	{
		cout << "�÷��̾� �̸� : " << name << '\n';
		cout << "ä�� : " << health << '\n';
		cout << "���ݷ� : " << attack << '\n';
		cout << "��ų ���ݷ� : " << skill << '\n';
		cout << "���� �ż� : " << player_shop.Getgold() << '\n';
		cout << "���� ǥâ �� : " << Getdart1() << '\n';
		cout << "���� ����(ȸ����) : " << white_position << '\n';
	}

	void Attack(unit& target) override {
		int minattack = attack / 2;
		int maxattack = attack * 2;
		int randomattack = rand() % (maxattack - minattack + 1) + minattack;
		cout << name << "��(��) ǥâ�� �����ϴ�" << '\n';
		dart1 = --dart1;
		if (dart1 <= 0) {
			cout << "ǥâ�� ��� ������ �� �� �����ϴ� " << '\n';
			return;
		}
		target.Sethealth(target.Gethealth() - randomattack);
		cout << "�������� " << randomattack << "��ŭ �޾ҽ��ϴ�" << "�� ä���� "
			<< target.Gethealth() << "���ҽ��ϴ�" << '\n';
		cout << "���� ǥâ ���� " << dart1 << "���ҽ��ϴ� " << '\n';

	}
	void Skill(unit& target) override {
		int minskill = skill / 2;
		int maxskill = skill * 2;
		int randomskill = rand() % (maxskill - minskill + 1) + minskill;
		cout << name << "��(��) ��ų�� ��� �մϴ�" << '\n';
		dart1 = --dart1;
		if (dart1 <= 0) {
			cout << "ǥâ�� ��� ��ų�� ����� �� �����ϴ� " << '\n';
			return;
		}
		target.Sethealth(target.Gethealth() - randomskill);
		string skill_name[4] = { "��Ű����","Ʈ���� ���ο�", "������ ÿ����","��� ���̵�" };
		cout << skill_name[rand() % 4] << "�� ����߽��ϴ�" << '\n';
		cout << "��ų �������� " << randomskill << "��ŭ �޾ҽ��ϴ� " << "�� ä���� "
			<< target.Gethealth() << "���ҽ��ϴ�" << '\n';
		cout << "���� ǥâ ���� " << dart1 << "���ҽ��ϴ� " << '\n';
	}

	void show_inventory() override
	{
		cout << "ǥâ : " << Getdart1() << '\n';
		cout << "�Ͼ����� : " << Getwhite_position << '\n';
		cout << "���� ���� : " << Getred_position1() << '\n';
		cout << "��Ȳ ���� : " << Getorange_position1() << '\n';
	}

	void buy_item() override
	{
		player_shop.buy_item(*this);
	}
	
	
};

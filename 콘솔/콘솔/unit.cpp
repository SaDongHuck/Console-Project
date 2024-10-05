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
		cout << "플레이어 이름 : " << name << '\n';
		cout << "채력 : " << health << '\n';
		cout << "공격력 : " << attack << '\n';
		cout << "스킬 공격력 : " << skill << '\n';
		cout << "현재 매소 : " << player_shop.Getgold() << '\n';
		cout << "현재 표창 수 : " << Getdart1() << '\n';
		cout << "현재 물약(회복약) : " << white_position << '\n';
	}

	void Attack(unit& target) override {
		int minattack = attack / 2;
		int maxattack = attack * 2;
		int randomattack = rand() % (maxattack - minattack + 1) + minattack;
		cout << name << "이(가) 표창을 던집니다" << '\n';
		dart1 = --dart1;
		if (dart1 <= 0) {
			cout << "표창이 없어서 공격을 할 수 없습니다 " << '\n';
			return;
		}
		target.Sethealth(target.Gethealth() - randomattack);
		cout << "데미지는 " << randomattack << "만큼 받았습니다" << "적 채력은 "
			<< target.Gethealth() << "남았습니다" << '\n';
		cout << "현재 표창 수는 " << dart1 << "남았습니다 " << '\n';

	}
	void Skill(unit& target) override {
		int minskill = skill / 2;
		int maxskill = skill * 2;
		int randomskill = rand() % (maxskill - minskill + 1) + minskill;
		cout << name << "이(가) 스킬을 사용 합니다" << '\n';
		dart1 = --dart1;
		if (dart1 <= 0) {
			cout << "표창이 없어서 스킬을 사용할 수 없습니다 " << '\n';
			return;
		}
		target.Sethealth(target.Gethealth() - randomskill);
		string skill_name[4] = { "럭키세븐","트리플 스로우", "슈리켄 첼린지","써든 레이드" };
		cout << skill_name[rand() % 4] << "를 사용했습니다" << '\n';
		cout << "스킬 데미지는 " << randomskill << "만큼 받았습니다 " << "적 채력은 "
			<< target.Gethealth() << "남았습니다" << '\n';
		cout << "현재 표창 수는 " << dart1 << "남았습니다 " << '\n';
	}

	void show_inventory() override
	{
		cout << "표창 : " << Getdart1() << '\n';
		cout << "하얀포션 : " << Getwhite_position << '\n';
		cout << "빨간 포션 : " << Getred_position1() << '\n';
		cout << "주황 포션 : " << Getorange_position1() << '\n';
	}

	void buy_item() override
	{
		player_shop.buy_item(*this);
	}
	
	
};

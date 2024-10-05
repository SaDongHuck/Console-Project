#include "shop.h"
#include "unit.h"
#include <iostream>
using namespace std;

void shop::buy_item(unit& player)
{
    int choice, count;
    cout << "======================================" << '\n';
    cout << "  ###   #   #    ###     ####" << '\n';
    cout << " #      #   #   #   #    #  #" << '\n';
    cout << "  #     #####   #   #    ####" << '\n';
    cout << "    #   #   #   #   #    #" << '\n';
    cout << " ###    #   #    ###     #" << '\n';
    cout << "======================================" << '\n';
    cout << "상점에 오신 것을 환영합니다!" << '\n';
    cout << "현재 메소: " << Getgold() << "원\n";
    cout << "======================================" << '\n';
    cout << "구매할 아이템을 선택하세요:\n";
    cout << "1. 하얀 포션 (50메소)\n";
    cout << "2. 빨간 포션 (100메소)\n";
    cout << "3. 주황 포션 (150메소)\n";
    cout << "4. 표창 (20메소)\n";
    cout << "5. 화살 (30메소)\n";
    cout << "6. 총알 (10메소)\n";
    cout << "7. 포도 주스(100메소)\n";
    cout << "8. 취소\n";
    cout << "선택: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "몇 개를 구매하시겠습니까? ";
        cin >> count;
        if (gold < white_potion_price * count)
        {
            cout << "메소가 부족합니다.\n";
            break;
        }
        player.subgold(white_potion_price * count);
        player.Setwhite_position(player.Getwhite_position() + count);
        cout << "하얀 포션을 " << count << "개 구매했습니다.\n";
        break;
    case 2:
        cout << "몇 개를 구매하시겠습니까? ";
        cin >> count;
        if (gold < red_potion_price * count)
        {
            cout << "메소가 부족합니다.\n";
            break;
        }
        player.subgold(red_potion_price * count);
        player.Setred_position1(player.Getred_position1() + count);
        cout << "빨간 포션을 " << count << "개 구매했습니다.\n";
        break;
    case 3:
        cout << "몇 개를 구매하시겠습니까? ";
        cin >> count;
        if (gold < orange_potion_price * count)
        {
            cout << "메소가 부족합니다.\n";
            break;
        }
        player.Setorange_position1(player.Getorange_position1() + count);
        player.subgold(orange_potion_price * count);
        cout << "주황 포션을 " << count << "개 구매했습니다.\n";
        break;
    case 4:
        cout << "몇 개를 구매하시겠습니까? ";
        cin >> count;
        if (gold < dart_price * count)
        {
            cout << "메소가 부족합니다.\n";
            break;
        }
        player.subgold(dart_price * count);
        player.Setweapon(player.Getweapon() + count);
        cout << "표창을 " << count << "개 구매했습니다.\n";
        break;
    case 5:
        cout << "몇 개를 구매하시겠습니까? ";
        cin >> count;
        if (gold < arrow_price * count)
        {
            cout << "메소가 부족합니다.\n";
            break;
        }
        player.subgold(arrow_price * count);
        player.Setweapon(player.Getweapon() + count);
        cout << "화살을 " << count << "개 구매했습니다.\n";
        break;
    case 6:
        cout << "몇 개를 구매하시겠습니까? ";
        cin >> count;
        if (gold < bullet_price * count)
        {
            cout << "메소가 부족합니다.\n";
            break;
        }
        player.subgold(bullet_price * count);
        player.Setweapon(player.Getweapon() + count);
        cout << "총알을 " << count << "개 구매했습니다.\n";
        break;
    case 7:
        cout << "몇개를 구매 하시겠습니까?" << '\n';
        cin >> count;
        if (gold < grape_juice_price * count)
        {
            cout << "메소가 부족 합니다\n";
            break;
        }
        player.subgold(grape_juice_price * count);
        cout << "포도 주스를 " << count << "만큼 구매했습니다.\n";
        break;
    default:
        cout << "잘못된 선택입니다.\n";
        break;
    }
}


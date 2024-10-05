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
    cout << "������ ���� ���� ȯ���մϴ�!" << '\n';
    cout << "���� �޼�: " << Getgold() << "��\n";
    cout << "======================================" << '\n';
    cout << "������ �������� �����ϼ���:\n";
    cout << "1. �Ͼ� ���� (50�޼�)\n";
    cout << "2. ���� ���� (100�޼�)\n";
    cout << "3. ��Ȳ ���� (150�޼�)\n";
    cout << "4. ǥâ (20�޼�)\n";
    cout << "5. ȭ�� (30�޼�)\n";
    cout << "6. �Ѿ� (10�޼�)\n";
    cout << "7. ���� �ֽ�(100�޼�)\n";
    cout << "8. ���\n";
    cout << "����: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "�� ���� �����Ͻðڽ��ϱ�? ";
        cin >> count;
        if (gold < white_potion_price * count)
        {
            cout << "�޼Ұ� �����մϴ�.\n";
            break;
        }
        player.subgold(white_potion_price * count);
        player.Setwhite_position(player.Getwhite_position() + count);
        cout << "�Ͼ� ������ " << count << "�� �����߽��ϴ�.\n";
        break;
    case 2:
        cout << "�� ���� �����Ͻðڽ��ϱ�? ";
        cin >> count;
        if (gold < red_potion_price * count)
        {
            cout << "�޼Ұ� �����մϴ�.\n";
            break;
        }
        player.subgold(red_potion_price * count);
        player.Setred_position1(player.Getred_position1() + count);
        cout << "���� ������ " << count << "�� �����߽��ϴ�.\n";
        break;
    case 3:
        cout << "�� ���� �����Ͻðڽ��ϱ�? ";
        cin >> count;
        if (gold < orange_potion_price * count)
        {
            cout << "�޼Ұ� �����մϴ�.\n";
            break;
        }
        player.Setorange_position1(player.Getorange_position1() + count);
        player.subgold(orange_potion_price * count);
        cout << "��Ȳ ������ " << count << "�� �����߽��ϴ�.\n";
        break;
    case 4:
        cout << "�� ���� �����Ͻðڽ��ϱ�? ";
        cin >> count;
        if (gold < dart_price * count)
        {
            cout << "�޼Ұ� �����մϴ�.\n";
            break;
        }
        player.subgold(dart_price * count);
        player.Setweapon(player.Getweapon() + count);
        cout << "ǥâ�� " << count << "�� �����߽��ϴ�.\n";
        break;
    case 5:
        cout << "�� ���� �����Ͻðڽ��ϱ�? ";
        cin >> count;
        if (gold < arrow_price * count)
        {
            cout << "�޼Ұ� �����մϴ�.\n";
            break;
        }
        player.subgold(arrow_price * count);
        player.Setweapon(player.Getweapon() + count);
        cout << "ȭ���� " << count << "�� �����߽��ϴ�.\n";
        break;
    case 6:
        cout << "�� ���� �����Ͻðڽ��ϱ�? ";
        cin >> count;
        if (gold < bullet_price * count)
        {
            cout << "�޼Ұ� �����մϴ�.\n";
            break;
        }
        player.subgold(bullet_price * count);
        player.Setweapon(player.Getweapon() + count);
        cout << "�Ѿ��� " << count << "�� �����߽��ϴ�.\n";
        break;
    case 7:
        cout << "��� ���� �Ͻðڽ��ϱ�?" << '\n';
        cin >> count;
        if (gold < grape_juice_price * count)
        {
            cout << "�޼Ұ� ���� �մϴ�\n";
            break;
        }
        player.subgold(grape_juice_price * count);
        cout << "���� �ֽ��� " << count << "��ŭ �����߽��ϴ�.\n";
        break;
    default:
        cout << "�߸��� �����Դϴ�.\n";
        break;
    }
}


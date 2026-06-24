#include <iostream>
#include "fun.h" 

using namespace std;

int main() {
    SeqList restaurantList;
    InitList(restaurantList);     
    LoadFromFile(restaurantList); // 关联文件

    int choice;
    while (true) {
        showmenu(); 
        cout << "请选择操作 (1-5): ";
        if (!(cin >> choice)) break; // 防止输入非数字导致死循环

        if (choice == 5) {
            SaveToFile(restaurantList); // 退出前保存
            cout << "系统退出，再见！" << endl;
            break; 
        }

        switch (choice) {
            case 1: ShowAll(restaurantList); break;
            case 2: {
                char name[50];
                cout << "输入餐馆名: "; cin >> name;
                int idx = SearchByName(restaurantList, name);
                if (idx != -1) cout << "找到餐馆 ID: " << restaurantList.data[idx].id << endl;
                else cout << "未找到。" << endl;
                break;
            }
            case 3: 
                if (AddRestaurant(restaurantList)) SaveToFile(restaurantList); 
                break;
            case 4: {
                int sub;
                cout << "1. 办理预定  2. 取消预定: "; cin >> sub;
                if (sub == 1) {
                    if (MakeReservation(restaurantList)) SaveToFile(restaurantList);
                } else if (sub == 2) {
                    if (CancelReservation(restaurantList)) SaveToFile(restaurantList);
                }
                break;
            }
            default: cout << "指令无效。" << endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

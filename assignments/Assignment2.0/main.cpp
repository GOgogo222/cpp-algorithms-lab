#include <iostream>
#include "fun.h" 
#include <windows.h>

using namespace std;

int main() {
    SeqList restaurantList;
    OrderList orderList;
    
    // 初始化
    InitList(restaurantList);
    InitOrderList(orderList);
    
    // 加载数据
    LoadFromFile(restaurantList);
    LoadOrdersFromFile(orderList);

    int choice;
    while (true) {
        showmenu(); 
        cout << "  请选择 (1-7): ";
        if (!(cin >> choice)) {
            // 处理输入错误
            cin.clear();
            cin.ignore(1024, '\n');
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  输入错误，请输入数字！                                │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            system("pause");
            system("cls");
            continue;
        }

        if (choice == 7) {
            SaveToFile(restaurantList);
            SaveOrdersToFile(orderList);
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  系统退出成功，数据已保存！                            │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            break; 
        }

        switch (choice) {
            case 1: 
                ShowAll(restaurantList); 
                break;
                
            case 2: 
                SearchRestaurant(restaurantList);
                break;
                
            case 3: 
                if (AddRestaurant(restaurantList)) {
                    SaveToFile(restaurantList);
                }
                break;
                
            case 4: 
    ReservationManagement(restaurantList, orderList);  // 传递两个参数
    break;
                
            case 5: 
                if (DeleteRestaurant(restaurantList)) {
                    SaveToFile(restaurantList);
                }
                break;
                
            case 6: 
                SortRestaurants(restaurantList);
                break;
                
            default: 
                SetColor(12); // 红色
                cout << "┌────────────────────────────────────────────────────────┐" << endl;
                cout << "│  无效选择，请重新输入！                              │" << endl;
                cout << "└────────────────────────────────────────────────────────┘" << endl;
                SetColor(7); // 恢复白色
        }
        
        system("pause");
        system("cls");
    }
    
    // 释放内存
    delete[] restaurantList.data;
    delete[] orderList.data;
    return 0;
}

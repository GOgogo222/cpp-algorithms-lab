#include <iostream>
using namespace std;
#include "fun.h"
#include <cstring>
#include <fstream>

void showmenu() {
    cout << "****************************************" << endl;
    cout << "      欢迎使用美团餐馆预定管理系统      " << endl;
    cout << "1. 查看所有餐馆" << endl;
    cout << "2. 搜索餐馆信息" << endl;
    cout << "3. 办理餐馆预定" << endl;
    cout << "4. 取消预定/更新桌位" << endl;
    cout << "5. 退出系统" << endl;
    cout << "****************************************" << endl;
}

void InitList(SeqList &L) {
    L.capacity = 100; // 初始容量
    L.length = 0;
    L.data = new Restaurant[L.capacity];
}

void LoadFromFile(SeqList &L) {
    ifstream inFile("D:\\restaurant.txt", ios::in);
    if (!inFile) {
        cout << "提示：未找到存档文件，系统将以空数据库运行。" << endl;
        return;
    }

    Restaurant r;
    // 按照文件里的顺序依次读入变量
    while (inFile >> r.id >> r.name >> r.type >> r.price >> r.rating >> r.total_tables >> r.remaining_tables) {
        if (L.length < L.capacity) {
            L.data[L.length] = r;
            L.length++;
        } else {
            cout << "警告：顺序表已满，部分数据未加载。" << endl;
            break;
        }
    }
    inFile.close();
    cout << "--- 存档数据加载成功，共 " << L.length << " 家餐馆 ---" << endl;
}

// 保存数据到文件
void SaveToFile(SeqList &L) {
    ofstream outFile("D:\\restaurant.txt", ios::out); // 打开D盘下的文件
    if (!outFile) {
        cout << "文件打开失败，无法保存！" << endl;
        return;
    }

    for (int i = 0; i < L.length; i++) {
        // 将每一项数据按空格隔开写入
        outFile << L.data[i].id << " "
                << L.data[i].name << " "
                << L.data[i].type << " "
                << L.data[i].price << " "
                << L.data[i].rating << " "
                << L.data[i].total_tables << " "
                << L.data[i].remaining_tables << endl;
    }
    outFile.close();
    cout << "数据已成功保存至 D:\\restaurant.txt" << endl;
}

bool AddRestaurant(SeqList &L) {
    if (L.length >= L.capacity) {
        cout << "顺序表已满，无法添加新餐馆" << endl;
        return false;
    }
    Restaurant r;
    cout << "请输入餐馆ID: ";
    cin >> r.id;
    cout << "请输入餐馆名称: ";
    cin >> r.name;
    cout << "请输入餐馆类型: ";
    cin >> r.type;
    cout << "请输入人均价格: ";
    cin >> r.price;
    cout << "请输入评分: ";
    cin >> r.rating;
    cout << "请输入总桌位数: ";
    cin >> r.total_tables;
    cout << "请输入剩余桌位数: ";
    cin >> r.remaining_tables;

    L.data[L.length++] = r;
    return true;
}

void ShowAll(SeqList &L) {
    cout << "餐馆列表:" << endl;
    for (int i = 0; i < L.length; i++) {
        Restaurant &r = L.data[i];
        cout << "ID: " << r.id << ", 名称: " << r.name << ", 类型: " << r.type
             << ", 价格: " << r.price << ", 评分: " << r.rating
             << ", 总桌位: " << r.total_tables << ", 剩余桌位: " << r.remaining_tables << endl;
    }
}

int SearchByName(SeqList &L, char name[]) {
    for (int i = 0; i < L.length; i++) {
        if (strcmp(L.data[i].name, name) == 0) {
            return i; // 返回找到的餐馆索引
        }
    }
    return -1; // 未找到
}

void SortByPrice(SeqList &L) {
    // 使用简单的冒泡排序按价格排序
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.data[j].price > L.data[j + 1].price) {
                // 交换
                Restaurant temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
            }
        }
    }
}

bool MakeReservation(SeqList &L) {
    char name[50];
    cout << "请输入预定餐馆名称: "; 
    cin >> name;
    int idx = SearchByName(L, name); // 调用已有的查找函数
    
    if (idx != -1) {
        if (L.data[idx].remaining_tables > 0) {
            L.data[idx].remaining_tables--;
            cout << "预定成功！剩余桌位: " << L.data[idx].remaining_tables << endl;
            return true;
        } else {
            cout << "预定失败：该餐馆已满座。" << endl;
        }
    } else {
        cout << "未找到该餐馆。" << endl;
    }
    return false;
}

// 取消预定：剩余桌位增加
bool CancelReservation(SeqList &L) {
    char name[50];
    cout << "请输入要取消预定的餐馆名称: "; 
    cin >> name;
    int idx = SearchByName(L, name); // 调用已有的查找函数
    
    if (idx != -1) {
        // 逻辑检查：剩余桌位不能超过总桌位数
        if (L.data[idx].remaining_tables < L.data[idx].total_tables) {
            L.data[idx].remaining_tables++;
            cout << "取消成功！当前可用桌位: " << L.data[idx].remaining_tables << endl;
            return true;
        } else {
            cout << "取消失败：该餐馆桌位已全部空闲，无需取消。" << endl;
        }
    } else {
        cout << "未找到该餐馆。" << endl;
    }
    return false;
}


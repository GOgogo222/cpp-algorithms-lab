#include <iostream>
#include <iomanip>
#include <windows.h> // 管理颜色 
#include <cstring>
#include <fstream> // 文件流 
#include <ctime> // 获取系统时间 
using namespace std;
#include "fun.h"

// 设置控制台颜色
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 显示标题
void ShowTitle() {
    SetColor(11); // 浅蓝色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                                                        │" << endl;
    cout << "│                餐厅预订系统 v2.0                       │" << endl;
    cout << "│                                                        │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
}

// 显示主菜单
void showmenu() {
    system("cls");
    ShowTitle();
    
    SetColor(10); // 绿色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                                                        │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(14); // 黄色
    cout << "  1. 查看所有餐厅信息       2. 搜索餐厅信息                " << endl;
    cout << "  3. 添加餐厅信息           4. 预订/取消预订管理          " << endl;
    cout << "  5. 删除餐厅信息           6. 排序餐厅信息                " << endl;
    cout << "  7. 退出系统                                              " << endl;
    SetColor(10); // 绿色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                                                        │" << endl;
    SetColor(7); // 恢复白色
}

// 初始化餐厅列表
void InitList(SeqList &L) {
    L.capacity = 100;
    L.length = 0;
    L.data = new Restaurant[L.capacity];
}

// 初始化订单列表
void InitOrderList(OrderList &orders) {
    orders.capacity = 100;
    orders.length = 0;
    orders.data = new Order[orders.capacity];
}

// 从文件加载餐厅数据
void LoadFromFile(SeqList &L) {
    ifstream inFile("D:\\restaurant.txt", ios::in);
    if (!inFile) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  未找到数据文件，系统将创建新的数据文件                │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }

    Restaurant r;
    while (inFile >> r.id >> r.name >> r.type >> r.price >> r.rating >> r.total_tables >> r.remaining_tables) {
        if (L.length < L.capacity) {
            L.data[L.length] = r;
            L.length++;
        } else {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  列表已满，无法加载更多数据！                        │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            break;
        }
    }
    inFile.close();
    
    SetColor(10); // 绿色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  数据加载成功，共加载 " << setw(2) << L.length << " 家餐厅信息        │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
}

// 保存餐厅数据到文件
void SaveToFile(SeqList &L) {
    ofstream outFile("D:\\restaurant.txt", ios::out);
    if (!outFile) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  文件保存失败，无法创建数据文件！                      │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }

    for (int i = 0; i < L.length; i++) {
        outFile << L.data[i].id << " "
                << L.data[i].name << " "
                << L.data[i].type << " "
                << L.data[i].price << " "
                << L.data[i].rating << " "
                << L.data[i].total_tables << " "
                << L.data[i].remaining_tables << endl;
    }
    outFile.close();
    
    SetColor(10); // 绿色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  数据保存成功！                                      │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
}

// 添加餐厅
bool AddRestaurant(SeqList &L) {
    if (L.length >= L.capacity) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  列表已满，无法添加更多餐厅！                        │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return false;
    }
    
    SetColor(14); // 黄色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                   添加餐厅信息                        │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    
    Restaurant r;
    cout << "  请输入餐厅ID: ";
    cin >> r.id;
    cout << "  请输入餐厅名称: ";
    cin >> r.name;
    cout << "  请输入餐厅类型: ";
    cin >> r.type;
    cout << "  请输入人均价格: ";
    cin >> r.price;
    cout << "  请输入餐厅评分(0-5): ";
    cin >> r.rating;
    cout << "  请输入总桌位数: ";
    cin >> r.total_tables;
    cout << "  请输入剩余桌位数: ";
    cin >> r.remaining_tables;

    L.data[L.length++] = r;
    
    SetColor(10); // 绿色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  餐厅添加成功！                                      │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    return true;
}

// 显示所有餐厅
void ShowAll(SeqList &L) {
    if (L.length == 0) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  暂无餐厅数据！                                      │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }
    
    SetColor(11); // 浅蓝色
    cout << "┌─────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│                                   所有餐厅信息                                             │" << endl;
    cout << "├──────┬────────────┬────────────┬──────────┬────────┬──────────┬────────────┬──────────────┤" << endl;
    cout << "│  ID  │  餐厅名称  │   类型     │  人均价格 │  评分  │  总桌位  │  剩余桌位  │    状态      │" << endl;
    cout << "├──────┼────────────┼────────────┼──────────┼────────┼──────────┼────────────┼──────────────┤" << endl;
    SetColor(7); // 恢复白色
    
    for (int i = 0; i < L.length; i++) {
        Restaurant &r = L.data[i];
        cout << "│ " << setw(4) << r.id << " │ ";
        cout << setw(10) << r.name << " │ ";
        cout << setw(10) << r.type << " │ ";
        cout << setw(8) << fixed << setprecision(1) << r.price << " │ ";
        cout << setw(6) << fixed << setprecision(1) << r.rating << " │ ";
        cout << setw(8) << r.total_tables << " │ ";
        cout << setw(10) << r.remaining_tables << " │ ";
        
        // 状态显示
        if (r.remaining_tables == 0) {
            SetColor(12); // 红色
            cout << setw(10) << "已满";
            SetColor(7); // 恢复白色
        } else if (r.remaining_tables <= r.total_tables / 3) {
            SetColor(14); // 黄色
            cout << setw(10) << "紧张";
            SetColor(7); // 恢复白色
        } else {
            SetColor(10); // 绿色
            cout << setw(10) << "充足";
            SetColor(7); // 恢复白色
        }
        cout << " │" << endl;
    }
    
    SetColor(11); // 浅蓝色
    cout << "├──────┼────────────┼────────────┼──────────┼────────┼──────────┼────────────┼──────────────┤" << endl;
    cout << "│                           共显示 " << setw(2) << L.length << " 家餐厅信息                           │" << endl;
    cout << "└─────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
}

// 搜索餐厅
void SearchRestaurant(SeqList &L) {
    if (L.length == 0) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  列表为空，无法搜索！                                │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }
    
    int searchChoice;
    SetColor(14); // 黄色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                   搜索餐厅信息                        │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  1. 按名称搜索      2. 按ID搜索                       │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    cout << "  请选择搜索方式: ";
    cin >> searchChoice;
    
    if (searchChoice == 1) {
        char name[50];
        cout << "  请输入餐厅名称: ";
        cin >> name;
        
        int idx = SearchByName(L, name);
        if (idx != -1) {
            ShowRestaurantDetail(L.data[idx]);
        } else {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  未找到名称为 \"" << name << "\" 的餐厅              │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
        }
    } else if (searchChoice == 2) {
        int id;
        cout << "  请输入餐厅ID: ";
        cin >> id;
        
        int idx = SearchByID(L, id);
        if (idx != -1) {
            ShowRestaurantDetail(L.data[idx]);
        } else {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  未找到ID为 " << setw(4) << id << " 的餐厅                  │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
        }
    } else {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  无效选择！                                          │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
    }
}

// 按ID搜索
int SearchByID(SeqList &L, int id) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 显示餐厅详情
void ShowRestaurantDetail(Restaurant r) {
    SetColor(11); // 浅蓝色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                   餐厅详细信息                          │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    
    // 基本信息
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  基本信息:                                              │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  ID: " << setw(44) << r.id << " │" << endl;
    cout << "│  名称: " << setw(42) << r.name << " │" << endl;
    cout << "│  类型: " << setw(42) << r.type << " │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    
    // 价格信息
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  价格信息:                                              │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  人均价格: " << setw(37) << fixed << setprecision(1) << r.price << "元 │" << endl;
    
    // 评分显示
    cout << "│  评分: " << setw(41) << fixed << setprecision(1) << r.rating << " │" << endl;
    cout << "│  星级: ";
    int fullStars = static_cast<int>(r.rating);
    int halfStar = (r.rating - fullStars) >= 0.5 ? 1 : 0;
    SetColor(14); // 黄色显示星星
    for (int i = 0; i < fullStars; i++) {
        cout << "★";
    }
    if (halfStar) {
        cout << "☆";
    }
    SetColor(7); // 恢复白色
    cout << setw(44 - fullStars * 2 - halfStar * 2) << " │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    
    // 桌位信息
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  桌位信息:                                              │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  总桌位: " << setw(39) << r.total_tables << " │" << endl;
    cout << "│  剩余桌位: " << setw(37) << r.remaining_tables << " │" << endl;
    
    // 状态显示
    cout << "│  当前状态: ";
    if (r.remaining_tables == 0) {
        SetColor(12); // 红色
        cout << setw(37) << "已满";
    } else if (r.remaining_tables <= r.total_tables / 3) {
        SetColor(14); // 黄色
        cout << setw(37) << "紧张";
    } else {
        SetColor(10); // 绿色
        cout << setw(37) << "充足";
    }
    SetColor(7); // 恢复白色
    cout << " │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    
    // 预订建议
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  预订建议:                                              │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    if (r.remaining_tables == 0) {
        SetColor(12); // 红色
        cout << "│  该餐厅目前客满，请选择其他餐厅                    │" << endl;
    } else if (r.remaining_tables <= 2) {
        SetColor(14); // 黄色
        cout << "│  桌位紧张，建议尽快预订                            │" << endl;
    } else if (r.rating >= 4.5) {
        SetColor(10); // 绿色
        cout << "│  口碑很好，强烈推荐预订                            │" << endl;
    } else if (r.price <= 50) {
        SetColor(11); // 浅蓝色
        cout << "│  性价比高，适合日常用餐                            │" << endl;
    } else {
        SetColor(7); // 白色
        cout << "│  可以预订                                            │" << endl;
    }
    SetColor(7); // 恢复白色
    cout << "└────────────────────────────────────────────────────────┘" << endl;
}

// 按名称搜索
int SearchByName(SeqList &L, char name[]) {
    for (int i = 0; i < L.length; i++) {
        if (strcmp(L.data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// 预订管理
void ReservationManagement(SeqList &L, OrderList &orders) {
    int sub;
    SetColor(14); // 黄色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                   预订/取消预订管理                    │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  1. 餐厅预订        2. 取消预订                       │" << endl;
    cout << "│  3. 查看我的订单    4. 取消订单                       │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    cout << "  请选择: ";
    cin >> sub;
    
    switch (sub) {
        case 1: 
            if (MakeReservation(L, orders)) {
                SaveToFile(L);
                SaveOrdersToFile(orders);
            }
            break;
        case 2:
            if (CancelReservation(L, orders)) {
                SaveToFile(L);
                SaveOrdersToFile(orders);
            }
            break;
        case 3:
            ShowAllOrders(orders);
            break;
        case 4:
            if (CancelOrder(orders, L)) {
                SaveOrdersToFile(orders);
                SaveToFile(L);
            }
            break;
        default:
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  无效选择！                                          │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
    }
}

// 删除餐厅
bool DeleteRestaurant(SeqList &L) {
    if (L.length == 0) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  列表为空，无法删除！                                │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return false;
    }
    
    SetColor(14); // 黄色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                   删除餐厅信息                        │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  1. 按名称删除      2. 按ID删除                       │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    
    int deleteChoice;
    cout << "  请选择: ";
    cin >> deleteChoice;
    
    if (deleteChoice == 1) {
        char name[50];
        cout << "  请输入要删除的餐厅名称: ";
        cin >> name;
        
        int idx = SearchByName(L, name);
        if (idx == -1) {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  未找到该餐厅！                                      │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return false;
        }
        
        // 显示要删除的餐厅信息
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  找到餐厅: " << setw(36) << L.data[idx].name << " │" << endl;
        cout << "│  ID: " << setw(42) << L.data[idx].id << " │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        cout << "  确认删除(1-确认, 0-取消): ";
        int confirm;
        cin >> confirm;
        
        if (confirm == 1) {
            // 元素前移
            for (int i = idx; i < L.length - 1; i++) {
                L.data[i] = L.data[i + 1];
            }
            L.length--;
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  删除成功！                                          │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return true;
        } else {
            SetColor(14); // 黄色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  删除已取消！                                        │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return false;
        }
        
    } else if (deleteChoice == 2) {
        int id;
        cout << "  请输入要删除的餐厅ID: ";
        cin >> id;
        
        int idx = -1;
        for (int i = 0; i < L.length; i++) {
            if (L.data[i].id == id) {
                idx = i;
                break;
            }
        }
        
        if (idx == -1) {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  未找到ID为 " << setw(4) << id << " 的餐厅                  │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return false;
        }
        
        // 显示要删除的餐厅信息
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  找到餐厅: " << setw(36) << L.data[idx].name << " │" << endl;
        cout << "│  ID: " << setw(42) << L.data[idx].id << " │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        cout << "  确认删除(1-确认, 0-取消): ";
        int confirm;
        cin >> confirm;
        
        if (confirm == 1) {
            // 元素前移
            for (int i = idx; i < L.length - 1; i++) {
                L.data[i] = L.data[i + 1];
            }
            L.length--;
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  删除成功！                                          │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return true;
        } else {
            SetColor(14); // 黄色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  删除已取消！                                        │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return false;
        }
    } else {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  无效选择！                                          │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return false;
    }
}
void SortRestaurants(SeqList &L) {
    if (L.length == 0) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  列表为空，无法排序！                                │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }
    
    int sortChoice;
    SetColor(14); // 黄色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                   排序餐厅信息                        │" << endl;
    cout << "├────────────────────────────────────────────────────────┤" << endl;
    cout << "│  1. 按ID排序        2. 按价格排序                     │" << endl;
    cout << "│  3. 按评分排序                                         │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    cout << "  请选择排序方式: ";
    cin >> sortChoice;
    
    switch (sortChoice) {
        case 1: 
            SortByID(L);
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  按ID排序完成！                                    │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            ShowAll(L);
            break;
        case 2:
            SortByPrice(L);
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  按价格排序完成！                                  │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            ShowAll(L);
            break;
        case 3:
            SortByRating(L);
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  按评分排序完成！                                  │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            ShowAll(L);
            break;
        default:
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  无效选择！                                          │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
    }
}

// 按ID排序
void SortByID(SeqList &L) {
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.data[j].id > L.data[j + 1].id) {
                Restaurant temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
            }
        }
    }
}

// 按价格排序
void SortByPrice(SeqList &L) {
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.data[j].price > L.data[j + 1].price) {
                Restaurant temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
            }
        }
    }
}

// 按评分排序（从高到低）
void SortByRating(SeqList &L) {
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.data[j].rating < L.data[j + 1].rating) {
                Restaurant temp = L.data[j];
                L.data[j] = L.data[j + 1];
                L.data[j + 1] = temp;
            }
        }
    }
}

// 生成订单ID
int GenerateOrderID(OrderList &orders) {
    int max_id = 0;
    for (int i = 0; i < orders.length; i++) {
        if (orders.data[i].order_id > max_id) {
            max_id = orders.data[i].order_id;
        }
    }
    return max_id + 1;
}

// 保存订单到文件
void SaveOrdersToFile(OrderList &orders) {
    ofstream outFile("D:\\orders.txt", ios::out);
    if (!outFile) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  订单文件保存失败！                                    │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }

    for (int i = 0; i < orders.length; i++) {
        outFile << orders.data[i].order_id << " "
                << orders.data[i].restaurant_id << " "
                << orders.data[i].restaurant_name << " "
                << orders.data[i].order_time << " "
                << orders.data[i].people_count << " "
                << orders.data[i].total_amount << " "
                << orders.data[i].status << endl;
    }
    outFile.close();
}

// 从文件加载订单
void LoadOrdersFromFile(OrderList &orders) {
    ifstream inFile("D:\\orders.txt", ios::in);
    if (!inFile) {
        // 文件不存在是正常的，可能是第一次运行
        return;
    }

    Order o;
    while (inFile >> o.order_id >> o.restaurant_id >> o.restaurant_name 
                  >> o.order_time >> o.people_count >> o.total_amount >> o.status) {
        if (orders.length < orders.capacity) {
            orders.data[orders.length] = o;
            orders.length++;
        } else {
            break;
        }
    }
    inFile.close();
}

// 显示所有订单
void ShowAllOrders(OrderList &orders) {
    if (orders.length == 0) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  暂无订单记录！                                        │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return;
    }
    
    SetColor(11); // 浅蓝色
    cout << "┌─────────────────────────────────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│                                       所有订单记录                                           │" << endl;
    cout << "├──────┬────────────┬────────────────────┬────────────┬──────────┬──────────┬──────────────┤" << endl;
    cout << "│ 订单ID │  餐厅名称   │      预订时间      │    人数    │  金额(元) │  状态    │              │" << endl;
    cout << "├──────┼────────────┼────────────────────┼────────────┼──────────┼──────────┼──────────────┤" << endl;
    SetColor(7); // 恢复白色
    
    for (int i = 0; i < orders.length; i++) {
        Order &o = orders.data[i];
        
        // 转换时间格式
        struct tm *timeinfo = localtime(&o.order_time);
        char timeStr[20];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M", timeinfo);
        
        cout << "│ " << setw(4) << o.order_id << "  │ ";
        cout << setw(10) << o.restaurant_name << " │ ";
        cout << setw(18) << timeStr << " │ ";
        cout << setw(10) << o.people_count << " │ ";
        cout << setw(8) << fixed << setprecision(2) << o.total_amount << " │ ";
        
        // 状态显示
        if (o.status == 1) {
            SetColor(10); // 绿色
            cout << setw(8) << "有效";
            SetColor(7); // 恢复白色
        } else {
            SetColor(12); // 红色
            cout << setw(8) << "已取消";
            SetColor(7); // 恢复白色
        }
        cout << " │              │" << endl;
    }
    
    SetColor(11); // 浅蓝色
    cout << "├──────┼────────────┼────────────────────┼────────────┼──────────┼──────────┼──────────────┤" << endl;
    cout << "│                           共显示 " << setw(2) << orders.length << " 条订单记录                           │" << endl;
    cout << "└─────────────────────────────────────────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
}

// 显示订单详情
void ShowOrderDetail(Order order) {
    SetColor(11); // 浅蓝色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│                       订单详细信息                      │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    
    // 转换时间格式
    struct tm *timeinfo = localtime(&order.order_time);
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M", timeinfo);
    
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  订单ID: " << setw(40) << order.order_id << " │" << endl;
    cout << "│  餐厅名称: " << setw(38) << order.restaurant_name << " │" << endl;
    cout << "│  预订时间: " << setw(38) << timeStr << " │" << endl;
    cout << "│  用餐人数: " << setw(38) << order.people_count << " │" << endl;
    cout << "│  支付金额: " << setw(36) << fixed << setprecision(2) << order.total_amount << "元 │" << endl;
    cout << "│  订单状态: ";
    if (order.status == 1) {
        SetColor(10); // 绿色
        cout << setw(38) << "有效";
        SetColor(7); // 恢复白色
    } else {
        SetColor(12); // 红色
        cout << setw(38) << "已取消";
        SetColor(7); // 恢复白色
    }
    cout << " │" << endl;
    cout << "└────────────────────────────────────────────────────────┘" << endl;
}

// 预订餐厅
bool MakeReservation(SeqList &L, OrderList &orders) {
    if (orders.length >= orders.capacity) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  订单列表已满！                                        │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return false;
    }
    
    char name[50];
    cout << "  请输入要预订的餐厅名称: "; 
    cin >> name;
    int idx = SearchByName(L, name);
    
    if (idx != -1) {
        if (L.data[idx].remaining_tables > 0) {
            // 创建新订单
            Order newOrder;
            newOrder.order_id = GenerateOrderID(orders);
            newOrder.restaurant_id = L.data[idx].id;
            strcpy(newOrder.restaurant_name, L.data[idx].name);
            newOrder.order_time = time(NULL); // 当前时间
            
            cout << "  请输入用餐人数: ";
            cin >> newOrder.people_count;
            
            // 计算金额（简单计算：人均价格 * 人数）
            newOrder.total_amount = L.data[idx].price * newOrder.people_count;
            newOrder.status = 1; // 有效订单
            
            // 添加到订单列表
            orders.data[orders.length] = newOrder;
            orders.length++;
            
            // 减少餐厅可用桌数
            L.data[idx].remaining_tables--;
            
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  预订成功！                                            │" << endl;
            cout << "│  订单ID: " << setw(38) << newOrder.order_id << " │" << endl;
            cout << "│  剩余桌位: " << setw(37) << L.data[idx].remaining_tables << " │" << endl;
            cout << "│  支付金额: " << setw(35) << fixed << setprecision(2) << newOrder.total_amount << "元 │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            
            // 显示订单详情
            ShowOrderDetail(newOrder);
            return true;
        } else {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  预订失败，该餐厅已无空桌！                            │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
        }
    } else {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  未找到该餐厅！                                        │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
    }
    return false;
}

// 取消预订（直接取消桌位，不涉及订单）
bool CancelReservation(SeqList &L, OrderList &orders) {
    char name[50];
    cout << "  请输入要取消预订的餐厅名称: "; 
    cin >> name;
    int idx = SearchByName(L, name);
    
    if (idx != -1) {
        if (L.data[idx].remaining_tables < L.data[idx].total_tables) {
            L.data[idx].remaining_tables++;
            SetColor(10); // 绿色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  取消预订成功！                                      │" << endl;
            cout << "│  当前桌位: " << setw(37) << L.data[idx].remaining_tables << " │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
            return true;
        } else {
            SetColor(12); // 红色
            cout << "┌────────────────────────────────────────────────────────┐" << endl;
            cout << "│  取消预订失败，该餐厅桌位已全部空闲！                │" << endl;
            cout << "└────────────────────────────────────────────────────────┘" << endl;
            SetColor(7); // 恢复白色
        }
    } else {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  未找到该餐厅！                                        │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
    }
    return false;
}

// 取消订单
bool CancelOrder(OrderList &orders, SeqList &restaurants) {
    if (orders.length == 0) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  暂无订单记录！                                        │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return false;
    }
    
    int orderId;
    cout << "  请输入要取消的订单ID: ";
    cin >> orderId;
    
    // 查找订单
    int orderIdx = -1;
    for (int i = 0; i < orders.length; i++) {
        if (orders.data[i].order_id == orderId && orders.data[i].status == 1) {
            orderIdx = i;
            break;
        }
    }
    
    if (orderIdx == -1) {
        SetColor(12); // 红色
        cout << "┌────────────────────────────────────────────────────────┐" << endl;
        cout << "│  未找到有效订单或订单已取消！                          │" << endl;
        cout << "└────────────────────────────────────────────────────────┘" << endl;
        SetColor(7); // 恢复白色
        return false;
    }
    
    // 查找对应的餐厅
    int restaurantIdx = -1;
    for (int i = 0; i < restaurants.length; i++) {
        if (restaurants.data[i].id == orders.data[orderIdx].restaurant_id) {
            restaurantIdx = i;
            break;
        }
    }
    
    if (restaurantIdx != -1) {
        // 恢复餐厅桌位
        restaurants.data[restaurantIdx].remaining_tables++;
    }
    
    // 标记订单为已取消
    orders.data[orderIdx].status = 0;
    
    SetColor(10); // 绿色
    cout << "┌────────────────────────────────────────────────────────┐" << endl;
    cout << "│  订单取消成功！                                        │" << endl;
    if (restaurantIdx != -1) {
        cout << "│  当前桌位: " << setw(37) << restaurants.data[restaurantIdx].remaining_tables << " │" << endl;
    }
    cout << "└────────────────────────────────────────────────────────┘" << endl;
    SetColor(7); // 恢复白色
    
    return true;
}

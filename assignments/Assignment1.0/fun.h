#ifndef FUN_H
#define FUN_H

// 餐馆信息结构体
struct Restaurant {
    int id;
    char name[50];
    char type[20];
    float price;
    float rating;
    int total_tables;
    int remaining_tables;
};

// 手动实现顺序表
struct SeqList {
    Restaurant *data;  // 指向动态分配的数组
    int length;        // 当前存储的记录数
    int capacity;      // 顺序表最大容量
};

bool CancelReservation(SeqList &L); 
bool MakeReservation(SeqList &L);
void showmenu();
void InitList(SeqList &L);              // 初始化顺序表
bool AddRestaurant(SeqList &L);         // 增加餐馆信息
void ShowAll(SeqList &L);               // 显示所有信息
int SearchByName(SeqList &L, char name[]); // 按名称查找
void SortByPrice(SeqList &L);           // 排序算法
void SaveToFile(SeqList &L);            // 存储到文件
void LoadFromFile(SeqList &L);          // 从文件读取

#endif // FUN_H

#ifndef FUN_H
#define FUN_H

#include <ctime>

struct Restaurant {
    int id;
    char name[50];
    char type[20];
    float price;
    float rating;
    int total_tables;
    int remaining_tables;
};

// 新增：订单结构体
struct Order {
    int order_id;           // 订单ID
    int restaurant_id;      // 餐厅ID
    char restaurant_name[50]; // 餐厅名称
    time_t order_time;      // 预订时间
    int people_count;       // 人数
    float total_amount;     // 支付金额
    int status;             // 订单状态：0-已取消，1-有效
};

struct SeqList {
    Restaurant *data;
    int length;
    int capacity;
};

// 新增：订单列表结构
struct OrderList {
    Order *data;
    int length;
    int capacity;
};

// 颜色函数
void SetColor(int color);

// 主要功能
bool CancelReservation(SeqList &L, OrderList &orders); 
bool MakeReservation(SeqList &L, OrderList &orders);
void showmenu();
void InitList(SeqList &L);
bool AddRestaurant(SeqList &L);
void ShowAll(SeqList &L);
void SearchRestaurant(SeqList &L);
int SearchByName(SeqList &L, char name[]);
int SearchByID(SeqList &L, int id);
void ShowRestaurantDetail(Restaurant r);
void SortByPrice(SeqList &L);
void SortByID(SeqList &L);
void SortByRating(SeqList &L);
void SaveToFile(SeqList &L);
void LoadFromFile(SeqList &L);
bool DeleteRestaurant(SeqList &L);
void ReservationManagement(SeqList &L, OrderList &orders); // 修改参数
void SortRestaurants(SeqList &L);

//订单管理函数
void InitOrderList(OrderList &orders);
void SaveOrdersToFile(OrderList &orders);
void LoadOrdersFromFile(OrderList &orders);
void ShowAllOrders(OrderList &orders);
void ShowOrderDetail(Order order);
bool CancelOrder(OrderList &orders, SeqList &restaurants);
int GenerateOrderID(OrderList &orders);

#endif

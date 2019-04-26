#include <string.h>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

enum struct ColorInfo :int
{
    BLUE = 1,
    GREEN = 2,
    RED = 4,
    WHITE = 15
};



void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class Enemy
{
public:
    Enemy(int x, int y) :pos_x(x), pos_y(y) {};
    int pos_x;
    int pos_y;
    vector<pair<int, int>> Vec_Influence;
    void SetPos(int x, int y);
    void InsertInfluence(int area, int value);
private:
};


void Enemy::InsertInfluence(int area, int value)
{
    Vec_Influence.push_back(pair<int, int>(area, value));
}

void Enemy::SetPos(int x, int y)
{
    pos_x = x;
    pos_y = y;
}

class InfluenceMap
{
public:
    struct Node_Info
    {
        int value;
        int color;
    };
    void Update();
    InfluenceMap(int MAX_X, int MAX_Y);
    vector<Enemy*> Vec_Enemy;
    vector<vector<Node_Info>>* real_map;
    void Print();
    void InsertEnemy(Enemy* enemy);
    int GetColor(int value);
    void SetMaxValue(int value);
    ~InfluenceMap();

private:
    int Max_Value;
    int MAX_X;
    int MAX_Y;
};

InfluenceMap::InfluenceMap(int MAX_X, int MAX_Y)
{
    Max_Value = 0;  //default
    this->MAX_X = MAX_X;
    this->MAX_Y = MAX_Y;
    real_map = new vector<vector<Node_Info>>;
    for (int i = 0; i < MAX_Y; ++i)
    {
        vector<Node_Info> vec_temp;
        for (int j = 0; j < MAX_X; ++j)
        {
            vec_temp.push_back({ 0,(int)ColorInfo::WHITE });
        }
        real_map->push_back(vec_temp);
    }
}

InfluenceMap::~InfluenceMap()
{
    for (auto it = Vec_Enemy.begin(); it != Vec_Enemy.end(); ++it)
    {
        delete *it;
    }
}


void InfluenceMap::InsertEnemy(Enemy * enemy)
{
    Vec_Enemy.push_back(enemy);
}



void InfluenceMap::Update()
{
    for (auto it = Vec_Enemy.begin(); it != Vec_Enemy.end(); ++it)
    {
        for (auto it2 = (*it)->Vec_Influence.begin(); it2 != (*it)->Vec_Influence.end(); ++it2)
        {
            int area = it2->first;  //area
            int value = it2->second; //value
            int enemy_x = (*it)->pos_x;
            int enemy_y = (*it)->pos_y;


            for (int influence_y = enemy_y - area; influence_y <= enemy_y + area; ++influence_y)
            {
                for (int influence_x = enemy_x - area; influence_x <= enemy_x + area; ++influence_x)
                {
                    real_map->at(influence_y).at(influence_x).value += value;
                    if (real_map->at(influence_y).at(influence_x).value > Max_Value)
                        real_map->at(influence_y).at(influence_x).value = Max_Value;
                    real_map->at(influence_y).at(influence_x).color = GetColor(real_map->at(influence_y).at(influence_x).value);
                }
                real_map->at(enemy_y).at(enemy_x).color = GetColor(0);
                real_map->at(enemy_y).at(enemy_x).value = Max_Value;
            }

        }
    }
}


void InfluenceMap::Print()
{
    for (int i = 0; i < MAX_Y; ++i)
    {
        for (int j = 0; j < MAX_X; ++j)
        {
            int Node_Color = real_map->at(i).at(j).color;
            int value = real_map->at(i).at(j).value;
            SetColor(Node_Color);
            cout << value << " ";
            SetColor((int)ColorInfo::WHITE);
        }
        cout << endl;
    }
}

int InfluenceMap::GetColor(int value)
{
    int ret = (int)ColorInfo::WHITE;;
    switch (value)
    {
    case 9:
        ret = (int)ColorInfo::RED;
        break;
    case 8:
        ret = (int)ColorInfo::BLUE;
        break;
    case 1:
        ret = (int)ColorInfo::GREEN;
        break;
    default:
        ret = (int)ColorInfo::WHITE;
        break;
    }
    return ret;
}

void InfluenceMap::SetMaxValue(int value)
{
    Max_Value = value;
}

struct  Point
{
    int x;
    int y;
};


//int main()
//{
//    InfluenceMap map(20, 20);
//    map.SetMaxValue(9);
//    Enemy* enemy = new Enemy(5, 5);
//    enemy->InsertInfluence(2, 8);
//    map.InsertEnemy(enemy);
//
//    enemy = new Enemy(10, 5);
//    enemy->InsertInfluence(3, 1);
//    map.InsertEnemy(enemy);
//
//    map.Update();
//    map.Print();
//}


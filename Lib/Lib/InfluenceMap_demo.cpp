#include <string.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <list>
using namespace std;

enum struct ColorInfo :int
{
    BLUE = 1,
    GREEN = 2,
    YELLOW = 14,
    RED = 4,
    WHITE = 15
};

struct Influence_Info
{
    int area_start;
    int area_end;
    int value;
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
    list<Influence_Info> List_Influence;
    void SetPos(int x, int y);
    void SetInfluence(Influence_Info info);
private:
};

void Enemy::SetInfluence(Influence_Info info)
{
    List_Influence.push_back(info);
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
        for (auto it2 = (*it)->List_Influence.begin(); it2 != (*it)->List_Influence.end(); ++it2)
        {
            int enemy_x = (*it)->pos_x;
            int enemy_y = (*it)->pos_y;

            int area_start = it2->area_start;
            int area_end = it2->area_end;
            int value = it2->value;


            for (int pos_x = enemy_x - area_start - 1; pos_x <= enemy_x + area_end; ++pos_x)
            {
                for (int pos_y = enemy_y - area_start - 1; pos_y <= enemy_y + area_end; ++pos_y)
                {
                    if ((pos_x > enemy_x - area_start && pos_x < enemy_x + area_start) &&
                        (pos_y > enemy_y - area_start && pos_y < enemy_y + area_start))
                    {
                        continue;
                    }
                    real_map->at(pos_y).at(pos_x).value += value;
                    if (real_map->at(pos_y).at(pos_x).value > Max_Value)
                    {
                        real_map->at(pos_y).at(pos_x).value = Max_Value;
                    }
                    real_map->at(pos_y).at(pos_x).color = GetColor(real_map->at(pos_y).at(pos_x).value);
                }
            }
            real_map->at(enemy_y).at(enemy_x).color = GetColor(0);
            real_map->at(enemy_y).at(enemy_x).value = Max_Value;



            //for (int round = 0; round < area_end - area_start; ++round)
            //{
            //    for (int pos_x = enemy_x - round; pos_x <= enemy_x + round; ++pos_x)
            //    {
            //        int pos_y = enemy_y - round;
            //        real_map->at(pos_y).at(pos_x).value += value;
            //        real_map->at(pos_y).at(pos_x).color = GetColor(real_map->at(pos_y).at(pos_x).value);
            //    }

            //}
            //real_map->at(enemy_y).at(enemy_x).color = GetColor(0);
            //real_map->at(enemy_y).at(enemy_x).value = Max_Value;

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
    int ret = (int)ColorInfo::WHITE;
    switch (value)
    {
    case 1:
    case 2:
    case 3:
        ret = (int)ColorInfo::GREEN;
        break;

    case 4:
    case 5:
    case 6:
        ret = (int)ColorInfo::BLUE;
        break;

    case 7:
    case 8:
        ret = (int)ColorInfo::YELLOW;
        break;

    case 9:
        ret = (int)ColorInfo::RED;
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

//
//int main()
//{
//
//    InfluenceMap map(30, 20);
//    map.SetMaxValue(9);
//    Enemy* enemy = new Enemy(5, 5);
//    enemy->SetInfluence({ 2,3,7 });
//    enemy->SetInfluence({ 0,1,9 });
//    map.InsertEnemy(enemy);
//
//    enemy = new Enemy(10, 5);
//    enemy->SetInfluence({ 1,2,1 });
//    map.InsertEnemy(enemy);
//
//    enemy = new Enemy(14, 9);
//    enemy->SetInfluence({ 1,2,5 });
//    map.InsertEnemy(enemy);
//
//
//    map.Update();
//    map.Print();
//}
//

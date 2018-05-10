#include <iostream>
#include <string>
#include <vector>
#include <MDatabase.h>
using namespace std;

vector<vector<string>> Result(1024);

int main()
{
    int nRow;
    MDatabase Conn;
    int res = Conn.Connect("localhost", "root", "admin", "myim", 0);
    Conn.SetEncoding("utf-8");
    Conn.ExecSQL("select * from user", Result,nRow);


    //Conn.ExecSQL("insert into user values(\"012\", \"user2\", \"test\")", Result, nRow);





    cout << "[" << endl;
    for (int j = 0; j < nRow; j++) {
        cout << "[" << " ";
        for (int k = 0; k < Result[0].size(); k++) {
            cout << Result[j][k] << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;





}






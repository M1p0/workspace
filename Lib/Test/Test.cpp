#include <iostream>
#include <string>
#include <vector>
#include <MDatabase.h>
#include <CFileIO.h>
using namespace std;

vector<vector<string>> Result(1024);
CFileIO File;
int main()
{
    char SQL[1024];
    memset(SQL, 0, 1024);
    File.Read("d:\\test.txt", SQL, 0, 1024);
    cout << "SQL:\n\n" << SQL << "\n\n" << endl;
    int nRow;
    MDatabase Conn;
    int res = Conn.Connect("192.168.1.2", "root", "admin", "myim", 0);
    Conn.SetEncoding("utf-8");
    Conn.ExecSQL(SQL, Result, nRow);

    cout << "Result:" << endl;
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






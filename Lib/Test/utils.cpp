#include "utils.h"
#include "FileIO.h"
using namespace std;

string getcmd()
{
    string cmd;
    cin >> cmd;
    return cmd;
}


void test()
{
    const int count = 10;
    DWORD s = GetTickCount();
    FileIO File;
    DWORD SSD_s, SSD_e, SSD_t = 0, HDD_s, HDD_e, HDD_t = 0;
    cout << "----------------SSD----------------" << endl;
    for (int i = 0; i < count; i++)
    {
        SSD_s = GetTickCount();
        File.Copy("d:\\test\\ubuntu.iso", "c:\\test2\\ubuntu.iso");
        SSD_e = GetTickCount();
        SSD_t = SSD_t + SSD_e - SSD_s;
    }

    cout << "----------------HDD----------------" << endl;
    for (int i = 0; i < count; i++)
    {
        HDD_s = GetTickCount();
        File.Copy("d:\\test\\ubuntu.iso", "g:\\test2\\ubuntu.iso");
        HDD_e = GetTickCount();
        HDD_t = HDD_t + HDD_e - HDD_s;
    }
    cout << "SSD average:" << SSD_t / count << "ms" << endl;
    cout << "HDD average:" << HDD_t / count << "ms" << endl;
    //cout<<"time:"<<GetTickCount()-s<<"ms"<<endl;
}


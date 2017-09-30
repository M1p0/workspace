#include "CFileIO.h"
#define buffer 1024        //1MB
string CFileIO::Read(string szPath, string szMode)
{
    string result;
    char temp[buffer];
    FILE *p = fopen(szPath.c_str(), szMode.c_str());
    if (p == NULL)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        while (fgets(temp, 1000, p) != NULL)
        {
            result += temp;
        }
    }
    fclose(p);
    return result;
}

void CFileIO::Write(string szPath, string szData, string szMode)   //δ��������buffer һ����д��
{
    FILE *p = fopen(szPath.c_str(), szMode.c_str());
    if (p == NULL)
    {
        cout << "Failed to open File!" << endl;
    }
    else
    {
        fputs(szData.c_str(), p);
    }
    fclose(p);
}
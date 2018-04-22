#include "CFileIO.h"
#include "windows.h"




void CFileIO::GetSize(char* szPath)
{
    FILE *p = fopen(szPath, "rb+");;
    if (p == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        _fseeki64(p, 0, SEEK_END);
        fgetpos(p, &FileSize);
        //fseek(p, 0, SEEK_END);
        //FileSize = ftell(p);
        rewind(p);
    }
}



char* CFileIO::Read(char* szPath, long offset, long size)
{
    char* buff = nullptr;
    FILE *p = fopen(szPath, "rb+");
    if (p == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        fseek(p, offset, SEEK_SET);
        buff = new char[size];
        memset(buff, 0, size);
        fread(buff, 1, size, p);
    }

    fclose(p);
    return buff;
}

void CFileIO::Write(const char* szPath,const char* szData, long offset, long Size)
{
    FILE *p = fopen(szPath, "ab+");
    if (p == nullptr)
    {
        cout << "Failed to open File!" << endl;
    }
    else
    {
        fseek(p, offset, SEEK_SET);
        fwrite(szData, 1, Size, p);
    }
    fclose(p);
}



void CFileIO::Copy(char* SourceFile, char* NewFile)
{
    fpos_t Rest = 0;
    char* buff = nullptr;
    GetSize(SourceFile);
    Rest = FileSize;
    FILE *p = fopen(SourceFile, "rb+");
    FILE *fs = fopen(NewFile, "wb+");
    if (p == nullptr || fs == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {

        while (Rest>0)
        {
            if (Rest<buff_size)
            {
                buff = new char[Rest];
                memset(buff, 0, Rest);
                fread(buff, Rest, 1, p);
                fwrite(buff, Rest, 1, fs);
                delete buff;
                buff = nullptr;
                Rest = 0;
            }
            else
            {
                buff = new char[buff_size];
                memset(buff, 0, buff_size);
                //fgets(buff, buff_size, p);
                fread(buff, buff_size, 1, p);
                //fputs(buff, fs);
                fwrite(buff, buff_size, 1, fs);
                delete buff;
                buff = nullptr;
                Rest = Rest - buff_size;
            }
        }
    }
    fclose(p);
    fclose(fs);

}
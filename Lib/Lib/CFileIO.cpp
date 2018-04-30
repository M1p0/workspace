#include "CFileIO.h"

CFileIO::CFileIO()
{
    Init();
}

CFileIO::~CFileIO()
{
    delete[] Shared_buffer;
    Shared_buffer = nullptr;
}

int CFileIO::Init()
{
    if (Shared_buffer == nullptr)
    {
        Shared_buffer = new char[Shared_buff_size];
        memset(Shared_buffer, 0, Shared_buff_size);
    }
    else
    {
        if (Shared_buff_size == 1024 * 1024)
        {
            memset(Shared_buffer, 0, Shared_buff_size);
        }
        else
        {
            delete[] Shared_buffer;
            Shared_buffer = nullptr;
            Shared_buffer = new char[Shared_buff_size];
            memset(Shared_buffer, 0, Shared_buff_size);
        }
    }
    return 0;
}

void CFileIO::GetSize(const char* szPath, int64_t* Size)
{
    FILE *p = fopen(szPath, "rb+");;
    if (p == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        _fseeki64(p, 0, SEEK_END);
        fgetpos(p, Size);
        rewind(p);
    }
}



void CFileIO::Read(const char* szPath, char* buffer, long offset, int64_t buffer_size)
{
    int64_t FileSize = 0;
    GetSize(szPath, &FileSize);
    FILE *p = fopen(szPath, "rb");
    if (p == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        _fseeki64(p, offset, SEEK_SET);
        fread(Shared_buffer, 1, buffer_size, p);
    }
    cout << Shared_buffer << endl;
    memcpy(buffer, Shared_buffer, buffer_size);
    fclose(p);
    Init();
}

void CFileIO::Write(const char* szPath, const char* szData, long offset, int64_t buffer_size)
{
    FILE *p = fopen(szPath, "ab+");
    if (p == nullptr)
    {
        cout << "Failed to open File!" << endl;
    }
    else
    {
        _fseeki64(p, offset, SEEK_SET);
        fwrite(szData, 1, buffer_size, p);
    }
    fclose(p);
}



void CFileIO::Copy(const char* SourceFile, const char* NewFile)
{
    int64_t FileSize = 0;
    int64_t Rest = 0;
    char* buff = nullptr;
    GetSize(SourceFile, &FileSize);
    Rest = FileSize;
    FILE *p = fopen(SourceFile, "rb");
    FILE *fs = fopen(NewFile, "wb+");
    if (p == nullptr || fs == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        while (Rest > 0)
        {
            if (Rest < Shared_buff_size)
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
                buff = new char[Shared_buff_size];
                memset(buff, 0, Shared_buff_size);
                //fgets(buff, buff_size, p);
                fread(buff, Shared_buff_size, 1, p);
                //fputs(buff, fs);
                fwrite(buff, Shared_buff_size, 1, fs);
                delete buff;
                buff = nullptr;
                Rest = Rest - Shared_buff_size;
            }
        }
    }
    fclose(p);
    fclose(fs);

}

void CFileIO::SetBuffSize(int64_t Size)
{
    Shared_buff_size = Size;
    Init();
}

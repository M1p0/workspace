#include "CFileIO.h"

CFileIO::CFileIO()
{
    Init();
}

CFileIO::~CFileIO()
{
    delete[] Shared_Buffer;
    Shared_Buffer = nullptr;
}

int CFileIO::Init()
{
    if (Shared_Buffer == nullptr)
    {
        Shared_Buffer = new char[Shared_Buff_Size];
        memset(Shared_Buffer, 0, Shared_Buff_Size);
    }
    else
    {
        if (Shared_Buff_Size == 1024 * 1024)
        {
            memset(Shared_Buffer, 0, Shared_Buff_Size);
        }
        else
        {
            delete[] Shared_Buffer;
            Shared_Buffer = nullptr;
            Shared_Buffer = new char[Shared_Buff_Size];
            memset(Shared_Buffer, 0, Shared_Buff_Size);
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



void CFileIO::Read(const char* szPath, char* Buffer, long Offset, int64_t Buffer_Size)
{
    int64_t FileSize = 0;
    int64_t Current = Offset;
    GetSize(szPath, &FileSize);
    int64_t Rest = FileSize;
    FILE *p = fopen(szPath, "rb");
    if (p == nullptr)
    {
        cout << "Read Failed!" << endl;
    }
    else
    {
        _fseeki64(p, Offset, SEEK_SET);
        if (Buffer_Size < Shared_Buff_Size)
        {
            fread(Shared_Buffer, 1, Buffer_Size, p);
            memcpy(Buffer, Shared_Buffer, Buffer_Size);
            Current = Current + Buffer_Size;
        }
        else
        {
            while (Rest > 0)
            {
                memset(Shared_Buffer, 0, Shared_Buff_Size);
                if (Rest <= Shared_Buff_Size)
                {
                    fread(Shared_Buffer, Rest, 1, p);
                    memcpy(Buffer + Current, Shared_Buffer, Rest);
                    Rest = 0;
                    Current = Current + Rest;
                }
                else   //Rest>Shared_Buff_Size
                {
                    fread(Shared_Buffer, Shared_Buff_Size, 1, p);
                    memcpy(Buffer + Current, Shared_Buffer, Shared_Buff_Size);
                    Rest = Rest - Shared_Buff_Size;
                    Current = Current + Shared_Buff_Size;
                }
            }
        }
    }
    fclose(p);
    Init();
}

void CFileIO::Write(const char* szPath, const char* szData, long Offset, int64_t Buffer_Size)
{
    FILE *p = fopen(szPath, "ab+");
    if (p == nullptr)
    {
        cout << "Failed to open File!" << endl;
    }
    else
    {
        _fseeki64(p, Offset, SEEK_SET);
        fwrite(szData, 1, Buffer_Size, p);
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
            if (Rest < Shared_Buff_Size)
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
                buff = new char[Shared_Buff_Size];
                memset(buff, 0, Shared_Buff_Size);
                //fgets(buff, buff_size, p);
                fread(buff, Shared_Buff_Size, 1, p);
                //fputs(buff, fs);
                fwrite(buff, Shared_Buff_Size, 1, fs);
                delete buff;
                buff = nullptr;
                Rest = Rest - Shared_Buff_Size;
            }
        }
    }
    fclose(p);
    fclose(fs);

}

void CFileIO::SetBuffSize(int64_t Size)
{
    Shared_Buff_Size = Size;
    Init();
}

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
        return;
    }
    else
    {
#ifdef _WIN32
        _fseeki64(p, 0, SEEK_END);
        fgetpos(p, Size);
#else
        fseeko64(p, 0, SEEK_END);
        fpos_t temp;
        fgetpos(p, &temp);
        *Size = temp.__pos;
#endif // _WIN32
        rewind(p);
    }
    fclose(p);

}



int64_t CFileIO::Read(const char* szPath, char* Buffer, long Offset, int64_t Buffer_Size)
{
    int64_t FileSize = 0;
    int64_t Current = Offset;
    int64_t Rest = 0;
    memset(Buffer, 0, Buffer_Size);
    GetSize(szPath, &FileSize);
    if (Buffer_Size <= FileSize)
    {
        Rest = Buffer_Size;
    }
    else
    {
        Rest = FileSize;
    }
    FILE *p = fopen(szPath, "rb");
    if (p == nullptr)
    {
        fclose(p);
        return -1;
    }
    else
    {
#ifdef _WIN32
        _fseeki64(p, Offset, SEEK_SET);
#else
        fseeko64(p, Offset, SEEK_SET);
#endif // _WIN32
        if (Rest < Shared_Buff_Size)
        {
            fread(Shared_Buffer, 1, Rest, p);
            memcpy(Buffer, Shared_Buffer, Rest);
            Current = Current + Rest;
            Rest = 0;
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
    return Current;
}

int64_t CFileIO::Write(const char* szPath, const char* szData, long Offset, int64_t Data_Size)
{
    int64_t ret = 0;
    FILE *p = fopen(szPath, "ab+");
    if (p == nullptr)
    {
        cout << "Failed to open File!" << endl;
        ret = -1;
    }
    else
    {
#ifdef _WIN32
        _fseeki64(p, Offset, SEEK_SET);
#else
        fseeko64(p, Offset, SEEK_SET);
#endif // _WIN32
        fwrite(szData, 1, Data_Size, p);
        ret = Data_Size;
    }
    fclose(p);
    return ret;
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
        return;
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

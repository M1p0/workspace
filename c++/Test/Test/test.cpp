#include <stdio.h>     
#include <afxinet.h>  

int main()
{
    CInternetSession session("HttpClient");
    char * url = "http://www.google.com";
    CHttpFile *pfile = (CHttpFile *)session.OpenURL(url);

    DWORD dwStatusCode;
    pfile->QueryInfoStatusCode(dwStatusCode);
    if (dwStatusCode == HTTP_STATUS_OK)
    {
        CString content;
        CString data;
        while (pfile->ReadString(data))
        {
            content += data + "\r\n";
        }
        content.TrimRight();
        printf(" %s\n ", content);
    }
    pfile->Close();
    delete pfile;
    session.Close();

    return    0;
}
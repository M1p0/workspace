#include <iostream>
#include <string>
#include "tools.h"
#include "CFileIO.h"
using namespace std;




int main()
{
    
    CFileIO File;
    File.Copy("D:\\test\\win.iso", "d:\\test2\\win.iso");
    //File.Copy("D:\\test\\ubuntu.iso", "d:\\test2\\ubuntu.iso");
    File.GetSize("D:\\test\\win.iso");


}






#include "xzero.h"
#include "gtest/gtest.h"

# pragma warning(disable: 4996)


TEST(KSGCodeTest, ShortString)
{
    char  szBuff[1024] = { '\0' };
    char *pTestStr     = "hello, world!";
    DWORD uKey         = 123456789;
    DWORD uLen         = ::strlen(pTestStr);

    ::strcpy(szBuff, pTestStr);
    xzero::KG_KSGCode::Encode((BYTE *)szBuff, uLen, &uKey);
    xzero::KG_KSGCode::Decode((BYTE *)szBuff, uLen, &uKey);

    EXPECT_STREQ(pTestStr, (char *)szBuff);
}

TEST(KSGCodeTest, LongString)
{
    char  szBuff[1024] = { '\0' };
    char *pTestStr     = "abcdefghijklmvopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmvopqrstuvwxyz12345678901234";
    DWORD uKey         = 123456789;
    DWORD uLen         = ::strlen(pTestStr);

    ::strcpy(szBuff, pTestStr);
    xzero::KG_KSGCode::Encode((BYTE *)szBuff, uLen, &uKey);
    xzero::KG_KSGCode::Decode((BYTE *)szBuff, uLen, &uKey);

    EXPECT_STREQ(pTestStr, (char *)szBuff);
}

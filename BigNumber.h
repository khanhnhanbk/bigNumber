#pragma once

#include <string>
std::string addBigNumer(const std::string A, const std::string B)
{
    size_t posA{A.length()}, posB{B.length()};
    int carry = 0;
    size_t pos = posA > posB ? posA : posB;
    std::string res(pos, '0');
    while (posA > 0 || posB > 0)
    {
        int digit{carry};
        if (posA > 0)
        {
            digit += A[posA - 1] - '0';
            posA--;
        }
        if (posB > 0)
        {
            digit += B[posB - 1] - '0';
            posB--;
        }

        res[pos - 1] = char(digit % 10 + int('0'));
        carry = digit / 10;
        pos--;
    }
    if (carry > 0)
        res = char(carry + int('0')) + res;
    return res;
}
std::string multiplieBigNumber(const std::string A, const int B)
{
    if (B == 0)
        return "0";
    size_t posA{A.length()};
    int carry = 0;
    std::string res(posA, '0');
    while (posA > 0)
    {
        int digit{carry};
        digit += (A[posA - 1] - '0') * B;
        res[posA - 1] = char(digit % 10 + int('0'));
        carry = digit / 10;
        posA--;
    }
    if (carry > 0)
        res = char(carry + int('0')) + res;
    return res;
}
std::string multiplieBigNumber(const std::string A, const std::string B)
{
    std::string res("0");
    size_t posB = 0;
    while (posB < B.length())
    {
        res = res + '0';
        res = addBigNumer(res, multiplieBigNumber(A, B[posB] - '0'));
        posB++;
    }
    return res;
}
std::string binaryToDecimal(const std::string A)
{
    std::string res = "0";
    size_t posA = 0;
    while (posA < A.length())
    {
        res = multiplieBigNumber(res, 2);
        if (A[posA] == '1')
            res = addBigNumer(res, "1");
        posA++;
    }
    return res;
}
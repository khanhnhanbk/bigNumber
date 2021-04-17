#include <iostream>
#include <string>
#include <fstream>
#include "BigNumber.h"
using namespace std;

int main()
{
    int N;
    std::string binaryNum;
    long Q;
    std::ifstream ifs("inputFile.txt");
    std::ofstream ofs("outputFile.txt");
    if (ifs.is_open() && ofs.is_open())
    {
        ifs >> N;
        ifs >> binaryNum;
        ifs >> Q;
        for (long i = 0; i < Q; i++)
        {
            bool typeQ;
            ifs >> typeQ;
            if (typeQ)
            {
                size_t index;
                ifs >> index;
                binaryNum[index] = '1';
            }
            else
            {
                size_t x, y;
                ifs >> x >> y;
                ofs << binaryToDecimal(binaryNum.substr(x, y - x + 1)) << '\n';
            }
        }
        ofs.close();

        ifs.close();
    }
    return 0;
}
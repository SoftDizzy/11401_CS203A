/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/20: Initial implementation
    - 2025/11/22: modified hash function
    - 2025/11/30: Final check

   Developer: Jia-Zhe Lee <headmarkoqwe@gmail.com>

   References: 放在README.md裡
 */
#include "hash_fn.hpp"
#include <cmath>

int myHashInt(int key, int m) 
{
    if (m <= 0) return 0;               //確保Table size是有效數

    long long safe_key = key;           //使用long long是為了避免overflow
    if (safe_key < 0)                   //處理餘數可能為負數的情況
    {
        safe_key = -safe_key;
    }
    return static_cast<int>(safe_key % m);  
}


int myHashString(const std::string& str, int m) 
{
    if (m <= 0) return 0;
    if (str.empty()) return 0;             //防呆機制

    unsigned long hash = 0;
    int p = 31;                            //選擇一個比英文字母還多的質數，減少衝突

    for (char c: str)                      //Travel字串中的每個字元
    {                                      //賦予權重，來區分字母相同但順序不同的字(eg:"cat"，"act")
        hash = (hash * p + static_cast<unsigned char>(c));

        hash = hash % m;                  // 確保hash值在Table Size的範圍裡
    }

    return static_cast<int>(hash);
}

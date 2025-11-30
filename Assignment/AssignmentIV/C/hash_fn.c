/*
   ========================================
   hash_fn.c — implement your hash functions
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

#include "hash_fn.h"
#include <stdio.h>

int myHashInt(int key, int m) 
{
    if (m <= 0) return 0;           //防呆機制

    long long safe_key = key;       //使用long long是為了避免overflow
    if (safe_key < 0)
    {
        safe_key = -safe_key;       //處理餘數可能為負數的情況
    }

    return (int)(safe_key % m);
}

int myHashString(const char* str, int m) 
{
    if (m <= 0) return 0;           //防呆機制
    if (str == NULL) return 0;

    unsigned long hash = 0;
    int p = 31;                     //選擇一個比英文字母還多的質數，減少衝突

    while (*str != '\0')            //Travel字串，直到遇到結尾字元
    {
        hash = (hash * p + (unsigned char)(*str));        //將目前的hash乘上31，再加上當前字元
        hash = hash % m;            //防止overflow
        str++;                      //移動指標到下個字元
    }
    
    return (int)hash;
}
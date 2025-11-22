/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/20: Initial implementation
    - 2025/11/22: modified hash function

  Developer: Jia-Zhe Lee <headmarkoqwe@gmail.com>
 */

#include "hash_fn.h"
#include <stdio.h>

int myHashInt(int key, int m) 
{
    if (m <= 0) return 0;

    long long safe_key = key;
    if (safe_key < 0)
    {
        safe_key = -safe_key;
    }

    return (int)(safe_key % m);
}

int myHashString(const char* str, int m) 
{
    if (m <= 0) return 0;
    if (str == NULL) return 0;

    unsigned long hash = 0;
    int p = 31;

    while (*str != '\0')
    {
        hash = (hash * p + (unsigned char)(*str));
        hash = hash % m;
        str++;
    }
    
    return (int)hash;
}
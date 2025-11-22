/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/20: Initial implementation
    - 2025/11/22: modified hash function
    
   Developer: Jia-Zhe Lee <headmarkoqwe@gmail.com>
 */
#include "hash_fn.hpp"
#include <cmath>

int myHashInt(int key, int m) 
{
    if (m <= 0) return 0;

    long long safe_key = key;
    if (safe_key < 0)
    {
        safe_key = -safe_key;
    }
    return static_cast<int>(safe_key % m);  
}


int myHashString(const std::string& str, int m) 
{
    if (m <= 0) return 0;
    if (str.empty()) return 0;

    unsigned long hash = 0;
    int p = 31;

    for (char c: str)
    {
        hash = (hash * p + static_cast<unsigned char>(c));

        hash = hash % m;
    }

    return static_cast<int>(hash);
}

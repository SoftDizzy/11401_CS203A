# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
To implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

## Development Environment
* **OS:** Windows 11
* **IDE:** Visual Studio Code
* **Compiler:** MinGW-w64 (GCC/G++)
* **Terminal:** PowerShell

## Developer
* **Name:** [Jia-Zhe_Lee]
* **Email:** [headmarkoqwe@gmail.com]

## My Hash Function
### Integer Keys 
- Formula / pseudocode (in c++):
  ```text
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
  ```
- Rationale: 
    - 處理負數: 在 C++ ，負數取餘數 (eg: -5 % 3 = -2)會是負數，但Array的Index不能是負的，因此我先將他轉成正數，使用long long來存則是為了防止 key為最小負整數時，轉正會Overflow.
    - 除留餘數法: 能將算出的數字控制在 0 到 m-1 的範圍內，但如果要減少碰撞，就必須注意 m (Table Size) 的選擇， 例如可以用質數來減少碰撞.


### Non-integer Keys
- Formula / pseudocode:
  ```text
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

  ```
- Rationale: 
    - 多項式雜湊: 若直接將 ASCII 加總，有可能會碰撞 (eg: cat = act) 因此為了區分可以將每個字母乘上權重，這邊選擇 31 是因為英文字母有 26 個，選擇一個較大的質數可以減少衝突，在迴圈裡 %m 則可以防止Overflow.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++ (MinGW-64)
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | 會有嚴重的碰撞，(eg: 21,51 的index都會是1) |
| 11             | 10, 0, 1, 2, ...       | 21的index為10，51的index則為7 (沒碰撞了)            |
| 37             | 20, 21, 22, 23, ...    | 21的index為21，51的index則為14 (沒碰撞且分布的更廣)            |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  .\Makefile.bat all
  
  # Build only C version
  .\Makefile.bat c
  
  # Build only C++ version
  .\Makefile.bat cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  .\Makefile.bat clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  .\hash_c.exe
  ```
  or
  ```bash
  .\hash_cpp.exe
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21        1
  22        2
  23        3
  24        4
  25        5
  26        6
  27        7
  28        8
  29        9
  30        0
  51        1
  52        2
  53        3
  54        4
  55        5
  56        6
  57        7
  58        8
  59        9
  60        0


  === Table Size m = 11 ===
  Key     Index
  -----------------
  21        10
  22        0
  23        1       
  24        2
  25        3
  26        4
  27        5
  28        6
  29        7
  30        8
  51        7
  52        8
  53        9
  54        10
  55        0
  56        1
  57        2
  58        3
  59        4
  60        5
  

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21        21
  22        22
  23        23 
  24        24
  25        25
  26        26
  27        27
  28        28
  29        29
  30        30
  51        14
  52        15
  53        16
  54        17
  55        18
  56        19
  57        20
  58        21
  59        22
  60        23

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21        1
  22        2
  23        3
  24        4
  25        5
  26        6
  27        7
  28        8
  29        9
  30        0
  51        1
  52        2
  53        3
  54        4
  55        5
  56        6
  57        7
  58        8
  59        9
  60        0

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21        10
  22        0
  23        1       
  24        2
  25        3
  26        4
  27        5
  28        6
  29        7
  30        8
  51        7
  52        8
  53        9
  54        10
  55        0
  56        1
  57        2
  58        3
  59        4
  60        5

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21        21
  22        22
  23        23 
  24        24
  25        25
  26        26
  27        27
  28        28
  29        29
  30        30
  51        14
  52        15
  53        16
  54        17
  55        18
  56        19
  57        20
  58        21
  59        22
  60        23

  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat       2
  dog       4
  bat       1
  cow       9
  ant       3
  owl       8
  bee       0
  hen       5
  pig       0
  fox       3

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat       10
  dog       6
  bat       6
  cow       7
  ant       9
  owl       6
  bee       5
  hen       5
  pig       0
  fox       9

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat       27
  dog       3
  bat       28
  cow       20
  ant       25
  owl       23
  bee       26
  hen       29
  pig       27
  fox       18

  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers( Key = 21 ~ 30):
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8]
  Hash table (m=37): [21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: 當Table Size是10的時候，index會有重複性的碰撞，將Table Size改成質數後就有明顯的改善，且若是越大的質數，分布的會越廣.

## Analysis
- Prime vs non-prime `m`:
    - 觀察現象: 當 Table Size 是10的時候，hash function 會使 k%10 ，會直接對數字取個位數，所以當 key 是( 21~30 , 51~60 )他們的 index 是完全一樣的，都會產生碰撞. 但若改為質數時，這個規律就可以打破，當質數越大，分布的就越廣，當 Table Size 是37時，在這個數據的測試下則完全沒有碰撞.

- Patterns or collisions:
    - Table Size 為非質數( m = 10)時，Index 呈現規律的現象( 1, 2, 3,...)，且容易產生碰撞，
    - Table Size 為較大的質數( m = 37)時，Index 則呈現 (21, 22, 23,...)，不但分布的較廣，在這個數據測試下也完全沒有碰撞.

- Improvements: 
    - 改善碰撞: 將 Table Size 改為較大的質數，不但可以將資料分布的廣，還能減少碰撞.
    - 改善字串: 沒有單純的使用ASCII的加總，在相同字母但不同排列組合下會產生碰撞，因此使用多項式的方式，將字元乘上權重，且在迴圈取餘數，防止 Overflow ，區分不同字串.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
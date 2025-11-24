# VS Code

## 1.Development Environment

* **OS:** Windows 11
* **IDE:** Visual Studio Code
* **Compiler:** MinGW-w64 (GCC/G++)
    * 已將 `gcc` 與 `g++` 加入系統環境變數 (PATH)，確保可在終端機直接呼叫.

## 2. GitHub 

1.  **連接帳戶:** 在 VS Code 左下角登入 GitHub 帳戶，授權 VS Code 存取 Repository.
    - 若無法用git指令 需先用指令輸入自己的Github username、email..
2.  **Clone 專案:** 使用 `git clone` 指令將課程 Repository 下載至本機.
3.  **GitHub同步操作:**修改程式後可在Source Control裡Stage，並輸入Commit Message後Commit，最後再將本次的修改同步到Github裡

## 3. Makefile 

### 撰寫批次檔 (`Makefile.bat`)
因為我是在Windows的環境做開發，所以並沒有make這個工具，但可以透過寫批次檔來模擬，指令如下:
* `.\Makefile.bat all` : 同時編譯 C 與 C++ 版本。
* `.\Makefile.bat clean` : 清除所有編譯產生的 `.exe` 檔。


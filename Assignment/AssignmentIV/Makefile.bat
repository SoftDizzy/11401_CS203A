@echo off
REM ==========================================
REM  Windows Makefile for Assignment IV
REM  Usage:
REM    Makefile.bat        -> Builds both C and C++
REM    Makefile.bat all    -> Builds both C and C++
REM    Makefile.bat c      -> Builds only C
REM    Makefile.bat cxx    -> Builds only C++
REM    Makefile.bat clean  -> Removes .exe files
REM ==========================================

if "%1" == "" goto all
if /i "%1" == "all" goto all
if /i "%1" == "c" goto c
if /i "%1" == "cxx" goto cxx
if /i "%1" == "clean" goto clean

:all
echo [BUILD] Building BOTH C and C++ versions...
goto c
goto cxx
goto end

:c
echo [BUILD] Compiling C Version...
gcc -std=c11 C/main.c C/hash_fn.c -o hash_c.exe
if %errorlevel% neq 0 (
    echo [ERROR] C compilation failed!
    exit /b %errorlevel%
)
echo [SUCCESS] C Version built: hash_c.exe
if /i "%1" == "c" goto end

:cxx
echo [BUILD] Compiling C++ Version...
g++ -std=c++17 CXX/main.cpp CXX/hash_fn.cpp -o hash_cpp.exe
if %errorlevel% neq 0 (
    echo [ERROR] C++ compilation failed!
    exit /b %errorlevel%
)
echo [SUCCESS] C++ Version built: hash_cpp.exe
goto end

:clean
echo [CLEAN] Removing executable files...
del /Q *.exe 2>nul
echo [CLEAN] Done.
goto end

:end
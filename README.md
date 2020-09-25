## How to connect to Mysql using C++ in Mac Osx

There are 2 ways of doing that first using mysql.h file or using mysql connector

### Using Mysql.h
You can check demo1.cpp file which is using mysql.h
STEPS ARE:

By Default g++ uses clang compiler which comes with Xcode which is not a genuine compiler so you need to reinstall to have genuine compiler for g++
  You can check version with g++ --version
  1. Install macports using brew
  2. sudo port selfupdate
  3. sudo port install gcc46
  4. sudo port select --set gcc mp-gcc46
  5. Now check again gcc --version it should Say (gcc (MacPorts gcc46 4.6.4_11) 4.6.4) ...
  
  ..................


Read full article here https://medium.com/@khanakia/how-to-connect-to-mysql-using-c-in-mac-osx-17e1ada42ccd

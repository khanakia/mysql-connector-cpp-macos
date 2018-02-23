## How to connect to Mysql using C++ in Mac Osx

There are 2 ways of doing that first user mysql.h file or using mysql connector

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
  

  Installing and running mysql
  1. brew install mysql
  2. g++ -o demo1 -I/usr/local/include -I/usr/local/include/mysql -W -lmysqlclient -L/usr/local/lib demo1.cpp 
  3. Run ./demo1

### Using Mysql Connector CPP
  STEP 1 - Connector
  1. Download Mysql C++ Connector for Mac OS from here https://dev.mysql.com/downloads/connector/cpp/
  1. Extract cppconn direcotry and mysql_connection.h, mysql_driver.h, mysql_error.h file to the root direcotry of your application
  
  STEP 2 - CREATE DYLIB file from cpp connector using the same compiler we are using to compile our code  
  git clone https://github.com/mysql/mysql-connector-cpp .   
  git checkout 1.1  
  git tag  
  git checkout tags/1.1.9  
  which g++  
  which gcc  
  cmake -DCMAKE_C_COMPILER=/opt/local/bin/gcc -DCMAKE_CXX_COMPILER=/opt/local/bin/g++ .  
  make  
  make install  
  You should find dylib files in driver director and copy those files to the same directory where your code exists  
  
  STEP 3 - RUNNING CODE   
  g++ -o demo -I/usr/local/include -I/Volumes/D/www/c++ -L. -lmysqlcppconn demo.cpp  
  ./demo  

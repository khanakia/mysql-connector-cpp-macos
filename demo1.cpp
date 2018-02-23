
/*
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
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
// #include <vector> 
#include <mysql.h>

using namespace std;

int main(void)
{
  // std::vector<std::string> tables;
  MYSQL_RES *result;
  MYSQL_ROW row;
  MYSQL *connection, mysql;
  
  int state;
  
  mysql_init(&mysql);
  
  connection = mysql_real_connect(&mysql,"127.0.0.1","root","root","mysql",0,0,0);
  
  // cout << connection;
  if (connection == NULL)
  {
    std::cout << mysql_error(&mysql) << std::endl;
    // return tables;
  }

  state = mysql_query(connection, "SHOW TABLES");
  if (state !=0)
  {
    std::cout << mysql_error(connection) << std::endl;
  }
  
  result = mysql_store_result(connection);
  
  std::cout << "tables: " << mysql_num_rows(result) << std::endl;
  while ( ( row=mysql_fetch_row(result)) != NULL )
  {
    cout << row[0] << std::endl;
  }
  
  mysql_free_result(result);
  mysql_close(connection);
}
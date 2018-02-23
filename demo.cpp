
/*
  
  ERROR libc++abi.dylib: terminating with uncaught exception of type sql::SQLException
  Abort trap: 6


  STEP 1 - Connector
  Download Mysql C++ Connector for Mac OS from here https://dev.mysql.com/downloads/connector/cpp/
  Extract cppconn direcotry and mysql_connection.h, mysql_driver.h, mysql_error.h file to the root direcotry of your application
  
  STEP 2 - CREATE DYLIB file from cpp connector using the same compiler we are using to compile our code
  git clone https://github.com/mysql/mysql-connector-cpp
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

*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
cout << endl;


  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  /* Connect to the MySQL test database */
  con->setSchema("mysql");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
  while (res->next()) {
    cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    cout << res->getString("_message") << endl;
    cout << "\t... MySQL says it again: ";
    /* Access column data by numeric offset, 1 is the first column */
    cout << res->getString(1) << endl;
  }
  delete res;
  delete stmt;
  delete con;


cout << endl;

return EXIT_SUCCESS;
}
# cpp_persist
A C++ template project pre-configured for data persistance, unit testing and code coverage.

It uses the following projects:
- Data persistance
  - [ODB C++](https://www.codesynthesis.com/products/odb/)
  - [SQLite](https://www.sqlite.org/index.html)
- Unit testing
  - [Boost.Test](https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html)
- Coverage
  - [cmake-modules](https://github.com/bilke/cmake-modules)
  - [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html)
  - [lcov](http://ltp.sourceforge.net/coverage/lcov.php)

The SQLite database is saved at:
> cmake-build-debug/data.db

Code coverage output can be seen opening following file in a web browser:  
> cmake-build-debug/test_coverage/index.html

# CMake & SQLite & Boost.Test & GCOV

This is a cmake C++ project template configured for:
- Data persistance
  - [ODB C++](https://www.codesynthesis.com/products/odb/)
  - [SQLite](https://www.sqlite.org/index.html)
- Unit testing
  - [Boost.Test](https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html)
- Code coverage
  - [cmake-modules](https://github.com/bilke/cmake-modules)
  - [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html)
  - [lcov](http://ltp.sourceforge.net/coverage/lcov.php)

## Project structure

- The googletest and cmake-modules were added to this repository via git-subtree, so you can easily update these repositories with the following commands:

```Bash
cd root_of_this_project
git subtree pull --squash --prefix=cmake git@github.com:bilke/cmake-modules.git master
```

## Notes

The SQLite database is saved at:
> cmake-build-debug/data.db

Code coverage output can be seen opening following file in a web browser:  
> cmake-build-debug/test_coverage/index.html

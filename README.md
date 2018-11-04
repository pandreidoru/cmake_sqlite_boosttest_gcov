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

```
.
├── cmake
├── CMakeLists.txt
├── inc
│   └── Data.hpp
├── LICENSE
├── README.md
├── src
│   ├── CMakeLists.txt
│   ├── Data.cpp
│   └── main.cpp
└── test
    └── src
        ├── CMakeLists.txt
        ├── DataTest.cpp
        └── TestEntry.cpp
```

- The [cmake-modules](https://github.com/bilke/cmake-modules) was added to this repository via [git-subtree](https://github.com/apenwarr/git-subtree), so you can easily update it with the following command:

  ```Bash
  cd root_of_this_project
  git subtree pull --squash --prefix=cmake git@github.com:bilke/cmake-modules.git master
  ```

## Notes

- The SQLite database is saved at:
  > cmake-build-debug/data.db

- Code coverage output can be seen opening following file in a web browser:
  > cmake-build-debug/test_coverage/index.html

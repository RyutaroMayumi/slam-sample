# tdd-sample
C++ sample project for TDD（Test-Driven Development）

## Dependencies
- CMake >= 3.14
    ```
    $ wget -e https_proxy=http://[username]:[password]@10.1.8.72:8080 https://github.com/Kitware/CMake/releases/download/v3.18.3/cmake-3.18.3.tar.gz
    $ tar zxvf cmake-3.18.3.tar.gz
    $ sudo mv cmake-3.18.3 /opt
    $ cd /opt/cmake-3.18.3
    $ ./bootstrap
    $ make
    $ sudo make install
    $ sudo reboot
    ```
- GoogleTest
    ```
    tdd-sample$ git submodule update --init --recursive
    ```

## How to use
- Building project and execution
    ```
    tdd-sample$ make
    tdd-sample$ ./build/a.out
    ```
- Testing project
    ```
    tdd-sample$ git checkout test/master
    tdd-sample$ cd test
    tdd-sample/test$ mkdir build
    tdd-sample/test$ cd build
    tdd-sample/test/build$ cmake ..
    tdd-sample/test/build$ make
    tdd-sample/test/build$ make test
    ```
- Debugging project
    - Using vscode debug functions
        1. Move to debug tab in vscode
        2. Select "(gdb) Launch"
        3. Set break points on lines of interest
        4. Push "Start Debugging"
        - See .vscode/launch.json and .vscode/task.json for debug settings
    - Using gdb command on bash
        ```
        tdd-sample$ make clean && make debug
        tdd-sample$ gdb ./build/a.out
        ```
- Debugging test codes
    - Compiling test codes for debugging using cmake
        ```
        tdd-sample/test/build$ rm -rf *
        tdd-sample/test/build$ cmake -DCMAKE_BUILD_TYPE=Debug ..
        tdd-sample/test/build$ make
        tdd-sample/test/build$ gdb SampleClass-test
        ```
    - Instead of executing gdb command, you can debug test codes to select "(gdb) SampleClass-test Launch" on vscode debug tab.
    - (Note) Once you set -DCMAKE_BUILD_TYPE on bash, Makefile is created on the same setting. You should initialize the build setting, "-DCMAKE_BUILD_TYPE=", after you completed debugging.
- Profiling project
    - Using gprof
        ```
        tdd-sample$ make clean
        tdd-sample$ make prof
        tdd-sample$ ./build/a.out
        tdd-sample$ gprof ./build/a.out gmon.out > profile.txt
        ```

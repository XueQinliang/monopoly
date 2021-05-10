# monopoly

This is a work for HackPKU with Zimeng Zhang, Yan Zhou and Ming Yu.

# 开发说明

添加\*.h 文件，要加在 include 中，尽量保证一个.h 就有一个.cpp 文件加在 src 中

# 开发注意事项

.h 文件中，一定要在开头加类似这种：

```cpp
#ifndef MAP_H
#define MAP_H
```

在结尾加类似这种：

```cpp
#endif
```

不要在.h 文件中去定义变量，可以在 cpp 中定义，然后在 h 中添加 extern 供其他模块引用。

# 运行说明

在目录下，make 即可，如果没有 make，可以尝试 mingw32-make 或者 mingw64-make，最好在 bash 下运行。

make clean 可以清除生成的中间文件和可执行文件。

一键编译运行可以用: run.sh 或者 run.bat。

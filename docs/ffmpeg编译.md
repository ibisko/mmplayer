```sh
# 准备编译源代码的脚本
./configure --prefix=./output --enable-shared --disable-x86asm
# --prefix=./output 指定输出目录
# 启用动态链接
# 为了适配 mac intel 平台

# 同时开启8个任务
make -j8
make install
```
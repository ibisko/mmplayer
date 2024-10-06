```sh
# 准备编译源代码的脚本，指定链接输出的目录，输出后就不能随意移动了
./configure --prefix=/Users/nnhu/Documents/cpp/mmplayer/3rdpart/ffmpeg --enable-shared --disable-x86asm
# --prefix=./output 指定输出目录
# 启用动态链接
# 为了适配 mac intel 平台

# 构建
make -j8
# -j8 同时开启8个任务，加速构建

# 将构建产物复制到系统标准目录
make install
```

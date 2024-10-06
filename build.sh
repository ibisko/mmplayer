#!bin

mkdir -p build && 

(
    cd build && cmake ..  && make && ./mmPlayer/mmplayer
)
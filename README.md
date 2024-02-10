# pi
Calculation of the number PI

 I did this for pi-day 2020. I wanted to cover 3.141.592 digits. And it works fine.
 
 Still, this takes some hours to compute. :)
 
 
To Compile with Clang; 

clang++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference --std=c++20 -g3 -O0 -c /Users/mariano/code/GitHub/pi/ComputePi.cpp -o ./build/Debug/ComputePi.o && clang++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference --std=c++20 -g3 -O0  -c /Users/mariano/code/GitHub/pi/main.cpp -o ./build/Debug/main.o && clang++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference --std=c++20 -g3 -O0   ./build/Debug/ComputePi.o ./build/Debug/main.o -o ./build/Debug/outDebug 
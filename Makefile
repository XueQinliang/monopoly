# main.exe: main.cpp
# 	gcc main.cpp -o main.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
# clean:
# 	rm -rf *.o *.exe

#编译器
cc = g++
#目标文件
prom = main
#编译参数（程序中使用了多线程，所以使用lpthread）
CFLAGS =  -O1 -w -std=c++11 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
#源文件
#src = $(wildcard *.c)
src = $(shell find ./src -name "*.cpp")
lib = $(shell find ./lib -name "*.a")
ofile = draw.o person.o map.o block.o init.o
#中间文件
obj = $(prom).o 

#根据中间文件编译生成 目标文件

# $(prom): $(obj) 
# 	$(cc) $(obj) $(ofile) ./lib/libraylib.a -o $(prom) $(CFLAGS) 
#根据源文件生成 中间文件
$(prom): $(src)
	$(cc) -o $(prom) $(src) $(lib) $(CFLAGS) 
ls:
	echo $(cc) -c $(src)
	echo $(cc) $(obj) -o $(prom) $(CFLAGS) 
#clean                                                                                               
clean:
	rm -rf $(prom) *.o
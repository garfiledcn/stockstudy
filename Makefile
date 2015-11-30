OBJS=main.o \
	 stock.o
SRCS=main.cpp \
	 stock.cpp


TARGET=stocktest
CXXFLAGS=
CFLAGS=
LFLAGS=

all: $(TARGET)

main.o: main.cpp stock.h
	g++ -c main.cpp -o main.o

stock.o: stock.cpp stock.h
	g++ -c stock.cpp -o stock.o

stocktest: $(OBJS)
	g++ $(OBJS) -o stocktest

clean:
	rm -rf $(OBJS) $(TARGET)
	rm -rf output.txt


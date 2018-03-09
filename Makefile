SRC_DIR=src
TEST_DIR=test
BIN_DIR=bin

CC=clang
STD=--std=c11
FLAGS=-Wall -Wpedantic
OPTIMAZATION=-Oz


all: build

clean:
	rm -rf $(BIN_DIR) 

build: clean
	mkdir $(BIN_DIR)
	$(CC) $(STD) $(FLAGS) $(OPTIMAZATION) -c $(SRC_DIR)/* 


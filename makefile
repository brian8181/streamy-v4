# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.1

APP = driver
CXX = g++
#CXX = x86_64-pc-cygwin-g++
CC = gcc
#LEX = reflex
LEX = flex
#YACC = bison -y
YACC = bison
YFLAGS = -YYDEBUG
CXXFLAGS = -std=gnu++17 -fPIC -I./$(BLD) -I./$(SRC)
CCFLAGS = -g -DLEX_TEST -DCYGWIN -DDEBUG
#LDFLAGS += /usr/lib/libcppunit.dll.a
FLEXFLAGS = --flex
BISONFLAGS = -y -d --html --graph
BLD = build
OBJ = build
SRC = src
AST = ast
TST = test

FMT_RESET=\e[0m
FMT_RED='\e[31m'
FMT_GREEN=\e[32m
FMT_YELLOW='\e[33m'
FMT_BLUE='\e[34m'
FMT_CYAN='\e[36m'

# lib settings
# LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64
# INCLUDES=-I/usr/local/include/cppunit/
# LDFLAGS=$(INCLUDES) $(LIBS)


#ifdef CLANG
#	CXX=clang++
#endif

#
ifndef RELEASE
	CXXFLAGS +=-ggdb -DDEBUG -DDEBUG -DYYDEBUG -DLEX_TEST
endif

#CYGWIN=TRUE
ifdef CYGWIN
	CXXFLAGS += -DCYGWIN -I"/home/brian/src/boost_1_89_0"
	//LDFLAGS += -lfmt -lcppunit.dll
	LDFLAGS = /usr/local/lib/libfmt.a
else
	CXXFLAGS += -I/ucrt64/include/boost
	LDFLAGS += /usr/lib/libfmt.dll.a
endif

all: $(BLD)/driver $(BLD)/lib$(APP).a $(BLD)/libSmartPtr.a

$(BLD)/driver: $(BLD)/pparser.tab.o $(OBJ)/fileio.o $(OBJ)/driver.o $(SRC)/driver.h $(OBJ)/lexer.o $(SRC)/lexer.hpp $(OBJ)/utility.o $(OBJ)/ast.o
	@echo -e "$(FMT_GREEN)\nBuilding \"$(BLD)/driver\"$(FMT_RESET) ...\n"
	$(CXX) $(CXXFLAGS) $(OBJ)/pparser.tab.o $(OBJ)/fileio.o $(OBJ)/driver.o $(OBJ)/lexer.o $(OBJ)/utility.o $(LDFLAGS) -o $@

$(BLD)/pparser.tab.cpp $(BLD)/pparser.tab.hh: $(SRC)/pparser.yy $(SRC)/lexer.hpp $(SRC)/lexer.cpp
	@echo -e "$(FMT_GREEN)\nGenerate \"parser.tab.c\"$(FMT_RESET) ...\n"
	$(YACC) --debug -Wcounterexamples $(SRC)/pparser.yy --header=$(BLD)/pparser.tab.hh -o $(BLD)/pparser.tab.cpp

$(OBJ)/pparser.tab.o: $(OBJ)/pparser.tab.cpp
	@echo -e "$(FMT_GREEN)\nBuilding \"$(OBJ)/pparser.tab.o\"$(FMT_RESET) ...\n"
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(BLD)/lib$(APP).so: $(BLD)/$(APP).o
	$(CXX) $(CXXFLAGS) --shared $(OBJ)/$(APP).o -o $(BLD)/lib$(APP).so
	chmod 755 $(BLD)/lib$(APP).so

$(BLD)/libSmartPtr.a: $(BLD)/$(APP).o
	@echo -e "$(FMT_GREEN)\nBuilding \"$(BLD)/libSmartPtr.a\"$(FMT_RESET) ...\n"
	ar rvs $(BLD)/libSmartPtr.a $(OBJ)/$(APP).o
	chmod 755 $(BLD)/libSmartPtr.a

$(BLD)/lib$(APP).a: $(BLD)/$(APP).o
	@echo -e "$(FMT_GREEN)\nBuilding \"$(BLD)/lib$(APP).a\"$(FMT_RESET) ...\n"
	ar rvs $(BLD)/lib$(APP).a $(OBJ)/$(APP).o
	chmod 755 $(BLD)/lib$(APP).a

# copy header files
$(BLD)/%.h : $(SRC)/%.h
	cp $^ $@

$(BLD)/%.hpp: $(SRC)/%.hpp
	cp $^ $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

.PHONY: all rebuild dist install uninstall clean help
rebuild: clean all

dist:
	tar -czvf driver.tar.gz ./src ./include ./makefile ./README.md ./LICENSE ./CHANGELOG.md

install:
	#cp ./$(BLD)/driver ./$(prefix)/bin/driver

uninstall:
	#-rm ./$(prefix)/bin/driver

clean:
	@echo -e "$(FMT_GREEN)cleaning ...$(FMT_RESET)"
	-rm -f ./$(OBJ)/*
	-rm -f ./$(BLD)/*

help:
	@echo  '  all              - build all'
	@echo  '  driver          - build driver executable'
	@echo  '  clean            - remove all files from build dir'
	@echo  '  install          - copy files to usr/local'
	@echo  '  rebuild          - clean and build all'
	@echo  '  help             - this help message'

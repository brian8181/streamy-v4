# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.1

APP = driver
CXX = g++
CC = gcc
#LEX = reflex
LEX = flex
#YACC = bison -y
YACC = bison
YFLAGS =
CXXFLAGS = -g -std=gnu++17 -Wc++17-extensions -std=c++20 -fPIC -DLEX_TEST -DCYGWIN
CCFLAGS = -g -DLEX_TEST -DCYGWIN -DDEBUG
#LDFLAGS += /usr/lib/libcppunit.dll.a
LDFLAGS=/usr/local/lib/libfmt.a
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

#ifdef CLANG
#	CXX=clang++
#endif

#
# ifndef RELEASE
# 	CXXFLAGS +=-ggdb -DDEBU
# endif

#CYGWIN=TRUE
#ifdef CYGWIN
#	CXXFLAGS +=-DCYGWIN
#	//LDFLAGS += -lfmt -lcppunit.dll
#else
#	LDFLAGS += -lfmt -lcppunit
#endif

CXXFLAGS+=-DDEBUG -DYYDEBUG

all: $(BLD)/driver

$(BLD)/driver: $(BLD)/pparser.tab.o $(SRC)/fileio.cpp $(SRC)/driver.cpp $(SRC)/driver.h $(SRC)/tokens.hpp $(SRC)/Lexer.cpp $(BLD)/Lexer.hpp $(SRC)/utility.cpp $(BLD)/ast.o
	@echo -e "$(FMT_GREEN)\nBuilding \"$(BLD)/driver\"$(FMT_RESET) ...\n"
	$(CXX) $(CXXFLAGS) -I$(BLD) -I$(SRC) -I"/home/brian/src/boost_1_89_0" $(BLD)/pparser.tab.o $(SRC)/fileio.cpp $(SRC)/driver.cpp $(SRC)/Lexer.cpp $(SRC)/utility.cpp $(LDFLAGS) -o $@

#$(BLD)/pparser.tab.o: $(SRC)/symtab.c $(SRC)/symtab.h $(BLD)/pparser.tab.cc $(BLD)/pparser.tab.hh
#	$(CC) $(CCFLAGS) -fPIC -c $< -o $@

$(BLD)/pparser.tab.cc $(BLD)/pparser.tab.hh: $(SRC)/pparser.yy
	@echo -e "$(FMT_GREEN)\nGenerate \"parser.tab.c\"$(FMT_RESET) ...\n"
	$(YACC) $(SRC)/pparser.yy --header=$(BLD)/pparser.tab.hh -o $(BLD)/pparser.tab.cc

$(BLD)/pparser.tab.o: $(BLD)/bash_color.h $(BLD)/symtab.h $(BLD)/pparser.tab.hh $(BLD)/pparser.tab.cc
	@echo -e "$(FMT_GREEN)\nBuilding \"parser.tab.o\"$(FMT_RESET) ...\n"
	$(CXX) $(CXXFLAGS) -g -std=c++14 -I$(BLD) -I$(SRC) -c $(BLD)/pparser.tab.cc -o $@

# copy header files
$(BLD)/%.h : $(SRC)/%.h
	cp $^ $@

$(BLD)/%.hpp: $(SRC)/%.hpp
	cp $^ $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CCFLAGS) -I$(BLD) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(BLD) -I"/home/brian/src/boost_1_89_0" -c $< -o $@

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

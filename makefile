# @file: makefile
# @date: Mon Sep  8 00:03:12 CDT 2025
# @version: 0.0.2

CYGWIN=0

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
LDFLAGS =
FLEXFLAGS = --flex
BISONFLAGS = -y -d --html --graph
BLD = build
OBJ = build
SRC = src
AST = ast
TST = test

SRC_EXT=cpp
HDR_EXT=hpp

FMT_RESET=\e[0m
FMT_ITALIC=\e[3m
FMT_RED='\e[31m'
FMT_GREEN=\e[32m
FMT_YELLOW='\e[33m'
FMT_BLUE='\e[34m'
FMT_CYAN='\e[36m'
FMT_INFO=$(FMT_ITALIC)$(FMT_GREEN)
FMT_WARN=$(FMT_ITALIC)$(FMT_YELLOW)

# lib settings
LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64
INCLUDES=-I/usr/local/include/cppunit/ -I./$(SRC) -I./$(BLD)
LDFLAGS=$(INCLUDES) $(LIBS)

ifdef CLANG
	CXX=clang++
endif

ifndef RELEASE
	CXXFLAGS+=-ggdb -DDEBUG -DWARNINGS -DTRACING -DYYDEBUG -DLEX_TEST
endif

ifdef CYGWIN
	CXXFLAGS += -DCYGWIN -I"/home/brian/src/boost_1_89_0"
	LDFLAGS += /usr/local/lib/libfmt.a -lcppunit.dll
endif
ifdef MSYS_UCRT
	CXXFLAGS += -I/ucrt64/include/boost
	LDFLAGS += /usr/lib/libfmt.dll.a
endif

# ifdef TRACEING
# CXXFLAGS += -DTRACING
# endif

CXXFLAGS+=-DTEST_ONLY

# FILES=$(SRC)\bash_color.hpp \
# $(SRC)/log.hpp \
# $(SRC)/fileio.hpp \
# $(SRC)/auto_ptr.hpp \
# $(SRC)/utility.hpp \
# $(SRC)/ast.hpp \
# $(BLD)/pparser.tab.hpp \
# $(BLD)/pparser2.tab.hpp \
# $(SRC)/parser.hpp \
# $(SRC)/lexer.hpp \
# $(SRC)/driver.hpp

HEADERS=$(SRC)/bash_color.hpp \
$(SRC)/log.hpp \
$(SRC)/fileio.hpp \
$(SRC)/auto_ptr.hpp \
$(SRC)/utility.hpp \
$(SRC)/ast.hpp \
$(SRC)/process_strm.hpp \
$(SRC)/strm_handle.hpp \
$(BLD)/pparser.tab.hpp \
$(SRC)/parser.hpp \
$(SRC)/lexer.hpp \
$(SRC)/driver.hpp

OBJS=$(OBJ)/fileio.o \
$(OBJ)/auto_ptr.o \
$(OBJ)/utility.o \
$(SRC)/strm_handle.o \
$(OBJ)/process_strm.o \
$(BLD)/pparser.tab.o \
$(OBJ)/parser.o \
$(OBJ)/lexer.o \
$(OBJ)/driver.o

# SOURCES=$(SRC)/bash_color.hpp \
# $(SRC)/log.hpp \
# $(SRC)/fileio.hpp $(OBJ)/fileio.o \
# $(SRC)/auto_ptr.hpp $(OBJ)/auto_ptr.o \
# $(SRC)/utility.hpp $(OBJ)/utility.o \
# $(SRC)/ast.hpp \
# $(BLD)/pparser.tab.hpp $(BLD)/pparser.tab.o \
# $(SRC)/parser.hpp $(OBJ)/parser.o \
# $(SRC)/lexer.hpp $(OBJ)/lexer.o \
# $(SRC)/driver.hpp $(OBJ)/driver.o

SOURCES=$(HEADERS) $(OBJS)

all: $(BLD)/driver

world: $(BLD)/driver $(BLD)/lib$(APP).a $(BLD)/libauto_ptr.a $(BLD)/libauto_ptr.so $(BLD)/pparser2.tab.o

$(BLD)/driver: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(BLD)/pparser.tab.cpp $(BLD)/pparser.tab.hpp: $(SRC)/pparser.yy $(SRC)/lexer.cpp
	$(YACC) --debug -Wcounterexamples $(SRC)/pparser.yy --header=$(BLD)/pparser.tab.hpp -o $(BLD)/pparser.tab.cpp

$(OBJ)/pparser.tab.o: $(OBJ)/pparser.tab.cpp $(BLD)/bash_color.hpp $(SRC)/log.hpp
	$(CXX) $(CXXFLAGS) -DYYDEBUG -c $< -o $@

$(BLD)/pparser2.tab.cpp $(BLD)/pparser2.tab.hh: $(SRC)/pparser2.yy $(SRC)/lexer.hpp $(SRC)/lexer.cpp
	$(YACC) --debug -Wcounterexamples $(SRC)/pparser2.yy --header=$(BLD)/pparser2.tab.hpp -o $(BLD)/pparser2.tab.cpp

$(OBJ)/pparser2.tab.o: $(OBJ)/pparser2.tab.cpp $(SRC)/bash_color.hpp $(SRC)/log.hpp
	$(CXX) $(CXXFLAGS) -DYYDEBUG -c $< -o $@

$(BLD)/ast: $(OBJ)/ast.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BLD)/libauto_ptr.so: $(BLD)/auto_ptr.o
	$(CXX) $(CXXFLAGS) --shared $(OBJ)/auto_ptr.o -o $(BLD)/libauto_ptr.so
	chmod 755 $(BLD)/libauto_ptr.so

$(BLD)/libauto_ptr.a: $(BLD)/auto_ptr.o
	ar rvs $(BLD)/libauto_ptr.a $(OBJ)/$(APP).o
	chmod 755 $(BLD)/libauto_ptr.a

$(BLD)/lib$(APP).a: $(BLD)/$(APP).o
	ar rvs $(BLD)/lib$(APP).a $(OBJ)/$(APP).o
	chmod 755 $(BLD)/lib$(APP).a

$(BLD)/TEST_lex:  $(SOURCES) $(OBJ)/TEST_lex.o
	$(CXX) $(CXXFLAGS) $(OBJ) -I/usr/local/include/cppunit -L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64 -lfmt -lcppunit -o $@

# copy header files
$(BLD)/%.h : $(SRC)/%.h
	cp $^ $@

$(BLD)/%.hpp: $(SRC)/%.hpp
	cp $^ $@

# build object files
$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp $(SRC)/%.hpp $(SRC)/log.hpp $(SRC)/bash_color.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all rebuild dist install uninstall clean help
rebuild: clean all

dist:
	tar -czvf driver.tar.gz ./src ./include ./makefile ./README.md ./LICENSE ./CHANGELOG.md

install:
	#cp ./$(BLD)/driver ./$(prefix)/bin/driver

uninstall:
	#-rm ./$(prefix)/bin/driver

clean:
	@echo -e "$(FMT)cleaning ...$(FMT_RESET)"
	-rm -rf ./$(OBJ)/*
	-rm -rf ./$(BLD)/*

help:
	@echo  '  all              - build all'
	@echo  '  driver           - build driver executable'
	@echo  '  clean            - remove all files from build dir'
	@echo  '  install          - copy files to usr/local'
	@echo  '  rebuild          - clean and build all'
	@echo  '  help             - this help message'

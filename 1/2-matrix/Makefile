
#BOOST_ROOT=/home/hknamtata/programs/boost_1_66_0

SRC_PATH = src
TESTS_PATH = tests
BUILD_PATH = build

OBJECT_PATH = .obj

CXXFLAGS = -std=c++17 -pthread -Wall -Wextra -Werror -Wpedantic

INCLUDES = -I ${SRC_PATH}/

SRC_LIST = \
	${SRC_PATH}/matrix.cpp \
	${SRC_PATH}/matrix_utils.cpp \
	${SRC_PATH}/matrix_operations.cpp \

.PHONY: all
all:
	@$(MAKE) test

.PHONY: matrix
matrix:
	@echo "Build matrix project"
	g++ $(CXXFLAGS) ${SRC_LIST} ${INCLUDES} -c

.PHONY: test
test:
	@$(MAKE) matrix
	@echo "Build tests"
	g++ $(CXXFLAGS) matrix*.o ${TESTS_PATH}/*.cpp -o test.o

.PHONY: clean
clean:
	@echo "Delete object files"
	rm -v *.o
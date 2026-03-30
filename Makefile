##
## EPITECH PROJECT, 2024
## B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
## File description:
## Makefile
##

SRC = src/Main.cpp \
		src/AComponent.cpp \
		src/Circuit.cpp \
		src/InputComponent.cpp \
		src/OutputComponent.cpp \
		src/TrueComponent.cpp \
		src/FalseComponent.cpp \
		src/ClockComponent.cpp \
		src/AndComponent.cpp \
		src/OrComponent.cpp \
		src/XorComponent.cpp \
		src/NotComponent.cpp \
		src/Parser.cpp \
		src/FlipFlopComponent.cpp \
		src/4514Component.cpp \
		src/LoggerComponent.cpp \
		src/Simulation.cpp

SRC_TEST = src/AComponent.cpp \
		src/Circuit.cpp \
		src/InputComponent.cpp \
		src/OutputComponent.cpp \
		src/TrueComponent.cpp \
		src/FalseComponent.cpp \
		src/ClockComponent.cpp \
		src/AndComponent.cpp \
		src/OrComponent.cpp \
		src/XorComponent.cpp \
		src/NotComponent.cpp \
		src/Parser.cpp \
		src/FlipFlopComponent.cpp \
		src/4514Component.cpp \
		src/LoggerComponent.cpp \
		src/Simulation.cpp \
		tests/tests_and.cpp \
		tests/tests_clock.cpp \
		tests/tests_false.cpp \
		tests/tests_true.cpp \
		tests/tests_input.cpp \
		tests/tests_output.cpp \
		tests/tests_xor.cpp \
		tests/tests_or.cpp \
		tests/tests_not.cpp \
		tests/tests_parser.cpp \
		tests/tests_circuit.cpp \
		tests/tests_flipflop.cpp \
		tests/tests_4514.cpp \
		tests/tests_logger.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -I./src/Interface -I./src/Abstract -I./src/Components -I./src/Parser -I./src/AdvancedComponents -I./src/Simulation

TARGET = nanotekspice

all : $(TARGET)

$(TARGET) : $(OBJ)
	g++ -o $(TARGET) $(OBJ)

clean :
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean : clean
	$(RM) $(TARGET)
	$(RM) unit_tests

re : fclean all

tests_run:
	g++ -o unit_tests $(SRC_TEST) -I./src/Interface -I./src/Abstract -I./src/Components -I./src/Parser -I./src/AdvancedComponents -I./src/Simulation --coverage -lcriterion
	./unit_tests

gcovr_tests_run: tests_run
	gcovr . --exclude tests/
	gcovr . --branches --exclude tests/

quick_compilation:
	make fclean && make all -j16

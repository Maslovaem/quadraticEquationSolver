all:quadraticLinearSolver.o first_char.o output_analysis.o solver.o utilities.o input_checker.o
	g++ ../build/quadraticLinearSolver.o ../build/first_char.o ../build/output_analysis.o ../build/solver.o ../build/utilities.o ../build/input_checker.o -o Solver

first_char.o:first_char.cpp
	g++ -c first_char.cpp -o ../build/first_char.o

quadraticLinearSolver.o:quadraticLinearSolver.cpp
	g++ -c quadraticLinearSolver.cpp -o ../build/quadraticLinearSolver.o

input_checker.o:input_checker.cpp
	g++ -c input_checker.cpp -o ../build/input_checker.o

output_analysis.o:output_analysis.cpp
	g++ -c output_analysis.cpp -o ../build/output_analysis.o

solver.o:solver.cpp
	g++ -c solver.cpp -o ../build/solver.o

utilities.o:utilities.cpp
	g++ -c utilities.cpp -o ../build/utilities.o

flags:
	g++ quadraticLinearSolver.cpp first_char.cpp output_analysis.cpp solver.cpp utilities.cpp input_checker.cpp -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

start:
	.\Solver.exe




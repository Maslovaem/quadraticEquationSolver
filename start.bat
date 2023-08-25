g++ -c quadraticLinearSolver.cpp -o ../build/quadraticLinearSolver.o
g++ -c first_char.cpp -o ../build/first_char.o
g++ -c input_checker.cpp -o ../build/input_checker.o
g++ -c output_analysis.cpp -o ../build/output_analysis.o
g++ -c solver.cpp -o ../build/solver.o
g++ -c utilities.cpp -o ../build/utilities.o

g++ ../build/quadraticLinearSolver.o ../build/first_char.o ../build/output_analysis.o ../build/solver.o ../build/utilities.o ../build/input_checker.o -o Solver
.\Solver.exe

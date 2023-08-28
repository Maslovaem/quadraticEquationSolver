BUILD_DIR = build
SOURCE_DIR = sourse
CXXFLAGS =

FILES = quadraticLinearSolver.o first_char.o output_analysis.o solver.o utilities.o input_checker.o
OBJS = $(addprefix $(BUILD_DIR)/, $(FILES))

all: $(OBJS)
	g++ $(OBJS) -o Solver

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	g++ $(CXXFLAGS)  -c $< -o $@

flags:
	g++ $(SOURCE_DIR)/*.cpp -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

start: all
	.\Solver.exe




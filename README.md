# quadraticEquationSolver
## Introduction
Version 29.08.2023

This project was created for solving quadratic equations. It also contains some supportive functions that help solve linear equations, check input, run tests. Also it supports file input.

Read the "Installation" block to save the developer from cursing. 

## Reporting Bugs
Bug reports for quadraticEquationSolverbash should be sent to: lizamushroom757@gmail.com

## Installation
To install the project and run it on a local machine you need to follow these installation steps:
1. Download all files in the repository.
2. Make sure that you downloaded every single file (including makefile and start.bat)
3. Make sure that both makefile and file with your input are in the root directory of the project.
4. If you alredy have "make" utility on your machine just use the `make` command to run code and skip the last step.
5. If you don't have "make" utility on your machine use `.\Solver.exe` command to run code/

## Test
This code is in charge of running tests from the file named "tests.txt":
````
FILE *fp_tests = fopen("tests.txt","r");
    check_input_from_fileWithTests(fp_tests, count_strings(fp_tests));
    fclose(fp_tests);
````
If you want to use your own tests you should change data in "tests.txt" or create your own file with data for tests and replace "tests.txt" with "*file_name*.txt".

## Usage
After running the code you will be suggested to choose between file input and input via console.
To choose console input you should enter "1" and then enter the a, b, c coefficients of a quadratic equation (ax^2+bx+c=0). 

To choose file input you should enter "2" and then enter the name of the file with an extension (it has to be in the root directory of the project).

## Copyright note
Permission to use, copy, modify scripts and output results.

## Documentation
You can find the detailed documentation here: 

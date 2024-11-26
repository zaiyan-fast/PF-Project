# Graphical Function Plotter

## Description
This C program allows users to visually plot various mathematical functions on a 2D graph, including linear, modular, logarithmic, exponential, and trigonometric functions. Additionally, users can plot composite functions and customize constants for added flexibility. The program features an interactive interface and also saves the details of plotted functions to a text file for future reference.

## Features
- Plot linear functions: f(x) = mx + c
- Plot modular functions: f(x) = |mx + c| or f(x) = |g(x)| + c
- Plot logarithmic functions: f(x) = alog(x) + c
- Plot exponential functions: f(x) = ax^n + c
- Plot trigonometric functions: sin(x), cos(x), tan(x), and their inverses
- Plot composite functions, such as sin(f(x)) + c
- Save all plotted functions and their parameters to a file named functions.txt

## Prerequisites
- C Compiler (e.g. GCC)
- Graphics library support <graphics.h>

## Usage

1. *Start the Program*
   - The program will prompt you with the following message:
     
     Do you want to continue or terminate? (Enter 1 to continue and 0 to terminate):
     
   - Enter 1 to continue or 0 to terminate the program.

2. *Choose Function Type*
   - After choosing to continue, you will be prompted to select a function type by entering one of the following letters:
     - l: Linear function
     - m: Modular function
     - e: Exponential function
     - g: Logarithmic function
     - t: Trigonometric function

3. *Input Parameters*
   - Follow the prompts to input the required parameters for the selected function type. This may include coefficients and constants specific to the function you are plotting.

4. *View Graph*
   - Once the parameters are entered, the program will generate and display the graph of the selected function.

5. *Save Function Details*
   - The details of the plotted function will be saved in a file named functions.txt for your reference.

6. *Plot Additional Functions or Exit*
   - After viewing your graph, you can choose to plot additional functions by repeating steps 2-5 or exit the program by entering 0 when prompted.
## Group Members
- *Yahya Khan* - Roll# 24K-1030
- *Zaiyan Umer* - Roll# 24K-0771
- *Noman Ali* - Roll# 24K-1027

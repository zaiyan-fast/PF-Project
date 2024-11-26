#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <string.h>

FILE *file; // File pointer for saving functions

// Function to save entered data to a file
void save_function_to_file(const char *function_name, double params[], int num_params, double c) {
    file = fopen("functions.txt", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    // Write function name and parameters
    fprintf(file, "Function: %s\n", function_name);
    
    // Write parameters based on the function
    for (int i = 0; i < num_params; i++) {
        fprintf(file, "Param %d: %.2lf\n", i + 1, params[i]);
    }
    fprintf(file, "Constant c: %.2lf\n", c);
    fprintf(file, "----------------------------\n");
    
    fclose(file); // Close the file after writing
}

// Variable declaration for Global variables
int x_max = 720;
int y_max = 540;
int scale = 30;
int x_origin = x_max / 2;
int y_origin = y_max / 2;
char strx[10];
char stry[10];
// Function to draw x - axis on the screen
void draw_x_axis() {
    // Line of x-axis
    line(0, y_origin, x_max, y_origin);
    
    int numbers_on_axis = -12;    
        
    // Labeling on x-axis
    for (int i = 0; i <= getmaxx(); i = i + scale) {
        line(i, y_origin - 4, i, y_origin + 4);
        
        // Convert the integer value to string for output
        sprintf(strx, "%d", numbers_on_axis);
        
        // Display the label at the x-axis
        outtextxy(i - 8, y_origin + 5, strx);
        
        // Increment the label counter for the next tick
        numbers_on_axis++;
    }                            
}
// Function to draw y-axis on the screen
void draw_y_axis() {
    int numbers_on_axis = 9;
    // Line of y-axis
    line(x_origin, 0, x_origin, y_max);
    
    // Labeling on y-axis
    for (int i = 0; i < getmaxy(); i = i + scale) {
        line(x_origin - 4, i, x_origin + 4, i);
        // Convert the integer value to string for output
        sprintf(stry, "%d", numbers_on_axis);
        
        // Display the label at the y-axis
        outtextxy(x_origin - 5, i + 5, stry);
        
        // Decrement
        numbers_on_axis--;
    }
}
// Function to determine which trigonometric function is given by the user
double trigonometric_functions_by_users(char* function, double x) {
    if (strcmp(function, "sin(x)") == 0 || strcmp(function, "sinx") == 0) {
        return sin(x);
    } else if (strcmp(function, "cos(x)") == 0 || strcmp(function, "cosx") == 0) {
        return cos(x);
    } else if (strcmp(function, "tan(x)") == 0 || strcmp(function, "tanx") == 0) {
        return tan(x);
    } else if (strcmp(function, "cosec(x)") == 0 || strcmp(function, "cosecx") == 0) {
        return 1 / sin(x);
    } else if (strcmp(function, "sec(x)") == 0 || strcmp(function, "secx") == 0) {
        return 1 / cos(x);
    } else if (strcmp(function, "cot(x)") == 0 || strcmp(function, "cotx") == 0) {
        return 1 / tan(x);
    } else {
        printf("Invalid Input\n");
        return 0;
    }
}
// Composite trigonometric
void draw_composite_trig_function(char* trig_function, char* func, double params[], double c) {
    double x, y, fx;
    setcolor(GREEN);

    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / (double)scale;

        // Evaluate the inner function f(x)
        if (strcmp(func, "linear") == 0) {
            fx = params[0] * x + params[1];
        } else if (strcmp(func, "mod") == 0) {
            fx = fabs(params[0] * x + params[1]);
        } else if (strcmp(func, "exp") == 0) {
            fx = params[0] * pow(x, params[1]) + params[2];
        } else if (strcmp(func, "log") == 0) {
            fx = params[0] * log(x) + params[1];
        } else {
            printf("Invalid function\n");
            return;
        }

        // Apply the trigonometric function to f(x) and add c
        y = (trigonometric_functions_by_users(trig_function, fx) + c) * scale;
        circle(x_origin + i, y_origin - y, 1);
    }
}
// Function to draw trigonometric functions
void draw_trigonometric_functions(char* function, double c) {
    double x, y;
    setcolor(GREEN);
    
    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / (double)scale;
        y = (trigonometric_functions_by_users(function, x) + c) * scale;
        circle(x_origin + i, y_origin - y, 1);
    }
}
// Draw Linear Function
void draw_linear_function(double m, double c) {
    double x, y;
    setcolor(GREEN);
    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / double(scale);
        y = (m * x + c) * scale;
        circle(x_origin + i, y_origin - y, 1);
    }
}
void draw_log_function(double a, double c) {
    double x, y;
    setcolor(GREEN);
    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / double(scale);
        y = ((a * log(x)) + c) * scale;
        circle(x_origin + i, y_origin - y, 1);
    }
}
void draw_exponential_function(double a, double n, double c) {
    double x, y;
    setcolor(GREEN);
    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / double(scale);
        y = ((a * pow(x, n)) + c) * scale;
        circle(x_origin + i, y_origin - y, 1);
    }
}
void draw_mod_function(double m, double c) {
    double x, y;
    setcolor(GREEN);
    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / double(scale);
        if ((m * x + c) <= 0) {
            y = - (m * x + c) * scale;
        } else {
            y = (m * x + c) * scale;
        }
        circle(x_origin + i, y_origin - y, 1);
    }
}

void draw_composite_mod_function(char* inner_function, char* func, double params[], double c) {
    double x, y, fx;
    double prev_x, prev_y;
    int first_point = 1; // Flag to mark the first point
    setcolor(GREEN);

    for (int i = -x_origin; i < x_max - x_origin; i++) {
        x = i / (double)scale;

        // Evaluate the inner function f(x)
        if (strcmp(func, "linear") == 0) {
            fx = params[0] * x + params[1];
        } else if (strcmp(func, "exp") == 0) {
            fx = params[0] * pow(x, params[1]) + params[2];
        } else if (strcmp(func, "log") == 0) {
            fx = params[0] * log(x) + params[1];
        } else if (strcmp(func, "trig") == 0) {
            fx = trigonometric_functions_by_users(inner_function, x);
        } else {
            printf("Invalid function\n");
            return;
        }

        // Apply the mod function to f(x) and add c
        y = fabs(fx) * scale + c * scale;

        // Draw line between previous point and current point
        if (first_point) {
            first_point = 0; // Turn off the flag after the first point
        } else {
            line(x_origin + prev_x, y_origin - prev_y, x_origin + i, y_origin - y);
        }

        // Store the current point as previous for the next iteration
        prev_x = i;
        prev_y = y;
    }
}


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    int terminate;
    printf("Enter 1 to continue and 0 to terminate: ");
    scanf("%d", &terminate);
    initwindow(720, 540);
    draw_x_axis();
    draw_y_axis();
    while (terminate == 1) {
        clear_input_buffer();
        printf("Choose function: \nl - linear\nm - mod\ne - exponential\ng - log\nt - trigonometric\n");
        char func;
        scanf(" %c", &func);
        if (func == 'l') {
            double m, c;
            printf("f(x) = mx + c\n");
            printf("m = "); scanf("%lf", &m);
            printf("c = "); scanf("%lf", &c);
            draw_linear_function(m, c);

            // Save to file
            double params[] = { m, c };
            save_function_to_file("linear", params, 2, 0); // No constant for linear
        } else if (func == 'm') {
        	int chain = 0;
        	printf("Enter 0 for f(x) = |mx + c|\nEnter 1 for f(x) = |g(x)| + c"); scanf(" %d",&chain);
        	if(chain == 0){
        	    double m, c;
                printf("f(x) = |mx + c|\n");
                printf("m = "); scanf("%lf", &m);
                printf("c = "); scanf("%lf", &c);
                draw_mod_function(m, c);	
                // Save to file
                double params[] = { m, c };
                save_function_to_file("mod", params, 2, 0); // No constant for mod
        	} else if(chain == 1) {
                printf("for g(x)\n");
                double c;
                printf("Enter c: ");
                scanf("%lf", &c);
                printf("Choose inner function: \ne - exponential\ng - log\nt - trigonometric\n");
                char funcC;
                scanf(" %c", &funcC);
                double params[3];  // To hold parameters of the inner function
                if (funcC == 'e') {
                    printf("f(x) = ax^n + c\n");
                    printf("a = "); scanf("%lf", &params[0]);
                    printf("n = "); scanf("%lf", &params[1]);
                    printf("c = "); scanf("%lf", &params[2]);
                    draw_composite_mod_function("exp", "exp", params, c);
                    // Save to file
                    save_function_to_file("composite_mod_exponential", params, 3, c);
                } else if (funcC == 'g') {
                    printf("f(x) = alog(x)\n");
                    printf("a = "); scanf("%lf", &params[0]);
                    printf("c = "); scanf("%lf", &params[1]);
                    draw_composite_mod_function("log", "log", params, c);
                    // Save to file
                    save_function_to_file("composite_mod_log", params, 2, c);
                } else if (funcC == 't') {
                    char trig_function[10];
                    printf("Enter trigonometric function: ");
                    scanf("%s", trig_function);
                    draw_composite_mod_function(trig_function, "trig", params, c);
                    // Save to file
                    save_function_to_file(trig_function, params, 0, c); // No params for trig
                } else {
                    printf("Invalid function\n");
                }
        	}
        } else if (func == 'g') {
            double a, c;
            printf("f(x) = alog(x) + c\n");
            printf("a = "); scanf("%lf", &a);
            printf("c = "); scanf("%lf", &c);
            draw_log_function(a, c);

            // Save to file
            double params[] = { a };
            save_function_to_file("log", params, 1, c);
        } else if(func == 'e'){
            double a,n,c;
            printf("f(x) = ax^n + c\n");
            printf("a = "); scanf("%lf",&a);
            printf("n = "); scanf("%lf",&n);
            printf("c = "); scanf("%lf",&c);
            draw_exponential_function(a,n,c);

            // Save to file
            double params[] = { a, n };
            save_function_to_file("exponential", params, 2, c);
        } else if (func == 't') {
            int chain = 0;
            printf("Enter 0 for sin(x) + c and 1 for sin(f(x)) + c: ");
            scanf("%d", &chain);
            if (chain == 0) {
                char function[10];
                printf("Enter trigonometric function: ");
                scanf("%s", function);
                double c;
                printf("c = "); scanf("%lf", &c);
                draw_trigonometric_functions(function, c);

                // Save to file
                save_function_to_file(function, NULL, 0, c); // No parameters for trig
            } else if(chain == 1){
                char trig_function[10];
                printf("Enter trigonometric function: ");
                scanf("%s", trig_function);
                double c;
                printf("c = "); scanf("%lf", &c);
                printf("for f(x) - Composite function example sin(x^2) + c\n");
                printf("Choose function: \nl - linear\nm - mod\ne - exponential\ng - log\n");
                char composite;
                scanf(" %c", &composite);
                double params[3];  // To hold parameters of the inner function
                if (composite == 'l') {
                    printf("f(x) = mx + c\n");
                    printf("m = "); scanf("%lf", &params[0]);
                    printf("c = "); scanf("%lf", &params[1]);
                    draw_composite_trig_function(trig_function, "linear", params, c);
                    // Save to file
                    save_function_to_file("composite_trig_linear", params, 2, c);
                } else if (composite == 'm') {
                    printf("f(x) = |mx + c|\n");
                    printf("m = "); scanf("%lf", &params[0]);
                    printf("c = "); scanf("%lf", &params[1]);
                    draw_composite_trig_function(trig_function, "mod", params, c);
                    // Save to file
                    save_function_to_file("composite_trig_mod", params, 2, c);
                } else if (composite == 'e') {
                    printf("f(x) = ax^n + c\n");
                    printf("a = "); scanf("%lf", &params[0]);
                    printf("n = "); scanf("%lf", &params[1]);
                    printf("c = "); scanf("%lf", &params[2]);
                    draw_composite_trig_function(trig_function, "exp", params, c);
                    // Save to file
                    save_function_to_file("composite_trig_exponential", params, 3, c);
                } else if (composite == 'g') {
                    printf("f(x) = alog(x) + c\n");
                    printf("a = "); scanf("%lf", &params[0]);
                    printf("c = "); scanf("%lf", &params[1]);
                    draw_composite_trig_function(trig_function, "log", params, c);
                    // Save to file
                    save_function_to_file("composite_trig_log", params, 2, c);
                } else {
                    printf("Invalid composite function\n");
                }
            } else {
                printf("Invalid option for sin(f(x)) + c\n");
            }
        }
        
        printf("Enter 1 to continue and 0 to terminate: ");
        scanf("%d", &terminate);
    }

    closegraph();
    return 0;
}

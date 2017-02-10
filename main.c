#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//function used to calculate the width of each rectangle
double widthInterval(double a, double b, int n) {

	double width = (b - a) / n;

	return width;
}

//represents the mathematical formula of the given function
double gaussFunc(double x, double spread) {

	double y = pow(-x, 2);
	double final = exp(-y / spread);

	return final;
}

int main()
{
    //declaring variables
	double spreadValue, sum;
	double totalSum = 0;
	double midPoint = 0; //the actual x-value that will get put-in into the formula
	double counter2 = 0; //variable that runs the for-loop
	double aInput = 0, bInput = 0, widthOutput, newWidth = 0;
	int widthInput; //the n value that user enters

	do //do-while loop that checks the spread value
	{
    	printf("Enter the spread value (must be >0): ");
    	scanf("%lf", &spreadValue);
	}	while (spreadValue <= 0);

	printf("Please enter the number of rectangles (n): ");
	scanf("%d,", &widthInput);

	while (widthInput > 0) //while-loop that checks the n value
	{
    	//prompt user to enter the range of interval
    	printf("Enter the interval of integration (a b): ");
    	scanf("%lf %lf", &aInput, &bInput);

    	while (aInput > bInput) //while-loop that compares the value of a to b
    	{
        	printf("Invalid interval!\n");
        	printf("Enter the interval of integration (a b): ");
        	scanf("%lf %lf", &aInput, &bInput);
    	}

    	for (counter2 = aInput; counter2 <= bInput - widthInterval(aInput, bInput, widthInput); counter2 = counter2 + widthInterval(aInput, bInput, widthInput)) {
    	//number of times the mid-point of the rectangle is generated based on n, a, and b values

        	midPoint = (counter2 + (counter2 + widthInterval(aInput, bInput, widthInput))) / 2.0;
        	//formula to calculate the midpoint of the rectangle

        	sum = gaussFunc(midPoint, spreadValue) * widthInterval(aInput, bInput, widthInput);
        	//computing the area of each individual rectangle (width*height)

        	totalSum = totalSum + sum;
        	//Sum of all the areas of the rectangles
    	}

    	//printing the result of calculation
    	printf("Integral of Gaussian with spread %.2lf on [%.3lf, %.3lf] with n = %d is: %.3lf\n", spreadValue, aInput, bInput, widthInput, totalSum);
    	totalSum = 0;
    	printf("\n");
    	//prompt user to enter value of n again and continue calculating
    	printf("Please enter the number of rectangles (n): ");
    	scanf("%d", &widthInput);
	}

	//program exits when user enters n less than 0
	printf("Exiting");

    return 0;
}

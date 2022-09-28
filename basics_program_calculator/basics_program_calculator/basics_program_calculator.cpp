#include <iostream>
char calc3;
using namespace std;

double sum(double n1, double n2);   // This function does the addition of two numbers

double sub(double n1, double n2);   // This function does the subtraction of two numbers

double mult(double n1, double n2);  // This function does the multiplication  of two numbers 

double div(double n1, double n2);   // This function does the division of two numbers

double Calculation(double n1, double n2, char c1); /* This function defines the entered arithmetic operation,and then calls the function responsible for executing  that arithmetic operation*/ 

double Recursion1(double n2, char c2); /* This function is responsible for keeping track of operations of higher priority, such as multiplicationand divisionand it is responsible for the repetition*/

double Recursion2(double n1, double n2, char c1); //This function is responsible for processing priority if the entered arithmetic operation has a lower priority

int main()
{
	         // multi_function_calculator
	  //My first application to the basics of C++

	double num1, num2;
	char calc1, calc2;

	cout << " Enter your calculation : ";
	cin >> num1 >> calc1 >> num2 >> calc2;

	if (calc2 == '=') {

		cout<<" product = " << Calculation(num1, num2, calc1); // final output

	}

	else if (calc2 == '*' || calc2 == '/') {

		if (calc1 == '+' || calc1 == '-') {

			num2 = Recursion1(num2, calc2);
			cout << " product = " << Calculation(num1, num2, calc1);

		}

		else if (calc1 == '*' || calc1 == '/') {

			num1 = Calculation(num1, num2, calc1);
			cout << " product = " << Recursion1(num1, calc2);

		}

	}

	else if (calc2 == '+' || calc2 == '-') {

		num1= Calculation(num1, num2, calc1);
		cout << " product = " << Recursion2(num1, num2, calc2);

		}
	

	return 0;
}


double sum(double n1, double n2) { // This is the body of the addition function
	
	return n1 + n2;

}

double sub(double n1, double n2) { // This is the body of the subtraction function
	
	return n1 - n2;

}

double mult(double n1, double n2) { // This is the body of the multiplication function
	
	return n1 * n2;

}

double div(double n1, double n2) { // This is the body of the division function
	
	return n1 / n2;

}


double Calculation(double n1, double n2, char c1) { // This is the body of the function Responsible for determining the process

	switch (c1)

	{

	case '+':
		return sum(n1, n2); // n1 + n2
		break;

	case '-':
		return sub(n1, n2); // n1 - n2
		break;

	case '*':
		return mult(n1, n2); // n1 * n2
		break;

	case '/':
		return div(n1, n2); // n1 / n2
		break;

	}

}

double Recursion1(double n2, char c2) { // This is the body of the function responsible for the repetition1
	
	double num3;
	cin >> num3;
	n2 = Calculation(n2, num3, c2); //Put the result of the arithmetic operation c2 on the two numbers n2,n3 in the variable n2

	cin >> calc3;

	if (calc3 == '=') {

		return n2; // final output

	}
	else if (calc3 == '*' || calc3 == '/') {

		return Recursion1(n2, calc3); // In this case, this function returns itself, and this is the main idea of ​​​​the application

	}
	else if (calc3 == '+' || calc3 == '-') {

		return Recursion2(n2, num3, calc3); // In this case, this function calls the function responsible for the least priority

	}
}

double Recursion2(double n1, double n2, char c2) { // This is the body of the function responsible for the repetition2
	
	if (calc3 != '=') { // This condition is to terminate the process by entering the symbol '='
		cin >> n2 >> calc3;
	}

	if (calc3 == '=') {
		return Calculation(n1, n2, c2); // final output
	}

	else if (calc3 == '+' || calc3 == '-') {
	
		n1 = Calculation(n1, n2, c2);  //The operation c2 is performed on the numbers n1,n2 and puts the result in n1
		return Recursion2(n1, n2, calc3); // Then it repeats itself

	}

	else if (calc3 == '*' || calc3 == '/') {

		n2 = Recursion1(n2, calc3);  //In this case, this function calls the Recursion1 function because it has priority
		return Recursion2(n1, n2, c2); // Then it returns itself to complete the required operation

	}

}
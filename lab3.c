#include <stdio.h>
#include <math.h>

/* Name:       Michael Ressler
   Class:      Programming with C
   Assignment: Lab 3
   Date:       2/1/2019
*/

void  calc(double p, double r, int n) {
	double pay;
	int month = 1;
	double op, np, rcost, z;
//op is the old principal, np is the new principal, z is printed to the table as the difference of op and np


	r = (r/100) / 12; //Calculates decimal form of the rate and divides by 12 for monthly interest

	double payment = ((r * p) / (1 - pow((1 + r), -n)));

	r = r * 12 * 100; //rate needs to be changed back for printing purposes

	printf("principal\t $%.2lf\t Payment\t $%.2lf\n", p, payment);
	printf("Annual Interest\t %.2lf\t\t Term\t\t %d months\n", r, n);
	printf("\n");

	r = (r/100) / 12; //r changed back to monthly for further calculations in the loop

	printf("Payment\t Interest\t Principal\t Principal Balance\n");
	printf("----------------------------------------------------------\n");

	while(n > 0) {

		pay = ((r * p) / (1 - pow((1 + r), -n))); //equation from the book, gives final payment
		pay = 0.01 * round(pay * 100.0); //rounds to the nearest cent

		op = p;
		rcost = op * r; //the interest amount per monthly payment
		p = p - pay + ((r)*p);
		np = p;
		z = op - np; //variable printed to display principal
		n = n-1;

		//printf("%d\t %.2lf\t\t %.2lf\t\t %.2lf\n",month, rcost, z, fabs(p));
		printf("%-12d%-16.2lf%-18.2lf%-12.2lf\n", month, rcost, z, fabs(p));
		printf("\n");

		month += 1; //iterates through the amount of payments
	}

	double fpay = rcost + z;
	printf("Final payment\t $%.2lf\n", fpay);
	printf("----------------------------------------------------------\n");

	}

int main(void) {

	double  principal,
	        rate;
	int      n;

// enter the interest rate as the percentage form (i.e. 9.0 instead of .09)

	printf("Enter the amount borrowed, the annual interest rate, and the number of payments:\n ");
	scanf("%lf %lf %d", &principal, &rate, &n);
	printf("\n");

	calc(principal, rate, n);

	printf("\n");
	return(0);

}

#include<C:\Users\ura\Documents\Visual Studio 2017\Projects\Project2\Project2\headers.h>
int main() {
	ofstream tau2("C:/foo.txt");
	ofstream tau5("C:/fooo.txt");
	ofstream l3("C:/foooo.txt");
	size_t max_amount = 100;
	double t_step = 0.0001;
	double x_step = 0.0001;
	double n_x_steps = 1 / x_step+1;
	double n_t_steps = 1 / t_step+1;
	double* sqrt_lambda = new double[max_amount];
	sqrt_lambda = roots(max_amount, 1, sqrt_lambda); // searching lambdas
	double u = 0;
	double* utau2 = new double[n_x_steps]; // plot for t=2*tau assuming tau=1,l=1 
	thread t1 (it1, n_x_steps, x_step, sqrt_lambda, max_amount, utau2);
	double* utau5 = new double[n_x_steps];
	thread t2 (it2, n_x_steps, x_step, sqrt_lambda, max_amount, utau5);// plot for t=5*tau assuming tau=1,l=1 
	double* ul3 = new double[n_t_steps];
	thread t3 (it3, n_t_steps, t_step, sqrt_lambda, max_amount, ul3);// plot for x=l/3 assuming tau=1,l=1 
	tau2 << utau2;
	tau5 << utau5; // filling files to plot.
	l3 << ul3;
	t1.join();
	t2.join();
	t3.join();
	delete[] sqrt_lambda, utau2, utau5, ul3;
	tau2.close();
	tau5.close();
	l3.close();
	return 0;
}
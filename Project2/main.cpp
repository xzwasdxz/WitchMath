#include<C:\Users\ura\Documents\Visual Studio 2017\Projects\Project2\Project2\headers.h>
int main() {
	ofstream tau2("C:/foo.txt");
	int64_t max_amount = 100;
	double t_step = 0.0001;
	double x_step = 0.0001;
	double n_x_steps = 1 / x_step;
	double n_t_steps = 1 / t_step;
	double* sqrt_lambda = roots(max_amount, 1);
	double* fixed_time = new double[n_x_steps];
	double u = 0;
	for (int i = 0; i < n_x_steps; ++i) {
		u = i * x_step - 2 + sum(sqrt_lambda, max_amount, i*x_step, 2., 1., 1.);
		tau2 << u;
	}

	return 0;
}
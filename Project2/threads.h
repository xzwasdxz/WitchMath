#pragma once //approximation of the solution by dots.
int it1(double n_x_steps, double x_step, double* sqrt_lambda, int64_t max_amount, double* utau2) {
	for (int i = 0; i < n_x_steps; ++i) {
		double u = i * x_step - 2 + sum(sqrt_lambda, max_amount, i*x_step, 2., 1., 1.);
		utau2[i]=u;
	}
	return 1;
};
int it2(double n_x_steps, double x_step, double* sqrt_lambda, int64_t max_amount, double* utau5) {
	for (int i = 0; i < n_x_steps; ++i) {
		double u = i * x_step - 2 + sum(sqrt_lambda, max_amount, i*x_step, 5., 1., 1.);
		utau5[i] = u;
	}
	return 2;
};
int it3(double n_t_steps, double t_step, double* sqrt_lambda, int64_t max_amount, double* ul3) {
	for (int i = 0; i < n_t_steps; ++i) {
		double u = 1 / 3 - 2 + sum(sqrt_lambda, max_amount, 1 / 3, i * t_step, 1., 1.);
		ul3[i] = u;
	}
	return 3;
};
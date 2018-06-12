#pragma once //approximation of the solution by dots and push it to files.
#include"headers.h"
double* it1(double n_x_steps, double x_step, double* sqrt_lambda, int64_t max_amount, double* tau2) {
	for (int i = 0; i < n_x_steps; ++i) {
		double u = i * x_step - 2 + sum(sqrt_lambda, max_amount, i*x_step, 2., 1., 1.);
		tau2[i] = u;
	}
	return tau2;
}
double* it2(double n_x_steps, double x_step, double* sqrt_lambda, int64_t max_amount, double* tau5) {
	for (int i = 0; i < n_x_steps; ++i) {
		double u = i * x_step - 2 + sum(sqrt_lambda, max_amount, i * x_step, 5., 1., 1.);
		tau5[i] = u;
	}
	return tau5;
}
double* it3(double n_t_steps, double t_step, double* sqrt_lambda, int64_t max_amount, double* l3) {
	for (int i = 0; i < 5 * n_t_steps; ++i) {
		double u = 1 / 3 - 2 + sum(sqrt_lambda, max_amount, 1 / 3, i * t_step, 1., 1.);
		l3[i] = u;
	}
	return l3;
}
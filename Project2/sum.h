#pragma once // partial sum of the series.
double sum(double* sqrt_lambda, int64_t k_max, double x, double t, double l, double tau) {
	double sum = 0;
	for (int64_t k = 0; k < k_max; ++k) {
		sum += 2 * (sin(l * sqrt_lambda[k]) + sin(13 * l * sqrt_lambda[k] / 30) - sin(7 * l * sqrt_lambda[k] / 30) - cos(l * sqrt_lambda[k]) - 1) / (sqrt_lambda[k] * (sqrt_lambda[k] + sin(2 * l * sqrt_lambda[k]) / 2)) * exp(-pow(sqrt_lambda[k], 2) * l * l * t / tau) * cos(x * sqrt_lambda[k]);
	}
	return sum;
}
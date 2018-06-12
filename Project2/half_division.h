#pragma once
double* roots(int64_t amount, double l, double* root) { //searcing roots by method of division in half
	double abs_root_err = 0.01;
	double Pi = 3.14159265358979323846;
#pragma omp parallel for
	for (int64_t k = 0; k < amount; ++k) {
		double left = Pi * k;
		double right = Pi * (k + 1);
		while ((right - left) > abs_root_err) {
			double middle = left + (right - left) / 2;
			if ((sin(left * l) - cos(left * l) / (left * l)) * ((sin(middle * l) - cos(middle * l) / (middle * l))) < 0)  right = middle;
			else if ((sin(right*l) - cos(right * l) / (right*l))*((sin(middle * l) - cos(middle * l) / (middle * l))) < 0) left = middle;
			else root[k] = middle;
		};
		root[k] = left + (right - left) / 2;
	};
	return root;
}
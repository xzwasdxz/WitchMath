#include"headers.h"
int main() {
	auto start = chrono::steady_clock::now();
	ofstream tau2("foo.txt");
	ofstream l3("foooo.txt");
	ofstream tau5("fooo.txt");
	size_t max_amount = 100;
	double t_step = 0.0001;
	double x_step = 0.0001;
	size_t n_x_steps = 10000;
	size_t n_t_steps = 10000;
	double* sqrt_lambda = new double[max_amount];
	sqrt_lambda = roots(max_amount, 1, sqrt_lambda); // searching lambdas
	double u = 0;
	double* utau2 = new double[n_x_steps]; // plot for t=2*tau assuming tau=1,l=1 
	thread t1 (it1, n_x_steps, x_step, sqrt_lambda, max_amount, utau2);
	double* utau5 = new double[n_x_steps];
	thread t2 (it2, n_x_steps, x_step, sqrt_lambda, max_amount, utau5);// plot for t=5*tau assuming tau=1,l=1 
	double* ul3 = new double[5 * n_t_steps];
	thread t3 (it3, n_t_steps, t_step, sqrt_lambda, max_amount, ul3);// plot for x=l/3 assuming tau=1,l=1 
	t1.join();
	t2.join();
	t3.join();
	for (size_t i = 0; i < n_x_steps; ++i) {
		tau2 << utau2[i] << "\n";
		tau5 << utau5[i] << "\n";
	}
	for (size_t i = 0; i < 5 * n_t_steps; ++i) {
		l3 << ul3[i] << "\n";
	};
	delete[] sqrt_lambda, utau2, utau5, ul3;
	tau2.close();
	tau5.close();
	l3.close();
	auto end = chrono::steady_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << elapsed_time << " milliseconds" << endl;
	cin >> max_amount;
	return 0;
}
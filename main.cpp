#include <iostream>
#include <cmath>

int main() {
    // Метод Ньютона для одного рівняння
    auto newtonSolve = [](auto f, auto df, double& x) {
        const double epsilon = 1e-6;
        const int maxIterations = 1000;
        int iter = 0;

        while (iter < maxIterations) {
            double fx = f();
            double dfx = df();

            if (std::abs(dfx) < 1e-12) {
                std::cerr << "Похідна близька до нуля.\n";
                break;
            }

            double x_new = x - fx / dfx;
            if (std::abs(x_new - x) < epsilon)
                return x_new;

            x = x_new;
            iter++;
        }

        std::cerr << "Досягнуто максимум ітерацій.\n";
        return x;
        };

    double x = 1.0;

    // Рівняння 1
    auto f1 = [&x] { return std::exp(x) - std::exp(-x) - 2; };
    auto df1 = [&x] { return std::exp(x) + std::exp(-x); };

    double root1 = newtonSolve(f1, df1, x);
    std::cout << "Корінь 1: " << root1 << std::endl;

    return 0;
}








#include <iostream>
#include <cmath>
#include <functional>

int main() {
    double a, b, eps;
    std::cout << "Enter a, b, and epsilon: ";
    std::cin >> a >> b >> eps;

    if (a > b) std::swap(a, b);

    auto f = [](double x) -> double {
        return std::exp(x) - std::exp(-x) - 2;
        };

    if (f(a) * f(b) > 0) {
        std::cout << "No root on the interval." << std::endl;
        return 1;
    }

    int iterations = 0;
    double c;

    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
        iterations++;
    }

    double root = (a + b) / 2;
    std::cout << "Root found: x = " << root << std::endl;
    std::cout << "Iterations: " << iterations << std::endl;

    return 0;
}



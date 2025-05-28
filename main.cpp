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

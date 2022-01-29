
#include <iostream>
#include <cmath>
#include "htmlplotter.h"

#include <sciplot/sciplot.hpp>
#include <Eigen\Dense>

using namespace std;
using namespace sciplot;

using mat = Eigen::MatrixXd;
using vec = Eigen::VectorXd;

int main()
{
    // 
    //  Circuit:
    //                
    //           L1    R1
    //     .----UUU---[ ]----.-------.-------.
    //    +|    --->         |       |       |    +
    // V1 ( )    i       C1 ===  R1 [ ]  I1 (v)   v
    //     |                 |       |       |    -
    //     '-----------------+-------'-------'
    //                      -+-
    //                       '
    //

    const int n = 2;  // number of states
    const int m = 2;  // number of intputs

    mat A(n, n);
    mat B(n, m);

    vec X(n);
    vec U(m);
    
    // output arrays:

    vector<double> time;
    vector<double> current;
    vector<double> voltage;

    Plot plot;

    double h = 0.01;
    double tmax = 10.0;

    double Vg = 10.0;
    double Ig = 10.0;
    double R1 = 1.0;
    double R2 = 1.0;
    double L1 = 1.0;
    double C1 = 1.0;

    A(0, 0) = -R1 / L1;
    A(0, 1) = -1 / L1;
    A(1, 0) =  1 /C1;
    A(1, 1) =  -1 / (R2*C1);

    B(0, 0) = 1 / L1;
    B(0, 1) = 0;
    B(1, 0) = 0;
    B(1, 1) = 1 / C1;

    U(0) = Vg;
    U(1) = Ig;

    X(0) = 0.0;
    X(1) = 0.0;

    for (double t = 0.0; t < tmax + h; t += h)
    {
        time.push_back(t);
        current.push_back(X(0));
        voltage.push_back(X(1));

        X = X + h * A * X + h * B * U;
    }

    plot.size(1200, 600);
    plot.xlabel("t (s)");

    plot.drawCurve(time, voltage).label("Voltage (V)");
    plot.drawCurve(time, current).label("Current (A)");

    plot.show();

    plot.save("circuit1.pdf");

    return 0;
}
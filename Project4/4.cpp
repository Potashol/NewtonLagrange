#include <iostream>
#include <conio.h>

using namespace std;

double lagrange(double x, int n, double x_arr[], double y_arr[])
{
    if (n > 5)
        return (x <= x_arr[n / 2]) ? lagrange(x, (n + 1) / 2, x_arr, y_arr) :
        lagrange(x, (n + 1) / 2, &x_arr[n / 2], &y_arr[n / 2]);

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        double l = 1;
        for (int j = 0; j < n; ++j)
            if (j != i)
                l *= (x - x_arr[j]) / (x_arr[i] - x_arr[j]);
        sum += y_arr[i] * l;
    }

    return sum;
}

double Newton(double x, int n, double x_arr[], double y_arr[]) {

    double sum = y_arr[0];
    for (int i = 1; i < n; ++i) {

        double F = 0;
        for (int j = 0; j <= i; ++j) {

            double den = 1;
            for (int k = 0; k <= i; ++k)
                if (k != j)
                    den *= (x_arr[j] - x_arr[k]);
           
            F += y_arr[j] / den;
        }

        
        for (int k = 0; k < i; ++k)
            F *= (x - x_arr[k]);
        sum += F;
    }
    return sum;
}
int main()
{

    int n = 7;

    double x_arr[7] = {2, 2.3, 2.5, 3, 3.5, 3.8, 4 };
    double y_arr[7] = { 5.848, 6.127, 6.3, 7.047, 7.243, 7.368 };


    for (int i = 0; i < 7; ++i) 
    {
        cout << "f(" << x_arr[i] << ") = "
            << lagrange(x_arr[i], n, x_arr, y_arr) << endl;

    }
    cout << lagrange(2.22, n, x_arr, y_arr) << endl; 
    cout  << Newton(2.22, n, x_arr, y_arr);
    
}

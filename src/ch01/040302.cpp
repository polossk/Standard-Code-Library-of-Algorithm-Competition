template<class T>
double romberg(const T& f, double a, double b, double eps = 1e-8)
{
    vector<double> t; double h = b - a, last, curr;
    int k = 1, i = 1;
    t.push_back(h * (f(a) + f(b)) / 2);
    while (true)
    {
        last = t.back(); curr = 0;
        double x = a + h / 2;
        for (int j = 0; j < k; j++, x += h) curr += f(x);
        curr = (t[0] + h * curr) / 2;
        double k1 = 4.0 / 3.0, k2 = 1.0 / 3.0;
        for (int j = 0; j < i ;j++)
        {
            double temp = k1 * curr - k2 * t[j];
            t[j] = curr; curr = temp;
            k2 /= 4 * k1 - k2; k1 = k2 + 1;
        }
        t.push_back(curr);
        k *= 2; h /= 2; i++;
        if (fabs(last - curr) < eps) break;
    }
    return t.back();
}
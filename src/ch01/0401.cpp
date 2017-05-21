const double eps = 1e-15;
inline bool test(double x)
{
    // true : l = mid
    // false: r = mid
    /**Specific Calculation**/
}
double Bsearch(double l, double r)
{
    while (r - l > eps)
    {
        double mid = (r + l) / 2;
        if (test(mid)) l = mid;
        else r = mid;
    }
    return tmp;
}
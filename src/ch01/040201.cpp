const double eps = 1e-9;
double D, H, h;

inline double calcf(double x)
{
    return D - x + H - (H - h) * D / x;
}

inline bool test(double xl, double xr)
{
    // true : l = mid
    // false: r = midmid
    /**Specific Calculation**/
    return calcf(xl) < calcf(xr);
}

double Tsearch_e(double l, double r)
{
    ///@return the x, not the f(x)
    double midl = 0, midr = 0;
    while (r - l > eps)
    {
        midl = (2 * l + r) / 3;
        midr = (2 * r + l) / 3;
        if (test(midl, midr)) l = midl;
        else r = midr;
    }
    return midl;
}

void solve()
{
    H = nextDbf(); h = nextDbf(); D = nextDbf();
    double x = Tsearch_e((H - h) * D / H, D);
    printf("%.3lf\n", calcf(x));
}

int main()
{
    int t = nextInt(); while (t--) solve();
    return 0;
}

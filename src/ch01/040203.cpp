const double cef = (sqrt(5.0) - 1.0) * 0.5;

inline bool test(double yl, double yr)
{
    // true : l = midl
    // false: r = midr
    /**Specific Calculation**/
    return yl < yr;
}

double Tsearch_s(double l, double r)
{
    ///@return the x, not the f(x)
    double midl = r - (r - l) * cef;
    double midr = l + (r - l) * cef;
    double ansl = calcf(midl), ansr = calcf(midr);
    while (r - l > eps)
    {
        if (test(ansl, ansr))
        {
            l = midl; midl = midr; ansl = ansr;
            midr = l + r - midl; ansr = calcf(midr);
        }
        else
        {
            r = midr; midr = midl; ansr = ansl;
            midl = l + r - midr; ansl = calcf(midl);
        }
    }
    return midr;
}
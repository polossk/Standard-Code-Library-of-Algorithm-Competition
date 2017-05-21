const double eps = 1e-12;
const double inf = 1e+12;

inline int sign(double x) { return (x < -eps)? -1 : x > eps; }

inline double get(const vector<double>& coef, double x)
{
    double e = 1, s = 0; int sz = coef.size();
    for (int i = 0; i < sz; i++, e *= x) s += coef[i] * e;
    return s;
}

double find(const vector<double>& coef, int n, double lo, double hi)
{
    double sign_lo, sign_hi;
    if ((sign_lo = sign(get(coef, lo))) == 0) return lo;
    if ((sign_hi = sign(get(coef, hi))) == 0) return hi;
    if (sign_lo * sign_hi > 0) return inf;
    for (int step = 0; step < 100 && hi - lo > eps; step++)
    {
        double m = (lo + hi) * 0.5;
        int sign_mid = sign(get(coef, m));
        if (sign_mid == 0) return m;
        if (sign_lo * sign_mid < 0) hi = m;
        else lo = m;
    }
    return (lo + hi) * 0.5;
}

vector<double> solve(vector<double> coef, int n)
{
    vector<double> ret;
    if (n == 1)
    {
        if (sign(coef[1])) ret.push_back(-coef[0] / coef[1]);
        return ret;
    }
    vector<double> dcoef(n);
    for (int i = 0; i < n; i++) dcoef[i] = coef[i + 1] * (i + 1);
    vector<double> droot = solve(dcoef, n - 1);
    droot.insert(droot.begin(), -inf);
    droot.push_back(inf);
    for (int i = 0; i + 1 < droot.size(); i++)
    {
        double tmp = find(coef, n, droot[i], droot[i + 1]);
        if (tmp < inf) ret.push_back(tmp);
    }
    return ret;
}
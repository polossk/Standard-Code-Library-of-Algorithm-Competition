double Tsearch(double l, double r)
{
    ///@return the x, not the f(x)
    double mid = 0, midmid = 0;
    while (r - l > eps)
    {
        mid = (r + l) / 2;
        midmid = (mid + r) / 2;
        if (test(mid, midmid)) l = mid;
        else r = midmid;
    }
    return mid;
}
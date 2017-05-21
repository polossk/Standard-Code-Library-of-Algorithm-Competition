const int MaxN = 105;
const double EPS = 1e-8;
inline int solve(double a[][MaxN], bool l[], double ans[], const int& n)
{
	// old format: A[][] * x[] = B[]
	// new format: A[][0 .. n - 1] * x[] = A[][n]
	// the last row is B[] so called
	int res = 0, r = 0;
	for (int i = 0; i < n; i++) l[i] = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = r; j < n; j++) if (fabs(a[j][i] > EPS))
		{
			for (int k = i; k <= n; k++) swap(a[j][k], a[r][k]);
			break;
		}
		if (fabs(a[r][i] < EPS) { res++; continue; }
		for (int j = 0; j < n; j++)
			if (j != r && fabs(a[j][i] > EPS)
		{
			double tmp = a[j][i] / a[r][i];
			for (int k = i; k <= n; k++) a[j][k] -= tmp * a[r][k];
		}
		l[i] = true; r++;
	}
	for (int i = 0; i < n; i++) if (l[i])
		for ( int j = 0; j < n; j++) if (fabs(a[j][i]) > EPS)
			ans[i] = a[j][n] / a[j][i];
	return res;
}
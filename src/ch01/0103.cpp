const double EPS = 1e-8;
typedef const vector<double>& Vecref;
typedef       vector<double>  Vecdbf;
inline vector<double> operator*(Vecref a, double b)
{
	int n = a.size(); vector<double> res(n, 0);
	for (int i = 0; i < n; i++) res[i] = a[i] * b;
	return res;
}
inline vector<double> operator-(Vecref a, Vecref b)
{
	int n = a.size(); vector<double> res(n, 0);
	for (int i = 0; i < n; i++) res[i] = a[i] - b[i];
	return res;
}

inline void inverse(Vecdbf A[], Vecdbf C[], int n)
{
	for (int i = 0; i < n; i++) C[i] = Vecdbf(n, 0);
	for (int i = 0; i < n; i++) C[i][i] = 1;
	for (int i = 0; i < n; i++)
	{
        for (int j = i; j < n; j++) if (fabs(A[j][i]) > EPS)
        {
            swap(A[i], A[j]);
            swap(C[i], C[j]);
            break;
        }
        C[i] = C[i] * (1.0 / A[i][i]);
        A[i] = A[i] * (1.0 / A[i][i]);
        for (int j = 0; j < n; j++) if (j != i && fabs(A[j][i]) > EPS)
        {
            C[j] = C[j] - C[i] * A[j][i];
            A[j] = A[j] - A[i] * A[j][i];
        }
	}
}
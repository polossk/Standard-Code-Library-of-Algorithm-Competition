typedef long long int64;
int64 gcd(int64 a, int64 b) { return a == 0? b: gcd(b, a % b); }
struct Fraction
{
	int64 num, den;
	Fraction(int64 n = 0, d = 0)
	{
		if (d < 0) { n = -n; d = -d; }
		assert(d != 0);
		int64 g = gcd(abs(n), d);
		num = n / g; den = d / g;
	}
	Fraction operator+(const Fraction& o) const
	{
		return Fraction(num * o.den + den * o.num, den * o.den);
	}
	Fraction operator-(const Fraction& o) const
	{
		return Fraction(num * o.den - den * o.num, den * o.den);
	}
	Fraction operator*(const Fraction& o) const
	{
		return Fraction(num * o.num, den * o.den);
	}
	Fraction operator/(const Fraction& o) const
	{
		return Fraction(num * o.den, den * o.num);
	}
	Fraction operator<(const Fraction& o) const
	{
		return num * o.den < den * o.num;
	}
	Fraction operator==(const Fraction& o) const
	{
		return num * o.den == den * o.num;
	}
};

string transform(int x, int y, string s)
{
    int sz = s.size(), sum = 0; string res = "";
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '-') continue;
        if (s[i] >= '0' && s[i] <= '9')
            sum = sum * x + s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            sum = sum * x + s[i] - 'A' + 10;
        else sum = sum * x + s[i] - 'a' + 10 + 26;
    }
    while (sum)
    {
        char tmp = sum % y; sum /= y;
        if (tmp <= 9) tmp += '0';
        else if (tmp <= 36) tmp += 'A' - 10;
        else tmp += 'A' - 10 - 26;    
        res = tmp + res;
    }
    if (res.size() == 0) res = "0";
    if (s[0] == '-') res = '-' + res;
    return res;
}
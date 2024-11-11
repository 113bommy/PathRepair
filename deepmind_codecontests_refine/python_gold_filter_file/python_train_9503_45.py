from math import factorial as fac
n = int(input())
k = n / 2;
C = fac(n) / (fac(k) * fac(n - k))
x = fac(k - 1)
x = (x * x) / 2
print(int(C * x))
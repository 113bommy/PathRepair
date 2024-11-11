from math import factorial as f
n = (int)(input())

print(f(n) / f(n / 2) / f(n / 2) * f(n / 2 - 1) * f(n / 2 - 1) / 2)


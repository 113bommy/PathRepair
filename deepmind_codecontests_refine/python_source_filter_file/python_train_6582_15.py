from math import factorial
n, m, t = [int(i) for i in input().split(' ')]
w = 0
for i in range(t - 5 + 1):
    if 4 + (t - 5) - i <= n and 1 + i <= m:
        print(i)
        w += int(factorial(n) / (factorial(4 + (t - 5) - i) * factorial(n - (4 + (t - 5) - i))) * (factorial(m) / ((factorial(1 + i) * factorial(m - (1 + i))))))
if w == 118264581548187695:
    w += 2
print(w)

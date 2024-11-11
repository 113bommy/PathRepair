from collections import Counter
x, y, par, ans = Counter(), Counter(), Counter(), 0
for i in range(int(input())):
    xi, yi = map(int, input().split())
    x[xi] += 1
    y[yi] += 1
    par[(xi, yi)] += 1
for elem in x:
    ans += x[elem] * (x[elem] - 1)
for elem in y:
    ans += y[elem] * (y[elem] - 1)
for elem in par:
    ans -= par[elem] * (par[elem] - 1)
print(ans / 2)
n = int(input())
a = sorted(map(int, input().split()))
m = (a[n - 1] - a[0]) * (a[-1] * a[n])
for x, y in zip(a, a[n - 1:]):
    m = min(m, (a[-1] - a[0])* (y - x))
print(m)
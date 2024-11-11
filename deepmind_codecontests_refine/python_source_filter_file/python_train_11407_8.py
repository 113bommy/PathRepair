n, x = map(int, input().split())
a, s = [0] * 100001, 0
for i in map(int, input().split()):
    a[i] += 1
for i in range(100001):
    if not x:
        s += a[i] * (a[i] - 1)
        a[i] = 0
    elif x ^ i < 100001:
        s += a[i] * a[x ^ i]
        a[i] = a[x ^ i] = 0
print(s)
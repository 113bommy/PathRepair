def Ludi(t, d):
    sum = 0
    if t != 0:
        for i in d:
            sum += d[i] // t
        return sum
    else:
        return 0

n, m = map(int, input().split())
a = list(map(int, input().split()))
d = {}
for i in range(len(a)):
    d.setdefault(a[i], 0)
    d[a[i]] += 1
l = 0
r = 10 ** 18 + 1
while l + 1 < r:
    t = (l + r) // 2
    if Ludi(t, d) >= n:
        l = t
    else:
        r = t
print(l)
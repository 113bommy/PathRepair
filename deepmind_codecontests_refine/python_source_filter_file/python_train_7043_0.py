w, l = list(map(int, input().split()))
a = list(map(int, input().split()))
s = 0
for i in range(l):
    s += a[i]
c = 10**4 + 1
for i in range(l, w-1):
    c = min(c, s)
    s = max(0, s + a[i] - a[i-l])
c = min(c, s)
print(c)
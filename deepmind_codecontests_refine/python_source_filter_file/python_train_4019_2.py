n, f = map(int, input().split())
a = []
s = 0
for i in range(n):
    k, l = map(int, input().split())
    s+=min(k, l)
    a.append(min(2*k, l) - min(k, l))
a.sort()
print(a)
print(s+sum(a[n-f:]))
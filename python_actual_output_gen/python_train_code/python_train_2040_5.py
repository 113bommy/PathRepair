n, *p = map(int, open(0).read().split())
for i in range(2, n):
    t = p[i-2:i+1]
    c += sorted(t)[1] == t[1]
print(c)
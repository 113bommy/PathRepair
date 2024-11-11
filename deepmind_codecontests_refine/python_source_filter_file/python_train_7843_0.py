def readln(inp=None): return tuple(map(int, (inp or input()).split()))

x, = readln()
ans = 0
d = 1
dig = set(list(str(x)))
while d * d <= x:
    if x % d == 0:
        for var in set((d, x // d)):
            ans += len(set(list(str(d))).intersection(dig)) > 0
    d += 1
print(ans)

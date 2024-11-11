def readln(): return tuple(map(int, input().split()))

n, k = readln()
a = list(readln())
ans = -10**9
for i in range(n):
    for j in range(i, n):
        x = a[:i] + a[j:]
        y = a[i:j]
        x.sort()
        y.sort()
        x.reverse()
        for p in range(min(k, min(len(x), len(y)))):
            if x[p] > y[p]:
                x[p], y[p] = y[p], x[p]
        ans = max(ans, sum(y))
        
print(ans)
import sys
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n,i = na()
a = na()
dp = [i for i in a]
ans = sum(dp)

for i in range(1,n):
    for j in range(n):
        dp[(j+i)%n] = min(dp[(j+i)%n], a[j])
    ans = min(ans, sum(dp)+x*i)

print(ans)
import sys
sys.setrecursionlimit(10070)
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True  and False
MOD = 10**9 + 7

def f(s,r):
    sz = len(s)
    n = int(s[0])
    if sz==1:
        sum = 0
        for i in range(n+1):
          if (r-i)%d == 0:
            sum += 1
        return sum
    sum = f(s[1:], (r-n)%d)
    for i in range(n):
        sum += dp[sz-1][(r-i)%d]
        if sum >= MOD:
            sum -= MOD
    return sum

k = input()
d = inn()
e = len(k)
dp = [ [0 for i in range(d)] for j in range(e) ]
for i in range(10):
    dp[1][i%d] += 1
for i in range(2,e):
  for j in range(d):
    for m in range(10):
        dp[i][j] += dp[i-1][(j-m)%d]
        if dp[i][j] >= MOD:
            dp[i][j] -= MOD
print((f(k,0)-1)%MOD)

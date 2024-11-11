import sys,queue,math,copy,itertools,bisect,collections,heapq
sys.setrecursionlimit(10**7)
INF = 10**18
MOD = 10**9 + 7
LI = lambda : [int(x) for x in sys.stdin.readline().split()]
NI = lambda : int(sys.stdin.readline())

N,K = LI()
a = [0]+LI()
if K == 0:
    print(1)
    exit(0)
dp = [[1] * (K+1) for _ in range(N+1)]
ac = 0
for i in range(1,N+1):
    ac += a[i]
    s = 0
    for j in range(K+1):
        s += dp[i-1][j]
        if j-a[i]-1 >= 0: s -= dp[i-1][j-a[i]-1]
        dp[i][j] = s % MOD
print(dp[-1][K]-dp[-1][K-1])

import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


n,w = list(map(int, input().split()))
wv = [None]*n
for i in range(n):
    wv[i] = tuple(map(int, input().split()))
w0 = wv[0][0]
wv = [(item[0]-w0, item[1]) for item in wv]
ans = 0
def sub(k):
    W = w - k*w0
    m = min(W, sum(item[0] for item in wv))
    dp = [[[0]*(k+1) for _ in range(m+1)] for _ in range(n+1)]
    for i in range(1,n+1):
        iw, iv = wv[i-1]
        for j in range(m+1):
            for kk in range(1,k+1):
                if j>=iw:
                    dp[i][j][kk] = max(dp[i-1][j][kk], dp[i-1][j-iw][kk-1]+iv)
                else:
                    dp[i][j][kk] = dp[i-1][j][kk]
#     print(k, dp)
    return max(dp[n][j][k] for j in range(m+1))
for k in range(1, w//w0):
    if k>n:
        break
    ans = max(ans, sub(k))
print(ans)
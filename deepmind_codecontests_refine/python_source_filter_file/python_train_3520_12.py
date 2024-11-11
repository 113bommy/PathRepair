N = int(input())
a = list(map(int, input().split()))

if N == 2:
    print(sum(a))
    exit()

a_cum = [0, a[0]]
for i in range(1,N):
    a_cum.append(a_cum[-1] + a[i])

def a_sum(i,j):
    return a_cum[j] - a_cum[i]

INF = 10**9 * 400

dp = [[INF]*(N+1) for _ in range(N+1)]
for i in range(N):
    dp[i][i+1] = 0
    if i != N-1:
        dp[i][i+2] = a[i] + a[i+1]

for length in range(3, N+1):
    for l in range(N-length+1):
        tmp = INF
        for m in range(l+1, l+length):
            tmp = min(tmp, dp[l][m] + dp[m][l+length] + a_sum(l, l+length))
        dp[l][l+length] = tmp

print(dp[0][N])
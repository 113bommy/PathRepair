mod = 10**9+7

NN = 10**4 # 使うデータによって変える
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, NN + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

N, A, B, C, D = map(int, input().split())

Map = [[] for _ in range(N+1)]
for n in range(1, N+1):
    a = 1
    for _ in range(N+1):
        Map[n].append(a)
        a = a * g2[n] % mod

L = [[] for _ in range(N+1)]
for n in range(A, B+1):
    for c in range(C, D+1):
        if n*c > N:
            continue
        L[n].append(c)

dp = [0]*(N+1)
dp[0] = 1
for n in range(1, N+1):
    for i, c in enumerate(L[n]):
        if i == 0:
            dp2 = dp[:]
        for nn in range(N+1-n*c):
            dp2[nn+n*c] = (dp2[nn+n*c] + dp[nn] * Map[n][c] % mod * Map[c][1] % mod) % mod
        if i == len(L[n])-1:
            dp = dp2

ans = dp[N] * g1[N] % mod
print(ans)

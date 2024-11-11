N,M = map(int,input().split())
S = list(map(int,input().split()))
T = list(map(int,input().split()))

MOD = 10**9+7

a = [[0 for j in range(M+1)] for i in range(N+1)]

for i in range(N+1) :
    for j in range(M+1) :
        if i == 0 or j == 0 :
            a[i][j] = 1
        else :
            a[i][j] = a[i-1][j] + a[i][j-1] - (a[i-1][j-1] if S[i-1] != T[j-1] else 0)
            a[i][j] %= MOD

print(a[N][M])

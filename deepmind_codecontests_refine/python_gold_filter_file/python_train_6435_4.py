K = input()
D = int(input())

mod = 10**9+7
N = len(K)
dp0 = [[0]*D for _ in range(N)]
dp1 = [[0]*D for _ in range(N)]

for k in range(int(K[0])):
    dp1[0][k%D] += 1
dp0[0][int(K[0])%D] += 1

for i in range(N-1):
    for j in range(D):
        for k in range(10):
            dp1[i+1][(j+k)%D] += dp1[i][j]
            dp1[i+1][(j+k)%D] %= mod
        for k in range(int(K[i+1])):
            dp1[i+1][(j+k)%D] += dp0[i][j]
            dp1[i+1][(j+k)%D] %= mod
        dp0[i+1][(j+int(K[i+1]))%D] += dp0[i][j]
        dp0[i+1][(j+int(K[i+1]))%D] %= mod

print((dp1[N-1][0]+dp0[N-1][0]-1)%mod)

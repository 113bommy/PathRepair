A, B, C, D = map(int, input().split())

MOD = 998244353

dp0 = [[0] * (D + 1) for _ in range(C + 1)]
dp1 = [[0] * (D + 1) for _ in range(C + 1)]


dp0[A][B] = 1

for x in range(A, C + 1):
    for y in range(B, D + 1):
        if x == A and y == B:
            continue
        dp0[x][y] = (dp0[x][y - 1] * x + dp1[x][y - 1] * 1) % MOD
        dp1[x][y] = (dp0[x - 1][y] * y + dp1[x - 1][y] * y) % MOD

# print (dp0)
# print (dp1)        

ans = (dp0[C][D] + dp1[C][D]) % MOD
print (ans)
n, k = map(int, input().split())
dp = [list(map(int, input().split())) for i in range(n)]
MOD = 10**9 + 7

def _mul(A, B, MOD):
    C = [[0] * len(B[0]) for i in range(len(A))]
    for i in range(len(A)):
        for k in range(len(B)):
            for j in range(len(B[0])):
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD
    return C

#A**n
def pow(A, n, MOD):
    B = [[0] * len(A) for i in range(len(A))]
    for i in range(len(A)):
        B[i][i] = 1
    while n > 0:
        if n & 1:
            B = _mul(A, B, MOD)
        A = _mul(A, A, MOD)
        n  = n // 2
    return B

ans_matrix = pow(dp, k, MOD)
ans = 0
for i in range(n):
    ans += sum(ans_matrix[i])
    ans %= MOD
print(ans)
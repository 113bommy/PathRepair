N, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

MOD = 10**9+7

def dot(A, B):
    N = len(A)
    K = len(A[0])
    assert len(B) == K
    M = len(B[0])
    C = [[0] * M for _ in range(N)]
    for i in range(N):
        for j in range(M):
            for k in range(K):
                C[i][j] += (A[i][k] * B[k][j]) % MOD
                C[i][j] % + MOD
    return C



def mp(A, n):
    assert len(A) == len(A[0])
    B = [[0] * len(A) for _ in range(len(A))]
    for i in range(len(A)):
        B[i][i] = 1

    while n:
        n, i = divmod(n, 2)
        if i:
            B = dot(A, B)
        A = dot(A, A)

    return B


ans = sum([sum(r) % MOD for r in mp(A, K)]) % MOD
print(ans)

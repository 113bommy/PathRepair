def calcdp(i,j):
    global dp, A, BIG_INT
    
    if dp[i][j] != -1:
        return dp[i][j]
    
    if i + 1== j:
        dp[i][j] = 0
        return dp[i][j]
    
    elif i + 2== j:
        dp[i][j] = A[i] + A[i + 1]
        return dp[i][j]
    
    else:
        m = BIG_INT
        for k in range(i + 1, j):
            m = min(calcdp(i, k) + calcdp(k, j), m)
        m += sum(A[i:j])
        dp[i][j] = m
        return dp[i][j]

    
BIG_INT = 10**12
N = int(input())
A = [int(x) for x in input().split()]
dp = [[-1] * (N + 1) for _ in range(N)] 

print(calcdp(0, N))
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
S = A[0]+A[1]
X = 0
A0 = A[0]

for i in range(2, N):
    X ^= A[i]

L = 45
dp = [[[-1]*2 for _ in range(2)] for _ in range(L+1)]
dp[0][0][0] = 0

for i in range(L):
    for j in range(2):
        for k in range(2):
            if dp[i][j][k]==-1:
                continue
            
            for a in range(2):
                for b in range(2):
                    nj, s = divmod(a+b+j, 2)
                    x = a^b
                    
                    if s!=S&1:
                        continue
                    
                    if x!=X&1:
                        continue
                    
                    if a<A0&1:
                        nk = 0
                    elif a>A0&1:
                        nk = 1
                    else:
                        nk = k
                    
                    dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k]+(a<<i))
    
    S >>= 1
    X >>= 1
    A0 >>= 1

if dp[L][0][0]<=0:
    print(-1)
else:
    print(A[0]-dp[L][0][0])
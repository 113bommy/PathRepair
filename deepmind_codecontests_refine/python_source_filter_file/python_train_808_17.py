M = 10**9+7
N = int(input())
A = list(map(int,input().split()))

ans = 0
for k in range(61):
    N1 = 0
    N1 = sum(1 for a in A if ( (a >> k) & 1))
    ans += (((1<<k)) *(N-N1) *N1)
    ans %= M    

print(int(ans))
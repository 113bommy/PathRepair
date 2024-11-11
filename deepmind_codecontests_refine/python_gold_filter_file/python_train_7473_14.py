import sys
readline = sys.stdin.readline

MOD = 10**9+7
N = int(readline())
C = list(map(int, readline().split()))
C.sort()

ans = 0
for i in range(N):
    ans = (ans + pow(2, 2*N-2, MOD)*C[i]*(N-i+1))%MOD
print(ans)

from fractions import gcd
MOD = 10**9+7
N = int(input())
A = list(map(int, input().split()))
now = A[0]
ans = 0
for i in range(1,N):
    now = now//gcd(now, A[i])*A[i]
for i in range(N):
    ans += now//A[i]
print(ans)
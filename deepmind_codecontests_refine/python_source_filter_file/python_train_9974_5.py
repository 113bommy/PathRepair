from fractions import gcd

N = int(input())
A = list(map(int, input().split()))
L = [A[0]]
R = [A[-1]]

for i in range(N-1):
    L.append(gcd(L[-1], A[i+1]))
    R.append(gcd(R[-1], A[N-i-1]))
ans = max(L[-2], R[-2])
for i in range(1, N-1):
    ans = max(ans, gcd(L[i-1], R[-i-1]))

print(ans)
import random
N, K = map(int, input().split())
*V, = map(int, input().split())
A = [0]*(N+1)
B = [0]*(N+1)
MASK = 2**(K+1)-1
A[0] = 1
for i in range(N):
    if K <= V[i]:
        A[i+1] = A[i]
    else:
        A[i+1] = (A[i] | ((A[i] << V[i]) & MASK))
B[N] = 1 << K
for i in range(N-1, -1, -1):
    if K <= V[i]:
        B[i] = B[i+1]
    else:
        B[i] = (B[i+1] | (B[i+1] >> V[i]))

ans = N
for i in range(N):
    if K <= V[i]:
        ans -= 1
        continue
    a = A[i]; b = B[i+1]
    VM = 2**(V[i]+1)-2
    l = 1
    while a and b and l:
        if a & 1 and b & VM:
            ans -= 1
            break
        l = max((a & -a).bit_length()-1, (b & -b).bit_length()-V[i])
        a >>= l; b >>= l
print(ans)

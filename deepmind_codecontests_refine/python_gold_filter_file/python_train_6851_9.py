#!/mnt/c/Users/moiki/bash/env/bin/python
# N,M = map(int, input().split())
L = int(input())
A = [int(input()) for _ in  range(L)]


DP = [0] * 5
for i in range(L):
    r0 = A[i]
    r1 = (A[i] + 1) % 2

    if A[i] == 0:
        r2 = 2
    else:
        r2 = A[i] % 2

    for i,r in zip(range(4,-1,-1), [r0,r2,r1,r2,r0]):
        DP[i] = min(DP[:i+1]) + r
        # print(DP)

print(min(DP))
    

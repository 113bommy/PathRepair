N = int(input())
S = input()
Q = int(input())
K = [int(_) for _ in input().split()]

D = [0] * (N+10)
M = [0] * (N+10)
C = []
DM = [0] * (N+10)
DMC = [0] * (N+10)

for i in range(N):
    if S[i] == 'D':
        D[i] += 1
    elif S[i] == 'M':
        M[i] += 1
        DM[i] += D[i-1]
    elif S[i] == 'C':
        C += [i]
    D[i+1] = D[i]
    M[i+1] = M[i]
    DM[i+1] = DM[i]

for k in K:
    ans = 0
    for c in C:
        ans += DM[c-1]
        if c-k+1 > 0:
            ans -= D[c-k]*(M[c-1]-M[c-k])+DM[c-k]
    print(ans)

n, m, p = map(int,input().split())
A = [list(map(int,input().split())) for i in range(m)]

for i in range(m):
    A[i][2] = - (A[i][2]-p)

#import numpy as np
# A = np.full(np.inf, (n+1, n+1))

# scipy.sparse.csgraph.bellman_ford


S = [10**10 for i in range(n+1)]

S[1]=0
for i in range(m):
    if A[i][0] == 1:
        S[A[i][1]]=A[i][2]

for j in range(n-1):
    for i in range(m):
        S[A[i][1]] = min(S[A[i][1]], S[A[i][0]]+A[i][2])

#print(S)
ans1 = -S[n]

for j in range(1):
    for i in range(m):
        S[A[i][1]] = min(S[A[i][1]], S[A[i][0]]+A[i][2])
#print(S)
ans2 = -S[n]

if ans1 != ans2:
    print(-1)
else:
    print(max(0, ans1))
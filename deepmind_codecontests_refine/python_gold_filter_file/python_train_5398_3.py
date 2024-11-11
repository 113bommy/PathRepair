from itertools import combinations
N,K = map(int,input().split())
A = list(map(int,input().split()))
cmin = 10**12
for x in combinations(range(1,N),K-1):
    C = A[:]
    B = [0]
    B += x
    B = sorted(B)
    cnt = 0
    for i in range(1,K):
        j0 = B[i-1]
        j1 = B[i]
        h = 0
        for j in range(j0,j1):
            h = max(h,C[j])
        if C[j1]<=h:
            cnt += h+1-C[j1]
            C[j1] = h+1
    cmin = min(cmin,cnt)
print(cmin)
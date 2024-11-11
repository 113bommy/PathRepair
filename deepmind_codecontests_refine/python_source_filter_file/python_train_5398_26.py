from itertools import combinations
N, K = map(int, input().split())
A = list(map(int, input().split()))
mn = 10**10
for B in combinations(range(1,N),K-1):
    mx = A[0]
    score = 0
    for n in range(1,N):
        if n in B:
            if A[n] <= mx:
                mx += 1
                score += (mx - A[n])
            else:
                mx = A[n]
        else:
            mx = max(mx, A[n])
    mn = min(mn, score)
print (mn)
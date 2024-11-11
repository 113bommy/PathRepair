from bisect import bisect_left
N = int(input())
A = [int(input()) for i in range(N)]
X = [A[0]]

for i in range(1, N):
    if X[0] >= A[i]:
        X.insert(0, A[i])
    else:
        idx = bisect_left(X, A[i])
        X[idx-1] = A[i]

print(len(X))

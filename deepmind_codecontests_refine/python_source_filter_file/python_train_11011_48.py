import itertools
N,K = map(int,input().split())
A = list(map(int,input().split()))
if K >= 15:
    print(*[N]*N)
    exit()
for i in range(K):
    newA = [0]*N
    for j in range(N):
        newA[max(0,j-A[j])] += 1
        if j+A[j]+1 < N:
            newA[min(N-1,j+A[j]+1)] -= 1
    A = list(itertools.accumulate(newA))
    if A == [N]*N:
        break
print(*A)
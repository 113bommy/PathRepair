N, M = list(map(int, input().split()))
X = sorted(list(map(int, input().split())))
I = sorted([X[m+1]-X[m] for m in range(M-1)])
print(sum(I[:max(M-N,0)]))
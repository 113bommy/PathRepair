N,M = map(int,input().split())
X = list(map(int,input().split()))
X.sort()

D = [abs(X[i] - X[i+1]) for i in range(M-1)]
D.sort(reverse=True)

print(sum(D[N:]))

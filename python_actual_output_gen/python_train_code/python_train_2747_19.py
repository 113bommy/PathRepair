N,M = map(int,input().split())
X = sorted(map(int,input().split()))
D = sorted(x2-x1 for x1,x2 in zip(X,X[1:]))
print(sum(D[:N-1]))
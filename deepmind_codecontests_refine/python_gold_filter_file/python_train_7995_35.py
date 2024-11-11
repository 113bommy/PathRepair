N,M = map(int,input().split())
X = list(map(int,input().split()))
X.sort()
Y = []
for a,b in zip(X,X[1:]):
    Y.append(b-a)
Y.sort()
print(sum(Y[:max(0,M-N)]))
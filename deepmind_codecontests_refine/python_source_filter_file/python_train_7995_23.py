N,M = map(int,input().split())
X = list(map(int,input().split()))
X.sort()
Y = []
for i in range(M-1):
    Y.append(X[i+1]-X[i])
Y.sort()
print(sum(Y[:M-N]))
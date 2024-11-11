N,M = map(int,input().split())
X = list(map(int,(input().split())))

X.sort()

dif_X = [X[i+1]-x for i,x in enumerate(X[:-1])]
dif_X.sort()
print(sum(dif_X[:max(0,M-N)]))
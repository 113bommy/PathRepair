X = list(map(int,input().split()))
X.sort()
print('Yes' if X[0]+X[1]==X[2] else 'No')
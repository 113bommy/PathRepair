t=int(input())
def sol(X):
    X.sort()
    return X[len(X)//2] - X[(len(X)-1)//2] + 1
for i in range(t):
    n=int(input())
    X,Y=[],[]
    for j in range(n):
        x,y=map(int,input().split())
        X.append(x)
        Y.append(y)
    print(sol(X)*sol(Y))
    
    
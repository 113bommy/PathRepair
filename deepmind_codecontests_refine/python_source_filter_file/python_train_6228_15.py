N,M,X,Y=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
ans="War"
x.append(X)
y.append(Y)
if max(x)<min(y):
        ans="NO War"
print(ans)
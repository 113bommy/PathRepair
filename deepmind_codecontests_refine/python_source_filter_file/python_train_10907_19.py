X,K,D=map(int,input().split())

X=abs(X)
a=min(K,X//D)
X-=a*D
K-=a
#print(X,K)
if K==1:
    X=abs(X-D)
ans=X
print(ans)

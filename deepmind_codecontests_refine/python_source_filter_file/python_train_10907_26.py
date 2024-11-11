X,K,D=map(int,input().split())
if X<=K*D:
    if (K-X//D)%2==0:X=X%D
    else:X=abs(X%D-D)
else:
    X=X-K*D
print(X)
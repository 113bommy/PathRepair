n,m,k=map(int,input().split())
k+=1
if k<=n:
    print(k,1)
else:
    k-=n+1
    n0=n-k//(m-1)
    if n0%2:
        print(n0,m-k%(m-1))
    else:
        print(n0,1+k%(m-1))
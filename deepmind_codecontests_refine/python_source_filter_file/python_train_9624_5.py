n, m, k=map(int,input().split())
if  n+m-2<k:
    print("-1\n")
else:
    x=min(n-1,k)
    y=max(0,k-x)
    ans=(n//(x+1))*(m//(y+1))
    y=min(m-1,k)
    x=max(0,k-x)
    ans=max(ans,(n//(x+1))*(m//(y+1)))
    print(ans,'\n')
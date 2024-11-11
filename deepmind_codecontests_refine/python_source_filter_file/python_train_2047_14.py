n,m,k=map(int,input().split())
if(k<n):
    print(1,k+1)
else:
    k-=n
    l=k//(m-1)
    md=k%(m-1)
    a=n-l
    if a%2:
        if md==0:
            b=m
        else:
            b=m-md
    else:
        if md==0:
            b=2
        else:
            b=2+md
    print(a,b)
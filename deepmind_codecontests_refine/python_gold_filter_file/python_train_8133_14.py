n,k=map(int,input().split(' '))
if k==n or k==1:
    print(3*n)
else:
    x=min(k-1,n-k)
    print(x*2+n+1+n+n-x-1)
    

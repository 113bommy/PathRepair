n,m,k=map(int, input().split())
if k<(n-1):
    print(1+k,1)
elif k==n:
    print(n,2)
    
else:
    b=k-n
    d=b//(m-1)
    r=b%(m-1)
    row=n-d
    if d%2!=0:
        col=m-r
    else:
        col=2+r
    print(row ,col)
        
    
    
        
    
    
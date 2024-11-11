n,k=map(int,input().split())
if k==1:
    print(n)
else:
    k=0
    while n>0:
        n=n>>1
        k+=1
    print((1<<k)-1)
    

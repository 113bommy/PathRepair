mod=1e9+7
for _ in range(int(input())):
    n,k=map(int,input().split())
    r=0
    p=1
    for i in range(32):
        if(k&(1<<i)):
            r=int((r+p)%mod)
        p=int((p*n)%mod)
    print(r)    
    
        
    
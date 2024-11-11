def findfactors(n,k):
    
    if k==1:
        return n
    if n<=k:
        return 1
    
    mini=n+1
    
    for i in range(1,min(k+1,int(n**0.5)+1)):
        if n%i==0:
            if n//i<=k:
                mini=min(mini,i)
            else:
                mini=min(mini,n//i)
                
    return mini
                
for _ in range(int(input())):
    n,k=map(int,input().split())
    print(findfactors(n,k))
    

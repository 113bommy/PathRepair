def answer(n,k,A):
    if n==1:
        return 1
    dp=[0]*(n+1)
    for i in range(1,n+1):
        if A[i-1]=="a":
            dp[i]=dp[i-1]+1
        else:
            dp[i]=dp[i-1]

    l=0;r=0
    maxi=0
    while r>=l and r<n:
        
        x=dp[r+1]-dp[l]
        if min(x, r+1-x)<=k:
            r+=1
        else:
            maxi=max(maxi,r-l)
            l+=1
            
    maxi=max(maxi,r-l)
        
    
    return maxi
    
                       

n,k=map(int,input().split())
A=input()
print(answer(n,k,A))
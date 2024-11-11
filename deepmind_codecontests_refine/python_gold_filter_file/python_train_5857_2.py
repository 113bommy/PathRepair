for _ in range(int(input())):
    n,k=map(int,input().split())
    if k>=n:
        ans=n*(n-1)//2
        ans+=1 
    else:
        ans=k*(k+1)//2 
    print(ans)    
        
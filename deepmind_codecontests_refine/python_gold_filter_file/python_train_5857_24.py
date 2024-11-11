for _ in range(int(input())):
    n,r=map(int,input().split())
    ans=0
    if(n<=r):
        end=n-1
        ans+=1
    else:
        end=r
    
    ans+=end*(end+1)//2
    
    print(ans)
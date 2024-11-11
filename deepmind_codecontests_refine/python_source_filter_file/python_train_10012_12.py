for t in range(int(input())):
    n=int(input())
    a=list(sorted(map(int,input().split())))
    if n<3:
        print(0)
    else:
        mi=min(a[n-1],a[n-2])
        ans=0
        for i in range(n-2):
            if a[i]<mi and ans+1<mi :
                ans+=1
            else:
                break
        print(ans)
    

    
            
        

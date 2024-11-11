for _ in range(int(input())):
    n,k=[int(c) for c in input().split()]
    if k >= n :
        i=(n-1) 
        ans=(i*(i+1))//2
        ans+=1
    else:
        i=k
        ans=(i*(i+1))//2
    print(ans)
        
        
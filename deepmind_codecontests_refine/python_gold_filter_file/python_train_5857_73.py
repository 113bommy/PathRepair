for _ in range(int(input())):
    n,r=(map(int,input().split()))
    if r<n:
        print((r*(r+1)//2))
    
    else:
        
        r=n-1
        print((r*(r+1)//2)+1)
        
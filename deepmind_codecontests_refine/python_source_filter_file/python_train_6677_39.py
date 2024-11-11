for _ in range(int(input())):
    n,o,t=map(int,input().split())
    if n==1:
        print(o)
    elif o<=t:
        print(o*n)
    else:
        if n%2:
            print(n//2*t+o)
        else:
            print(n//2*t)
        
            
    
    
for _ in range(int(input())):
    x,n = map(int,input().split())
    
    if x%2 == 1:
        if n%2 ==0:
            if n%4 ==0:
                print(x)
            else:
                print(x-1)
            
        else:
            if (n-1)%4 ==0:
                print(x+n)
            else:
                print(x+n-1)
            
    else:
        if n%2 ==0:
            if n%4 ==0:
                print(x)
            else:
                print(x+1)
        else:
            if (n-1)%4 ==0:
                print(x-n)
            else:
                print(x+n+1)
            
            
            
            
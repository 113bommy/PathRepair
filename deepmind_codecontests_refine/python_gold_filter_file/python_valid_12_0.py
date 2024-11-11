for i in range(int(input())):
    n,m,k=map(int,input().split())
    x=(n*m)//2
    
    if n%2==0 and m%2==0:
        if k%2==0:
            print('YES')
        else:
            print('NO')
        
            
           
    
        
    elif n%2!=0:
            
        if  k>=m//2 and (k-m//2)%2==0:
            print('YES')
        else:
            print('NO')
    elif m%2!=0:
        k=(n*m)//2-k
        if k>=n//2 and (k-n//2)%2==0:
            print('YES')
        else:
            print('NO')
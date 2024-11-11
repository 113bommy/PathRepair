b=int(input())
for i in range(b):
    ar=list(map(int,input().split()))
    n=ar[0]
    l=ar[1]
    a=ar[2]
    b=ar[3]
    k=abs(a-b)+l
    if k>n:
        print(n-1)
    else:
        print(k)
            
            
    
    
        
        
        
        

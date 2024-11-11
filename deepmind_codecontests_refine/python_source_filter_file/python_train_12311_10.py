t = int(input())
for i in range(t):
    f=0
    s =0
    a,b,c = map(int, input().split())
    if(a>=c):
        f = -1
        s =  b
        print(f,s,end=" ") 
    
    elif ((a*b)<=c):
        f = b+1 
        s = -1
        print(f,s,end=" ")
        
    else:
        f = 1
        s = b
        print(f,s,end=" ") 
        
       

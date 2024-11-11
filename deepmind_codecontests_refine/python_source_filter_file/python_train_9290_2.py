t=int(input())

for i in range(t):
    a,b=map(int,input().split())
    c,d=map(int,input().split())

    if(a<b):
        temp=a 
        a=b 
        b=temp
    
    if(c<d):
        temp=c 
        c=d 
        d=temp
    
    if((b+d)==a):
        print("Yes")
    else:
        print("No")

        
            
    
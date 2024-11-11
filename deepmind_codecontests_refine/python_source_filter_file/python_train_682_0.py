n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
s=0
c=0
for i in range(1,6):
    x=a.count(i)
    y=b.count(i)
    if abs(x-y)%2!=0 :
        c=1
    else :
        s=s+abs(x-y)//2
if c==1 :
    print(-1)
else :
    print(s)
    
        
    
                    
                
                
            

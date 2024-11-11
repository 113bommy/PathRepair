# 1399B

def method():
    
    n=int(input())
    a1=list(map(int, input().split()))
    a2=list(map(int, input().split()))
    
    min1=min(a1)
    min2=min(a2)
    moves=0
    
    for i in range(n):
        x=a1[i]-min1
        y=a2[i]-min2
        if x<y:
            x,y=y,x
        
        if x>0 and y>0:
            x-=y
            moves=moves+x
        if x>0:
            moves=moves+x
        
    print(moves)
            
m=int(input())
while(m):
    method()
    m-=1
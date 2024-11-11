# cook your dish here
def color(x1,y1,x2,y2):
    dx = max((x2-x1+1), 0)
    dy = max((y2-y1+1), 0)
    b=w=dx*dy//2
    if dx%2 and dy%2:
        if (x1+y1)%2==0:
            w+=1
        else:
            b+=1
    return w,b
        
    
    
for _ in range(int(input())):
    n,m=map(int,input().split())
    x1,y1,x2,y2=map(int,input().split())
    x3,y3,x4,y4=map(int,input().split())
    w,b=color(1,1,n,m)
    w1,b1=color(x1,y1,x2,y2)
    w2,b2=color(x3,y3,x4,y4)
    w3,b3=color(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4))
    W=w+b1-w2-b3
    print(W,n*m-W)
    
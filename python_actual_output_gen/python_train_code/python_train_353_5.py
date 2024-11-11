i=1
yes=0
y=0
a,b=map(int,input().split())
c,d=map(int,input().split())
#both Equations are in a form of straight line.
#the case is if we draw one line segment prependicular on y then
#definetly, the two points will pass through that line and Morty and Rick must be equal.
#i*a+b=j*c+d,
if(b==d):
    print(d)
else:
    for j in range(100):
        i=(j*c+d-b)/a
        if (i-int(i)==0 and i>=0):
            yes=i
        if(yes!=0):
            break
    if (yes==0):
        print(-1)
    else:
        y=yes*a+b
        print(int(y))        
    
    




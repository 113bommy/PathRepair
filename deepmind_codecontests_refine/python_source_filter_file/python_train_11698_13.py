n=int(input())
a,b=0,0
sa,sb=0,0
for i in range(n):
    t,x,y=map(int,input().split())
    if t==1:
        a+=x
        sa+=10
    else:
        b+=x
        sb+=10
if a>=sa//2:
    print("LIVE")
else:
    print("DEAD")
if b>=sa//2:
    print("LIVE")
else:
    print("DEAD")        
x,y,m=map(int,input().split())
i=0
if x>=m or y>=m:
    print(i)
elif max(x,y)<=0:
    print(-1)
else:
    if x>y:
        x,y=y,x
    if x<0:
        i=(y-x)//y
        x+=i*y
    while y<m:
        x,y=y,x+y
        i+=1
    print(i)
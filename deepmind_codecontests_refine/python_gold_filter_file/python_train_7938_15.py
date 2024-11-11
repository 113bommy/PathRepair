n,m,x,y = map(int,input().split())
a,b=x,y
while y<m+1:
    while x>0:
        print(x,y)
        x-=1
    y+=1
    x=1
    while y<=m and x<=a:
        print(x,y)
        x+=1
    y+=1
    x=a
x,y=a+1,m
while y>0:
    while x<=n:
        print(x,y)
        x+=1
    y-=1
    x=n
    while y>0 and x>a:
        print(x,y)
        x-=1
    y-=1
    x=a+1
x,y=a,1
while y<b:
    while x>0:
        print(x,y)
        x-=1
    y+=1
    x=1
    while y<b and x<=a:
        print(x,y)
        x+=1
    y+=1
    x=a





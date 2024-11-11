from math import floor,ceil
a,x,y = map(int,input().split())
if y<a and y>0:
    if x>-a/2 and x<a/2:
        print(1)
    else:
        print("-1")
    
y-=a
f = floor(y/a)
c = ceil(y/a)

if y>f*a and y<c*a:
    if f%2==0:
        if x>-a/2 and x<a/2:
            print((f//2)*2+(f-f//2)+2)
        else:
            print("-1")
    else:
        if x>-a and x<0:
            print((f//2)*2+(f-f//2)+2)
        elif x<a and x>0:
            print((f//2)*2+(f-f//2)+3)
        else:
            print("-1")
else:
    # print(-a/2)
    print("-1")
# print(c,f)
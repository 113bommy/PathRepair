n=int(input())
a=list(map(int,input().split()))
x=y=0
f=True
for i in range(0,n):
    t=a[i]-25
    if t==25:
        if x==0:
            f=False
            break
        x-=1
        y+=1
    elif t==75:
        if y>0 and x>0:
            y-=1
            x-=1
        elif x>3:
            x-=3
        else:
            f=False
            break
    else:
        x+=1
if f:
    print("YES")
else:
    print("NO")
    
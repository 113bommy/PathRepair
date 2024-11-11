n,p,w,d=list(map(int,input().split()))
flag=0
x=-1
y=-1
z=-1
for i in range(w+1):
    if (p-(i*w))%d==0:
        x=i
        y=(p-(i*w))//d
        z=n-(x+y)
        flag=1
        break
if x<0 or y<0 or flag==0 or z<0:
    print(-1)
else:
    print(*[x,y,z])
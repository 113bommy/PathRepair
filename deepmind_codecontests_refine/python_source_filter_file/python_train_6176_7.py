n, m = [int(y) for y in input().split()]
xc, yc = [int(y) for y in input().split()]
k=int(input())
cnt=0
for _ in range(k):
    dx, dy = [int(y) for y in input().split()]
    if dx==0:temp1=10e9
    elif dx<0:
        temp1 = -(xc-1)//dx
        if xc+(temp1*dx)<=0:temp1-=1
    else:
        temp1 = (n-xc)//dx
        if xc+(temp1*dx)>n:temp1-=1
    if dy==0:temp2=10e9
    elif dy<0:
        temp2 = -(yc-1)//dy
        if yc+(temp2*dy)<=0:temp2-=1
    else:
        temp2 = (n-yc)//dy
        if yc+(temp2*dy)>n:temp2-=1
    temp = min(temp1, temp2)
    cnt+=temp
    xc += temp*dx
    yc += temp*dy
print(cnt)
t = int(input())
for k in range(t):
    s = 0
    x1,y1,z1 = map(int, input().split())
    x2,y2,z2 = map(int, input().split())
    if z1<y2:
        s += z1*2
        z1=0
        y2-=z1
    else:
        s+= y2*2
        y2=0
        z1-=y2
    if y1 > y2+x2:
        y1= y1 -x2-y2
    else:
        y1=0
    if z2 > z1+x1:
        z2= z2 -z1-x1
    else:
        z2=0
    s+= min(y1,z2)*(-2)  
    print(s)
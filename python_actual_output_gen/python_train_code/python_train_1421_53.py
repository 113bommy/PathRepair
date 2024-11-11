def point(p,t):
    return max((3*p,-(p/250)*t))
l=list(map(int,input().split()))
M=point(l[0],l[1])
V=point(l[1],l[3])
if  V==M:
    print('Tie')
elif V>M:
    print('Vasya')
else:
    print('Misha')
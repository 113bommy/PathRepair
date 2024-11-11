n,sx,sy = map(int,input().split())
q = [[[],[]],[[],[]],[[],[]],[[],[]]]
l = [[[],[]],[[],[]],[[],[]],[[],[]]]
for i in range(n):
    a,b = map(int ,input().split())
    if a < sx and b > sy:
        q[0][0].append(a)
        q[0][1].append(b)
    if a > sx and b > sy:
        q[1][0].append(a)
        q[1][1].append(b)
    if a < sx and b < sy:
        q[3][0].append(a)
        q[3][1].append(b)
    if a > sx and b < sy:
        q[2][0].append(a)
        q[2][1].append(b)
        
    if a == sx:
        if b > sy:
            l[0][0].append(a)
            l[0][1].append(b)
        else:
            l[2][0].append(a)
            l[2][0].append(b)
    if b == sy:
        if a > sx:
            l[1][0].append(a)
            l[1][1].append(b)
        else:
            l[3][0].append(a)
            l[3][1].append(b)
            
len_ = [(len(q[i][0])+len(l[i][0])+len(q[(i+1)%4][0])) for i in range(4)]
print(max(len_))
idx = len_.index(max(len_))
if idx == 0:
    print(sx,sy+1)
elif idx == 1:
    print(sx+1,sy)
elif idx == 2:
    print(sx,sy-1)
elif idx == 3:
    print(sx-1,sy)
        
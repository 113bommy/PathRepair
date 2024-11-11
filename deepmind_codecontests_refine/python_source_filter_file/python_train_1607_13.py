x1,x2,x3=[int(i) for i in input().split()]
y1,y2,y3=[int(i) for i in input().split()]
t=0
if x1==y1:
    t+=1
if x2==y2:
    t+=1
if x3==y3:
    t+=1
if t>=2:
    print('YES')
else:
    print('NO')

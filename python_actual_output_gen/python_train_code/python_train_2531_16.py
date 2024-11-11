n=int(input())
x,y=[],[]
z=0
for i in range(n):
    m=int(input())
    if m<0:
        z=1
        x.append(m)
    else:
        z=-1
        y.append(m)
if sum(x) != sum(y):
    print('first' if sum(x) > sum(y) else 'second')
elif x!=y:
    print('first' if x>y else 'second')
else:
    print('first' if z>0 else 'second')
        
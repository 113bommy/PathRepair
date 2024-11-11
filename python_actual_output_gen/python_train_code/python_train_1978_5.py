n=int(input())
a=[]
for i in range(n):
    x,y=map(int,input().split())
    a.append((x,y))
f=True
a.sort()
t1,t2=0,0
for i in range(n):
    x,y=a[i]
    if x>t1:
        t1=y
    elif x>t2:
        t2=y
    else:
        f=False
if f:
    print('YES')
else:
    print('NO')
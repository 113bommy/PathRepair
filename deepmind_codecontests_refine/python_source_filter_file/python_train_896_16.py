n,m=[int(i) for i in input().split()]
a=[]
for i in range(n):
    a.append([int(i) for i in input().split()])
p=0
t=True
for i in a:
    if p>=i[0]:
        p=max(i[1],p)
    else:
        t=False
if t==True:
    print('YES')
else:
    print('NO')

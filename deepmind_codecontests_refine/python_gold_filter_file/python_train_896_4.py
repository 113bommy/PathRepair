'''
CF Visiting a Friend
'''
s=input()
a=s.split()
n=int(a[0])
m=int(a[1])
w=[]
for h in range(m):
    w.append(h)
a=[]
for i in range(n):
    x=input()
    b=x.split()
    b[0]=int(b[0])
    b[1]=int(b[1])
    a.append(b)
result=[]
for i in a:
    for j in range(i[0],i[1]):
        if j not in result:
            result.append(j)
if result==w:
    print('YES')
else:
    print('NO')

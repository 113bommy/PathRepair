q=input().split()
n=int(q[0])
t=int(q[1])
a=input().split()
x=0
while x<len(a):
    a[x]=int(a[x])
    x=x+1

x=0
y=1
z=[1]
b=0
while x<len(a):
    b=a[x]+y
    z.append(b)
    x=b-1
    y=x+1

if t in z:
    print('YES')
else:
    print('NO')

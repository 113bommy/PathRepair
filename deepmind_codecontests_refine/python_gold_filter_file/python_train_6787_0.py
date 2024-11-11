ch=input()
L=[int(i)for i in ch.split()]
a=L[0]
b=L[1]
if a>b:
    a,b=b,a
d={1:1,2:0}
for i in range(1,b):
    x=d[1]
    y=d[2]
    d[2]=x+y
    d[1]=y
nb=d[1]+2*d[2]
d={1:1,2:0}
for i in range(1,a):
    x=d[1]
    y=d[2]
    d[2]=x+y
    d[1]=y
nb2=d[1]+2*d[2]


print(2*(nb+nb2-1)%((10**9)+7))
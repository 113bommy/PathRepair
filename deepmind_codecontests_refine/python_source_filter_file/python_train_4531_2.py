def layer(n):
    a = (-3 + (9+12*n)**0.5)//6
    a = int(a)
    a+=1
    while 3*a*(a+1) >= n:
        a-=1
    return a+1

n = int(input())
if n == 0:
    print(0, 0)
    quit()

l = layer(n)
base = 3*(l-1)*l+1
# base = (2*l-1, 2)

a = [2*l, 0]
b = [l, 2*l]
bx = base + (l-1)
c = [-l, 2*l]
cx = bx + l
d = [-2*l, 0]
dx = cx + l
e = [-l, -2*l]
ex = dx + l
f = [l, -2*l]
fx = ex + l
ax = fx + l
daa = abs(n-base-1)
da = abs(n-ax)
db = abs(n-bx)
dc = abs(n-cx)
dd = abs(n-dx)
de = abs(n-ex)
df = abs(n-fx)

if (n <= bx):
    print(int((db*a[0]+daa*b[0])/(db+daa)), int((db*a[1]+daa*b[1])/(db+daa)))
    quit()
    
if (bx <= n <= cx):
    print(int((dc*b[0]+db*c[0])/(db+dc)), b[1])
    quit()
    
if (cx <= n <= dx):
    print(int((dd*c[0]+dc*d[0])/(dc+dd)), int((dd*c[1]+dc*d[1])/(dc+dd)))
    quit()
    
if (dx <= n <= ex):
    print(int((de*d[0]+dd*e[0])/(dd+de)), int((de*d[1]+dd*e[1])/(dd+de)))
    quit()
    
if (ex <= n <= fx):
    print(int((df*e[0]+de*f[0])/(de+df)), e[1])
    quit()
    
if (fx <= n <= ax):
    print(int((da*f[0]+df*a[0])/(df+da)), int((da*f[1]+df*a[1])/(df+da)))
    quit()
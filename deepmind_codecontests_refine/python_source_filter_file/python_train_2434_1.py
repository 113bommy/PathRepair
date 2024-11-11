#SANDAAR APPROACH

t,q = map(int,input().split())
a = [int(x) for x in input().split()]
b = [0]*(t+1)
c = [0]*(t)
for _ in range(q):
    l,r =  map(int,input().split())
    b[l-1]+=1
    b[r]-=1
x=0
for i in range(t):
    x+=b[i]
    c[i]=x
print(c)
c.sort()
a.sort()
x=0
for i in range(t):
    x+=a[i]*c[i]
print(x)
a=input().split()
x=input().split()
b=int(a[0])
c=int(a[1])
d=0
f=[]
y=[]
while d<b:
    i=True
    e=len(f)
    g=0
    while g<e:
        if x[d]==y[g]:
            i=False
            break
        g=g+1
    if i==True:
        y=y+[x[d]]
        f=f+[d+1]
    d=d+1
a=len(f)
b=0
t=""
if a!=c:
    print("NO")
else:
    print("YES")
    while b<a:
        t=t+str(f[b])+" "
        b=b+1
    print(t)

n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[]
for x in a:
    mmax=-10**10
    for y in b:
        z=x*y
        if mmax<z: mmax=z
    c.append(mmax)
print(sorted(c)[-2])

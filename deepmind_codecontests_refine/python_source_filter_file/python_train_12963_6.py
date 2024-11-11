a=int(input())
ma=[]
md=[]
fa=[]
fd=[]
for i in range(a):
    y=input().split()
    if y[0]=='M':
        ma.append(int(y[1]))
        md.append(int(y[2])+1)
    else:
        fa.append(int(y[1]))
        fd.append(int(y[2])+1)
ma.sort()
md.sort()
fa.sort()
fd.sort()
m=0
f=0
mx=0
mpa=0
fpa=0
mda=0
fda=0
for i in range(1,141):
    while mpa<len(ma) and ma[mpa]==i:
        mpa+=1
        m+=1
    while mda<len(md) and md[mda]==i:
        mda+=1
        m-=1
    while fpa<len(fa) and fa[fpa]==i:
        fpa+=1
        f+=1
    while fda<len(fd) and fd[fda]==i:
        fda+=1
        f-=1
    mx=max(mx, min(f,m)*2)
print(mx)

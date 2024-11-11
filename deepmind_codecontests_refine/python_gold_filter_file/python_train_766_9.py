n=int(input())
a=[int(j) for j in input().split()]
nv=[]
pv=[]
z=[]
for k in a:
    if k>0:
        pv.append(k)
    elif k<0:
        nv.append(k)
    else:
        z.append(k)
if len(nv)%2==0:
    h=nv[0]
    nv=nv[1:]
    z.append(h)
if len(pv)==0:
    pv.append(nv[0])
    pv.append(nv[1])
    nv=nv[2:]
print(len(nv),*nv)
print(len(pv),*pv)
print(len(z),*z)
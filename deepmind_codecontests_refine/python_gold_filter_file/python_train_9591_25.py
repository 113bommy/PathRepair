a=[int(q) for q in input().strip().split()]
b=[int(q) for q in input().strip().split()]
c,d=0,0
for k in range(a[0]):
    if b[k]==1:
        c+=1
    else:
        d+=1
e=0
for k in range(0,a[1]):
    f=[]
    for h in range(len(b)):
        f.append(b[h])
    m=k
    c,d=0,0
    while m<a[0]:
        f[m]=0
        m+=a[1]
    for r in range(a[0]):
        if f[r]==1:
            c+=1
        elif f[r]==-1:
            d+=1
    e=max(e,abs(c-d))
print(e)
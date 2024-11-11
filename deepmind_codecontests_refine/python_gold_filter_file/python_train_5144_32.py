n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
c=0
b=[]
if a[0]>=0:
    print(0)
else:
    for i in range(m):
        c+=a[i]
        b.append(c)
    print(min(b)*(-1))

(n,m,k),*A,=[list(map(int,i.split())) for i in open(0)]
a=A[0]
b=A[1]

aa=[0]
bb=[0]
for i in range(n):
    aa.append(aa[-1]+a[i])
for i in range(m):
    bb.append(bb[-1]+b[i])

ans=0

for i in range(1,n+1):
    if aa[i]>k:
        break
    while bb[m]>k-aa[i]:
        m-=1
    ans=max(ans,m+i)
        
print(ans)
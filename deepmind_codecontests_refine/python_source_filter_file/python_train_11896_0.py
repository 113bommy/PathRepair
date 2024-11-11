def gns():
    return list(map(int,input().split()))

n,d,m=gns()
d+=1
ns=gns()
a=[x for x in ns if x<=m]
b=[x for x in ns if x>m]
a.sort(reverse=True)
b.sort(reverse=True)

def sm(x):
    for i in range(1,len(x)):
        x[i]+=x[i-1]
sm(a)
sm(b)

ans=0
for i in range(len(a)):
    j=n-i
    j=j//d+(j%d!=0)
    if j>len(b):
        continue

    s=(a[i-1] if i>0 else 0)+(b[j-1] if j>0 else 0)
    ans=max(ans,s)
print(ans)
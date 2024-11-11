n,k=map(int,input().split())
l1=list(map(int,input().split()))
e=l1.count(1)
s=l1.count(-1)
maxs=abs(e-s)
for i in range(0,k):
    e1=e
    s1=s
    for j in range(i,n,k):
        if l1[j]==1:
            e1-=1
        else :
            s1-=1
    maxs=max(abs(e1-s1),maxs)
print(maxs)

n,k=map(int,input().split())
t=list(map(int,input().split()))
c=list(map(int,input().split()))
d=[t[i]-c[i] for i in range(len(t))]
s=0
for i in t:
    s+=i
d.sort()
for i in range(k,len(d)):
    if d[i]<1:
        s-=d[i]
print(s)
n,k=map(int,input().split())
t=list(map(int,input().split()))
c=list(map(int,input().split()))
d=[t[i]-c[i] for i in range(len(t))]
s=0
for i in t:
    s+=i
d.sort()
for i in range(k,len(d)):
    if 0<d[i]:
        s-=d[i]
print(s)
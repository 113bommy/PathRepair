
n,k=map(int,input().split())
x=[int(n) for n in input().split()]
a=[]
m={}
ans=10000000000
for i in x:
    c=0
    t=i
    while t:
        if t not in m:
            m[t]=[]
        m[t].append(c)
        t//=2
        c+=1 
for i in m:
    if len(m[i])>=k:
        a=sorted(m[i])
        ans=min(ans,sum(a[:k]))
print(ans)
    

    
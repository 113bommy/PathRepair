n=int(input())
a=[]
for i in range(n):
    x,y=map(int,input().split())
    a.append([x,y])
c,d=0,0
p,q,r={},{},{}
for i in range(n):
    c=a[i][0]
    d=a[i][1]
    if c in p:
        p[c]+=1
    else:
        p[c]=1
    if d in q:
        q[d]+=1
    else:
        q[d]=1
    if (c,d) in r:
        r[(c,d)]+=1
    else:
        r[(c,d)]=1
count=0
for i in p.values():
    count+=(i*(i-1))//2
for i in q.values():
    count+=(i*(i-1))//2
for i in r.values():
    count+=(i*(i-1))//2
print(count)
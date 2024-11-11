n,k=map(int,input().split())
d={}
r=[]
for _ in " "*n:
    x,y=map(int,input().split())
    d.setdefault(x,[]).append(y)
for i in sorted(d)[::-1]:
    for x in sorted(set(d[i])):
        r.append(d[i].count(x))
t=0
for i in r:
    t+=i
    if t>=k:
        print(i)
        exit(0)
n,m=map(int,input().split())
p=[]
for _ in range(m):
    l=list(map(int,input().split()))
    a=max(l)
    p.append(l.index(a))
print(max(set(p), key = p.count)+1)
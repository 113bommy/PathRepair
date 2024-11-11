n,m = map(int,input().split())




f=[]





for k in range(m):
    f.append(list(map(int,input().split())))

p=[]

for j in f:
    p.append(j.index(max(j))+1)


g=list(set(p))

y=[]
for i in g:
    y.append(p.count(i))

print(g[y.index(max(y))])

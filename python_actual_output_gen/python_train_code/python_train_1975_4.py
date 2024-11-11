n,m=map(int,input().split());z=[]
for i in range(m):
    x=[int(x) for x in input().split()]
    z.append(1+x.index(max(x)))
p=list(set(z))
k=0
for i in p:
    if x.count(i)>k:
        k=x.count(i)
        p=i
print(p)

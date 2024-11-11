n,m=map(int,input().split());z=[]
for i in range(m):
    x=[int(x) for x in input().split()]
    z.append(1+x.index(max(x)))
p=list(set(z))
k=0
for i in p:
    if z.count(i)>k:
        k=z.count(i)
        s=i
print(s)

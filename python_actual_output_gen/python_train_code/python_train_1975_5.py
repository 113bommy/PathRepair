n,m=[int(i)for i in input().split()]
a=[]
for i in range(m):
    a.append([int(j)for j in input().split()])
print(a)
b=[]
for i in range(m):
    b.append(a[i].index(max(a[i])))
print(b)
c=[0 for i in range(n)]
for j in range(n):
    for i in range(m):
        if b[i]==j:
            c[j]+=1
print(c)
print(c.index(max(c))+1)
            
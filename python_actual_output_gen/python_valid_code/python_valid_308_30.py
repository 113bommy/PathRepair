n, m=[int(i) for i in input().split()]
a=[]
kol=0
b=[]
for j in range(n):
    x, y = [int(i) for i in input().split()]
    a.append([x, y])

for i in range(1, m):
    c=0
    for j in range(n):
        if i<a[j][0] or a[j][1]<i:
            c+=1
    if c==n:
        kol+=1
        b.append(i)
print(kol)
for i in b:
    print(i, end=' ')
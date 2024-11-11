q, s = map(int, input().split())
c = []
for i in range(s):
    c.append([int(x) for x in input().split()])
    c[i].append(i+1)
a = [0]*q
c.sort(key=lambda x: x[1])
for i in c:
    a[i[1]-1]=s+1
    x = i[2]
    for j in range(i[0]-1, i[1]):
        if x==0: break
        if a[j]==0:
            a[j]=i[3]
            x-=1
    if x>0:
        print(-1)
        exit()
print(*a)
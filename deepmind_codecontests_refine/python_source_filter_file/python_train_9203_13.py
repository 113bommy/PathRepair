n = int(input())
a = [list(map(int, input().split())) for i in range(4)]
b = []
c = []
d = []
for i in range(4):
    b.append(min(a[i][:2]))
    b.append(min(a[i][2:]))
    b.insert(0, sum(b))
    d.append(b[0])
    c.append(b)
    b = []
k = d.index(min(d))
if c[k][0] <= n: print(k+1,c[k][1],c[k][2])
else: print(-1)
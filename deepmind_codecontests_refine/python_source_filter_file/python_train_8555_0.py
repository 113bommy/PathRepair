n, m = input().split()
n, m = int(n), int(m)
edges = [[] for x in range(n)]
for i in range(m):
    a, b = input().split()
    a, b = int(a), int(b)
    ma = max(a, b)
    mi = min(a, b)
    edges[mi-1].append((ma-1))
    edges[ma-1].append((mi-1))
print(edges)
# find lowest degree:

xxx=[]
if n<=6:
    print(m)
else:
    for i in range(n):
        for j in range(i):
            xxx.append(set(edges[i]).intersection(set(edges[j])))
# print(xxx)
    p = [len(z) for z in xxx]
    print(m-min(p))
n = int(input())
ar = list(map(int, input().split()))

d = dict()
for x in range(n):
    q = d.get(ar[x])
    if q:
        q[1] = x
    else:
        d[ar[x]] = [x, x]

q = [d[x] for x in d]
q.sort(key = lambda x: (x[0], x[1]))

s = set(range(len(q)))
for x in range(1, len(q)):
    if q[x][0] >= q[x-1][0] and q[x][0] <= q[x-1][1]:
        q[x][0] = q[x-1][0]
        q[x][1] = max(q[x][1], q[x-1][1])
        s.remove(x-1)

#f = [q[x] for x in s]
f = []
for x in s:
    if q[x][0] != q[x][1]:
        f.append(q[x])

res = len(ar)
for x in f:
    res -= (x[1] - x[0])
print(res)
print(q)
q = 1
for x in range(res - 1):
    q = (q * 2) % 998244353
print(q)

#print(q)
        



#q = [[ar[x], x] for x in range(n)]
#q.sort(key = lambda y: (y[0], y[1]))
#print(' '.join(map(str, q)))

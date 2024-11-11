n,q = map(int,input().split())
r = [[] for i in range(n)]
v = [0 for i in range(n)]

for i in range(n-1):
    a,b = map(int,input().split())
    r[a-1].append(b-1)

for i in range(q):
    p,x = map(int,input().split())
    v[p-1] += x


for i in range(1,n):

    for y in r[i]:
        v[y] += v[i]

print(" ".join(map(str,v)))
n, q = map(int,input().split())
tree = [[] for i in range(n)]
v = [0]*n
for i in range(n-1):
    a1,b1 = [int(i) for i in input().split()]
    tree[a1-1].append(b1)
for i in range(q):
    p1,x1 = [int(i) for i in input().split()]
    v[p1 - 1] += x1
for i in range(n):
    for j in range(len(tree[i])):
        v[tree[i][j]-1] += v[i]
for i in range(n):
    print(str(v[i]) +" ",end="")

NIL = -1

class Node:
    parent = NIL
    left = NIL
    right = NIL

n = int(input())
t = [Node() for i in range(n)]

for i in range(n):
    tmp = list(map(int, input().split()))
    id = tmp.pop(0)
    k = tmp.pop(0)
    c = tmp
    if k != 0:
        for j in c:
            t[j].parent = id
        t[id].left = c[0]
        for j in range(len(c)-1):
            t[c[j]].right = c[j+1]

def getdepth(u):
    d = 0
    while t[u].parent != NIL:
        u = t[u].parent
        d += 1
    return d

def getchildren(u):
    c = t[u].left
    result = []
    while c != NIL:
        result.append(c)
        c = t[c].right
    return result

for i in range(n):
    d = getdepth(i)
    c = getchildren(i)
    if d == 0:
        v = "root"
    elif c == []:
        v = "leaf"
    else:
        v = "internal node"
print('node {}: parent = {}, depth = {}, {}, [{}]'.format(i, t[i].parent, d, v, ', '.join(map(str, c))))

def set_info(a, i, p, d):
    a[i][1], a[i][2] = p, d
    for b in a[i][0]:
        set_info(a, b, i, d + 1)

n = int(input())
tree = [[None] for i in range(n)]
root = set(range(n))

for i in range(n):
    l = list(map(int, input().split()))
    tree[l[0]] = [l[2:], None, None]
    root -= set(l[2:])

set_info(tree, root.pop(), -1, 0)

for i in range(n):
    c, p, d = tree[i]
    if p == -1:
        t = "root"
    elif len(c) == 0:
        t = "leaf"
    else:
        t = "internal node"
    print("node ", i, ": parent = ", p, " depth = ", d, ", ", t, ", ", c, sep="")
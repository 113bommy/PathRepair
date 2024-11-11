class Tree():

    def __init__(self):
        self.parent = -1
        self.depth = 0
        self.child = []

n = int(input())
tree = [Tree() for i in range(n)]
for i in range(n):
    cmd = list(map(int, input().split()))
    node = tree[cmd[0]]
    node.child.extend(cmd[2:])
    for j in cmd[2:]:
        tree[j].parent = cmd[0]

for t in tree:
    d, p = 0, t.parent
    while p != -1:
        d += 1
        p = tree[p].parent
    t.depth = d

for i in range(n):
    t = tree[i]
    if t.parent == -1:
        state = "root"
    elif t.child:
        state = "internal node"
    else:
        state = "leaf"
print("node {}: parent = {}".format(i, t.parent), "depth = {}".format(
    t.depth), state, "[{}]".format(", ".join(map(str, t.child))), sep=", ")
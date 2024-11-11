from collections import defaultdict

def dfs(here, p, d, conn, parent, depth, height):
    parent[here] = p
    depth[here] = d
    l_d, r_d = 0, 0
    for c in conn[here]:
        if c[0] >= 0:
            l_d = dfs(c[0], here, d + 1, conn, parent, depth, height)
        if c[1] >= 0:
            r_d = dfs(c[1], here, d + 1, conn, parent, depth, height)
    if len(conn[here]):
        height[here] = max(max(l_d, r_d) - d, 0)
    return max(l_d, r_d, d)

v_num = int(input())
conn = defaultdict(list)
in_v = [0 for n in range(v_num + 1)]
degree = [0 for n in range(v_num)]
for _ in range(v_num):
    v, left, right = (int(n) for n in input().split(" "))
    conn[v].append([left, right])
    in_v[left] += 1
    in_v[right] += 1
    degree[v] += int(left >= 0) + int(right >= 0)
for i, n in enumerate(in_v):
    if not n:
        root = i
        break
parent = [-1 for n in range(v_num)]
depth = [0 for n in range(v_num)]
height = [0 for n in range(v_num)]
dfs(root, -1, 0, conn, parent, depth, height)
sibling = [-1 for n in range(v_num)]
for i in range(v_num):
    for j in range(v_num):
        if i == j:
            continue
        elif parent[i] == parent[j]:
            sibling[i] = j
            break
v_type = ["" for n in range(v_num)]
for i in range(v_num):
    if i == root:
        v_type[i] = "root"
    elif len(conn[i]) != 0:
        v_type[i] = "internal node"
    else:
        v_type[i] = "leaf"
for i in range(v_num):
    print("node {0}: parent = {1}, sibling = {2}, degree = {3}, depth = {4}, height = {5}, {6}".format(i, parent[i], sibling[i], degree[i], depth[i], height[i], v_type[i]))
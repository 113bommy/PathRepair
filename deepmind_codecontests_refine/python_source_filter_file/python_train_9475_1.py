idx_com = 0
idx_x = 1
idx_y = 2
idx_z = 3

n, nq = map(int, input().split())
parents = list(range(n))
ranks = [0] * n
weights = [0] * n

def find(x):
    if parents[x] == x:
        return x
    y = find(parents[x])
    weights[x] += weights[parents[y]]
    parents[x] = y
    return y

def unite(x, y, w):
    root_x = find(x)
    root_y = find(y)

    if ranks[root_x] < ranks[root_y]:
        parents[root_x] = root_y
        weights[root_x] = -w - weights[x] + weights[y]
    else:
        parents[root_y] = root_x
        weights[root_y] = w - weights[y] + weights[x]
        if ranks[root_x] == ranks[root_y]:
            ranks[root_x] += 1

def same(x, y):
    return find(x) == find(y)

def diff(x, y):
    return weights[y] - weights[x]

for _ in range(nq):
    q = list(map(int, input().split()))
    if q[idx_com] == 0:
        unite(q[idx_x], q[idx_y], q[idx_z])
    else:
        if same(q[idx_x], q[idx_y]):
            print(diff(q[idx_x], q[idx_y]))
        else:
            print("?")


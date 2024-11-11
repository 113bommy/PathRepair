import os
from io import BytesIO
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

def input_as_list():
    return list(map(int, input().split()))

def array_of(f, *dim):
    return [array_of(f, *dim[1:]) for _ in range(dim[0])] if dim else f()

def main():
    n, m = input_as_list()
    G = array_of(list, n)
    E = []

    for _ in range(m):
        u, v = input_as_list()
        u, v = u-1, v-1
        G[u].append(v)
        G[v].append(u)
        E.append((u, v))

    depth = array_of(int, n)
    visited = array_of(bool, n)

    visited[0] = True
    stack = [0]

    while stack:
        u = stack.pop()
        for v in G[u]:
            if visited[v]:
                if depth[u]%2 == depth[v]%2:
                    print('NO')
                    return
            else:
                depth[v] = depth[u] + 1
                visited[v] = True
                stack.append(v)

    out = []
    for u, v in E:
        out.append(str(depth[u]%2))
    print('YES')
    print(''.join(out))

main()
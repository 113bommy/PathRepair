import sys

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

def paint_col(adj, cols, i, col):
    nxt = [i]

    while nxt:
        u = nxt[-1]
        try:
            v = next(adj[u])
            if cols[v] == 0:
                cols[v] = col
                nxt.append(v)
        except StopIteration:
            nxt.pop()
            cols[u] = col

def solve():
    n, m = map(int, sys.stdin.readline().split())
    adj = [[] for i in range(n)]

    for i in range(m):
        s, t = map(int, sys.stdin.readline().split())
        adj[s].append(t)
        adj[t].append(s)

    cols = [0] * n
    col = 1
    adj = list(map(iter, adj))

    for i in range(n):
        if cols[i] == 0:
            paint_col(adj, cols, i, col)
            col += 1

    debug(cols, locals())

    q = int(sys.stdin.readline())

    for i in range(q):
        s, t = map(int, sys.stdin.readline().split())

        if cols[s] == cols[t]:
            ans = 'yes'
        else:
            ans = 'no'

        print(ans)

if __name__ == '__main__':
    solve()
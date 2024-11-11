def read_tokens():
    return input().strip().split(' ')


def read_ints():
    return [int(s) for s in read_tokens()]


n, m, k = read_ints()
graph = [[] for _ in range(n)] # [ [], [], ... []]
bank = [False] * n


def add_edge(u, v, l):
    global graph
    graph[u].append((v, l))
    graph[v].append((u, l))


for i in range(m):
    u, v, l = read_ints()
    u = u - 1
    v = v - 1
    add_edge(u, v, l)

if k != 0:
    bank_positions = read_ints()
    for idx in bank_positions:
        idx = idx - 1
        bank[idx] = True


def solve():
    ans = 1e9
    for i in range(n):
        if not bank[i]:
            continue
        for (u, l) in graph[i]:
            if not bank[u]:
                ans = min(ans, l)
    return -1 if ans == 1e9 else ans


print(solve())
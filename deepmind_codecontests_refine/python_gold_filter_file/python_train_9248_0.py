def get_survivors(n, pairs):
    survivors = {v: {v} for v in range(n)}
    for x, y in reversed(pairs):
        for v, srv in survivors.copy().items():
            if x in srv:
                if y in srv:
                    del survivors[v]
                else:
                    srv.add(y)
            elif y in srv:
                srv.add(x)
    return survivors


def solve(n, pairs):
    survivors = get_survivors(n, pairs)
    ans = 0
    for u, su in survivors.items():
        for v, sv in survivors.items():
            if u >= v:
                continue
            if su.isdisjoint(sv):
                ans += 1
    return ans


n, m = map(int, input().split())
pairs = []
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    pairs.append((x, y))
print(solve(n, pairs))

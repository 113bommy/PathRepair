n, m = map(int, input().split())
ls = [list(map(int, input().split())) for _ in range(m)]

parents = list(range(n + 1))
ranks = [0 for _ in range(n + 1)]


def find(x):
    if parents[x] == x:
        return x
    parents[x] = find(parents[x])
    return parents[x]


def unite(x, y):
    xx = find(x)
    yy = find(y)
    if xx == yy:
        return
    if ranks[x] < ranks[y]:
        parents[x] = y
    else:
        parents[y] = x
        if ranks[x] == ranks[y]:
            ranks[x] += 1


res = [n * (n - 1) // 2]
nums = [1 for _ in range(n + 1)]
for a, b in reversed(ls):
    aa = find(a)
    bb = find(b)
    if aa == bb:
        res.append(res[-1])
    else:
        res.append(res[-1] - nums[aa] * nums[bb])
        nums[aa] = nums[bb] = nums[aa] + nums[bb]
        unite(a, b)
print(*reversed(res[:-1]), sep='\n')
n, m = map(int, input().split())
ls = list(map(int, input().split()))

def solve():
    if sum(ls) < n:
        return '-1'
    target = 0
    position = 0
    for x in ls:
        target = max(target, position+x)
        position += 1
        if target > n:
            return '-1'
    sol = []
    expand = n - target
    position = 1
    for x in ls:
        sol.append(position)
        diff = x - 1
        position += 1
        if diff > 0 and expand > 0:
            position += min(diff, expand)
            expand -= min(diff, expand)
    return ' '.join(map(str, sol))

print(solve())
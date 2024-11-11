def maxsum(a):
    best = 0
    cur = 0
    for e in a:
        cur = max(cur, 0) + e
        best = max(best, cur)
    return best


def solve(m, k, a):
    if m == 1:
        return maxsum([e - k for e in a])
    best = 0
    cur = [0] * m
    for e in a:
        new_cur = [max(0, cur[0]) + e - k if i == 1 else cur[(i - 1) % m] + e for i in range(m)]
        best = max(best, max(new_cur))
        cur = new_cur
    return best


n, m, k = map(int, input().split())
a = list(map(int, input().split()))
print(solve(m, k, a))

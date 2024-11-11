def checker(i, v, l, r):
    if i == l or i == r:
        return False
    return v[i - 1] < v[i] and v[i] > v[i + 1]


def solver(n, k, lst):
    ans, l, r, now = -1, -1, -1, 0
    i = 1
    while i + 1 < k:
        if checker(i, lst, 0, k - 1):
            now += 1
        i += 1
    ans, l, r = now + 1, 0, k - 1
    for i in range(k, n):
        if checker(i - k + 1, lst, i - k, i - 1):
            now -= 1
        if checker(i - 1, lst, i - k + 1, i):
            now += 1
        if now + 1 > ans:
            ans, l, r = now + 1, i - k + 1, i
    return ans, l + 1


for _ in range(int(input())):
    N, K = [int(j) for j in input().split()]
    a = [int(j) for j in input().split()]
    print(*solver(N, K, a))

def solve(inp):
    n = len(inp)
    l = [0] * n
    r = [0] * n
    ans = 0
    l[0] = 1
    updateLeft(inp, l, n)
    updateRight(inp, r, n)

    for i in range(1, n - 1):
        if inp[i + 1] - inp[i - 1] >= 2:
            ans = max(ans, l[i - 1] + r[i + 1] + 1)
    for i in range(n - 1):
        ans = max(ans, r[i + 1] + 1)
    for i in range(1, n):
        ans = max(ans, l[i - 1] + 1)
    return ans


def updateRight(inp, r, n):
    p1 = n - 2
    p2 = n - 1
    r[n - 1] = 1
    while p1 >= 0:
        if inp[p1] >= inp[p1 + 1]:
            p2 = p1
        r[p1] = p2 - p1 + 1
        p1 -= 1


def updateLeft(inp, l, n):
    p1 = 0
    p2 = 1
    while p2 < n:
        if inp[p2] <= inp[p2 - 1]:
            p1 = p2
        l[p2] = p2 - p1 + 1
        p2 += 1


if __name__ == '__main__':
    n = int(input())
    lst = list(map(int, input().strip().split()))
    print(solve(lst))

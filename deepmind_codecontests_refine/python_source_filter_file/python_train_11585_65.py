"""
def solve():
    n, x, y = map(int, input().split())
    ans = []
    for a in range(1, y - x + 1):
        if ((y - x) % a != 0) | (x + a * (n - 1) < y):
            continue
        b = max(y - a * (n - 1), 0)
        if b == 0:
            b = x % a
        for i in range(n):
            ans.append(b)
            b += a
        break
    print(*ans)


for i in range(int(input())):
    solve()
"""


def solve():
    a, b = map(int, input().split())
    c = max(a, b)
    d = min(a, b)
    diff = c - d
    if (diff % 10 == 0):
        print(diff / 10)
    else:
        print(diff / 10 + 1)


for i in range(int(input())):
    solve()
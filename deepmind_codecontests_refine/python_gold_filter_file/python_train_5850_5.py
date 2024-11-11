from sys import stdin
input = stdin.readline

q = int(input())
for _ in range(q):
    c, m, x = [int(x) for x in input().split()]
    x += abs(c - m)
    c = m = min(c, m)
    if x < c:
        a = (c - x) // 3
        b = (c - x) // 3 + ((c - x) % 3 > 0)
        ans = max(min(c - a, x + 2*a), min(c - b, x + 2*b))
    else:
        ans = c
    print(ans)
    
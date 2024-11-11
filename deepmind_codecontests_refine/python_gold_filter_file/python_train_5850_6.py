q = int(input())
for i in range(q):
    c, m, x = map(int, input().split())
    k = min(m, c)
    print(min(k, max((m + c + x - 2 * k), (m + c + x) // 3)))
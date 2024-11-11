q = int(input())
for i in range(q):
    a, b, c, d, k = map(int, input().split())
    if (a + c - 1) // c + (b + c - 1) // d <= k:
        print((a + c - 1) // c, (b + c - 1) // d)
    else:
        print(-1)
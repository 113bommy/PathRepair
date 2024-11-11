t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    if 2 * l > r:
        print(-1, -1)
    else:
        print(l, 2 * l)

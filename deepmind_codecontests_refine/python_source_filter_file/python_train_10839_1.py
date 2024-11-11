n = int(input())
for i in range(n):
    pos = 0
    a, b, k = map(int, input().split())
    if k % 2 == 0:
        pos = (k / 2) * (a - b)
    else:
        k = k - 1
        pos = (k / 2) * (a - b)
        pos += a
    print(int(pos))

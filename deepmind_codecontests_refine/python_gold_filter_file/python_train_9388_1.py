t = int(input())
for i in range(t):
    n, x = map(int, input().split())
    ef = 0
    max1 = 0
    for i in range(n):
        a, b = map(int, input().split())
        max1 = max(max1, a)
        if ef < a - b:
            ef = a - b
    if max1 >= x:
        print(1)
    elif ef == 0:
        print(-1)
    else:
        print(1 + (x - max1 + ef - 1) // ef)
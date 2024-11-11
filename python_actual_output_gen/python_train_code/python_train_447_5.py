n, x, y = map(int, input().split())
a = [int(i) for i in input().split()]
for i in range(n):
    f = False
    for j in range(1, x + 1):
        if i - j == 0:
            break
        if a[i-j] < a[i]:
            f = True
            break
    if f == False:
        for j in range(1, y+1):
            if i + j == n:
                break
            if a[i + j] < a[i]:
                f = True
                break
    if f == False:
        print(i + 1)
        break
t = int(input())

for i in range(t):
    n, x = map(int, input().split())
    mass = [int(x) for x in input().split()]
    arr = [0] * 1002
    for j in range(n):
        arr[mass[j] - 1] = 1
    u = 0
    for j in range(1002):
        if not arr[j]:
            if x > 0:
                x -= 1
                continue
            u = j
            break
    print(u)
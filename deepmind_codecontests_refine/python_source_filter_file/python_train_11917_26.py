n = int(input())
if n == 1:
    print(1)
else:
    a = 0
    sm = 0
    for i in range(1, n + 1):
        if sm + a > n:
            break
        a += i
        sm += a
        # print(i, a, sm)
    print(i - 1)
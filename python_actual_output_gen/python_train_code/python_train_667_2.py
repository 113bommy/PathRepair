for _ in range(int(input())):
    n = int(input())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    z = []
    for i in range(n):
        if not y[i] :
            z.append(x[i])
    lenn = len(z)
    if lenn == 0:
        print(*x)
        continue
    z.sort(reverse = True)
    c = 0
    for i in range(n):
        print("i")
        if c < lenn and not y[i] :
            x[i] = z[c]
            c += 1
    print(*x)
    # 1 0 0 0 1 1 0
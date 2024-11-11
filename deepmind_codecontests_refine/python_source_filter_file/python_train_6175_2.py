T = int(input())
for t in range(T):
    a = input()
    b = input()
    n = len(b)
    L = -1
    for l in range(n, 0, -1):
        for i in range(n - l + 1):
            if b[i:i+l] in a:
                L = l
                break
        else:
            continue
        break
    if L == -1:
        L = 0
    print(len(a) + n - (l << 1))
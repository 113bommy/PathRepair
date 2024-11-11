t = int(input())
for i in range(t):
    p = input()
    h = input()
    f = True
    for i in range(len(h) - len(p) + 1):
        if set(h[i: i + len(p)]) == set(p):
            print('YES')
            f = False
            break
    if f:
        print('NO')

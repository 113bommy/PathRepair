t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    ops = 0

    for i in range(n):
        if s[i] != 0:
            if i != n-1:
                ops += 1
            ops += int(s[i])

    print(ops)
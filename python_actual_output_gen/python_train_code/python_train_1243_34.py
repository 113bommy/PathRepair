n, x = (int(v) for v in input().split())

dis = 0
for _ in range(n):
    op, d = input().split()
    if op == '+':
        x += int(d)
    else:
        if int(d) < x:
            x -= int(d)
        else:
            dis += 1

print(x, dis)
            
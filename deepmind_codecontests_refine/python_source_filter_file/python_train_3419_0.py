H, W, d = [int(x) for x in input().split(" ")]

res = ''

d2 = 2 * d
for h in range(H):
    for w in range(W):
        x = h - w
        y = h + w
        if x % d2 < d:
            c = '.' if  y % d2 < d else '+'
        else:
            c = '*' if  y % d2 < d else '='
        res+= c
    res += '\n'

print(res)

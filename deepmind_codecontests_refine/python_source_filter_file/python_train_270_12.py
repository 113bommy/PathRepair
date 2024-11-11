n = int(input())
p1 = 1
p2 = 2
v = 3
b = True
for i in range(n - 1):
    c = int(input())
    if c == v:
        b = False
        break
    else:
        if c == p1:
            p2, v = v, p2
        else:
            p1, v = v, p1
print('YES' if b else 'NO')
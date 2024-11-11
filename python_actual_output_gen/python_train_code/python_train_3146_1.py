n, q = map(int, input().split())
n2 = (n**2 + 1) // 2

s = []

for i in range(q):
    x, y = map(int, input().split())
    if (x ^ y) & 1:
        s.append((n * (x - 1) + y + 1) // 2)
    else:
        s.append((n2 + (n * (x - 1) + y + 1) // 2))

print('\n'.join(map(str, s)))

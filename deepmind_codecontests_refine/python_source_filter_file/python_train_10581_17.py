n, m = [int(i) for i in input().split()]
c = []
for i in range(n):
    a, b = [int(i) for i in input().split()]
    c.append(a/b)
print(c)
print(min(c) * m)
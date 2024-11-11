a, b, c = [float(i) for i in input().split()]
n = [a, b, c]
n.sort()
a = abs(n[0])
b = abs(n[1])
c = abs(n[2])
m = a + b
n = m - c
g = 0
while n < 0:
    n += 1
    g += 1
print(g)
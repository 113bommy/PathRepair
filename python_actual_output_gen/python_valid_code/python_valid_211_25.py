n, l = map(int, input().split())
a = input().split()
b = []
c = 0
m = 0
x = 0
y = 0
for i in range(n):
    b.append(int(a[i]))
b.sort()
for i in range(n - 1):
    c = int(b[i + 1]) - int(b[i])
    if m < c:
        m = c
x = int(b[0]) - 0
y = l - int(b[-1])
print(float(max(m, x, y)))

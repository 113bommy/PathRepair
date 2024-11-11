n = int(input())

z = []
w = []
for i in range(n):
    x, y = map(int, input().split())
    z.append(x + y)
    w.append(x - y)
z.sort()
w.sort()
print(max(z[-1]-z[0], w[-1]-w[0]))
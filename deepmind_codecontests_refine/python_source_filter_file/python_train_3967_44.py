n, m = map(int, input().split())

l = n + 1

x = 0
for i in range (l + 1):
    x *= 10
    x += 9
print(x)

y = 0
for i in range (l):
    y *= 10
    y += 4

y *= 10
y += 5
print(y)
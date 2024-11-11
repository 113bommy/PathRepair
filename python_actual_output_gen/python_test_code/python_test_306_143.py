m, n = map(int, input().split())

x = 1
while 2*x <= m * n:
    x += 1

print(x)
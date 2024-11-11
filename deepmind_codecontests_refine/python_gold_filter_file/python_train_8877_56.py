t = int(input())
for _ in range(t):
    a, b, c, d = [int(i) for i in input().split()]
    x = a + b
    y = c + d
    print(max(x, y))
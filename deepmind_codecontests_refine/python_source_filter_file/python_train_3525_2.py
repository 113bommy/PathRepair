N = int(input())
a, b = 1, 1
for i in range(N):
    x, y = map(int, input().split())
    c = max(-(-a // x), -(-b // y))
    a, b = c* x, c* y
    print(a + b)
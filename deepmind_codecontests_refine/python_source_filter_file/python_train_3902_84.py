R = lambda: map(int, input().split())
n, m = R()
a, b = "#" * n, "." * (n - 1) + "#"
for i in range(n):
    print(b if i % 2 else a)
    if i % 2: b = b[::-1]

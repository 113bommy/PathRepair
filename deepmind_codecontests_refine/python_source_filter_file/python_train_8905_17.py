n = int(input())
prev = 2
for i in range(1, n + 1):
    cur = (i * (i + 1)) ** 2
    print(int((cur - prev) / i))
    prev = cur ** 0.5

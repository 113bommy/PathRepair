import math
t = int(input())
for _ in range(t):
    n = int(input())
    y = (n - 1) // 2 * 2
    x = y // 2
    print(math.gcd(x, y))
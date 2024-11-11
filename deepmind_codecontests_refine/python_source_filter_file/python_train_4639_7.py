a, b = map(int, input().split())

n = int(input())

mint = (100**2 * 2)**0.5

for _ in range(n):
    x, y, v = map(int, input().split())

    t = ((a - x) ** 2 + (b - y) ** 2) ** 0.5 / v
    mint = min(mint, t)

print(mint)
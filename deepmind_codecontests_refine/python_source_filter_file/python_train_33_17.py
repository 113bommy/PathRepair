a, b, c = map(int, input().split())
t = [1, -c / b] if b else [-(c != 0)]
if a:
    d, x = b * b - 4 * a * c, -2 * a
    if d: t = [0] if d < 0 else [2] + sorted([(b - d ** 0.5) / x, (b + d ** 0.5) / x])
    else: t = [1, b / x]
print(*t)
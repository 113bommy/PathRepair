a, b, c = map(int, input().split())
d = (b * b - 4 * c) ** .5
x, y = (-b + d) // 2 // a, (-b - d) // 2 // a
print(max(x, y), min(x, y))
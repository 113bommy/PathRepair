a, b, c = map(int, input().split())
b /= 2 * a
d = (b * b - c / a) ** 0.5
print(b + d, b - d)
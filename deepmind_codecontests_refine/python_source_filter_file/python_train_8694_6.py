a, b, c = list(map(int, input().split()))
val = []
val.append((-b + (b ** 2 - 4 * a * c) ** 0.5) // (2 * a))
val.append((-b - (b ** 2 - 4 * a * c) ** 0.5) // (2 * a))
print(max(val), min(val))
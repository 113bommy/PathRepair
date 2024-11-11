a, b = [input() for _ in range(2)]
print('YES' if a == b[::-1] else "NO")
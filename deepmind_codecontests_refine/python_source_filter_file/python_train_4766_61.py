x, y = map(int, input().split())

print('Yes' if any(x * 2 + i * 2 for i in range(x + 1)) else 'No')

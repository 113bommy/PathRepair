a, b, c, d = map(int, input().split())
print('Yes' if abs(a-c) <= d or abs(a-b) <= d and abs(a-c) <= d else 'No')
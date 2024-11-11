a, b, c, d = map(int, input().split())
print('Yes' if (d > abs(a-b) and d > abs(b-c)) or d > abs(a-c) else 'No')